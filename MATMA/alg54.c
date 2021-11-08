//WYDAJE MI SIE ZE SA JAKIES BLEDY W DEFINIZJI FUNKCJI PI W ZAD.54

#include <stdio.h>
#include <math.h>
#include <stdbool.h> 

//logarytm naturalny w C -> log(x);

const int MAX = 100001;
bool ZL[MAX]; //liczby zlozone

void sito() {
    int p = sqrt(MAX);

    ZL[0] = true;
    ZL[1] = true;

    for(int i=2; i<=p; i++) {
        if(!ZL[i]) {
            for(int j=i*i; j<=MAX; j+=i)
                ZL[j] = true;
        }
    }
}

int main() {
    int x, a;
    int licznik;

    int n = 2;
    while(n <= 100000) {
        licznik = 0;
        if(!ZL[n]) {
            for(int i=2; i<=n;)
        }
    }
}
