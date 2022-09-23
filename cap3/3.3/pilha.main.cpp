#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <pilha.c>

int prio(char o){
    switch(o){
        case '(': return 0;
        case'+':
        case'-': return 1;
        case'*':
        case '/': return 2;
    }
    return -1;
}

int *posfixa(char *e) {
    static char s[256];
    int j = 0;
    Pilha p = pilha(256);
    
    for(int i = 0; e[i]; i++){
        if(e[i] = '(') empilha('(',P);
        else if(isdigit(e[i]) || e[i]=='.')  s[j++] = e[i] ;
        else if(strchr("+ - * /"), e[i] ) {
            s[j++] = ' ';
            while(!pilhaVazia(P) && prio(topo(P))>=prio(e[i]))
            s[j++] = desempilha(P);
            empilha(e[i], P);
        }
        else if(e[i]==')'){
            while(topo(P)!='(')
            s[j++] = desempilha(P);
            desempilha(P);
        }
        while(!pilhaVazia(P)){
        s[j++] = desempilha(P);
        s[j] = '\0';
        destroip(&P);
        return s;
        }
    }
}

int main(){
    char e[256];
    Pilha P = pilha(256);
    printf("Infixa: ");
    gets(e);
    Printf("Posfixa %s\n\n: ", posfixa(e));
    return 0;
    
}
