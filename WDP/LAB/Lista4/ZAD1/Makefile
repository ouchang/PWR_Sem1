all: main

main: main.o match.o
	clang main.o match.o -o main

main.o: main.c
	clang -c main.c

match.o: match.c
	clang -c match.c

clean:
	rm -f main *.o*~
