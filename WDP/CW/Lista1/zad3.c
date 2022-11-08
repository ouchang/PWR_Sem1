#include <stdio.h>
#include <math.h>

int main() {
    int n,k=2;

    scanf("%d", &n);

    //rozkład na czynniki pierwsze
    while(n > 1) {
        //jeśli n jest podzielne przez k:
        while(n%k == 0) {
            printf("%d\n", k);
            n /= k;
        }
        k++;
    }

    return 0;
}
