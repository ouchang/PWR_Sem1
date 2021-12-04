/*
Problem układanki zawartej w tablicy 3x3 
W tablicy 3x3 mamy 8 ponumerowanych (od 1 do 8) klocków, które nie są ułożone w poprawnym porządku.
Dziewiąte miejsce pozostanie puste.
Zakładamy, że ruchem w tej układance jest ruch "pustej przestrzeni" w góre, dół, lewo bądź prawo.
Naszym zadaniem jest przedstawienie kroków, po których można ułożyć poprawnie klocki w tablicy 3x3

Licznik konfiguracji - zlicza ile tablic przeanalizował program w czasie rozwiązywania problemu

Posługuję się funkcją liczą koszt f(x) = g(x) + h(x) + 2*l(x), gdzie
    g(x) - liczba dotychczasowych wykonanych ruchów
    h(x) - odległość klocka od jego prawidłowego położenia
    l(x) - liczba konfliktów typu: linear conflict(*)

(*) Linear conflict - 2 klocki: a,b są w liniowym konflikcie jeśli oba klocki są w tym samym rzędzie
bądź kolumnie, również ich docelowe miejsca są w tym samym rzędzie bądź kolumnie oraz docelowe miejsce
jest zablokowane przez inny klocek w tym rzędzie/kolumnie

UWAGA: "Pustą przestrzeń" w tablicy oznaczam jako 0!
UWAGA: Za "uporządkowaną tablice"/docelową tablicę przyjmuje się również tablice, w której liczba inwersji 
        wynosi 1 (gdy nie ma takiego założenia -> program działa tak długo, że zostaje skillowany / nie da się
        doprowadzić do ściśle uporządkowanej tablicy np. przypadek przy zamianie jedynie 7 i 8)
*/
#include "func.h"
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

//uporzadkowana tablica 3x3
int Wzor3[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,0}
};

pair<int,int> Wzor_WSP3[9]; //współrzędne poprawnego miejsca dla każdego numeru klocka
int licznik_konf3 = 0; //licznik przeanalizowanych konfiguracji
int licznik_krok3 = 0; //liczba krokow, jaką należy wykonać by uporządkować tablice 

struct Wezel3 {
    Wezel3 *rodzic;
    int T[4][4]; //tablica 3x3
    int x,y; //wspolrzedne w tablicy, gdzie jest "pusta przestrzeń"
    int h=0; //zgodnie z funkcją kosztu: h(x) (sumarycznie dla całej tablicy)
    int g=0; //zgodnie z funkcją kosztu: g(x) (sumarycznie dla całej tablicy)
    int l=0;  //zgodnie z funkcją kosztu: l(x) (sumarycznie dla całej tablicy)
};


Wezel3* nowyWezel3(int T[4][4], int x, int y, int nowyX, int nowyY, int g, Wezel3* rodzic, bool korzen) { 
    Wezel3* nowy = new Wezel3;

    if(korzen) {
       // cout << "ZACZYNAM TWORZENIE KORZENIA" << endl;
        //kopiowanie wpisanej przez użytkownika tablicy
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                nowy->T[i][j] = T[i][j];
            }
        }
    }

    //cout << "ZAPISALAM RODZICA" << endl;
    nowy->rodzic = rodzic; 

    if(rodzic != NULL) {
        //ruch "pustej przestrzeni"
        // (x,y) - współrzędne "pustej przestrzeni" przed wykonaniem ruchu
        // (nowyX, nowyY) - współrzędne "pustej przestrzeni" po wykonaniu ruchu

        //cout << "RUCH PUSTEJ PRZESZTRZNI W TABLICY" << endl;
        nowy->T[x][y] = rodzic->T[nowyX][nowyY]; //ponumerowany klocek idzie na stare miejsce "pustej przestrzeni"
        nowy->T[nowyX][nowyY] = rodzic->T[x][y]; //"pusta przestrzeń" wykonuje ruch

        //cout << "KOPIOWANIE POZOSTALYCH KLOCKOW" << endl;
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
    //cout << "POLICZYLAM G: " << nowy->g << endl;

    //liczenie sumarycznej wartości h(x)
    int odl=0,roz_x=0,roz_y=0;
    pair<int,int> wsp;
    int nr;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            nr = nowy->T[i][j];
            if(nr != 0) {
                wsp = Wzor_WSP3[nr]; //poprawne współrzędne miejsca dla danego numerka

                roz_x = abs(i - wsp.first); //różnica wierszy pomiedzy aktualnym ustawienie a poprawnym
                roz_y = abs(j - wsp.second); //różnica kolumn pomiedzy aktualnym ustawienie a poprawnym
                odl = roz_x + roz_y; //odleglość od poprawnego miejsca [Manhattan distance]

                nowy->h += odl;
            }
        }
    } 

    //cout << "POLICZYLAM H: " << nowy->h << endl;
    //liczenie sumarycznej wartości l(x)

        //konflikt w rzędzie
    int r_konflikt = 0; //liczba konfliktów w rzędach
    pair<int, int> akt_cel; //współrzędne docelowego miejsca aktualnie analizowanego klocka
    pair<int,int> t_cel; //współrzędne miejsca docelowego "potencjalnego klocka",
                        // z który aktualny może mieć konflikt
                        
    for(int i=0; i<3; i++) { //pętla po rzędach
        for(int j=0; j<3; j++) { //pętla po kolumnach
            akt_cel = Wzor_WSP3[T[i][j]];
            if(T[i][j] == 0) //pomiń "pustą przestrzeń"
                continue;
            if(akt_cel.first != i) //aktualny klocek nie jest w tym samym rzędze co jego docelowe miejsce
                continue;
            
            for(int k=j+1; k<3; k++) { 
                //wystarczy sprawdzanie jedynie w jedną str (tutaj: w prawo),
                //bo konflikt liniowy jest symetryczny -> nie trzeba sprawdzać drugiej str (tutaj: lewej)

                t_cel = Wzor_WSP3[T[i][k]];
                if(t_cel.first == akt_cel.first && t_cel.second < akt_cel.second) //
                    r_konflikt++; //znaleźliśmy konflikt liniowy pomiędzy T[i][j] a T[i][k];
            }
        }
    }


        //konflikt w kolumnie
    int k_konflikt = 0; //liczba konfliktów w kolumnach
                        
    for(int j=0; j<3; j++) { //pętla po kolumnach
        for(int i=0; i<3; i++) { //pętla po rzędach
            akt_cel = Wzor_WSP3[T[i][j]];
            if(T[i][j] == 0) //pomiń "pustą przestrzeń"
                continue;
            if(akt_cel.second != j) //aktualny klocek nie jest w tej samej kolumnie co jego docelowe miejsce
                continue;
            
            for(int k=i+1; k<3; k++) { 
                //wystarczy sprawdzanie jedynie w jedną str (tutaj: w prawo),
                //bo konflikt liniowy jest symetryczny -> nie trzeba sprawdzać drugiej str (tutaj: lewej)

                t_cel = Wzor_WSP3[T[i][k]];
                if(t_cel.second == akt_cel.second && t_cel.first < akt_cel.first) //
                    k_konflikt++; //znaleźliśmy konflikt liniowy pomiędzy T[i][j] a T[i][k];
            }
        }
    }

        //zsumuje konflikty w tablicy
    nowy->l = r_konflikt + k_konflikt;
    //cout << "POLICZYLAM L: " << nowy->l << endl;

    //wprowadzam wspolrzedne "psutej przestrzeni"
    nowy->x = nowyX;
    nowy->y = nowyY;
    //cout << "NOWE WSPOLRZEDNE PUSTEJ PRZESTRZENI" << endl;

    return nowy;
}

int r_x3[4] = {1,0,-1,0}; //x - numer wiersza 
int r_y3[4] =  {0,-1,0,1}; //y - numer kolumny

//(r_x, r_y) -> ruch w tablicy
//(1,0) -> w prawo, (0,-1) -> w dół, (-1,0) -> w lewo, (0,1) -> w górę

bool CzyRuchMozliwy3(int x, int y, int ruch_x, int ruch_y) {
    int nowyX = x + ruch_x; 
    int nowyY = y + ruch_y; 

    if(nowyX >= 3 || nowyX < 0 || nowyY >= 3 || nowyY < 0) //wyjście poza tablice
        return false;
    return true;
}

struct cmp3 { //porównywanie dla kolejki priorytetowej
    bool operator() (const Wezel3* lhs, const Wezel3* rhs) {
        //uporządkowanie rosnące
        //porównanie funkcji kosztu (biore o mniejszym koszcie)
        return ((lhs->g + lhs->h + 2*(lhs->l)) > (rhs->g + rhs->h + 2*(rhs->l))); 
    }
};

void Drukowanie3(Wezel3* wezel) {
    if(wezel == NULL)
        return;
    
    Drukowanie3(wezel->rodzic);

    licznik_krok3++;
    //drukowanie
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", wezel->T[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int ZliczInwersje(Wezel3* wezel) {
    int l_inwersji=0;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(wezel->T[i][j] == 0)
                continue;
            
            //szukanie inwersji
            for(int p=i; p<3; p++) {
                for(int q=j+1; q<3; q++) {
                    if(wezel->T[p][q] == 0)
                        continue;
                    else if(wezel->T[i][j] > wezel->T[p][q]) {
                        l_inwersji++;
                    }
                }
            }

        }
    }

    return l_inwersji;
}

void Rozwiazanie3(int T[4][4], int x, int y) {
    priority_queue <Wezel3*, vector<Wezel3*>, cmp3> Q;

    //cout << "TWORZE KORZEN!" << endl;

    Wezel3* korzen = nowyWezel3(T, x, y, x, y, 0, NULL, true);

    Q.push(korzen);
    //cout << "DODALAM KORZEN DO KOLEJKI" << endl;
    while(!Q.empty()) {
        Wezel3* akt = Q.top(); //aktualnie analizowana tablica 3x3
        Q.pop();

        licznik_konf3++;
        //cout << "WCZYTALAM WEZEL" << endl;
        //jeżeli udało nam się otrzymać wymagane uporządkowanie

        //if(akt->h == 0 || (akt->h == 2 && T[2][0] == 8 && T[2][1] == 7)) 
        int l_inwersji = ZliczInwersje(akt);
        if(akt->h == 0 || l_inwersji == 1) { 
            //wszystkie klocki są na swoim miejscu LUB zaszedł sprzególny przypadek (8puzzle-test)
            
            //drukowanie
            //cout << "MAMY ULOZONE" << endl;
            Drukowanie3(akt);
            return;
        }

        //wykonywanie ruchu "pustej przestrzeni"
        for(int i=0; i<4; i++) { 
            //cout << "SPAWDZAM RUCH" << endl;
            if(CzyRuchMozliwy3(akt->x, akt->y, r_x3[i], r_y3[i])) {
                //tworze nową tablicę z wykonanym ruchem "pustej przestrzeni"
                Wezel3* dziecko = nowyWezel3(T, akt->x, akt->y, akt->x + r_x3[i], akt->y + r_y3[i], akt->g + 1, akt, false);
                Q.push(dziecko); 
                //cout << "DODAJE DZIECKO DO KOLEJKI" << endl;
            }
        }
    }
}

void rozw3() {
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
            Wzor_WSP3[Wzor3[i][j]] = wsp;
        }
    }

    //wylosowanie tablicy
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

    Rozwiazanie3(T, x, y);
    printf("Liczba przeanalizowanych konfiguracji: %d\nLiczba wykonanych krokow: %d\n", licznik_konf3, licznik_krok3);
}
