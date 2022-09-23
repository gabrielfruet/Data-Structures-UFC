#include <iostream>

using namespace std;

void adiciona_topo(int v[], int &n, int topo){
  v[n] = topo;
  n++;
}

void imprime_topos_crescentes(int v[], int n){
  int topos[n/3];
  int topos_tam = 0;

  for(int i = 1; i < n - 1; i++){
    if(v[i-1] < v[i] && v[i] > v[i+1]){
      adiciona_topo(topos, topos_tam, v[i]);
      if(topos[topos_tam - 1] < topos[topos_tam - 2]) 
        break;
    }
  }

  for(int i = 0; i < topos_tam; i++){
    cout << topos[i] << ", ";
  }
  cout << endl;
}

int main(){
  int v[] = {16,19,41,8,42,39,33,22,29,48};
  int n = 10;

  imprime_topos_crescentes(v, n);
}
