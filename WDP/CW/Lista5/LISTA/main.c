#include <stdio.h>
#include "listy.h"

int main() {
    List wsk = NULL;
    dopisz_niemalejaco(&wsk, 1);
    drukowanie(wsk);
    dopisz_niemalejaco(&wsk, 3);
    drukowanie(wsk);
    dopisz_niemalejaco(&wsk, 3);
    drukowanie(wsk);
    //dopisz_niemalejaco(&wsk, 5);
    //drukowanie(wsk);
    dopisz_niemalejaco(&wsk, 6);
    drukowanie(wsk);
    dopisz_niemalejaco(&wsk, 2);
    drukowanie(wsk);
    dopisz_niemalejaco(&wsk, 6);
    //drukowanie
    drukowanie(wsk);

    usun(&wsk, 1);
    drukowanie(wsk);
    usun(&wsk, 3);
    drukowanie(wsk);
    usun(&wsk, 6);
    drukowanie(wsk);
    usun(&wsk, 2);
    drukowanie(wsk);
}
