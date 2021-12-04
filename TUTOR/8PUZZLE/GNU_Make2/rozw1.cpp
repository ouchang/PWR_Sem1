/*
Problem układanki zawartej w tablicy 3x3 
W tablicy 3x3 mamy 8 ponumerowanych (od 1 do 8) klocków, które nie są ułożone w poprawnym porządku.
Dziewiąte miejsce pozostanie puste.
Zakładamy, że ruchem w tej układance jest ruch "pustej przestrzeni" w góre, dół, lewo bądź prawo.
Naszym zadaniem jest przedstawienie kroków, po których można ułożyć poprawnie klocki w tablicy 3x3


Posługuję się funkcją liczącą koszt f(x) = g(x) + h(x), gdzie
    g(x) - liczba dotychczasowych wykonanych ruchów
    h(x) - ile jeszcze klocków jest nie na swoim miejscu

UWAGA: "Pustą przestrzeń" w tablicy oznaczam jako 0!
*/
#include "func.h"
#include <iostream>
#include <stdio.h>
#include <queue>
#include <array>
#include <vector>
using namespace std;

//uporzadkowana tablica 3x3
int Wzor1[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,0}
};

int licznik_konf1 = 0; //licznik przeanalizowanych konfiguracji
int licznik_krok1 = 0; //liczba krokow, jaką należy wykonać by uporządkować tablice 

struct Wezel1 {
    Wezel1 *rodzic;
    int T[4][4]; //tablica 3x3
    int x,y; //wspolrzedne w tablicy, gdzie jest "pusta przestrzeń"
    int h=0; //zgodnie z funkcją kosztu: h(x) (sumarycznie dla całej tablicy)
    int g=0; //zgodnie z funkcją kosztu: g(x) (sumarycznie dla całej tablicy)
};


Wezel1* nowyWezel1(int T[4][4], int x, int y, int nowyX, int nowyY, int g, Wezel1* rodzic, bool korzen) {
    Wezel1* nowy = new Wezel1;

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
            if((nowy->T[i][j] != Wzor1[i][j]) && nowy->T[i][j] != 0) //nie wliczaj pustej przestrzeni
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

int r_x1[4] = {1,0,-1,0}; // x - nr wiersza
int r_y1[4] =  {0,-1,0,1}; // y - nr kolumny

//(r_x, r_y) -> ruch w tablicy
//(1,0) -> w prawo, (0,-1) -> w dół, (-1,0) -> w lewo, (0,1) -> w górę

bool CzyRuchMozliwy1(int x, int y, int ruch_x, int ruch_y) {
    int nowyX = x + ruch_x; 
    int nowyY = y + ruch_y; 

    if(nowyX >= 3 || nowyX < 0 || nowyY >= 3 || nowyY < 0) //wyjście poza tablice
        return false;
    return true;
}

struct cmp1 { //porównywanie dla kolejki priorytetowej
    bool operator() (const Wezel1* lhs, const Wezel1* rhs) {
        //uporządkowanie rosnące
        return ((lhs->g + lhs->h) > (rhs->g + rhs->h)); //porównanie funkcji kosztu (biore o mniejszym koszcie)
    }
};

void Drukowanie1(Wezel1* wezel) {
    if(wezel == NULL)
        return;
    
    Drukowanie1(wezel->rodzic);

    licznik_krok1++;

    //drukowanie
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", wezel->T[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Rozwiazanie1(int T[4][4], int x, int y) {
    priority_queue <Wezel1*, vector<Wezel1*>, cmp1> Q;

    Wezel1* korzen = nowyWezel1(T, x, y, x, y, 0, NULL, true);

    Q.push(korzen);

    while(!Q.empty()) {
        Wezel1* akt = Q.top(); //aktualnie analizowana tablica 3x3
        Q.pop();

        licznik_konf1++;

        //jezeli udało nam się otrzymać wymagane uporządkowanie
        if(akt->h == 0) { //liczba klocków nie na swoim miejscu = 0
            //drukowanie
            Drukowanie1(akt);
            return;
        }

        //wykonywanie ruchu "pustej przestrzeni"
        for(int i=0; i<4; i++) {
            if(CzyRuchMozliwy1(akt->x, akt->y, r_x1[i], r_y1[i])) {
                //tworze nową tablicę z wykonanym ruchem "pustej przestrzeni"
                Wezel1* dziecko = nowyWezel1(T, akt->x, akt->y, akt->x + r_x1[i], akt->y + r_y1[i], akt->g + 1, akt, false);
                Q.push(dziecko);
            }
        }
    }
}

void rozw1() {
    int T[4][4];
    int x,y; 
    int TAB[9];
    int* A; //wylosowana tablica
    int idx=0;

    //losowanie tablicy
    A = wylosowanie(TAB);

    //wczytywanie tablicy 3x3
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            //scanf("%d", &T[i][j]);
            T[i][j] = A[idx];
            idx++;

            if(T[i][j] == 0) {
                x = i;
                y = j;
            }
        }
    }
    
    Rozwiazanie1(T, x, y);
    printf("Liczba przeanalizowanych konfiguracji: %d\nLiczba wykonanych krokow: %d\n", licznik_konf1, licznik_krok1);
}
