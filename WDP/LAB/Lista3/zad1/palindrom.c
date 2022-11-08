#include <stdbool.h>
#include "funs1.h"

bool palindrom(char s[]) {
    bool ok=true;
    char znak;
    int n=0;

    //obliczam długość napisu
    while(s[n] != 0) {
        n++;
    }

    for(int i=0; i<n; i++) {
        //porównuje pierwszą literę z ostatnią, drugą z przedostatnią itd.
        if(s[i] != s[n-i-1]) { 
            //litery się różnią -> to nie jest palindrom
            ok = false;
            break;
        }

        if(!ok) //wiemy, że to już nie jest palindrom
            break;
    }

    if(ok)
        return true;
    else
        return false;
}
