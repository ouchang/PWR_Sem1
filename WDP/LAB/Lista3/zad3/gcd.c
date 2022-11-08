#include "funs3.h"

long int gcd(long int a, long int b) {
    long int tmp;
    
    //algorytm Euklidesa
    while(b > 0) {
        tmp = a%b;
        a = b;
        b = tmp;
    }

    return a;
}
