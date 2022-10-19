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

int soma(Lista L){
    if(L == NULL) return 0;
    return L->item + soma(Lista->prox);
}

int main(){
    Lista l;

    l = inclue(4, NULL);
    l = inclue(5, l);
    l = inclue(1, l);
    l = inclue(3, l);

    exibe(l);
    printf("\nSoma: ");
    soma(l);
}
