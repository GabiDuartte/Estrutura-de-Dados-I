#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class No{
	public:
		int mat;
		char nome[23];
		No *prox;
		No(int m,char n[23]){
			mat=m;
			strcpy(nome,n);
			prox=NULL;
		}
};

class Lista{
	public:
		No *inicio;
		No *fim;

	    Lista(){
	    	inicio = NULL;
	    	fim = NULL;
		}
		void addToFinal(int m, char n[23]){
			No *novo= new No(m,n);
			if (fim==NULL){
				inicio = novo;
				fim = novo;
			}
			else{
				fim->prox=novo;
				fim=novo;
			}
		}


		int lst_vazia(){
			return (inicio==NULL);
		}
		void addToInicio(int m,char n[23]){
            No *novo = new No(m,n);
			if(fim == NULL){
                inicio = novo;
                fim = novo;
			}
			else{
                novo->prox = inicio;
                inicio = novo;
			}

		}
		void mostra(){
			if (lst_vazia()){
				cout<<"\nLista vazia!!!";
			}
			else{
				No *item = inicio;
				while(item != NULL){
                    cout<<item->mat<<item->nome<<endl;
                    item = item->prox;
				}
			}
		}

		int remove(int mat){
			 No *atual = inicio;
			 No *anterior = NULL;
			 while(atual != NULL){
                if(atual->mat == mat){
                    if(atual == inicio)
                        inicio = inicio->prox;
                    else if(atual == fim){
                        fim = anterior;
                        fim->prox = NULL;
                    }
                    else
                        anterior->prox = atual->prox;
                    free(atual);
                    return 1;
                }
                anterior = atual;
                atual = atual->prox;
			 }
			 return 0;
		}

		No *busca(int mat){
		    int achou;
		    No *atual;
			do{
                    atual = inicio;
                    achou = 0;
                    while(atual != NULL){
                    if(atual->mat == mat){
                        achou = 1;
                        cout<<"%9d%-20s\n"<<atual->mat<<atual->nome<<endl;
                        break;
                    } else {
                        atual = atual->prox;
                    }
                    }
                    } while (atual->prox != NULL);
                      if(achou != 1){
                        cout<<"aluno nao encontrado";
                }
		}

		void removeTodos(){
			No *atual=inicio;
			No *proximo=NULL;
			while (atual!=NULL){
					proximo=atual->prox;
					cout<<"\n Apaga:"<<atual->nome;
					free(atual);
					atual=proximo;
			}
			inicio=atual;
		}

		void crialistainversa(){
            No *atual = inicio;
            No *anterior = NULL;

            No *nvinicio = NULL;
            No *nvfim = NULL, *novo;

            while(atual != NULL){
                novo = (No *)malloc(sizeof(No));
                novo->mat = atual->mat;
                strcpy(novo->nome, atual->nome);
                if(nvinicio == NULL){
                    novo->prox = NULL;
                    nvinicio = novo;
                    nvfim = novo;
                }
                else{
                    novo->prox = nvinicio;
                    nvinicio = novo;
                }
                anterior = atual;
                atual = atual->prox;
            }
            No *item = nvinicio;
            do{
                cout<<item->mat<<item->nome<<endl;
                item = item->prox;
            } while(item->prox != NULL);
		}

		void listainvertida(){
            No *no = inicio;
            No *anterior = NULL;
            No *aux, *seguinte;

            while(no != NULL){
                seguinte = no->prox;
                no->prox = anterior;
                anterior = no;
                no = seguinte;
            }
            aux = inicio;
            inicio = fim;
            fim = aux;
		}
};
main(){

   Lista *l=new Lista();
   l->addToFinal(1,"Joao");
   l->addToFinal(2,"Gabriela");
   l->addToFinal(3,"Fabiola");
   l->addToInicio(5,"Joana Oliveira");
   l->addToInicio(6,"Cristiano Oliveira");
   l->mostra();

  l->listainvertida();
  l->mostra();


}
