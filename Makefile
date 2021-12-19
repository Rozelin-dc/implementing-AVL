# compiler
CC = g++
# flags
CFLAGS = -Wall

all: avl.o
	$(CC) avl.o $(CFLAGS)

test: test.o avl.o
	$(CC) -o test test.o avl.o $(CFLAGS)

test.o: test.cpp
	$(CC) -c test.cpp $(CFLAGS)

avl.o: avl.cpp avl.hpp
	$(CC) -c avl.cpp $(CFLAGS)
