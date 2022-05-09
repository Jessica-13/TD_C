all: bin/hanoi

bin/hanoi: obj/main.o obj/hanoi.o obj/pile.o
	gcc -o $@ $^


obj/%.o: src/%.c
	gcc -Wall -Iinclude -o $@ -c $<

clean:
	rm -f obj/* *~

mrproper: clean
	rm bin/*
