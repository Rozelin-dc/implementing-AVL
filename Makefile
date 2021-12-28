# compiler
CC = g++
# flags
CFLAGS = -Wall

test: avl.o test.o
	$(CC) -o test test.o avl.o $(CFLAGS)

test.o: test.cpp avl.hpp
	$(CC) -c test.cpp $(CFLAGS)

avl.o: avl.cpp avl.hpp
	$(CC) -c avl.cpp $(CFLAGS)
