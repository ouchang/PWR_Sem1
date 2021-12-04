#include "funs2.h"
#include <stdio.h>

double rozwiazanie(double a, double b, double eps) {
    if(f(a) == 0.0)
        return a;
    else if(f(b) == 0.0)
        return b;

    while(b-a > 2*eps) { //wcześniej: b-a > eps
        double mid = (a+b)/2;

        if(f(mid) == 0.0)
            return mid;
        
        if((f(a) * f(mid)) < 0.0) 
            b = mid;
        else 
            a = mid;
    }

    return (a+b)/2;
}
