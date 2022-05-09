CFLAGS = -g -Wall -DDEBUG 
LDFLAGS = -g -Wall -DDEBUG

all: tar pgcd ex1.2 ex1.3 produit_matrice1 produit_matrice2 ABR

pgcd: pgcd.c pgcd.h
	gcc ${CFLAGS} pgcd.c -o pgcd

ex1.2: ex1.2.c
	gcc ${CFLAGS}  ex1.2.c -o ex1.2

ex1.3: ex1.3.c
	gcc ${CFLAGS}  ex1.3.c -o ex1.3

produit_matrice1: produit_matrice1.c
	gcc ${CFLAGS} produit_matrice1.c -o produit_matrice1

produit_matrice2: produit_matrice2.c
	gcc ${CFLAGS} produit_matrice2.c -o produit_matrice2

ABR: ABR.c
	gcc ${CFLAGS} ABR.c -o ANR

tar: clean
	cd ..; tar cvf  sol-DS.tar code/pgcd.* code/ex1.2.c code/ex1.3.c code/produit_matrice*.c code/ABR.c code/Makefile


clean: 
	\rm -rf *.o pgcd ex1.2 ex1.3 produit_matrice1 produit_matrice2
