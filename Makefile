all: avl.o
	g++ avl.o -Wall

avl.o: avl.cpp avl.hpp
	g++ -c avl.cpp -Wall
