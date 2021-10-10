#include <stdio.h>

int main() {
    int n,x;
    double sr=0.0;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        sr += x;
    }

    sr /= n;
    printf("%.2f\n", sr);

    return 0;
}
