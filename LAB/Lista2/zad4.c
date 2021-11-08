//Aleksandra Zaremba

#include <stdio.h>
#include <math.h>

int main() {
    double w=1;
    double p;
    double st=1000.0;

    for(int i=1; i<=1000; i++) {
        p = pow(i,1.0/st); //sqrt^1000(1) * sqrt^1000(2) * ... sqrt^1000(1000) = sqrt^1000(1000!)
        w *= p;
    }

    printf("%lf\n", w);
}
