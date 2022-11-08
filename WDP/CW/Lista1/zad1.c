#include <stdio.h>
#include <stdbool.h>

int T[999];

int main() {
    int n, idx=0;
    bool ok=true;
    
    scanf("%d", &n);

    //zamiana cyfr na ciag znakow char
    while(n > 0) {
        T[idx] = n%10;
        idx++;
        n /= 10;
    }

    //sprawdzenie czy jest palindromem
    for(int i=0; i<idx; i++) {
        if(T[i] != T[idx-1-i]) {
            ok = false;
            break;
        }
    }

    if(ok)
        printf("TO JEST PALINDROM\n");
    else
        printf("TO NIE JEST PALINDROM\n");

    return 0;
}
