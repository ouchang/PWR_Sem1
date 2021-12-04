/*
Problem układanki zawartej w tablicy 3x3 
W tablicy 3x3 mamy 8 ponumerowanych (od 1 do 8) klocków, które nie są ułożone w poprawnym porządku.
Dziewiąte miejsce pozostanie puste.
Zakładamy, że ruchem w tej układance jest ruch "pustej przestrzeni" w góre, dół, lewo bądź prawo.
Naszym zadaniem jest przedstawienie kroków, po których można ułożyć poprawnie klocki w tablicy 3x3


Posługuję się funkcją liczą koszt f(x) = g(x) + h(x), gdzie
    g(x) - liczba dotychczasowych wykonanych ruchów
    h(x) - odległość klocka od jego prawidłowego położenia

UWAGA: "Pustą przestrzeń" w tablicy oznaczam jako 0!
*/
#include "func.h"
#include <iostream>
#include <stdio.h>
#include <queue>
#include <array>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

//uporzadkowana tablica 3x3
int Wzor2[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,0}
};

pair<int,int> Wzor_WSP2[9]; //współrzędne poprawnego miejsca dla każdego nr klocka
int licznik_konf2 = 0; //licznik przeanalizowanych konfiguracji
int licznik_krok2 = 0; //liczba krokow, jaką należy wykonać by uporządkować tablice 

struct Wezel2 {
    Wezel2 *rodzic;
    int T[4][4]; //tablica 3x3
    int x,y; //wspolrzedne w tablicy, gdzie jest "pusta przestrzeń"
    int h=0; //zgodnie z funkcją kosztu: h(x) (sumarycznie dla całej tablicy)
    int g=0; //zgodnie z funkcją kosztu: g(x) (sumarycznie dla całej tablicy)
};


Wezel2* nowyWezel2(int T[4][4], int x, int y, int nowyX, int nowyY, int g, Wezel2* rodzic, bool korzen) { 
    Wezel2* nowy = new Wezel2;

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
                    wsp = Wzor_WSP2[nr]; //poprawne współrzędne miejsca dla danego numerka

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

        wsp = Wzor_WSP2[nr_klocka];
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

int r_x2[4] = {1,0,-1,0}; //ruch w rzedzie
int r_y2[4] =  {0,-1,0,1}; //ruch w kolumnie

//(r_rzad, r_kol)
//(1,0) -> w prawo, (0,-1) -> w dół, (-1,0) -> w lewo, (0,1) -> w górę

bool CzyRuchMozliwy2(int x, int y, int ruch_x, int ruch_y) {
    int nowyX = x + ruch_x; 
    int nowyY = y + ruch_y; 

    if(nowyX >= 3 || nowyX < 0 || nowyY >= 3 || nowyY < 0) //wyjscie poza tablice
        return false;
    return true;
}

struct cmp2 { //porównywanie dla kolejki priorytetowej
    bool operator() (const Wezel2* lhs, const Wezel2* rhs) {
        //uporządkowanie rosnące
        return ((lhs->g + lhs->h) > (rhs->g + rhs->h)); //porównanie funkcji kosztu (biore o mniejszym koszcie)
    }
};

void Drukowanie2(Wezel2* wezel) {
    if(wezel == NULL)
        return;
    
    Drukowanie2(wezel->rodzic);

    licznik_krok2++;

    //drukowanie
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", wezel->T[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Rozwiazanie2(int T[4][4], int x, int y) {
    priority_queue <Wezel2*, vector<Wezel2*>, cmp2> Q;

    Wezel2* korzen = nowyWezel2(T, x, y, x, y, 0, NULL, true);

    Q.push(korzen); 

    while(!Q.empty()) {
        Wezel2* akt = Q.top(); //aktualnie analizowana tablica 3x3 
        Q.pop();

        licznik_konf2++;

        //jezeli udalo nam sie otrzymac wymagane uporzadkoanie
        if(akt->h == 0) {
            //drukowanie
            Drukowanie2(akt);
            return;
        }

        //wykonywanie ruchu "pustej przestrzeni"
        for(int i=0; i<4; i++) {
            if(CzyRuchMozliwy2(akt->x, akt->y, r_x2[i], r_y2[i])) {
                //tworze nową tablicę z wykonanym ruchem "pustej przestrzeni"
                Wezel2* dziecko = nowyWezel2(T, akt->x, akt->y, akt->x + r_x2[i], akt->y + r_y2[i], akt->g + 1, akt, false);
                Q.push(dziecko); 
            }
        }
    }
}

void rozw2() {
    int T[4][4];
    int x,y; 
    int TAB[9];
    int* A; //wylosowana tablica
    int idx=0;
    
    //wprowadzenie do tablicy Wzor_WSP poprawnych współrzędnych klocków
    int nr=1;
    pair<int,int> wsp; 
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            wsp = make_pair(i,j);
            Wzor_WSP2[Wzor2[i][j]] = wsp;
        }
    }
    //wylosowanie tablicy
    A = wylosowanie(TAB);

    //wczytywanie tablicy 3x3
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            //scanf("%d", &T[i][j]);
            T[i][j] =A[idx];
            idx++;

            if(T[i][j] == 0) {
                x = i;
                y = j;
            }
        }
    }

    Rozwiazanie2(T, x, y);
    printf("Liczba przeanalizowanych konfiguracji: %d\nLiczba wykonanych krokow: %d\n", licznik_konf2, licznik_krok2);
}
