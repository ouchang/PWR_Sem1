#include <bits/stdc++.h>
#include "puzzle.h"
//#include "wezel.h"
#include "cmp.h"
using namespace std;

int main() {
    int T[4][4];
    int x,y; 
    int licznik_konf1, licznik_konf2, licznik_konf3;
    array<int, 9> A;
    int idx=0;

    //losowanie tablicy
    A = Losowanie();

    //wczytywanie tablicy 3x3
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            T[i][j] = A[idx];
            idx++;

            if(T[i][j] == 0) {
                x = i;
                y = j;
            }
        }
    }

    printf("ROZWIAZANIE 1: \n");
    licznik_konf1 = Rozwiazanie1(T, x, y);
    printf("\n");

    printf("ROZWIAZANIE 2: \n");
    licznik_konf2 = Rozwiazanie2(T, x, y);
    printf("\n");

    printf("ROZWIAZANIE 3: \n");
    licznik_konf3 = Rozwiazanie3(T, x, y);
    printf("\n");

    printf("Liczba przeanalizowanych konfiguracji w Rozwiązaniu1: %d\n", licznik_konf1);
    printf("Liczba przeanalizowanych konfiguracji w Rozwiązaniu2: %d\n", licznik_konf2);
    printf("Liczba przeanalizowanych konfiguracji w Rozwiązaniu3: %d\n", licznik_konf3);
}
