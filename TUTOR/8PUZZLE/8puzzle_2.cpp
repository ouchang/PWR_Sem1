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

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

//uporzadkowana tablica 3x3
int Wzor[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,0}
};

pair<int,int> Wzor_WSP[9]; //współrzędne poprawnego miejsca dla każdego numeru klocka

struct Wezel {
    Wezel *rodzic;
    int T[4][4]; //tablica 3x3
    int x,y; //wspolrzedne w tablicy, gdzie jest "pusta przestrzeń"
    int h=0; //zgodnie z funkcją kosztu: h(x) (sumarycznie dla całej tablicy)
    int g=0; //zgodnie z funkcją kosztu: g(x) (sumarycznie dla całej tablicy)
};


Wezel* nowyWezel(int T[4][4], int x, int y, int nowyX, int nowyY, int g, Wezel* rodzic, bool korzen) { 
    Wezel* nowy = new Wezel;

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

    //wprowadzam wspolrzedne "psutej przestrzeni"
    nowy->x = nowyX;
    nowy->y = nowyY;

    return nowy;
}

int r_x[4] = {1,0,-1,0}; //x - numer wiersza 
int r_y[4] =  {0,-1,0,1}; //y - numer kolumny

//(r_x, r_y) -> ruch w tablicy
//(1,0) -> w prawo, (0,-1) -> w dół, (-1,0) -> w lewo, (0,1) -> w górę

bool CzyRuchMozliwy(int x, int y, int ruch_x, int ruch_y) {
    int nowyX = x + ruch_x; 
    int nowyY = y + ruch_y; 

    if(nowyX >= 3 || nowyX < 0 || nowyY >= 3 || nowyY < 0) //wyjście poza tablice
        return false;
    return true;
}

struct cmp { //porównywanie dla kolejki priorytetowej
    bool operator() (const Wezel* lhs, const Wezel* rhs) {
        //uporządkowanie rosnące
        return ((lhs->g + lhs->h) > (rhs->g + rhs->h)); //porównanie funkcji kosztu (biore o mniejszym koszcie)
    }
};

void Drukowanie(Wezel* wezel) {
    if(wezel == NULL)
        return;
    
    Drukowanie(wezel->rodzic);

    //drukowanie
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", wezel->T[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Rozwiazanie(int T[4][4], int x, int y) {
    priority_queue <Wezel*, vector<Wezel*>, cmp> Q;

    Wezel* korzen = nowyWezel(T, x, y, x, y, 0, NULL, true);

    Q.push(korzen);

    while(!Q.empty()) {
        Wezel* akt = Q.top(); //aktualnie analizowana tablica 3x3
        Q.pop();

        //jeżeli udało nam się otrzymać wymagane uporządkowanie
        if(akt->h == 0) { //wszystkie klocki są na swoim miejscu
            //drukowanie
            Drukowanie(akt);
            return;
        }

        //wykonywanie ruchu "pustej przestrzeni"
        for(int i=0; i<4; i++) { 
            if(CzyRuchMozliwy(akt->x, akt->y, r_x[i], r_y[i])) {
                //tworze nową tablicę z wykonanym ruchem "pustej przestrzeni"
                Wezel* dziecko = nowyWezel(T, akt->x, akt->y, akt->x + r_x[i], akt->y + r_y[i], akt->g + 1, akt, false);
                Q.push(dziecko); 
            }
        }
    }
}

int main() {
    int T[4][4];
    int x,y; 
    
    //wprowadzenie do tablicy Wzor_WSP poprawnych współrzędnych klocków
    int nr=1;
    pair<int,int> wsp; 

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            wsp = make_pair(i,j);
            Wzor_WSP[Wzor[i][j]] = wsp;
        }
    }

    //wczytywanie tablicy 3x3
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            scanf("%d", &T[i][j]);

            if(T[i][j] == 0) {
                x = i;
                y = j;
            }
        }
    }

    Rozwiazanie(T, x, y);
}
