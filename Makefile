# compiler
CC = g++
# flags
CFLAGS = -Wall

test: test.cpp avl.hpp avl_interface.hpp
	$(CC) -o test test.cpp $(CFLAGS)
