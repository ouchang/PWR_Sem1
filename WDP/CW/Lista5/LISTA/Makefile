
all: main

main: main.o dopisz_niemalejaco.o drukowanie.o usun.o
	clang_compile main.o dopisz_niemalejaco.o usun.o drukowanie.o -o main

main.o: main.c
	clang_compile -c main.c

dopisz_niemalejaco.o: dopisz_niemalejaco.c
	clang_compile -c dopisz_niemalejaco.c

drukowanie.o: drukowanie.c
	clang_compile -c drukowanie.c

usun.o: usun.c
	clang_compile -c usun.c

clean:
	rm -f *.o *~
