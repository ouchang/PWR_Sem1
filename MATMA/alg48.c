#include <stdio.h>

int NWD(int a, int b) {
    if(b == 0)
        return a;
    return NWD(b, a%b);
}

int main() {
    int a,b;
    double licznik=0;
    int n=100;
    double w;

    //scanf("%d", &n);
    while(n >= 1) {
        licznik = 0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(NWD(i,j) == 1)
                    licznik++; 
            }
        }
    
        w = licznik/(n*n);
        printf("%d;%f\n", n, w);
        n--;
    }
}
