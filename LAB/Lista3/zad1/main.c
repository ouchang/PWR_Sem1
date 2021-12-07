#include <stdio.h>
#include <stdbool.h>
#include "funs1.h"

char str[10000]; //wypełniona zerami

int main() {
    bool wynik;

    scanf("%s", str);

    wynik = palindrom(str);

    if(wynik == true)
        printf("To jest palindrom\n");
    else
        printf("To nie jest palindrom!\n");
       
    return 0;
}
