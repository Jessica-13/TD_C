all: affichage
all: factorielle # Lorsqu’on m’appelle (i.e. commande make), je dois réaliser la cible hello
all: portee
all: lecture

affichage: affichage.c # Pour réaliser la cible hello, je dois avoir la cible hello.c
# gcc affichage.c -o affichage 
		gcc -c affichage.c -o affichage.o
		gcc affichage.o -o affichage
# De plus (ligne 4), si cette cible hello.c est plus récente que le hello 
# que j’ai, je dois exécuter la commande indiqué à la ligne suivante

factorielle: factorielle.c
		gcc -c factorielle.c -o factorielle.o
		gcc factorielle.o -o factorielle

portee: portee.c
		gcc -c portee.c -o portee.o
		gcc portee.o -o portee

lecture: lecture.c
		gcc -c lecture.c -o lecture.o
		gcc lecture.o -o lecture

clean:
		rm -f affichage 
		rm -f affichage.o 

		rm -f factorielle
		rm -f factorielle.o

		rm -f portee
		rm -f portee.o

		rm -f lecture
		rm -f lecture.o
