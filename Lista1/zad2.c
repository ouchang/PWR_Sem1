#include <stdio.h>
#include <math.h>

int main() {
    int a,b,c;
    double delta=0;
    double x1=0.0, x2=0.0;

    scanf("%d %d %d", &a, &b, &c);

    delta = b*b - (4*a*c);

    if(delta < 0) //brak rozw.
        printf("BRAK ROZWIAZAN RZECZYWISTYCH\n");
    else if(delta == 0) {// 1 rozw.
        x1 = (-1*b)/(2*a);
        printf("%.2f\n", x1);
    } else { // 2 rozw.
        x1 = (-1*b - sqrt(delta)) / (2*a); //problem z sqrt i funk. pow
        x2 = (-1*b + sqrt(delta)) / (2*a); //
        printf("%.2f %.2f\n", x1, x2);
    }

    return 0;
}
