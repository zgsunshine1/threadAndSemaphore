.PHONY:multiThread
multiThread:
	g++ -g -Wall multiPthread.cpp -o multithread -lpthread -std=c++11
.PHONY:
clean:
	rm -rf multiPthread
