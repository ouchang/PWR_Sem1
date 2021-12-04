#include "wezel.h"
#include "puzzle.h"
using namespace std;

struct cmp { //porównywanie dla kolejki priorytetowej
    bool operator() (const struct Wezel* lhs, const struct Wezel* rhs) {
        //uporządkowanie rosnące
        return ((lhs->g + lhs->h) > (rhs->g + rhs->h)); //porównanie funkcji kosztu (biore o mniejszym koszcie)
    }
};
