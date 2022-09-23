#include <iostream>

using namespace std;

void imprime_topos(int v[], int n){
  for(int i = 1; i < n - 1; i++){
    if(v[i-1] < v[i] && v[i] > v[i+1]) 
      cout << v[i] << ", ";
  }
  cout << endl;
}

int main(){
  int v[] = {16,19,41,8,42,39,33,22,29,48};
  int n = 10;

  imprime_topos(v, n);
}
