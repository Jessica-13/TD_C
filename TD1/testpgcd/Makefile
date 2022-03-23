all: main

main: main.o
	gcc -Wall -L../pgcd/ main.o -o main -lpgcd

main.o: main.c
	gcc -Wall -I../pgcd main.c -c -o main.o

clean:
	rm -f main *.o *~