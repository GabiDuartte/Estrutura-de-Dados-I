#include <stdio.h>
#include <stdlib.h>

typedef char Itemp;

typedef struct pilha {
    int max;
    int topo;
    Itemp *item;
}*Pilha ;

Pilha pilha (int m){
    
Pilha P = malloc(sizeof(struct pilha));
P->max = m;
P->topo = -1;
P->item = malloc(m*sizeof(Itemp));
return P;


int pilhaVazia(Pilha P){
	return (P->topo == -1);
}


int pilhaCheia(Pilha P){
	return (P->topo == (P->max-1));
}

void empilha(Itemp x, Pilha P) {
    if(pilhaCheia(P)){
        printf("cheia");
    }
    else{
    P->topo++;
    P->item[P->topo] = x;
    }
}

Itemp desempilha(Pilha p){
    if(pilhaVazia(P)){
        printf("vazia");
    }
    else {
    Itemp x = P->item[P->topo];
    P->topo--;
    return x;
    }
}

void destroip(Pilha *Q){
    free((*Q)->item);
    free(*Q);
    *Q = NULL;
}
}
