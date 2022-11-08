#include <stdio.h>
#include "listy.h"

void drukowanie(List wsk) {
    while(wsk != NULL) {
        printf("%d ", wsk->wart);
        wsk = wsk->next;
    }
    printf("\n");
}
