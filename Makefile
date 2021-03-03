all:
	g++ `pkg-config --cflags --libs protobuf` -lpthread -o main main.cpp test.pb.cc
clean:
	rm -f main
