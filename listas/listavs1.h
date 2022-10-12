#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef struct aluno{
	int mat;
	string nome;
}Aluno;

Aluno lista[30];


void incluirDesordenado(){
    int qtd = 0, cont;
    do{
        if(qtd < 29){
            printf("\nmatricula: ");
            scanf("%d", &lista[qtd].mat);
            printf("\nnome: ");
            cin>>lista[qtd].nome;
            qtd++;
        }
        else{
            printf("\nerro, turma cheia");
            break;
        }
        printf("\ncontinuar? 1-sim, 2-nao \n");
        scanf("%d", &cont);
    }
    while(cont == 1);
}

int procura(int mat){
    int i = 0;
    while(i < 29){
        if(lista[i].mat == mat) return 1;
        else i++;
    }
}

void mostrar(int pos){
    int i = 0;
    while(i < pos){
        cout<< lista[i].mat;
        cout<<" -> ";
        cout<< lista[i].nome<<endl;
        i++;
    }

}

void consultar(){
    int i, elemento,cont, achou = -1;
    do{
        printf("\nmatricula: ");
        scanf("%d", &elemento);
        achou = procura(elemento);

        if(achou != -1){
            mostrar(achou);
        }
        else{
            printf("\nElemento nao existe");
            printf("\nprosseguir? 1-sim 2-nao \n");
            scanf("%d", &cont);
        }
    }
    while(cont == 1);
}

void rmv(int indice){
    int i = 0;
    if(indice < 0 || indice > i - 1){
        cout << "elemento nao existe";
    }
    else{
        lista[indice].mat = lista[i - 1].mat;
        lista[indice].nome = lista[i - 1].nome;
        i--;
    }
}

void remover00(){
    int i, elemento, achou, cont, resp;
    do{
        printf("\nMatricula: ");
        scanf("%d", &elemento);
        achou = procura(elemento);

        if(achou != -1){
            mostrar(achou);
            printf("\nremover? 1-sim 2-nao \n");
            scanf("%d", &resp);
        if(resp == 1){
            rmv(achou);
            printf("elemento removido");
        }
        else{
            printf("\n nao removido");
            break;
        }
        }
        else{
            printf("\ncontinuar? 1-sim 2-nao \n");
            scanf("%d", &cont);
        }
    } while(cont == 1);

}

void remover01(int indice){
    int i = 0;
    if(indice < 0 || indice > i - 1){
        cout<< "elemento nao existe";
    }
    else{
        while(indice < 1){
            lista[indice].mat = lista[indice + 1].mat;
            lista[indice].nome = lista[indice + 1].nome;
            indice++;
        }
        i--;
    }
}

main(){
    Aluno lista[30];

	int i = 0;

	do{
        printf("1-inserir \n");
        printf("2-consultar \n");
        printf("3-remover \n");
        printf("4-mostrar \n");
        scanf("%d", &i);

        if( i == 1){
            incluirDesordenado();
        }else if(i == 2){
            consultar();
        }else if(i == 3){
            remover00();
        }else if(i == 4){
            mostrar(i);
        }
        else{
            printf("erro");
            break;
        }
	} while(i < 30);
}

