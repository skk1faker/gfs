/*================================================================
*   Copyright (C) 2023 Wangxinpeng. All rights reserved.
*   
*   filename：    chunkserver.cpp
*   username:     skt1faker
*   create time:  14:05  2023.07.01
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/


#include "./rpc/gfs_server.grpc.pb.h"
#include "./rpc/gfs_server.pb.h"
#include "chunkserver.h"
#include <grpcpp/grpcpp.h>

using grpc::ServerContext;
using grpc::ServerBuilder;
using grpc::Status;
using grpc::Server;


class Chunk;

Status Chunk::get_heartbeat(ServerContext *context, const ChunkServer::VoidMessage *voidmessage, ChunkServer::HeartBeat *heartbeat){
    heartbeat->set_worktimes(10);
    return Status::OK;
}

int main(int argc,char *argv[])
{
  if(argc < 2){
    printf("need port");
    return 0;
  }
  std::string server_addr = (std::string)"0.0.0.0:" + (std::string)argv[1];
  ServerBuilder builder;
  builder.AddListeningPort(server_addr,grpc::InsecureServerCredentials());
  Chunk chunk_server;
  builder.RegisterService(&chunk_server);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  server->Wait();
}
