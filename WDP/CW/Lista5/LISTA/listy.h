struct Node {
    int wart;
    struct Node* next;
};

typedef struct Node* List;

void dopisz_niemalejaco(List *ptr, int i);
void drukowanie(List wsk);
void usun(List *ptr, int i);
