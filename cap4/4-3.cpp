#include <stdio.h>
#include <stdlib.h>
#include "../ed/fila.h"

int main(){
    char s[256];
    Fila F = criarFila(256);
    Pilha P = criarpilha(256);
    printf("Frase: ");
    gets(s);
    for(int i = 0; s[i]; i++)
    if(isalpha(s[i])){
        enfileira(s[i], F);
        empilha(s[i],P);
    }
    while(!vaziaf(F) && desenfileira(F)==desempilha(P));
    if(vaziaf(F)) puts("A frase e palindroma");
    else puts("A frase nao e palindroma");
    destroif(&F);
    destroip(&P);
    return 0;
};
