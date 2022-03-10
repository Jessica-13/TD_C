all: main

main: main.o whileQ3.o
		gcc main.o whileQ3.o -o main

whileQ3.o: whileQ3.c whileQ3.h
		gcc -c whileQ3.c -o whileQ3.o

main.o: main.c whileQ3.h
		gcc -c main.c -o main.o

clean:
		rm -f main *.o