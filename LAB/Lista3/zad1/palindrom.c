#include <stdbool.h>
#include "funs1.h"

bool palindrom(char s[]) {
    bool ok=true;
    char znak;
    int n=0;

    while(s[n] != 0) {
        n++;
    }

    for(int i=0; i<n; i++) {
        if(s[i] != s[n-i-1]) {
            ok = false;
            break;
        }

        if(!ok)
            break;
    }

    if(ok)
        return true;
    else
        return false;
}
