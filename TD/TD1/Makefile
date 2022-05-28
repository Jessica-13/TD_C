all: main

main: main.o hello.o carre.o
		gcc main.o hello.o -o main

carre.o: carre.c carre.h
		gcc -c carre.c -o carre.o

hello.o: hello.c hello.h
		gcc -c hello.c -o hello.o

main.o: main.c hello.h carre.h
		gcc -c main.c -o main.o

clean:
		rm -f main *.o