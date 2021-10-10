#include <stdio.h>

int main() {
    float a,b;
    float suma=0.0,roz=0.0,iloczyn=0.0,iloraz=0.0;


    scanf("%f %f", &a, &b);

    suma = a+b;
    roz = a-b;
    iloczyn = a*b;
    iloraz = a/b;

    printf("Suma: %.2f, roznica: %.2f, iloczyn: %.2f, iloraz: %.2f\n", suma, roz, iloczyn, iloraz);
}
