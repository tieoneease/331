CPPFLAGS=-std=c++11 -g -O3

bstree: main.o 
	g++ main.o -o bipartite

main.o: main.cpp graph.h 
	g++ $(CPPFLAGS) -c main.cpp

clean:
	rm *.o -f
