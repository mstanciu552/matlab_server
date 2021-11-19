CC = g++
FLAGS = -Wall -Wextra -ggdb
MAIN = main.cpp
SRC = $(wildcard src/*.cpp)
HEADERS = $(wildcard src/*.hpp)
OBJ = $(filter-out obj/json.o, $(wildcard obj/*.o))

# TODO Separate compilation and linking of libs

all: build run

# build: rpc.o main.o link
build: $(MAIN) $(SRC) $(HEADERS)
	$(CC) $(FLAGS) $< $(SRC) -o build/main

%.o: src/%.cpp src/%.hpp
	$(CC) $(FLAGS) -o ./obj/$@ -c $<

%.o: lib/%.hpp
	$(CC) $(FLAGS) -o ./obj/$@ -c $<

%.o: %.cpp
	$(CC) $(FLAGS) -o ./obj/$@ -c $<

link: $(OBJ)
	$(CC) -o build/main $^ -lc

run: build/main
	build/main

clean:
	rm build/main

.PHONY: clean
