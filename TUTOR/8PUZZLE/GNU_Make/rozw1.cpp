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

int licznik_konf = 0; //licznik przeanalizowanych konfiguracji
int licznik_krok = 0; //liczba krokow, jaką należy wykonać by uporządkować tablice 

int r_x[4] = {1,0,-1,0}; // x - nr wiersza
int r_y[4] =  {0,-1,0,1}; // y - nr kolumny

//(r_x, r_y) -> ruch w tablicy
//(1,0) -> w prawo, (0,-1) -> w dół, (-1,0) -> w lewo, (0,1) -> w górę


int Rozwiazanie1(int T[4][4], int x, int y) {
    priority_queue <Wezel*, vector<Wezel*>, cmp> Q;

    struct Wezel* korzen = nowyWezel1(T, x, y, x, y, 0, NULL, true);

    Q.push(korzen);

    while(!Q.empty()) {
        struct Wezel* akt = Q.top(); //aktualnie analizowana tablica 3x3
        Q.pop();

        licznik_konf++;

        //jezeli udało nam się otrzymać wymagane uporządkowanie
        if(akt->h == 0) { //liczba klocków nie na swoim miejscu = 0
            //drukowanie
            Drukowanie(akt);
            return;
        }

        //wykonywanie ruchu "pustej przestrzeni"
        for(int i=0; i<4; i++) {
            if(CzyRuchMozliwy(akt->x, akt->y, r_x[i], r_y[i])) {
                //tworze nową tablicę z wykonanym ruchem "pustej przestrzeni"
                struct Wezel* dziecko = nowyWezel1(T, akt->x, akt->y, akt->x + r_x[i], akt->y + r_y[i], akt->g + 1, akt, false);
                Q.push(dziecko);
            }
        }
    }

    return licznik_konf;
}
