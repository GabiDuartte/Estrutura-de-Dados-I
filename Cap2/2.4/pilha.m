int main(){
    int n, vlr;

    printf("Quantidade: ");
    scanf("%d", &n);

    Pilha Pb = criarpilha(n);
    Pilha Pa = criarpilha(n);

    for(int i = 0; i < n; i++){
       if(i == 0){
        printf("Valor: ");
        scanf("%d", &vlr);
        empilha(vlr, Pa);
       }
       else{
        printf("Valor: ");
        scanf("%d", &vlr);

        if(topo(Pa) > vlr){
            empilha(vlr, Pa);

        }
        else{
            while(topo(Pa) > vlr){
                if(vaziap(Pa)){
                    if(topo(Pa) > vlr){
                        empilha(desempilha(Pa), Pb);
                    }
                    else{
                        empilha(desempilha(Pb), Pa);
                    }
                }
            }
        }
       }
    }
    printf("%d", desempilha(Pa));

    mostrar(Pa);

    }
