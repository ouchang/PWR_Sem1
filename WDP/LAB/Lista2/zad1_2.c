//Aleksandra Zaremba

#include <stdio.h>
#include <stdbool.h>

int N_B[5] = {200, 100, 50, 20, 10}; //nominaly - bnknoty
int N_MZ[3] = {5, 2, 1}; //nominaly - monety (zl)
int N_MG[6] = {50, 20, 10, 5, 2, 1}; //nominaly - monety (gr)

int main() {
    int k,g; //kwota w zl; kwota w gr
    int licznik=0; //ile uzyje danego nominału
    int idx_b=0, idx_m=0; //idx po tablicach z nominałami
    bool napis_bank=false, napis_monety=false; //czy wyswietlilam dany napis

    //wczytywane
    printf("Podaj liczbe zloty: ");
    scanf("%d", &k);

    printf("Podaj liczbe groszy: ");
    scanf("%d", &g);

    //wydawanie kwoty w zloty
    while(k > 0) {
        licznik = 0;

        if(k >= 10) { //uzyj banknotow
            if(!napis_bank) { //jezeli nie wyswietlilam napisu
                printf("    Banknoty:\n");
                napis_bank = true;
            }

            //ile razy uzyje dany nominal
           licznik = k / N_B[idx_b];
           k -= licznik * N_B[idx_b];

            //wyswietlanie uzycia danego nominalu
            if(licznik != 0)
                printf("%d x %d zl\n", licznik, N_B[idx_b]);

            idx_b++;
        } else { //uzyj monet
            if(!napis_monety) { //jezeli nie wyswietlilam napisu
                printf("    Monety:\n");
                napis_monety = true;
            }

            //ile razy uzyje danej monety
            licznik = k / N_MZ[idx_m];
            k -= licznik * N_MZ[idx_m];

            //wyswietlanie uzycia danej monety
            if(licznik != 0)
                printf("%d x %d zl\n", licznik, N_MZ[idx_m]);

            idx_m++;
        }
    }

    //czyszczenie
    idx_m = 0 ;

    //wydawanie kwoty w groszach
    while(g > 0) {
        licznik = 0;

        if(!napis_monety) { //jezeli nie wyswietlilam napisu
            printf("    Monety:\n");
            napis_monety = true;
        }

        //ile razy uzyje danej monety (gr)
        licznik = g / N_MG[idx_m];
        g -= licznik * N_MG[idx_m];

        //wyswietlanie uzycia danej monety (gr)
        if(licznik != 0)
            printf("%d x %d gr\n", licznik, N_MG[idx_m]);

        idx_m++;
    }

    return 0;
}
