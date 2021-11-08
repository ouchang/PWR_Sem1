#include <stdio.h>
#include <stdbool.h>
#include "funs1.h"

char str[10000];

int main() {
    bool wynik;
    int len=0;

    scanf("%s", str);

    while(str[len] != 0) {
        len++;
    }

    wynik = palindrom(str, len);

    if(wynik == true)
        printf("To jest palindrom\n");
    else
        printf("To nie jest palindrom!\n");
       
    return 0;
}
