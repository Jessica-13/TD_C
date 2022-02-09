########################################################
# Makefile generique pour les programme du TD1 AGP
# Tanguy Risset, 2005
#########################################################
# Variables pour le compilateur et 
# l'editeur de lien (ici on utilise l'editeur de
# lien de gcc
CC            =gcc 
# Attention quand on parle de variable 
# il s'agit de variable d'environnement 
# utilisée par make (exemple: $(CC)
CFLAGS += -g -Wall
#ensemble des préfixes (executable) des programmes a compiler
EXE=pgcd pgcdPrint carre CNP

#A partir des préfixes, on construit les source .c
#les objet (.o inutilisés ici) et une cible prefix.test 
#qui sera utilisée pour lancer le test du prefix correspondant
#La syntaxe $(VAR:suff1=suff2) replace suff1 par suff2 partout dans 
#la variable VAR
SRC=$(EXE:=.c)
OBJ=$(SRC:.c=.o)

#cible principales: on construit les executables 
all: $(EXE) 


#règle générique pour fabriquer les exécutable
#la dépendence sur Makefile permet de forcer 
#la recompilation lorsque l'on modifie le Makefile
%: %.c Makefile %.h
	$(CC) $(CFLAGS) $<  -o $@

test: dummy $(EXE)
	pgcd 779 665
	pgcdPrint  779 665
	carre 9

tar:	dummy 
	make clean
	cd ..;tar cvf facultatif_TD1.tar facultatif_TD1/*.h facultatif_TD1/*.c  facultatif_TD1/Makefile 


dummy:

clean:
	-rm -f *~ *.out $(EXE) *.o

