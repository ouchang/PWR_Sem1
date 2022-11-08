#include <stdio.h>
#include "header.h"

void main() {
    printf("I am in main.c\n");
    printf("Calling hello function\n");
    hello();
    printf("Calling add function\n");
    add(3,5);
    printf("Back in main.c\n");
}