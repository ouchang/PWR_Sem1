//Aleksandra Zaremba

#include <stdio.h>

int S[1001]; //tablica z sumami dzielnikow danych liczb

int main() {
    int suma=1; //suma dzielnikow danej liczby
    int k; //aktualnie analizowany dzielnik danej liczby

    //znajdowanie liczb dokonalych
    printf("Liczby doskonale:\n");

    for(int i=2; i<1000; i++) {
        suma = 1;

        //znajdwanie dzielnikow i ich sumowanie
        for(k=2; k*k<=i; k++) {
            if(i%k == 0) {
                suma += k;
                suma += (i/k);
            }
        }

        //gdyby pierwiastek danej liczby i byl l. calkowita
        if(k*k == i)
            suma -= k; //wowczas policzylismy o jeden dzielnik za duzo

        //zapisanie sumy dzielnikow w tablicy
        S[i] = suma;

        //czy doskonala
        if(i == S[i])
            printf("%d\n", i);
    }

    //czy zaprzyjaznione
    printf("Liczby zaprzyjaznione:\n");

    int m;
    for(int n=2; n<1000; n++) {
        m = S[n];
        if(m < 1000)
            if((n == S[m]) && (n < m))
                printf("(%d;%d)\n", n, m);
    }
    
    return 0;
}
