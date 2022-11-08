
all: main

main: main.o liczba_wezlow.o liczba_lisci.o wstawianie.o wysokosc.o usun_drzewo.o
	clang_compile main.o liczba_wezlow.o liczba_lisci.o wstawianie.o wysokosc.o usun_drzewo.o -o main

main.o: main.c
	clang_compile -c main.c

liczba_wezlow.o: liczba_wezlow.c
	clang_compile -c liczba_wezlow.c

liczba_lisci.o: liczba_lisci.c
	clang_compile -c liczba_lisci.c

wstawianie.o: wstawianie.c
	clang_compile -c wstawianie.c

wysokosc.o: wysokosc.c 
	clang_compile -c wysokosc.c

usun_drzewo.o: usun_drzewo.c 
	clang_compile -c usun_drzewo.c

clean:
	rm -f *.o *~
