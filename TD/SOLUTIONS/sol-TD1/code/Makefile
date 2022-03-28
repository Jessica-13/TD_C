CFLAGS	+= -Wall -g -I./

all: hello sqrt

hello: hello.o
	gcc ${CFLAGS} hello.o -o hello

hello.o: hello.c
	gcc ${CFLAGS} -c hello.c -o hello.o

sqrt: sqrt.c
	gcc -Wall sqrt.c -o sqrt -lm

tar-sol: clean
	cd ..; tar cvf sol-TD1.tar code

clean:
	rm -f hello *~ sqrt *.o
