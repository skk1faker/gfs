/*================================================================
*   Copyright (C) 2023 Wangxinpeng. All rights reserved.
*
*   filename：    master.cpp
*   username:     skt1faker
*   create time:  14:06  2023.07.01
    email:        skk1faker@163.com
*   descripe:
*
================================================================*/

#include "./rpc/gfs_server.grpc.pb.h"
#include "./rpc/gfs_server.pb.h"
#include "master.h"
#include <bits/stdc++.h>
#include <grpcpp/grpcpp.h>
#include <thread>

namespace Metadata {
bool TreeNode::tree_node_mute::get_read_lock(std::string ip) {
  std::unique_lock<std::mutex> mu(mute);
  if (write_lock.size() > 0) {
    return false;
  }
  read_lock.insert(ip);
  return true;
}
bool TreeNode::tree_node_mute::get_write_lock(std::string ip) {
  std::unique_lock<std::mutex> mu(mute);
  if (write_lock.size() > 0 || read_lock.size() > 0) {
    return false;
  }
  write_lock.insert(ip);
  return true;
}
bool TreeNode::tree_node_mute::unlock(std::string ip) {
  std::unique_lock<std::mutex> mu(mute);
  if (write_lock.size() > 0) {
    if (write_lock.find(ip) == write_lock.end()) {
      return false;
    } else {
      write_lock.erase(ip);
      return true;
    }
  } else if (read_lock.size() > 0) {
    if (read_lock.find(ip) == read_lock.end()) {
      return false;
    } else {
      read_lock.erase(ip);
      return true;
    }
  } else {
    return false;
  }
}
bool TreeNode::get_mute(enum TreeNode::tree_node_mute::Kind k, std::string ip) {
  if (k == TreeNode::tree_node_mute::Kind::READ) {
    return rwmute.get_read_lock(ip);
  } else if (k == TreeNode::tree_node_mute::Kind::WRITE) {
    return rwmute.get_write_lock(ip);
  } else
    return false;
}
bool TreeNode::unlock(std::string ip) { return rwmute.unlock(ip); }
void TreeNode::change_son_name(std::string filename, std::string change_name) {
  TreeNode *val = next_node[filename];
  next_node.erase(filename);
  next_node[change_name] = val;
}
void TreeNode::rename(std::string filename, std::string change_name) {
  // get_next_node(fa_name)->change_son_name(filename, change_name);
  next_node[fa_name]->change_son_name(filename, change_name);
}

TreeNode *TreeNode::get_next_node(std::string name) { return next_node[name]; }

TreeNode *TreeNode::get_pre_node() { return next_node[fa_name]; }

Chunk TreeNode::get_chunk(int length) { return chunk[length / chunk_length]; }
void Chunk::add_chunk_posi(std::string ip) { chunk_posis.insert(ip); }
void Chunk::dele_chunk_posi(std::string ip) { chunk_posis.erase(ip); }
void Chunk::change_chunk_posi(std::string ipdel, std::string ipadd) {
  add_chunk_posi(ipadd);
  dele_chunk_posi(ipdel);
}
void TreeNode::make_chunk(int length) {
  Chunk temp(get_new_ChunkId(), length);
  chunk.push_back(temp);
}
void TreeNode::add_tree_node(Kind k, std::string son_name){
  next_node[son_name] = new TreeNode(k,this,son_name);
}

} // namespace Metadata

namespace timespace{
void handle_hah(int sig){
  timer &t = timer::get_instance();
  timer::timer_item t_item;
  while(!t.isempty()){
    size_t now_time = time(NULL);
    if(!t.get_item(t_item))break;
    if(t_item.out_time > now_time)break;
    t.pq_pop();
    /*
     * 定时器执行条件
     * 1. 在执行列表中
     * 2. 超时类型定时器，只有在超时的时候执行，首先检查是否超时
     * */
    if(t.need_todo.find(t_item.id) == t.need_todo.end())continue;
    if(t_item.kind == timer::timer_item::reset && t_item.out_time < t.last_reflash_time[t_item.id] + t_item.add_time){  // 未超时
      t_item.out_time = t.last_reflash_time[t_item.id] + t_item.add_time;
      t.push_timer(t_item); // 重新设置超时时间
      continue;
    }
    std::thread(t_item.fun);
  }
  alarm(t_item.out_time - time(NULL));
}
}


using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

int main() {
  std::shared_ptr<Channel> channel = grpc::CreateChannel(
      "127.0.0.1:33334", grpc::InsecureChannelCredentials());
  std::unique_ptr<ChunkServer::ChunkService::Stub> stub_ =
      ChunkServer::ChunkService::NewStub(channel);
  while (true) {
    printf("1");
    ChunkServer::VoidMessage void_message;
    ChunkServer::HeartBeat heartBeat;
    ClientContext context; // 一个grpc请求对应一个，每个请求加都要重新申请新的
    Status st = stub_->get_heartbeat(&context, void_message, &heartBeat);
    if (st.ok()) {
      for (int i = 0; i < heartBeat.chunkaddlist().size(); i++) {
        printf("%ld\n", heartBeat.chunkaddlist()[i]);
      }
    }
  }
}
