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

pair<int,int> Wzor_WSP[9] = { make_pair(2,2), make_pair(0,0), make_pair(0,1), make_pair(0,2), make_pair(1,0), make_pair(1,1), make_pair(1,2), make_pair(2,0), make_pair(2,1)};

struct Wezel* nowyWezel2(int T[4][4], int x, int y, int nowyX, int nowyY, int g, Wezel* rodzic, bool korzen) { 
    Wezel* nowy = new Wezel;

    if(korzen) {
        //kopiowanie wpisanej przez użytkownika tablicy
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                nowy->T[i][j] = T[i][j];
            }
        }

        //liczenie sumarycznej wartości h(x)
        int odl=0,roz_x=0,roz_y=0;
        pair<int,int> wsp; //współrzędnego poprawnego miejsca dla danego klocka
        int nr;

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                nr = nowy->T[i][j];
                if(nr != 0) {
                    wsp = Wzor_WSP[nr]; //poprawne współrzędne miejsca dla danego numerka

                    roz_x = abs(i - wsp.first); //różnica wierszy pomiedzy aktualnym ustawienie a poprawnym
                    roz_y = abs(j - wsp.second); //różnica kolumn pomiedzy aktualnym ustawienie a poprawnym
                    odl = roz_x + roz_y; //odleglość od poprawnego miejsca [Manhattan distance]

                    nowy->h += odl;
                }
            }
        }
    }

    nowy->rodzic = rodzic; 

    if(rodzic != NULL) {
        //ruch "pustej przestrzeni"
        // (x,y) - wspolrzedne "pustej przestrzeni" przed wykonaniem ruchu
        // (nowyX, nowyY) - wspolrzedne "pustej przestrzeni" po wykonaniu ruchu

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

        //liczenie sumarycznej wartości h(x)
        pair<int,int> wsp; //współrzędnego poprawnego miejsca dla danego klocka

            //odległość klocka, który chce zamienić z "pustą przestrzenią", od poprawnego miejsca PRZED WYKONANIEM RUCHU
            //współrzędne klocka (PRZED WYKONANIEM RUCHU), który chce zamienić z "pustą przestrzenią", to (nowyX, nowyY)!
        int nr_klocka = rodzic->T[nowyX][nowyY];

        wsp = Wzor_WSP[nr_klocka];
        int stara_odl = abs(nowyX - wsp.first) + abs(nowyY - wsp.second);

            //odległość klocka, który chce zamienić z "pustą przestrzenią", od poprawnego miejsca PO WYKONANIU RUCHU
            //współrzędne klocka (PO WYKONANIU RUCHU), który chce zamienić z "pustą przestrzenią", to (x, y)!

        int nowa_odl = abs(x - wsp.first) + abs(y - wsp.second);

            //aktualizowanie zsumowanej wartości "odległości" dla tworzonej tablicy
            //nowa_odl != stara_odl, bo wykonałam ruch, więc albo się odległość zmiejszyła o 1 bądź zwiększyła o 1

        if(nowa_odl > stara_odl) //klocek oddalił się do poprawnego miejsca
            nowy->h = rodzic->h+1;
        else //klocek przybliżył się do poprawnego miejsca
            nowy->h = rodzic->h-1; 
    }

    //liczenie sumarycznej wartości g(x)
    nowy->g = g;

    //wprowadzam wspolrzedne "psutej przestrzeni"
    nowy->x = nowyX;
    nowy->y = nowyY;

    return nowy;
}
