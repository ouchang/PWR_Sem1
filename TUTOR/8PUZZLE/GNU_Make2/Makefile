#Makefile do zad1

all: main

main: main.o wylosowanie.o rozw1.o rozw2.o rozw3.o
	g++ main.o wylosowanie.o rozw1.o rozw2.o rozw3.o -o main

main.o: main.cpp
	g++ -c main.cpp

wylosowanie.o: wylosowanie.cpp
	g++ -c wylosowanie.cpp

rozw1.o: rozw1.cpp 
	g++ -c rozw1.cpp

rozw2.o: rozw2.cpp 
	g++ -c rozw2.cpp

rozw3.o: rozw3.cpp
	g++ -c rozw3.cpp

clean:
	rm -f main *.o *~ 
