#include <stdio.h>
#include "drzewo.h"

int main() {
    Tree wsk = NULL;

    wstawianie(&wsk, 4);
    wstawianie(&wsk, 5);
    wstawianie(&wsk, 6);
    wstawianie(&wsk, 2);
    wstawianie(&wsk, 3);
    wstawianie(&wsk, 7);
    wstawianie(&wsk, 8);

    int l_lisci, l_wezlow;

    l_wezlow = liczba_wezlow(wsk);
    l_lisci = liczba_lisci(wsk);

    printf("LICZBA LISCI: %d, LICZBA WEZLOW: %d\n", l_lisci, l_wezlow);

    int wys=0;
    wys = wysokosc(wsk);
    printf("WYSOKOSC DRZEWA: %d\n", wys);

    usun_drzewo(&wsk);

    if(wsk == NULL)
        printf("PUSTE\n");
}
