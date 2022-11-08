#include <stdio.h>
#include "funs2.h"

int main() {
    double a,b,eps;
    double w; //miejsce zerowe funkcji w przedziale [a,b]

    scanf("%lf %lf %lf", &a, &b, &eps);
    
    w = rozwiazanie(a,b,eps);

    printf("%f\n", w);

    return 0;
}
