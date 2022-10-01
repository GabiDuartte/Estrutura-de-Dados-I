#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../ed/fila.h"

int main(){
    Fila F = criarFila(5);
    enfileira(17, F);
    enfileira(25, F);
    enfileira(39, F);
    enfileira(46, F);

    while(!vaziaf(F)){
        int x = desenfileira(F);
        int p = x/10;
        int t = x%10;

        if(t>3) enfileira(p*10+(t-tempo), F);
        else printf("Processo %d concluido ", p);
    }
    destroif(&F);
    return 0;
}
// A ordem obtida foi: 2,4,1,3
