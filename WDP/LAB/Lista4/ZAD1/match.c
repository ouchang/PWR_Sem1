// ? - zgodność z dowolnym znakiem
// * - zgodność z dowolnym, również pustym, ciągiem znaków w łańcuchu
// Znak różny od ’?’ i ’*’ oznacza zgodność tylko z samym sobą.

//wzorzec posiada "specjalne znaki"
//lancuch - łańcuch literek
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "lancuch.h"

bool match(char* wzorzec, char* lancuch) {
    int w_len, l_len;
    w_len = strlen(wzorzec);
    l_len = strlen(lancuch);

    char nowy_w[100]; //zmieniona kopia wzorca
    char nowy_l[100]; //zmieniona kopia lancucha

    //Oba słowa są puste
    if(w_len == 0 && l_len == 0) {
        return true;
    }

    //Jedno ze słów jest już puste
    if(w_len == 0 && l_len > 0) {
        return false;
    } else if(l_len == 0) {
        return false;
    }

    //Wzorzec to same gwiazdki
    bool tylko_gw=true;
    for(int i=0; i<w_len; i++) {
        if(wzorzec[i] != '*')
            tylko_gw = false;
    }
    if(tylko_gw)
        return true;

    //Analizuje pierwszy znak aktualnego słowa,
    //w zależności od przypadku, odpowiednio skracam dane słowe 
    //o jeden znak

    if(wzorzec[0] != '*') {
        if(wzorzec[0] == lancuch[0] || wzorzec[0] == '?') {
            //Skracam oba słowa o pierwszą literkę
            
            //printf("PIERWSZA LITERA W: %c\n", wzorzec[0]);
            //printf("PIERWSZA LITERA L: %c\n", lancuch[0]);
            for(int i=0; i<w_len-1; i++) {
                nowy_w[i] = wzorzec[i+1];
            }
            nowy_w[w_len-1] = '\0'; //symbol końca

            for(int i=0; i<l_len; i++) {
                nowy_l[i] = lancuch[i+1];
            }
            nowy_l[l_len-1] = '\0';

            //Uruchamian ponownie funkcję, ale już na skróconych słów
            return match(nowy_w, nowy_l);
        }
    } else {
        //We wzorcu jest '*'

        //Przygotuje kopie słów z usuniętą pierwszą literą
        for(int i=0; i<w_len-1; i++) {
            nowy_w[i] = wzorzec[i+1];
        }
        nowy_w[w_len-1] = '\0'; //symbol końca

        //UWAGA: W nowy_w pozbyłam się '*'
        for(int i=0; i<l_len-1; i++) {
            nowy_l[i] = lancuch[i+1];
        }
        nowy_l[l_len-1] = '\0';

        bool nastepny_ok=false, dalej_ok=false; 

        //Sprawdzam czy znak tuż za '*' jest równy
        //pierwszemu znakowi z łańcucha, 
        //(jeśli tak, prowadzę dalszą analizę)
        //na końcu zwracam wynik porównywania
        nastepny_ok = match(nowy_w, lancuch);

        //Sprawdzam czy znak tuż za '*' jest równy
        //jakiemuś dalszemu znakowi z łańcucha, 
        //(jeśli tak, prowadzę dalszą analizę)
        //na końcu zwracam wynik porównywania
        dalej_ok = match(wzorzec, nowy_l);

        //Jeśli którakolwiek z powyższych 2 analiz,
        //zwróciła TRUE, zawracam TRUE
        if(nastepny_ok || dalej_ok)
            return true;
        return false;
    }

    return false;
}
