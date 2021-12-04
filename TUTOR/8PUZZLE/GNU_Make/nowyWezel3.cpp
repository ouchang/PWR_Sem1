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

struct Wezel* nowyWezel3(int T[4][4], int x, int y, int nowyX, int nowyY, int g, Wezel* rodzic, bool korzen) { 
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

    //liczenie sumarycznej wartości g(x)
    nowy->g = g; 

    //liczenie sumarycznej wartości h(x)
    int odl=0,roz_x=0,roz_y=0;
    pair<int,int> wsp;
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

    //liczenie sumarycznej wartości l(x)

        //konflikt w rzędzie
    int r_konflikt = 0; //liczba konfliktów w rzędach
    pair<int, int> akt_cel; //współrzędne docelowego miejsca aktualnie analizowanego klocka
    pair<int,int> t_cel; //współrzędne miejsca docelowego "potencjalnego klocka",
                        // z który aktualny może mieć konflikt
                        
    for(int i=0; i<3; i++) { //pętla po rzędach
        for(int j=0; j<3; j++) { //pętla po kolumnach
            akt_cel = Wzor_WSP[T[i][j]];
            if(T[i][j] == 0) //pomiń "pustą przestrzeń"
                continue;
            if(akt_cel.first != i) //aktualny klocek nie jest w tym samym rzędze co jego docelowe miejsce
                continue;
            
            for(int k=j+1; k<3; k++) { 
                //wystarczy sprawdzanie jedynie w jedną str (tutaj: w prawo),
                //bo konflikt liniowy jest symetryczny -> nie trzeba sprawdzać drugiej str (tutaj: lewej)

                t_cel = Wzor_WSP[T[i][k]];
                if(t_cel.first == akt_cel.first && t_cel.second < akt_cel.second) //
                    r_konflikt++; //znaleźliśmy konflikt liniowy pomiędzy T[i][j] a T[i][k];
            }
        }
    }


        //konflikt w kolumnie
    int k_konflikt = 0; //liczba konfliktów w kolumnach
                        
    for(int j=0; j<3; j++) { //pętla po kolumnach
        for(int i=0; i<3; i++) { //pętla po rzędach
            akt_cel = Wzor_WSP[T[i][j]];
            if(T[i][j] == 0) //pomiń "pustą przestrzeń"
                continue;
            if(akt_cel.second != j) //aktualny klocek nie jest w tej samej kolumnie co jego docelowe miejsce
                continue;
            
            for(int k=i+1; k<3; k++) { 
                //wystarczy sprawdzanie jedynie w jedną str (tutaj: w prawo),
                //bo konflikt liniowy jest symetryczny -> nie trzeba sprawdzać drugiej str (tutaj: lewej)

                t_cel = Wzor_WSP[T[i][k]];
                if(t_cel.second == akt_cel.second && t_cel.first < akt_cel.first) //
                    k_konflikt++; //znaleźliśmy konflikt liniowy pomiędzy T[i][j] a T[i][k];
            }
        }
    }

        //zsumuje konflikty w tablicy
    nowy->l = r_konflikt + k_konflikt;

    //wprowadzam wspolrzedne "psutej przestrzeni"
    nowy->x = nowyX;
    nowy->y = nowyY;

    return nowy;
}
