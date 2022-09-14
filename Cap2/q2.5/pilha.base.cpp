#include <stdio.h>
#include <stdlib.h>

typedef struct no{
        char caracter;
        struct no *prox;
} No;

No* empilhar(No *pilha, char valor){
    No *novo = malloc(sizeof(No));
    
    if(novo){
             novo-> caracter = valor;
             novo->prox = pilha;
             return novo;
    }
    else
    printf("\nErro");
    return NULL;
}

No* desempilhar(No **pilha){
    No *retirar;
    
    if(*pilha){
               retirar = *pilha;
               *pilha = retirar->prox;
               return retirar;
    }
    else
    printf("\nPilha vazia");
    return NULL;
}

void mostrar(No *pilha){
     printf("\nPilha\n");
     while(pilha){
                  printf("%c", pilha->caracter);
                  pilha = pilha->prox;
     }
     printf("\nFim\n");
}

int par(char f, char d){
    switch(f){
    case ')':
    if(d == '(')
       return 1;
    else
       return 0;
    break;
    
    case ']':
    if(d == '[')
       return 1;
    else
       return 0;
    break;
    
    case '}':
    if(d == '{')
       return 1;
    else
       return 0;
    break;
}
}

int expressao(char x[]){
    int e = 0;
    No *retirar, *pilha = NULL;
    
    while(x[e] != '\0'){
               if(x[e] == '[' || x[e] == '(' || x[e] == '{'){
                       pilha = empilhar(pilha, x[e]);
                       mostrar(pilha);
               }
               else if(x[e] == ']' || x[e] == ')' || x[e] == '}'){
                      retirar = desempilhar(&pilha);
                      if(par(x[e], retirar -> caracter) == 0){
                         return 1;
                         }
               free(retirar);
               }
              e++  
    }
    mostrar(pilha);
    if(pilha){
              printf("\nErro de expressao");
              return 1;
    }
    else{
         return 0;
}
}

