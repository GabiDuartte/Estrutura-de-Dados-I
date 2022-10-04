#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class No{
public:

    char nome;
    No *prox;
    No(char n){
    nome=n;
    prox = NULL;
}

};
class Fila{
public:

    No *inicio;
    No *fim;

Fila(){
    inicio = NULL;
    fim = NULL;
}


void insereNaFila(char n){
    No *novo= new No(n);
    if (inicio==NULL){ 
    inicio = novo;
    fim = novo;
}
else{ 
    fim->prox=novo;
    fim=novo;
}
}

char retiraDaFila(){
    No *el;
    char nome;
    if (inicio!=NULL){
    el=inicio;
    nome=el->nome;
    inicio=inicio->prox;
    free(el);

}

return nome;
}
bool fila_vazia(){
    return (inicio==NULL);
}
void mostra(){
    No *atual;

    while(inicio != NULL){
    atual=inicio;
    printf("\n Nome %c \n",inicio->nome);
    inicio = inicio->prox;
    free(atual);
    break;
}
}
};

main(){
Fila *f1=new Fila();
Fila *f2=new Fila();
int resp;
char letra;
do {
cout<<"\nDigite a letra:";
cin>>letra;
if(f1->fila_vazia() == 1){
    f1->insereNaFila(letra);
}
else{
    while(f1->fila_vazia() != 1){
        f2->insereNaFila(f1->retiraDaFila());
    }
    f1->insereNaFila(letra);

    while(f2->fila_vazia() != 1){
        f1->insereNaFila(f2->retiraDaFila());
    }
}
cout<<"\nDeseja continuar (1-Sim 2-Nao)?";
cin>>resp;
}while(resp==1);
f1->mostra();

}

