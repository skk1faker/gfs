all:chunkserver master
.PHONY:all
chunkserver:chunkserver.cpp ./rpc/gfs_server.pb.cc ./rpc/gfs_server.grpc.pb.cc
	g++ $^ -g -o  $@ -std=c++11 -I. `pkg-config --cflags protobuf grpc`     `pkg-config --libs protobuf grpc++ grpc`     -pthread -Wl,--no-as-needed -lgrpc++_reflection -W

master:master.cpp ./rpc/gfs_server.pb.cc ./rpc/gfs_server.grpc.pb.cc
	g++ $^ -g -o  $@ -std=c++11 -I. `pkg-config --cflags protobuf grpc`     `pkg-config --libs protobuf grpc++ grpc`     -pthread -Wl,--no-as-needed -lgrpc++_reflection -W

.PHONY:clean
clean:
	rm chunkserver master


