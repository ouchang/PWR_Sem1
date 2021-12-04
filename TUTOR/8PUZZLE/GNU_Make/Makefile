all: main

main: main.o Losowanie.o CzyRuchMozliw.o Drukowanie.o nowyWezel1.o nowyWezel2.o nowyWezel3.o Rozwiazanie1.o Rozwiazanie2.o Rozwiazanie3.o
	clang main.o Losowanie.0 CzyRuchMozliw.o Drukowanie.o nowyWezel1.o nowyWezel2.o nowyWezel3.o Rozwiazanie1.o Rozwiazanie2.o Rozwiazanie3.o -o main

main.o: main.c
	clang -c main.c

Losowanie.o: Losowanie.c
	clang -c Losowanie.c

CzyRuchMozliw.o: CzyRuchMozliw.c
	clang -c CzyRuchMozliw.c

Drukowanie.o: Drukowanie.c
	clang -c Drukowanie.c

nowyWezel1.o: nowyWezel1.c
	clang -c nowyWezel1.c

nowyWezel2.o: nowyWezel2.c
	clang -c nowyWezel2.c

nowyWezel3.o: nowyWezel3.c
	clang -c nowyWezel3.c

Rozwiazanie1.o: Rozwiazanie1.c
	clang -c Rozwiazanie1.c

Rozwiazanie2.o: Rozwiazanie2.c
	clang -c Rozwiazanie2.c

Rozwiazanie3.o: Rozwiazanie3.c
	clang -c Rozwiazanie3.c

clean:
	rm -f main *.o*~
