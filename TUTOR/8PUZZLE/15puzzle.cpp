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
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <random>
#include <cmath>
using namespace std;

//uporzadkowana tablica 3x3
int Wzor[4][4] = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,0}
};

pair<int,int> Wzor_WSP[15]; //współrzędne poprawnego miejsca dla każdego numeru klocka
int licznik_konf = 0; //licznik przeanalizowanych konfiguracji
int licznik_krok = 0; //liczba krokow, jaką należy wykonać by uporządkować tablice 

struct Wezel {
    Wezel *rodzic;
    int T[5][5]; //tablica 3x3
    int x,y; //wspolrzedne w tablicy, gdzie jest "pusta przestrzeń"
    int h=0; //zgodnie z funkcją kosztu: h(x) (sumarycznie dla całej tablicy)
    int g=0; //zgodnie z funkcją kosztu: g(x) (sumarycznie dla całej tablicy)
    int l=0;  //zgodnie z funkcją kosztu: l(x) (sumarycznie dla całej tablicy)
};


Wezel* nowyWezel(int T[5][5], int x, int y, int nowyX, int nowyY, int g, Wezel* rodzic, bool korzen) { 
    Wezel* nowy = new Wezel;

    if(korzen) {
       // cout << "ZACZYNAM TWORZENIE KORZENIA" << endl;
        //kopiowanie wpisanej przez użytkownika tablicy
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
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
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
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

    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
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
                        
    for(int i=0; i<4; i++) { //pętla po rzędach
        for(int j=0; j<4; j++) { //pętla po kolumnach
            akt_cel = Wzor_WSP[T[i][j]];
            if(T[i][j] == 0) //pomiń "pustą przestrzeń"
                continue;
            if(akt_cel.first != i) //aktualny klocek nie jest w tym samym rzędze co jego docelowe miejsce
                continue;
            
            for(int k=j+1; k<4; k++) { 
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
                        
    for(int j=0; j<4; j++) { //pętla po kolumnach
        for(int i=0; i<4; i++) { //pętla po rzędach
            akt_cel = Wzor_WSP[T[i][j]];
            if(T[i][j] == 0) //pomiń "pustą przestrzeń"
                continue;
            if(akt_cel.second != j) //aktualny klocek nie jest w tej samej kolumnie co jego docelowe miejsce
                continue;
            
            for(int k=i+1; k<4; k++) { 
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

int r_x[4] = {1,0,-1,0}; //x - numer wiersza 
int r_y[4] =  {0,-1,0,1}; //y - numer kolumny

//(r_x, r_y) -> ruch w tablicy
//(1,0) -> w prawo, (0,-1) -> w dół, (-1,0) -> w lewo, (0,1) -> w górę

bool CzyRuchMozliwy(int x, int y, int ruch_x, int ruch_y) {
    int nowyX = x + ruch_x; 
    int nowyY = y + ruch_y; 

    if(nowyX >= 4 || nowyX < 0 || nowyY >= 4 || nowyY < 0) //wyjście poza tablice
        return false;
    return true;
}

struct cmp { //porównywanie dla kolejki priorytetowej
    bool operator() (const Wezel* lhs, const Wezel* rhs) {
        //uporządkowanie rosnące
        //porównanie funkcji kosztu (biore o mniejszym koszcie)
        return ((lhs->g + lhs->h + 2*(lhs->l)) > (rhs->g + rhs->h + 2*(rhs->l))); 
    }
};

void Drukowanie(Wezel* wezel) {
    if(wezel == NULL)
        return;
    
    Drukowanie(wezel->rodzic);

    licznik_krok++;
    //drukowanie
    /*
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", wezel->T[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */
}

int ZliczInwersje(Wezel* wezel) {
    int l_inwersji=0;

    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(wezel->T[i][j] == 0)
                continue;
            
            //szukanie inwersji
            for(int p=i; p<4; p++) {
                for(int q=j+1; q<4; q++) {
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

void Rozwiazanie(int T[5][5], int x, int y) {
    priority_queue <Wezel*, vector<Wezel*>, cmp> Q;

    Wezel* korzen = nowyWezel(T, x, y, x, y, 0, NULL, true);

    Q.push(korzen);

    while(!Q.empty()) {
        Wezel* akt = Q.top(); //aktualnie analizowana tablica 3x3
        Q.pop();

        licznik_konf++;
        //jeżeli udało nam się otrzymać wymagane uporządkowanie

        //if(akt->h == 0 || (akt->h == 2 && T[2][0] == 8 && T[2][1] == 7)) 
        int l_inwersji = ZliczInwersje(akt);
        if(akt->h == 0 || l_inwersji == 1) { //l_inwersji%2 == 1
            //wszystkie klocki są na swoim miejscu LUB zaszedł sprzególny przypadek (8puzzle-test)
            
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
    int T[5][5];
    int x,y; 
    
    //wprowadzenie do tablicy Wzor_WSP poprawnych współrzędnych klocków
    int nr=1;
    pair<int,int> wsp; 

    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            wsp = make_pair(i,j);
            Wzor_WSP[Wzor[i][j]] = wsp;
        }
    }

    //tworzenie randomowej tablicy 3x3
    /*
    vector<int> V;
    int idx=0;

    for(int i=0; i<9; i++) 
        V.push_back(i);

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            //losowanie liczby
            srand(time(NULL));
            idx = rand() % (V.size()); //wylosowana liczba jest w zakresie 0-8
            
            //wpisywanie wylosowanej liczby do  tabliy 3x3
            T[i][j] = V[idx];

            if(T[i][j] == 0) {
                x = i;
                y = j;
            }

            //usuwanie wylosowanej liczby z vectora
            swap(V[idx], V[V.size()-1]);
            V.pop_back();
        }
    }
    */

    //tworzenie randomowej tablicy 4x4
    int V[9];
    int idx=0;

    mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

    for(int i=0; i<15; i++) 
        V[i] = i;
    
    for(int i=0; i<15; i++) {
        for(int j=0; j<i; j++) {
            srand((unsigned int) time(NULL));
            // "rzucam monetą" czy zamieniać ze sobą miejscami 2 liczby
            if(rng()%2 == 0) {
                swap(V[i], V[j]);
            }
        }
    }

    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            T[i][j] = V[idx];
            idx++;

            if(T[i][j] == 0) {
                x = i;
                y = j;
            }
        }
    }

    //rozwiązanie
    Rozwiazanie(T, x, y);
    printf("Liczba przeanalizowanych konfiguracji: %d\nLiczba wykonanych krokow: %d\n", licznik_konf, licznik_krok);
}
