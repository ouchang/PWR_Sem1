#include <stdio.h>
#include <stdlib.h>
#include "drzewo.h"

void usun_drzewo(Tree *ptr) {
    printf("JESTEM W %d\n", (*ptr)->wart);
    if((*ptr)->lewo == NULL && (*ptr)->prawo == NULL) {
        printf("USUWAM LISCIA: %d\n", (*ptr)->wart);
        free((*ptr));
        return;
    }

    if((*ptr)->lewo != NULL) {
        printf("IDE NA LEWO\n");
        usun_drzewo(&((*ptr)->lewo));
        (*ptr)->lewo = NULL;
    }

    if((*ptr)->prawo != NULL) {
        printf("IDE NA PRAWO\n");
        usun_drzewo(&((*ptr)->prawo));
        (*ptr)->prawo = NULL;
    }
    
    printf("USUWAM TERAZ WEZEL: %d\n", (*ptr)->wart);
    if((*ptr)->lewo == NULL && (*ptr)->prawo == NULL)
        printf("HEHE JESTEM LISCIEM TERAZ\n");
    free((*ptr));
    (*ptr) = NULL;
}
