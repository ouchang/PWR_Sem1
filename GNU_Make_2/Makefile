#Makefile
#Przykład z listy 3 na laboratoria (WST_DO_INF)

all: main

main: main.o f.o g.o h.o
	clang main.o f.o g.o h.o -o main

main.o: main.c
	clang -c main.c

f.o: f.c
	clang -c f.c

g.o: g.c
	clang -c g.c

h.o: h.c
	clang -c h.c

clean:
	rm -f main *.o*~