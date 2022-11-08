#include <stdio.h>
#include <stdbool.h>
#include "lancuch.h"

int main() {
    char wzorzec[100];
    char lancuch[100];
    bool wynik;

    printf("Wpisz wzorzec: ");
    scanf("%s", wzorzec);
    printf("Wpisz łańcuch: ");
    scanf("%s", lancuch);

    wynik = match(wzorzec, lancuch);
    if(wynik)
        printf("Zgodność\n\n");
    else
        printf("Brak zgodności\n\n");

    return 0;
}
