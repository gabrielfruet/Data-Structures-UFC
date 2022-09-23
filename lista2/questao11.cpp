#include <iostream>
#define MAX 1
#define MIN -1

using namespace std;

int pos_max_min(int v[], int n, int op){
  int indice = 0;

  for(int i = 0; i < n; i++){
    if(op*v[i] > op*v[indice])
      indice = i;
  }
  return indice;
}

int pos_max(int v[], int n){
  return pos_max_min(v, n, MAX);
}

int pos_min(int v[], int n){
  return pos_max_min(v, n, MIN);
}

int min(int v[], int n){
  return v[pos_min(v,n)];
}

int max(int v[], int n){
  return v[pos_max(v,n)];
}

void troca(int* a, int* b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

void troca_menor_maior(int L[], int V[], int n){
  while(min(L, n) < max(V, n)){
    troca(
        &L[pos_min(L, n)],
        &V[pos_max(V, n)]
        );
  }
}


int main(){
  int L[] = {16,19,22,8,42,39,33,22,29,48};
  int V[] = {2,5,17,9,35,19,23,72,91,44};
  int n = 10;


  for(int i = 0; i < n; i++){
    cout << L[i] << ", ";
  }
  cout << endl;

  for(int i = 0; i < n; i++){
    cout << V[i] << ", ";
  }
  cout << endl;
  
}
