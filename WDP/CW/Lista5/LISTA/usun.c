#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "listy.h"

void usun(List *ptr, int i) {
    //usun wszystkie wystapienia wartosci całkowitej i
    List pomoc, tmp, tnode;
    printf("AKTUALNE I: %d\n", i);

    tmp = (*ptr);
    printf("USTAWIŁAM TMP NA POCZĄTEK!\n");

    if((*ptr)->wart == i) { //pierwszy elem. do usunięcia
        printf("USUWAM POCZTEK I PRZESUWAM PTR\n");
        while((*ptr) != NULL && (*ptr)->wart == i) { 
            pomoc = (*ptr)->next;
            free((*ptr));
            (*ptr) = pomoc;
        }
        if((*ptr) != NULL)
            printf("NOWY POCZATEK TO: %d\n", (*ptr)->wart);
        tmp = (*ptr);
    }

    if((*ptr) == NULL) {
        return;
    }
    
    while(tmp->next != NULL) {
        printf("WARTOSC TERAZ TO: %d\n", tmp->wart);
        printf("WARTOSC SASIADA TO: %d\n", tmp->next->wart);
        if(tmp->next->wart == i) {
            printf("TMP_NEXT DO WYWALENIA\n");
            tnode = tmp->next;
            while(tnode != NULL && tnode->wart == i) {
                pomoc = tnode->next;
                free(tnode);
                tnode = pomoc;
            }
            tmp->next = tnode;
        } else {
            printf("MOGE PRZEJSC NA SASIADA\n");
            tmp = tmp->next;
        } 
    }
}
