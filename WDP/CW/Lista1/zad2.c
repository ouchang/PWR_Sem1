#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool P[999]; //same fałsze by default
// w P: PIERWSZA -> FALSE; ZLOZONA -> TRUE

void sito(int n) {
    int p=sqrt(n);

    P[0] = true;
    P[1] = true;

    for(int i=2; i<=p; i++) 
        if(P[i] == 0)
            for(int j=i*i; j<=n; j=j+i)
                P[j] = true;
}

int main() {
    int n, idx=2; // wyświetl n poczatkowych l. pierwszych
    //idx = 2, bo 2 to pierwsza l. pierwsza

    scanf("%d", &n);

    //wygenrerowanie l. pierwszych
    sito(1000);

    while(n > 0) {
        if(P[idx] == false) {
            printf("%d\n", idx);
            n--;
        }
        idx++;
    }

    return 0;
}
