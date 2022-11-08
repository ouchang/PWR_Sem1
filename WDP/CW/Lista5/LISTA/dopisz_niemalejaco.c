#include <stdio.h>
#include <stdlib.h>
#include "listy.h"

void dopisz_niemalejaco(List *ptr, int i) {
    List nowy, pomoc, tmp;
    nowy = malloc(sizeof(struct Node));
    nowy->wart = i;
    nowy->next = NULL;

    printf("ANALIZUJE TERAZ I: %d\n", i);;

    //ptr to wskazanie na miejsce gdzie jest wskazanie na pierwsze miesjce listy
    if(*ptr == NULL) { //pusta lista
        //printf("PUSTA LISTA!\n");
        *ptr = nowy;
        //printf("WARTOSC PIERWSZEGO ELEMENTU W LISCIE TO: %d\n", (*ptr)->wart);
    } else { //lista jest niepusta
        //printf("NIEPUSTA LISTA!\n");
        pomoc = (*ptr); //pomoc = wskazanie na pierwsze miejsce listy
        //printf("NIEPUSTA LISTA2!\n");
        printf("WARTOSC AKTUALNEGO ELEMENTU W LISCIE TO: %d\n", pomoc->wart);
        
        while(pomoc->next != NULL) {
            printf("LISTA MA WIĘCEJ NIŻ 1 ELEMENT\n");
            if(pomoc->wart < i) {
                printf("ELEMENT: %d < I\n", pomoc->wart);
                printf("IDZIEMY DALEJ W LIŚCIE\n");
                if(pomoc->next->wart >= i) {
                    printf("ELEMENT: %d < I\n", pomoc->next->wart);
                    printf("I WSTAWIANE DO LISTY\n");
                    nowy->next = pomoc->next;
                    pomoc->next = nowy; 
                    return;
                }
                pomoc = pomoc->next;
            } 
        }

        if(pomoc->next == NULL) {
            printf("LISTA MA AKTUALNIE TYLKO 1 ELEMENT\n");
            if(pomoc->wart <= i) {
                printf("JEDYNY ELEMENT: %d < I\n", pomoc->wart);
                pomoc->next = nowy;
                //printf("WARTOSC KOLEJNEGO ELEMENTU W LISCIE TO: %d\n", pomoc->next->wart);
            } else { //pomoc->wart >= i
               // printf("JEDYNY ELEMENT: %d >= I\n", pomoc->wart);
                printf("I IDZIE NA POCZĄTEK LISTY\n");
                nowy->next = pomoc;
                *ptr = nowy; // !!!
                return;
                //printf("WARTOSC KOLEJNEGO ELEMENTU W LISCIE TO: %d\n", (*ptr)->next->wart);
            }
        }
    }
}
