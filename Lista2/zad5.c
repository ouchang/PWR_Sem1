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
    int nwd;
    double licznik=0.0; //licznik par wzglednie pierwszych
    double ulam=0.0; //ulam = r(n)/(n^2)

    for(int n=1; n<=1000; n++) {
        //szukam par (n,i), które są wzglednie pierwsze
        for(int i=1; i<=n; i++) {
            nwd = NWD(n,i);
            if(nwd == 1)
                licznik++;
        }

        ulam = licznik / (n*n);

        printf("%d;%.2f\n", n, ulam);
    }

    return 0;
}

