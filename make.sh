#!/bin/bash
file_dir="./rpc"
file_name="gfs_server.proto"
rm -rf ${file_dir}
mkdir ${file_dir}
protoc -I ./ --grpc_out=${file_dir} --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ${file_name}
protoc -I ./ --cpp_out=${file_dir} ${file_name}
make -j8
