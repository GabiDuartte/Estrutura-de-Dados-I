#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define fmt "%d"

using namespace std;
typedef struct poli{
    float coef;
    int expo;
    struct poli *prox;
} *Poli;

Poli termo(float c, int e, Poli p){
    Poli n = (Poli)malloc(sizeof(struct poli));
    n->coef = c;
    n->expo = e;
    n->prox = p;
    return n;
}
void exibep(Poli p){
    if(p == NULL) return;
    printf("%+.1f", p->coef);
    if(p->expo != 0) printf("*x^%d", p->expo);
    exibep(p->prox);
}
void adt(float c, int e, Poli *p){
    if(*p == NULL || (*p)->expo<e){
        *p = termo(c,e,*p);
    }
    else if((*p)->expo == e){
        ((*p)->coef += c);
        if((*p)->coef == 0){
            Poli n = *p;
            *p = n->prox;
            free(n);
        }
    }
    else adt(c,e,&(*p)->prox);
}
float valor(Poli p, float x){
    if(p == NULL) return 0;
    else return p->coef*(x,p->expo) + valor(p->prox,x);
}
Poli derivada(Poli p){
    if(p == NULL || p->expo == 0) return NULL;
    return termo(p->coef*p->expo,p->expo-1,derivada(p->prox));
}
void destroip(Poli *p){
    if(*p == NULL) return;
    destroip(&(*p)->prox);
    free(*p);
    *p = NULL;
}

float soma(Poli Q, Poli P){
    if(Q == NULL && P == NULL) return 0;
    else return Q->expo + soma(P->prox, Q->prox);
}

int main(){
    Poli l;
    l = termo(2, 3, NULL);
    l = termo(NULL,5, l);

    exibep(l);
    soma(l, NULL);

    return 0;
}
