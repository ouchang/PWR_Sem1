#include "puzzle.h"
#include <bits/stdc++.h>
#include <array>
#include <vector>
using namespace std;

array<int, 9> Losowanie() {
    array<int, 9> T;
    vector<int> V;
    int idx=0;

    for(int i=0; i<9; i++) {
        V.push_back(i);
    }

    for(int i=0; i<9; i++) {
        //losowanie liczby
        srand(time(NULL));
        idx = rand() % (V.size()); //wylosowana liczba jest w zakresie 0-8
        
        //wpisywanie wylosowanej liczby do  tabliy 3x3
        T[i] = V[idx];

        //usuwanie wylosowanej liczby z vectora
        swap(V[idx], V[V.size()-1]);
        V.pop_back();
    }

    return T;
}

