#include <stdio.h>

int main() {
    int len=0, licznik=0; // len - dlug. "ABRAKADABRA"; licznik - ile spacji dać na pocz. wiersza
    char word[] = "ABRAKADABRA";

    len = 11;

    for(int i=0; i<len; i++) {
        //wyświetlam spacje
        for(int j=0; j<licznik; j++)
            printf(" ");
        
        //wyświetlam litery
        for(int j=0; j<len-licznik; j++)
            printf("%c ", word[j]);
        
        licznik++;
        printf("\n");
    }

    return 0;
}
