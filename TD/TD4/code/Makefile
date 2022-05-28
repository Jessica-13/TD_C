# On peut visualiser l'ensemble des réglages par défaut de make avec l'option -p

# CC indique le compilateur C utilisé par le système
# SHELL indique sous quel shell est exécuté la commande (en général sh)
CFLAGS = -g -Wall -DDEBUG # CFLAGS indique les options par défaut du compilateur
LDFLAGS =  -Wall # LDFLAGS indique les options par défaut de l'éditeur de lien
SOURCE = pointeur1.c pointeur2.c pointeur3.c pointeur1-bis.c produitScalaireSol.c
OBJECT = $(SOURCE:.c=.o) # variable dynamique pour avoir les noms des .o
TARGET = $(SOURCE:.c=)
HEADER = $(wildcard *.h) # wildcard récupère tous les fichiers .h du repertoire
.PRECIOUS: $(OBJECT) # indication à make de ne pas supprimer les .o intermédiaire

all:  $(TARGET)


%: %.o $(HEADER)
	gcc  ${LDFLAGS} $< -o $@ 
# $@ est le nom de la cible de la règle
# $< est le nom de la première dépendance sélectionnée

%.o: %.c
# Indique que chaque fichier .o nécessaire à la création du projet est obtenu à partir du fichier .c correspondant
	gcc ${CFLAGS} -c $< -o $@


tar: clean
	cd ..; tar cvf  TD4-code.tar code/pointeur*.c code/Makefile code/produitScalaireSol.c

tar-sol: clean
	cd ..; tar cvf  TD4-sol.tar code/pointeur*.c code/Makefile code/produitScalaireSol.c code/produitScalairePointeurSol.c code/sol-pointeur3.c


clean: 
	\rm -rf *.o $(TARGET)  *~ a.out sol-pointeur2 sol-pointeur3

# Résultat de l'exécution de la commande make
# 	gcc -g -Wall -DDEBUG  -c produitScalaireSol.c -o produitScalaireSol.o
# 	gcc  -Wall  produitScalaireSol.o -o produitScalaireSol

# .SUFFIXES : .o .c
# .c.o :
# ${CC} ${CFLAGS} -c $< -o $@
