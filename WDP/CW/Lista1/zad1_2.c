#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int n, licznik=0;
    int pot_10; //potega 10
    bool ok=true;
    
    scanf("%d", &n);

    int tn = n;

    //obliczam dlugosc liczby
    while(tn > 0) {
        licznik++;
        tn /= 10;
    }

    int i=licznik, j=1;
    int c1, c2; //analizowane cyfry

    //sprawdzenie czy jest palindromem
    while(i>=1 && j<=5) {
        pot_10 = pow(10,i);
        printf("i: %d POT_10: %d\n", i, pot_10);
        c1 = (n%pot_10) / (pot_10/10);
        printf("C1: %d\n", c1);

        pot_10 = pow(10,j);
        printf("j: %d POT_10: %d\n", j, pot_10);
        c2 = (n%pot_10) / (pot_10/10);
        printf("C2: %d\n", c2);

        if(c1 != c2) {
            ok = false;
            break;
        }

        i--;
        j++;
    }

    if(ok)
        printf("TO JEST PALINDROM\n");
    else
        printf("TO NIE JEST PALINDROM\n");

    return 0;
}
