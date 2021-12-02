CC = g++
FLAGS = -Wall -Wextra -ggdb -llua -L./lua -I./lua -ldl
MAIN = main.cpp
SRC = $(wildcard src/*.cpp)
HEADERS = $(wildcard src/*.hpp)
OBJ = $(SRC:.cpp=.o)

.PHONY: all build clean

all: build run

build: main.o link

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

# Test part

test_%: tests/%.json
	make build
	clear
	build/main < $<

