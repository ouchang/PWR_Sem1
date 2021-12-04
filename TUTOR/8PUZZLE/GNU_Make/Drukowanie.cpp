#include <bits/stdc++.h>
#include "puzzle.h"
#include "wezel.h"
using namespace std;

//int licznik_krok = 0;

void Drukowanie(Wezel* wezel) {
    if(wezel == NULL)
        return;
    
    Drukowanie(wezel->rodzic);

    //licznik_krok++;

    //drukowanie
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", wezel->T[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
