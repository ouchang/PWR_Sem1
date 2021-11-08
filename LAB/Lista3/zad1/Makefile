#Makefile do zad1

all: main

main: main.o palindrom.o
	clang_compile main.o palindrom.o -o main

main.o: main.c
	clang_compile -c main.c

palindrom.o: palindrom.c 
	clang_compile -c palindrom.c

clean:
	rm -f main *.o *~ 