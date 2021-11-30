CC = g++
FLAGS = -Wall -Wextra -ggdb -llua -L./lua -I./lua -ldl
MAIN = main.cpp
SRC = $(wildcard src/*.cpp)
HEADERS = $(wildcard src/*.hpp)
# OBJ = $(wildcard obj/*.o)
OBJ = $(SRC:.cpp=.o)

# TODO Separate compilation and linking of libs

.PHONY: all build clean

all: build run clean

build: rpc.o utils.o error.o state.o methods.o server.o main.o link

%.o: src/%.cpp src/%.hpp
	$(CC) $(FLAGS) -c $<

link: $(OBJ)
	$(CC) $(FLAGS) -o build/main main.o $^ -lc

run: build/main
	build/main

clean:
	rm -rf build/main
	rm -rf *.o
	rm -rf src/*.o

