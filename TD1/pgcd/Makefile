all: main
all: libpgcd.a

main: main.o pgcd.o 
		gcc main.o pgcd.o -o main
		gcc -Wall -L../libpgcd/ main.o -o main -lpgcd

pgcd.o: pgcd.c pgcd.h
		gcc -c pgcd.c -o pgcd.o

main.o: main.c pgcd.h
		gcc -c main.c -o main.o

libpgcd.a : pgcd.o
		ar -crs libpgcd.a pgcd.o

clean:
		rm -f main *.o
		rm -f pgcd *.o
		rm -f libpgcd.a

# ar -crs libpgcd.a pgcd.o
# gcc -Wall -L../libpgcd/ main.o -o main -lpgcd