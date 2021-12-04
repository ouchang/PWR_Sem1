using namespace std;

struct Wezel {
    struct Wezel *rodzic;
    int T[4][4]; //tablica 3x3
    int x,y; //wspolrzedne w tablicy, gdzie jest "pusta przestrzeń"
    int h=0; //zgodnie z funkcją kosztu: h(x) (sumarycznie dla całej tablicy)
    int g=0; //zgodnie z funkcją kosztu: g(x) (sumarycznie dla całej tablicy)
    int l=0;  //zgodnie z funkcją kosztu: l(x) (sumarycznie dla całej tablicy)
};
