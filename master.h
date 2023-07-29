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
#include <unistd.h>
#include <mutex>
const int chunk_length = 64 << 20;
namespace Metadata {

class ChunkServer{
  std::string name;
  int reserve[4];         // 剩余容量TGMK
  int max_capacity[4];    // 最大容量
};
extern std::map<std::string,ChunkServer> chunkservers;    // 服务器元数据
class Chunk {
  int chunkid;
  int chunk_length;                               // 现在chunk的大小
  std::string lease_posi;                         // 租约位置
  std::set<std::string> chunk_posis;              // 所在服务器位置
  static std::map<std::string,int> chunkserver_lease_num; // 租约数量
  
public:
  Chunk(int chunkid, int length) : chunkid(chunkid), chunk_length(length) {}
  void add_chunk_posi(std::string ip);
  void dele_chunk_posi(std::string ip);
  void change_chunk_posi(std::string ipdel, std::string ipadd);
  void change_lease(std::string);       // change lease
  //static std::map<std::string, int>chunkserver_lease_num;   // chunkserver上面存在的租约数量
};


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
  std::vector<Chunk> chunk;
  tree_node_mute rwmute;
  std::string name;
  std::string fa_name; // 上一层节点名称
  int ChunkId_num;

public:
  TreeNode(Kind k, TreeNode *fa,std::string name) : k(k),name(name) {
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
  bool get_mute(enum tree_node_mute::Kind k, std::string ip);
  bool unlock(std::string ip);
  std::string get_name() { return name; }
  void change_son_name(std::string ori_name, std::string now_name);
  void rename(std::string filename, std::string change_name); //
  TreeNode *get_next_node(std::string name);
  TreeNode *get_pre_node();
  Chunk get_chunk(int length);
  void make_chunk(int length);
  TreeNode & get_instance(){
    static TreeNode instance(Kind::DIR,NULL,"/");
    return instance;
  }
  void add_tree_node(Kind k, std::string name);
};
} // namespace Metadata

namespace timespace{
void handle(int sig);                  // 信号处理函数
class timer{  // 多线程共享资源，单线程处理定时器。
public:
  class timer_item;
  timer(){
    struct sigaction newact;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;
    newact.sa_handler =static_cast<__sighandler_t>(handle);
    if(sigaction(SIGALRM,&newact,nullptr) == -1){
      std::cerr<<"sig band false"<<std::endl;
    }

  }
  void push_timer();
  bool isempty(){
    std::unique_lock<std::mutex> mute(timer_mute);
    return timer_pq.empty();
  }
  bool get_item(timer_item &t){
    std::unique_lock<std::mutex> mute(timer_mute);
    if(!timer_pq.empty()){
      t = timer_pq.top();
      return true;
    }
    return false;
  }
  bool pq_pop(bool need_alarm = true){
    std::unique_lock<std::mutex> mute(timer_mute);
    if(timer_pq.empty())return false;
    timer_item t = timer_pq.top();
    timer_pq.pop();
    if(need_todo.find(t.id) != need_todo.end())
      need_todo.erase(t.id);
    if(last_reflash_time.find(t.id) != last_reflash_time.end())
      last_reflash_time.erase(t.id);
    if(need_alarm)alarm(t.out_time - time(NULL));

    return true;
  }
  void push_timer(const timer_item &t,bool need_alarm = true){
    std::unique_lock<std::mutex> mute(timer_mute);
    timer_pq.push(t);
    need_todo.insert(t.id);
    if(need_alarm)alarm(t.out_time - time(NULL));
  }

  static timer &get_instance(){
    static timer instance;
    return instance;
  }
  class timer_item{
  public:
    enum Kind{normal,reset} kind;    // 是否会重置定时器 -- 锁需要
    std::function<void()> fun;  // 使用lambda作为回调函数。
    std::string id;             // 定时器唯一标识。
    size_t out_time;
    size_t add_time;            // 当前时间经过add_time时间就算超时
  };
  std::map<std::string,size_t>last_reflash_time;  // 某一定时器最新超时时间。如果没有超时限制，那么到时见直接执行。
  std::set<std::string> need_todo;                // 仍然需要执行的定时器
private:
  void reset_time(timer_item &);              // 定时器超时后，重置定时器时间。
  void reset_out_time(std::string id);        // 重置定时器超时时间
  std::priority_queue<timer_item> timer_pq;   // 优先队列
  std::mutex timer_mute;

};
}
/*
#pragma once
#include <bits/stdc++.h>

class timer_fa {
public:
  timer_fa(size_t time_clock) : time_clock(time_clock) {}

private:
  size_t time_clock;
};

template <class T> class timer_ : public timer_fa {
public:
  timer_(size_t time_clock, std::function<T(void)> fun)
      : timer_fa(time_clock), fun(fun) {}
  bool operator<(const timer_ &t) const { return time_clock > t.time_clock; }
  void callback() { fun(); }

private:
  size_t time_clock;
  std::function<T(void)> fun;
};

#ifdef TEST
int haha(int a) { cout << a << endl; }
int main() {
  timer_ t(time(NULL) + 64, std::bind(haha, 10));
  t.callback();
}
#endif
*/
