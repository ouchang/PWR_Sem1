#include <stdlib.h>
#include <stdio.h>
#include "drzewo.h"

void wstawianie(Tree* ptr, int i) {
    printf("ANALIZUJE I:%d\n", i);
    if(*ptr == NULL) {
        printf("PUSTY WEZEL, WSTAWIAM I: %d\n", i);
        *ptr = malloc(sizeof(struct Node));
        (*ptr)->wart = i;
        (*ptr)->lewo = NULL;
        (*ptr)->prawo = NULL;
    } else {
        if(i < (*ptr)->wart) {
            printf("IDE NA LEWO\n");
            wstawianie(&((*ptr)->lewo), i);
        } else if(i > (*ptr)->wart) {
            printf("IDE NA PRAWO\n");
            wstawianie(&((*ptr)->prawo), i);
        }
    }
}
