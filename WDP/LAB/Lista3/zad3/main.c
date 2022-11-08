#include <stdio.h>
#include "funs3.h"

int main() {
    long int n;
    int licznik;

    scanf("%ld", &n);

    licznik = phi(n);

    printf("%d\n", licznik);
}
