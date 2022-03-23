all: main

main: main.o arbre.o
		gcc main.o arbre.o -o main

arbre.o: arbre.c arbre.h arbre_type.h
		gcc -c arbre.c -o arbre.o

main.o: main.c arbre.h 
		gcc -c main.c -o main.o

clean:
		rm -f main *.o


# all : arbre.o (ça est notre objectif)
# arbre.o : arbre.c arbre.h arbre_type.h (on veut arbre.o , on  besoin de arbre.c arbre.h arbre_type.h)
# gcc -c arbre.c -o arbre.o