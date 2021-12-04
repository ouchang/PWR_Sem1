#include <bits/stdc++.h>
#include "puzzle.h"
#include "cmp.h"
#include "wezel.h"
using namespace std;

bool CzyRuchMozliwy(int x, int y, int ruch_x, int ruch_y) {
    int nowyX = x + ruch_x; 
    int nowyY = y + ruch_y; 

    if(nowyX >= 3 || nowyX < 0 || nowyY >= 3 || nowyY < 0) //wyjście poza tablice
        return false;
    return true;
}
