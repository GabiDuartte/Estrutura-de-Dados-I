#include <stdio.h>
#include <stdlib.h>
#include "pilha.base"

int main(){
    char exp[100];
    
    printf("Informe expressao: ");
    scanf("%99[^\n]", exp);
    printf("\nExpresssao: %s\n Retorno: %d", exp, expressao(exp));
}
