#include <stdio.h>

int main() {
    double n=0.0;
    double suma=0.0;
    double tmp;

    while(suma < 10) {
        n++;
        suma += 1/n;
    }

    printf("%.0f\n", n);

    return 0;
}
 /*
niezmiennikiem pętli będzie wartość 10 (?)
https://forum.pasja-informatyki.pl/516575/niezmiennik-petli-while
https://pl.wikipedia.org/wiki/Niezmiennik_p%C4%99tli
*/
