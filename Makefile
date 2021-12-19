# compiler
CC = g++
# flags
CFLAGS = -Wall

all: avl.o
	$(CC) avl.o $(CFLAGS)

avl.o: avl.cpp avl.hpp
	$(CC) -c avl.cpp $(CFLAGS)
