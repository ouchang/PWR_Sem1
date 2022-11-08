#include "funs2.h"
#include <stdio.h>

double rozwiazanie(double a, double b, double eps) {

    //sprawdzam czy końce przedziału są miejscem zerowym
    if(f(a) == 0.0)
        return a;
    else if(f(b) == 0.0)
        return b;

    while(b-a > eps) { //znajdowanie miejsca zerowego z dokładnością do epsilon
        double mid = (a+b)/2;

        //sprawdzam czy środek przedziały jest miejscem zerowym
        if(f(mid) == 0.0)
            return mid;
        
        if((f(a) * f(mid)) < 0.0) //miejsce zerowe jest w "lewej" części przedziału
            b = mid;
        else //miejsce zerowe jest w "prawej" części przedziału
            a = mid;
    }

    return (a+b)/2;
}
