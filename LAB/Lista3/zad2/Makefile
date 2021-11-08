#Makefile do zadanie 2

all: main

main: main.o rozwiazanie.o f.o
	clang_compile main.o rozwiazanie.o f.o -o main -lm

main.o: main.c
	clang_compile -c main.c

rozwiazanie.o: rozwiazanie.c
	clang_compile -c rozwiazanie.c

f.o: f.c
	clang_compile -c f.c

clean:
	rm -f main *.o *~