CC = g++

all: ./bin/simualoc.o ./bin/main.o
	$(CC) -o trabalho ./bin/simualoc.o ./bin/main.o

./bin/main.o: ./main.cpp ./simualoc.hpp
	$(CC) -o ./bin/main.o ./main.cpp -c

./bin/simualoc.o: ./simualoc.cpp 
	$(CC) -o ./bin/simualoc.o ./simualoc.cpp -c

