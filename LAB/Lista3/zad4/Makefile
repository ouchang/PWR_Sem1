#Makefile dla zadania 4

all: main

main: main.o newagent.o north.o south.o west.o east.o distance.o
	clang_compile main.c newagent.c north.c south.c west.c east.c distance.c -o main -lm

newagent.o: newagent.c
	clang_compile -c newagent.c

north.o: north.c
	clang_compile -c north.c

south.o: south.c
	clang_compile -c south.c

west.o: west.c
	clang_compile -c west.c

east.o: east.c
	clang_compile -c east.c

distance.o: distance.c
	clang_compile -c distance.c

clean:
	rm -f *.o *~
