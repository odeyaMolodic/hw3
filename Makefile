CC = gcc
FLAGS = -Wall

all: isort txtfind

isort: insertionSort.o
	$(CC) $(FLAGS) -o isort insertionSort.o
txtfind: strings.o main.o
	$(CC) $(FLAGS) -o txtfind strings.o main.o

insertionSort.o: insertionSort.c
	$(CC) $(FLAGS) -c insertionSort.c
strings.o: strings.c strings.h
	$(CC) $(FLAGS) -c strings.c
main.o: main.c strings.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o isort txtfind