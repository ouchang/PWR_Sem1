//Aleksandra Zaremba

#include <stdio.h>
#include <assert.h>

//Niezmiennik to koniunkcja następujących warunków: 
//suma elementów 1/1 + 1/2 + ... + 1/(n-1) <= 10
//suma elementów 1/1 + 1/2 + ... + 1/(n-1 >= 0
//n >= 0

int main() {
    double n=0.0;
    double suma=0.0;

    assert(suma <= 10 && suma >= 0 && n >= 0); // gdy n=0, 1/n nie istnieje

    while(suma <= 10) {
        n++;
        suma += 1/n;
        assert(suma - (1/(n)) <= 10 && suma >= 0 && n >= 0); //
    }

    assert(suma - (1/(n)) <= 10 && suma >= 0 && n >= 0); //

    printf("%.0f\n", n);

    return 0;
}
