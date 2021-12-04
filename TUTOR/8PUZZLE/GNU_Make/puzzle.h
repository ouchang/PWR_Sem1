#include "wezel.h"
#include "cmp.h"
using namespace std;

void Losowanie();
bool CzyRuchMozliwy(int x, int y, int ruch_x, int ruch_y);
void Drukowanie(Wezel* wezel);
Wezel* nowyWezel1(int T[4][4], int x, int y, int nowyX, int nowyY, int g, Wezel* rodzic, bool korzen);
Wezel* nowyWezel2(int T[4][4], int x, int y, int nowyX, int nowyY, int g, Wezel* rodzic, bool korzen);
Wezel* nowyWezel3(int T[4][4], int x, int y, int nowyX, int nowyY, int g, Wezel* rodzic, bool korzen);
void Rozwiazanie1(int T[4][4], int x, int y);
void Rozwiazanie2(int T[4][4], int x, int y);
void Rozwiazanie3(int T[4][4], int x, int y);
