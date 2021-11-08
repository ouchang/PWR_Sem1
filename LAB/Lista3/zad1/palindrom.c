#include <stdbool.h>
#include "funs1.h"

bool palindrom(char s[], int n) {
    bool ok=true;
    char znak;

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
