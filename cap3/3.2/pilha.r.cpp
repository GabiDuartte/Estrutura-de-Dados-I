#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../cap3/pilha.c"

float valor(char *e) {
    Pilha P = pilha(256);
    for(int i = 0; e[i]; i++){
        if(isdigit(e[i])){
        empilha(atof(e+i), P);
       while(isdigit(e[i+1]) || e[i+1]=='.') i++;
        }
        else if(strchr("+-/*", e[i])) {
            float y = desempilha(P);
            float x = desempilha(P);
            switch(e[i]) {
                case '+': empilha(x+y, P); break;
                case '-': empilha(x-y, P); break;
                case '*': empilha(x*y, P); break;
                case '/': empilha(x/y, P); break;
            }
        }
    }
}
float z = desempilha(P);
destriop(&P);
return z;
}

float main(){
    Pilha P = pilha(256);
    printf("Infixa: ");
    gets(e);
    Printf("Posfixa %s\n\n: ", posfixa(e));
    return 0;
    
}
