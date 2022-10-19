#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define fmt "%d"

using namespace std;

typedef int Item;
typedef struct no{
    Item item;
    struct no *prox;
} *Lista;

Lista inclue(Item x, Lista p){
    Lista n = (Lista)malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
}

void exibe(Lista L){
    while(L != NULL){
        printf(fmt, L->item);
        L = L->prox;
    }
}

void anexa(Lista *A, Lista B){
    if(B == NULL) return;
    while(*A != NULL) A = &(*A)->prox;
    *A = B;
}

void destroi(Lista *L){
    while(*L != NULL){
        Lista n = *L;
        *L = n->prox;
        free(n);
    }
}

int igual(Lista A, Lista B){
    if(A != NULL && B != NULL){
       if(A->item == B->item) return igual(A->prox, B->prox);
       return 0;
    }
    else{
       return 1;
    }
}

int main(){
    Lista l;
    Lista l1;

    l = inclue(3, NULL);
    l = inclue(2, l);
    l = inclue(1, l);

    l1 = inclue(3, NULL);
    l1 = inclue(2, l1);
    l1 = inclue(1, l1);

    exibe(l);
    printf("\n");
    exibe(l1);
    printf("\n");
    igual(l, l1);
}
