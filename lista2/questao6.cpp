#include <cstdint>
#include <iostream>
#include <ctype.h>

using namespace std;

void adiciona_maior(int v[], int maior){
  v[1] = v[0];
  v[0] = maior;
}

int segundo_maior(int v[], int n){
  int max[2] = {INT32_MIN, INT32_MIN};
  
  int *maior = &max[0];
  int *segundo_maior = &max[1];

  for(int i = 0; i < n; i++){
    if(v[i] > *maior)
      adiciona_maior(max, v[i]);
    else if((*maior - *segundo_maior) > (*maior - v[i]))
      *segundo_maior = v[i];
  }

  return *segundo_maior;
}

int main(){
  int v[] = {122,121,44,1,2,33,12,5,9, 10};

  int n = 10;

  auto res = segundo_maior(v, n);
  cout << res << endl;
}
