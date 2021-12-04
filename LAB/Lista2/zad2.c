//Aleksandra Zaremba

#include <stdio.h>

int main() {
    int n;
    double x;
    double sr=0.0;

    scanf("%d", &n);

    if(n <= 0) {
        printf("NIE MOZNA POLICZYC ŚREDNIEJ!\n");
        return 0;
    }

    for(int i=0; i<n; i++) {
        scanf("%lf", &x);
        sr += x;
    }

    sr /= n;
    printf("%lf\n", sr);

    return 0;
}
