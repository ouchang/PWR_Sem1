#include "agents.h"

struct agent newagent(int x, int y) {
    struct agent newguy;
    newguy.x = x;
    newguy.y = y;
    
    return newguy; 
}
