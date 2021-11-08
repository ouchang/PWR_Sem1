#include <stdio.h>

int main() {
    int n;
    int licznik_g=1; // aktual. liczba * w wierszu
    int licznik_s=0; // aktual. liczba spacji przed pierwszą * w wierszu

    scanf("%d", &n);

    licznik_s = n-1;

    for(int i=0; i<n; i++) {
        //wypisuje spacje
        for(int j=0; j<licznik_s; j++)
            printf(" ");
        licznik_s--;

        //wypisuje *
        for(int j=0; j<licznik_g; j++) 
            printf("*");
        licznik_g += 2;

        printf("\n");
    }

    return 0;
}
