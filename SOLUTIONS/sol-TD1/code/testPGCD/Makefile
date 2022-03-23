all: main

main: main.o
	gcc -Wall  -L ../libPGCD/ main.o -o main -l pgcd

main.o: main.c
	gcc -Wall -I ../libPGCD main.c -c -o main.o

clean:
	rm -f main *.o *~
