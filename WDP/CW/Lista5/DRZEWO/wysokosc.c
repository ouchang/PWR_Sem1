#include <stdio.h>
#include "drzewo.h"

int wysokosc(Tree ptr) {
    int wys_lewa=0, wys_prawa=0;
    int wys=0;

    if(ptr->lewo != NULL) {
        wys_lewa = wysokosc(ptr->lewo);
    }

    if(ptr->prawo != NULL) {
        wys_prawa = wysokosc(ptr->prawo);
    }

    if(wys_lewa >= wys_prawa)
        wys = wys_lewa;
    else
        wys = wys_prawa;
    
    return wys+1;
}
