/*================================================================
*   Copyright (C) 2023 Wangxinpeng. All rights reserved.
*
*   filename：    master.h
*   username:     skt1faker
*   create time:  14:07  2023.07.01
    email:        skk1faker@163.com
*   descripe:
*
================================================================*/
#include <bits/stdc++.h>
#include <mutex>
#include <unistd.h>
#define LAST_HOUR 5
const int chunk_length = 64 << 20;
namespace Metadata {
class Chunk;
class ChunkServer {
  std::string name;          // serverip
  int reserve[4];            // 剩余容量TGMK
  int max_capacity[4];       // 最大容量
  std::set<size_t> chunk_set; // chunk集合
  std::set<size_t> lease;     // 持有租约的chunk
  int last_add_chunk[LAST_HOUR]; // 书写位置在当前时间小时位置 % LAST_HOUR
  int add_val;
};
extern std::map<std::string, ChunkServer> chunkservers; // 服务器元数据
class Chunk {
  size_t chunkid;
  int chunk_length;                  // 现在chunk的大小
  size_t chunk_version;                 // 版本号
  std::string lease_posi;            // 租约位置
  std::set<std::string> chunk_posis; // 所在服务器位置

public:
  Chunk(int chunkid, int length) : chunkid(chunkid), chunk_length(length) {}
  void add_chunk_posi(std::string ip);
  void dele_chunk_posi(std::string ip);
  void change_chunk_posi(std::string ipdel, std::string ipadd);
  void change_lease(
      std::
          string); // change lease
                   // 超时后自动释放租约，如果有持续的写请求就保持租约，租约的分配单位为chunk，不断地调整写操作所在服务器的位置
};
extern std::map<size_t, Chunk*> chunklist; // 所有chunk，使用size_t chunkid标识

class TreeNode {
private:
  class tree_node_mute { // 不可用来占用线程，所以使用这种锁的方式
  public:
    enum Kind { READ, WRITE } k;
    bool get_read_lock(std::string ip);
    bool get_write_lock(std::string ip);
    bool unlock(std::string ip);

  private:
    std::mutex mute;
    std::set<std::string> read_lock;
    std::set<std::string> write_lock;
  };
  enum Kind { FILE, DIR } k;
  std::map<std::string, TreeNode *> next_node;
  std::vector<size_t> chunk;   // 有问题这里应该是chunkid,否则chunk修改无法同步。
  std::vector<size_t>chunk_in_file_posi;    // chunk结尾位置为文件的偏移多少。一个chunk[i]的范围为(chunk_in_file_posi[i - 1],chunk_in_file_posi[i]],左开右闭，文件长度中，空文件长度为0.
  tree_node_mute rwmute;
  std::string name;
  std::string fa_name; // 上一层节点名称
  int ChunkId_num;     // 已经分配的chunkid的数量

public:
  TreeNode(Kind k, TreeNode *fa, std::string name) : k(k), name(name) {
    next_node[fa->name] = fa;
    fa_name = fa->name;
    ChunkId_num = 0;
  }
  int get_new_ChunkId() { return ++ChunkId_num; }
  /*  TODO:
   *  //元数据
   *  1.查看是否是文件
   *
   *  2.读取chunk
   *  3.获取chunk
   *  4.修改文件名
   *  5.获取读写锁是否成功
   *  6.释放读写锁
   *  7.进入下一层
   *  8.进入上一层
   * */
  bool is_file() { return k == Kind::FILE; }
  bool lock(
      enum tree_node_mute::Kind k,
      std::string
          ip); // 锁住一个文件，因为一个文件只有一个人操作。注意，这个必须是一个可重入锁，否则不能对多个chunk操作。
  bool unlock(std::string ip);
  std::string get_name() { return name; }
  void change_son_name(std::string ori_name, std::string now_name);
  void rename(std::string filename, std::string change_name); //
  TreeNode *get_next_node(std::string name);
  TreeNode *get_pre_node();
  Chunk get_chunk(int length);
  void make_chunk(int length);
  TreeNode &get_instance() {
    static TreeNode instance(Kind::DIR, NULL, "/");
    return instance;
  }
  void add_tree_node(Kind k, std::string name);
};

} // namespace Metadata
namespace LOG {

struct addchunk {
  std::string filename;
  int chunks_length;
  int chunkids[0];
};
struct delchunk {
  std::string filename;
  int chunks_length;
  int chunkids[0];
};
struct changelease{
  std::string filename;
  std::string chunkserver_posi;
}
class Masterlog {  // 记录修改元数据操作的位置。
  enum Op {
    ADDCHUNK,
    DELCHUNK,
  } op;
  union Opdata {
    struct addchunk add;
    struct delchunk del;
  } opdata;
  // 给出日志回放函数。
};
} // namespace LOG

namespace timespace {
void handle(int sig); // 信号处理函数
class timer { // 多线程共享资源，单线程处理定时器。 可能定时器处理上有问题。
public:
  class timer_item;
  timer() {
    struct sigaction newact;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;
    newact.sa_handler = static_cast<__sighandler_t>(handle);
    if (sigaction(SIGALRM, &newact, nullptr) == -1) {
      std::cerr << "sig band false" << std::endl;
    }
  }
  // handle 使用的接口,不需要加锁。
  bool pq_pop_handleuse(bool need_alarm = true);
  // handle
  // 不使用接口，下面是有lock的接口，handle整个操作使用一个大范围的锁，防止性能下降。
  bool isempty();
  bool get_item(timer_item &t);
  void push_timer(const timer_item &t, bool need_alarm = true);

  static timer &get_instance() {
    static timer instance;
    return instance;
  }
  class timer_item {
  public:
    enum Kind { normal, reset } kind; // 是否会重置定时器 -- 锁需要
    std::function<void()> fun;        // 使用lambda作为回调函数。
    std::string id; // 定时器唯一标识。mac + 线程id + 资源名，定时器涉及到
    size_t out_time;
    size_t add_time; // 当前时间经过add_time时间就算超时
    bool need_thread;
    bool operator<(const timer_item &item) const {
      return item.out_time < out_time;
    }
  };

private:
  std::map<std::string, size_t>
      last_reflash_time; // 某一定时器最新超时时间。如果没有超时限制，那么到时见直接执行。
  std::set<std::string> need_todo;          // 仍然需要执行的定时器
  std::priority_queue<timer_item> timer_pq; // 优先队列
  std::mutex timer_mute;
  friend void handle(int sig);
};
} // namespace timespace

namespace Threadpool {
template <class T> class Safequeue {
public:
private:
  std::queue<T> q;
  std::mutex queue_mute;
};

/*
class ThreadPool{
public:
  class Threadele{
  public:
    void operator ()(){
      while(!pool->shutdown){
        std::unique_lock<>
        if(pool)
      }
    }
  private:
    ThreadPool *pool;

  }
  ThreadPool(int thread_num){

  }
  static ThreadPool & get_instance()
  {
    static ThreadPool instance(int num);
    return instance;
  }
  template<class F,class ...Args>
  auto submit ->decltype(F(args...))(F && f, Args args...);
private :


}
*/

} // namespace Threadpool
