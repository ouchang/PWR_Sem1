struct Node {
    int wart;
    struct Node* lewo;
    struct Node* prawo;
};

typedef struct Node* Tree;

int liczba_lisci(Tree ptr);
int liczba_wezlow(Tree ptr);
void wstawianie(Tree* ptr, int i);
int wysokosc(Tree ptr);
void usun_drzewo(Tree *ptr);
