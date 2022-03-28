all: main

main: main.o hello.o
	gcc -Wall main.o hello.o -o main

main.o: main.c hello.h
	gcc -Wall main.c -c -o main.o

hello.o: hello.c hello.h
	gcc -Wall hello.c -c -o hello.o

clean:
	rm -f main *.o *~
