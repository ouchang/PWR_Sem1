#Makefile do zadania3

all: main

main: main.o phi.o gcd.o
	clang_compile main.o phi.o gcd.o -o main

main.o: main.c
	clang_compile -c main.c

phi.o: phi.c
	clang_compile -c phi.c

gcd.o: gcd.c
	clang_compile -c gcd.c

clean:
	rm -f main *.o *~
