//Aleksandra Zaremba

#include <stdio.h>

int NWD(int a, int b) {
    int tmp;

    while(b > 0) {
        tmp = a%b;
        a = b;
        b = tmp;
    }

    return a;
}

int main() {
    double licznik=0.0; //licznik par wzglednie pierwszych
    double nowe_pary=0.0;
    double ulam=0.0; //ulam = r(n)/(n^2)

    for(int n=1; n<=1000; n++) {
        for(int i=1; i<=n; i++) {
            if(NWD(n,i) == 1) {
                if(n == i) {
                    nowe_pary += 1;
                } else {
                    nowe_pary += 2; //doliczam parę i jej odwrotnosc np. (2,3) i (3,2)
                }
            }
        }

        licznik += nowe_pary;
        nowe_pary = 0;

        ulam = licznik / ((double) (n*n));
        printf("%d;%lf\n", n, ulam);
    }

    return 0;
}

