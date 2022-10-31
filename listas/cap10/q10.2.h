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

void inserir(Item x, Lista *L){
    while(*L != NULL && (*L)->item < x) L = &(*L)->prox;
    *L = inclue(x, *L);
}

void exibe(Lista L){
    while(L != NULL){
        printf(fmt, L->item);
        L = L->prox;
    }
}

void remover(Item x, Lista *L){
    while(*L != NULL && (*L)->item < x){
        L = &(*L)->prox;
    }
    if(*L == NULL || (*L)->item > x) return;
    Lista n = *L;
    *L = n->prox;
    free(n);
}

int busca(Item x, Lista L){
    while(L != NULL && L->item < x){
        L = L->prox;
    }
    return (L != NULL && L->item == x);
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
    int decrescente(Lista A, Lista B){
        int ordem;

        if(A <= B){
            ordem = 1;
        }
        else{
            ordem = -1;
        }
    }

int main(){
    Lista l;
    l = inclue(2, NULL);
    l = inclue(5, l);
    l = inclue(1, l);
    l = inclue(4, l);
    l = inclue(3, l);

    exibe(l);
    printf("\nDecrescente: ");
    decrescente(l, NULL);

    return 0;
}
