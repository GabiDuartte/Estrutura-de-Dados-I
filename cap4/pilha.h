#include <stdlib.h>
#include <stdio.h>

typedef char Itemp;

typedef struct pilha {
    int max;
    int topo;
    Itemp *item;
} *Pilha;

Pilha criarpilha(int n){
    Pilha P = (Pilha)malloc(sizeof(struct pilha));
    P->max = n;
    P->topo = -1;
    P->item = (Itemp*)malloc(sizeof(Itemp) * n);
    return P;
}
int vaziap(Pilha P){
    if(P->topo == -1) return 1;
    else return 0;
}
int cheiap(Pilha P){
    if(P->topo == P->max-1) return 1;
    else return 0;
}
void empilha(Itemp y, Pilha P){
    if(!(cheiap(P))){
        P->topo++;
        P->item[P->topo] = y;
    }
    else{
        printf("Pilha cheia");
    }
}
Itemp desempilha(Pilha P){
    if(!(vaziap(P))){
        Itemp item = P->item[P->topo];
        P->topo--;
        return item;
    }
    else{
        printf("Pilha vazia");
    }
}
Itemp topo(Pilha P){
    if(!(vaziap(P))){
        return P->item[P->topo];
    }
    else{
        printf("Pilha vazia");
    }
}
void destroip(Pilha *Q){
    free((*Q)->item);
    free(*Q);
    *Q = NULL;
}
