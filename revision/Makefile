all: creerPersonne

creerPersonne : creerPersonne.o 
	gcc creerPersonne.o -o creerPersonne

creerPersonne.o : creerPersonne.c type_personne.h
	gcc -c creerPersonne.c -o creerPersonne.o

clean: 
	rm -f creerPersonne *.o 