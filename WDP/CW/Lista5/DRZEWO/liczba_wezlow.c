#include <stdio.h>
#include "drzewo.h"

int liczba_wezlow(Tree ptr) {
    int licznik=1;
    
    if(ptr->lewo != NULL) {
        licznik += liczba_wezlow(ptr->lewo);
    }

    if(ptr->prawo != NULL) {
        licznik += liczba_wezlow(ptr->prawo);
    }

    return licznik;
}
