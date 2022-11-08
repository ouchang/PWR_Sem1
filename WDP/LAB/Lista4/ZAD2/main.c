#include <stdio.h>
#include <stdbool.h>

//RED - liczba poprawnych liczb na poprawnych miejscach
//WHITE - liczba poprawnych liczb, ale na złym miejscu

struct KOD {
    int a;
    int b;
    int c;
    int d;
};

bool KodKandydat[7][7][7][7]; //czy dany kod nadal jest kandydatem na rozwiązanie? 
                              //(czy nadal spelnia wymogi gracza?)

int main() {
    int red=0, white=0;
    int potencjalne_kody=6*6*6*6; //liczba wszystkich aktualnie potencjalnych rozwiązań kodu
    struct KOD curr_kod; //liczby proponowane przez komputer jako rozwiązanie kodu
    bool solved=false;
    bool found_kod=false;

    //Wypełniam tablicę KodKandydat wartościami true
    for(int a=1; a<=6; a++) {
        for(int b=1; b<=6; b++) {
            for(int c=1; c<=6; c++) {
                for(int d=1; d<=6; d++) {
                    KodKandydat[a][b][c][d] = true;
                }
            }
        }
    }
    
    
    //Rozwiązanie w maksymalnie 8 pytaniach!
    for(int t=1; t<=8; t++) {
        found_kod = false;
        
        //Czy gracz oszukuje?
        if(potencjalne_kody <= 0) {
            printf("You are cheating!\n");
            solved = true;
            break;
        }
        
        //Pomijam potencjalne rozwiązania, które zostały już wyeliminowane z rozważań
        if(potencjalne_kody > 0) {
            for(int a=1; a<=6; a++) {
                for(int b=1; b<=6; b++) {
                    for(int c=1; c<=6; c++) {
                        for(int d=1; d<=6; d++) {
                            if(KodKandydat[a][b][c][d]) {
                               curr_kod.a = a;
                               curr_kod.b = b;
                               curr_kod.c = c;
                               curr_kod.d = d;
                               
                               found_kod = true;
                               break;
                            }
                        }
                        
                        if(found_kod)
                            break;
                    }
                    
                    if(found_kod)
                        break;
                }
                
                if(found_kod)
                    break;
            } 
        }

        //Wyświetlam zapytanie komputera z proponowanym kodem i pobieram dane (red oraz white)
        printf("[%d] [%d] [%d] [%d]?\n", curr_kod.a, curr_kod.b, curr_kod.c, curr_kod.d);
        printf("Red: ");
        scanf("%d", &red);
        printf("White: ");
        scanf("%d", &white);

        //Czy kod został odgadnięty? 
        if(red == 4) {
            printf("I win!\n");
            solved = true;
            break;
        }
        
        //Zatem curr_kod nie jest rozwiązaniem
        //Można go wyeliminowac z późniejszych rozważań
        KodKandydat[curr_kod.a][curr_kod.b][curr_kod.c][curr_kod.d] = false;
        potencjalne_kody--;
        
        //Eliminuje potecjalne kody nie spełniające wymogów gracza
        for(int a=1; a<=6; a++) {
            for(int b=1; b<=6; b++) {
                for(int c=1; c<=6; c++) {
                    for(int d=1; d<=6; d++) {
                        //curr_kod -> propozycja kodu oceniona przez gracza
                        //a b c d -> aktualnie analizowana propozycja kodu 
                        
                        //Eliminacja kandydatow, ktorzy nie spelniaja wymogow gracza
                        if(KodKandydat[a][b][c][d]) {
                            //Zliczam ile cyfr jest na takich samych miejscach w abcd i curr_kod (RED)
                            int tRed=0;
                            if(a == curr_kod.a)
                                tRed++;
                            if(b == curr_kod.b)
                                tRed++;
                            if(c == curr_kod.c)
                                tRed++;
                            if(d == curr_kod.d)
                                tRed++;
                        
                            //Jeśli red != tRed, to abcd nie spelnia wymogow gracza
                            //abcd mozna wyeliminowac z pozniejszych rozwazan
                            if(red != tRed) {
                                //Elimuje kandydata z pozniejszych rozważań
                                KodKandydat[a][b][c][d] = false;
                                potencjalne_kody--;
                            } else if(red == tRed) {
                                //abcd spelnia wymogi gracza pod wzgledem red
                                
                                //Zliczam ile cyfr z curr_kod jest na innych pozycjach w abcd (WHITE)
                                int tWhite=0;
                                if(a != curr_kod.a) {
                                    if(a == curr_kod.b || a == curr_kod.c || a == curr_kod.d) {
                                        tWhite++;
                                    }
                                }
                                if(b != curr_kod.b) {
                                    if(b == curr_kod.a || b == curr_kod.c || b == curr_kod.d) {
                                        tWhite++;
                                    }
                                }
                                if(c != curr_kod.c) {
                                    if(c == curr_kod.a || c == curr_kod.b || c == curr_kod.d) {
                                        tWhite++;
                                    }
                                }
                                if(d != curr_kod.d) {
                                    if(d == curr_kod.a || d == curr_kod.b || d == curr_kod.c) {
                                        tWhite++;
                                    }
                                }
                                
                                //Jeśli white != tWhite, to abcd nie spelnia wymogow gracza
                                if(white != tWhite) {
                                    KodKandydat[a][b][c][d] = false;
                                    potencjalne_kody--;
                                }
                            }
                        }
                    }
                }
            }
        }
     }
     
     //Jeżeli nie udalo sie znalezc rozwiazania w 8 pytaniach, gracz wygrywa
     if(!solved) {
         printf("You win!\n");
     }
     
     return 0;
}
