#include <stdio.h>
#include <iostream>
#define fmt "%d"

using namespace std;

typedef int Item;
typedef struct no{
    Item item;
    struct no *prox;
} *Lista;

Lista inclue(Item x, Lista L){
    Lista n = (Lista)malloc(sizeof(struct no));
    n->item = x;
    n->prox = L;
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


int main(){
    Lista l;
    l = inclue(2, NULL);
    l = inclue(5, l);
    l = inclue(1, l);
    l = inclue(4, l);
    l = inclue(3, l);

    exibe(l);
    inserir(2,l);
    
    return 0;
}
