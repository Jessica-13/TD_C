CFLAGS=-Wall -g 

all: main 

main: main.o arbre.o
	gcc ${CFLAGS} main.o arbre.o -o main

main.o: main.c arbre.h arbre_type.h
	gcc ${CFLAGS}  -c -g main.c -o main.o

arbre.o: arbre.c arbre.h arbre_type.h
	gcc ${CFLAGS}  -c -g arbre.c -o arbre.o

ABR: ABR.c
	gcc ${CFLAGS}   ABR.c -o ABR

tar-sol: clean
	cd ..; tar cvf TD5-sol.tar code/

valgrindEx: valgrindEx.c
	gcc  valgrindEx.c -o valgrindEx

clean:
	\rm -rf *~ *.o main ABR a.out valgrindEx
