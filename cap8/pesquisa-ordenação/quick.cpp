#include<stdio.h>
#include<iostream>
using namespace std;
void Quick(int vetor[10], int inicio, int fim);

int main(){
   int vetor[6] = {7, 9, 4, 3,6,1};
   int i;
   Quick(vetor, 0, 5);
   printf("\n2.Vetor ordenado:\n");
   for(i = 0; i <= 5; i++){
      printf("%d ", vetor[i]);
   }
   printf("\n");
}

void Quick(int vetor[10], int inicio, int fim){
        while(fim > 0 && inicio < vetor[fim-1]){
        vetor[fim] = vetor[fim-1];
        fim--;
    }
    vetor[fim] = inicio;
}
