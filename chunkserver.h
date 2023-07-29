/*================================================================
*   Copyright (C) 2023 Wangxinpeng. All rights reserved.
*   
*   filename：    chunkserver.h
*   username:     skt1faker
*   create time:  14:07  2023.07.01
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#pragma once
#include "./rpc/gfs_server.grpc.pb.h"
#include "./rpc/gfs_server.pb.h"
#include <grpcpp/grpcpp.h>
using grpc::ServerContext;
using grpc::Status;
class Chunk:public ChunkServer::ChunkService::Service{
  Status get_heartbeat(ServerContext *context, const ChunkServer::VoidMessage *voidmessage, ChunkServer::HeartBeat *heartbeat);
  
};
