#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

pair<int, int> acha_soma(int v[], int n, int soma){
  unordered_map<int, bool> mapeados;

  for(int i = 0; i < n; i++){
    int complemento = abs(soma - v[i]);
    if(mapeados[complemento] == true){
      return pair<int, int>(complemento, v[i]);
    }
    mapeados[v[i]] = true;
  }
  return pair<int, int>(0, 0);
}

int main(){
  int v[] = {16,19,22,8,42,39,33,22,29,48};
  int n = 10;

  auto res = acha_soma(v, n, 47);
  cout << res.first << ", " << res.second << endl;
}
