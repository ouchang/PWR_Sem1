#include "funs3.h"

int phi(long int n) {
    int licznik = 0; //zliczam ile jest liczb z zakresu 1 do n, które są względnie pierwsze
    long int nwd;

    for(long int i=1; i<=n; i++) {
        nwd = gcd(i, n);
        
        if(nwd == 1) 
            licznik++;
    }

    return licznik;
}
