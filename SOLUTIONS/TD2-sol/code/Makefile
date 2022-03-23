CFLAGS=-Wall 

all: printf testPrintf scanf scanf2 portee tar-sol 

printf: printf.c
	gcc ${CFLAGS}  printf.c -o printf

scanf: scanf.c
	gcc ${CFLAGS}  scanf.c -o scanf

scanf2: scanf2.c
	gcc ${CFLAGS}  scanf2.c -o scanf2

portee: portee.c
	gcc  ${CFLAGS} portee.c -o portee

testPrintf: testPrintf.c
	gcc ${CFLAGS}  testPrintf.c -o testPrintf

tar-sol:
	cd ..;tar cvf TD2-sol.tar code/

clean:
	\rm -rf *.o testPrintf portee scanf printf scanf2 *~
