all: main

main: main.o pile.o hanoi.o
		gcc main.o pile.o hanoi.o -o main

pile.o: pile.c pile.h pile_type.h
		gcc -c pile.c -o pile.o

hanoi.o : hanoi.c hanoi.h pile.h pile_type.h
		gcc -c hanoi.c -o hanoi.o

main.o: main.c pile.h hanoi.h
		gcc -c main.c -o main.o

clean:
		rm -f main *.o