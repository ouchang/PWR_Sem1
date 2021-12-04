#include <bits/stdc++.h>
#include "puzzle.h"
#include "wezel.h"
#include "cmp.h"
using namespace std;

//uporzadkowana tablica 3x3
int Wzor[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,0}
};

struct Wezel* nowyWezel(int T[4][4], int x, int y, int nowyX, int nowyY, int g, Wezel* rodzic, bool korzen) {
    struct Wezel* nowy = new Wezel;

    if(korzen) { 
        //kopiowanie wpisanej przez użytkownika tablicy
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                nowy->T[i][j] = T[i][j];
            }
        } 
    }

    nowy->rodzic = rodzic;

    if(rodzic != NULL) {
        //ruch "pustej przestrzeni"
        // (x,y) - współrzędne "pustej przestrzeni" przed wykonaniem ruchu
        // (nowyX, nowyY) - współrzędne "pustej przestrzeni" po wykonaniu ruchu

        nowy->T[x][y] = rodzic->T[nowyX][nowyY]; //ponumerowany klocek idzie na stare miejsce "pustej przestrzeni"
        nowy->T[nowyX][nowyY] = rodzic->T[x][y]; //"pusta przestrzeń" wykonuje ruch

        //kopiowanie ustawień pozostałych klocków
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if((i == x && j == y) || (i == nowyX && j == nowyY))
                    continue;
                
                nowy->T[i][j] = rodzic->T[i][j];
            }
        }
    }

    //liczenie sumarycznej wartości h(x)
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if((nowy->T[i][j] != Wzor[i][j]) && nowy->T[i][j] != 0) //nie wliczaj pustej przestrzeni
                nowy->h++;
        }
    } 

    //liczenie sumarycznej wartości g(x)
    nowy->g = g;

    //wprowadzam współrzędne "pustej przestrzeni"
    nowy->x = nowyX;
    nowy->y = nowyY;

    return nowy;
}
