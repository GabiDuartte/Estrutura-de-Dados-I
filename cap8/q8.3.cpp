#include <string.h>
#include <iostream>
#define troca(a,b) {int x=a; a=b; b=x;}


using namespace std;

void empurra(int v[], int n){
    for(int i = 0; i < n; i++){
        if(v[i] > v[i+1]){
            troca(v[i], v[i+1];)
        }
    }
}

void bubble_sort(int v[], int n){
    for(int i = 1; i<n-1; i++){
        for(int j = 0; j<n-1; j++){
            if(v[j]>v[j+1]){
                troca(v[j], v[j+1]);
            }
        }
    }
}

int selecionar(int v[], int n){
    int i = 0;
    for(int j = 1; j<n; j++)
        if(v[i]<v[j]) i = j;
    return i;
}

void selection_sort(int v[], int n){
    while(n>1){
        troca(v[selecionar(v,n)], v[n-1]);
        n--;
    }
}

void insere(int x, int v[], int n){
    while(n > 0 && x < v[n-1]){
        v[n] = v[n-1];
        n--;
    }
    v[n] = x;
}

void insertion_sort(int v[], int n){
    for(int i = 0; i < n; i++)
        insere(v[i], v, i);
    }

int linear_search(int x, int v[], int n){
    for(int i = 0; i< n; i++)
        if(x == v[i]){
            return 1;
        }
    return 0;
}

int binary_search(int x, int v[], int n){
    int p = 0;
    int u = n - 1;
    while(p <= u){
        int m = (p+u)/2;
        if(x == v[m]) return 1;
        if(x < v[m]) u = m-1;
        else p = m+1;
    }
    return 0;
}

int main(){
    int lista[] = {1,2,3};
    bubble_sort(lista,4);
}