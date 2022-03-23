CFLAGS = -g -Wall -DDEBUG
LDLAGS = -g -Wall -DDEBUG
SOURCE = pointeur1.c pointeur2.c pointeur3.c pointeur1-bis.c
OBJECT = $(SOURCE:.c=.o)
TARGET = $(SOURCE:.c=)

.INTERMEDIATE: $(OBJECT) #pegagogic plugin: if not there, make will use its
			 #own implicit rules to compile the .c files
			 #instead of mine

all:  $(TARGET)



%: %.o
	gcc  $< -o $@

%.o: %.c
	gcc $(TEST) -c $< -o $@


tar: 
	cd ..; tar cvf  TD4-code.tar code/pointeur*.c code/Makefile code/produitScalaireSol.c

tar-sol: 
	cd ..; tar cvf  TD4-sol.tar code/pointeur*.c code/Makefile code/produitScalaireSol.c code/produitScalairePointeurSol.c code/sol-pointeur3.c


clean: 
	\rm -rf *.o $(TARGET)  *~ a.out sol-pointeur2 sol-pointeur3
