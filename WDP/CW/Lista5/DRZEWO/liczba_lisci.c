#include <stdio.h>
#include "drzewo.h"

int liczba_lisci(Tree ptr) {
    int licznik=0;
    printf("JESTEM W %d\n", ptr->wart);
    printf("1 WEZEL: %d, LICZBA LISCI DOTAD: %d\n", ptr->wart, licznik);
    if(ptr->lewo == NULL && ptr->prawo == NULL)
        return 1;

    if(ptr->lewo != NULL) {
        licznik += liczba_lisci(ptr->lewo);
        printf("PO LEWYM LICZBA LISCI DOTAD: %d\n", licznik);
    }

    if(ptr->prawo != NULL) {
        licznik += liczba_lisci(ptr->prawo);
        printf("PO PRAWYM LICZBA LISCI DOTAD: %d\n", licznik);
    }

    printf("2 WEZEL: %d, LICZBA LISCI DOTAD: %d\n", ptr->wart, licznik);
    return licznik;
}
