all: main

main: main.o
		gcc -Wall -L../libpgcd/ main.o -o main -lpgcd

main.o: main.c pgcd.h
		gcc -c main.c -o main.o

clean:
		rm -f main *.o

# ar -crs libpgcd.a pgcd.o
# gcc -Wall -L../libpgcd/ main.o -o main -lpgcd