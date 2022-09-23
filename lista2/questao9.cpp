#include <iostream>
#include <unordered_map>

using namespace std;

int acha_repetido(int v[], int n){
  unordered_map<int, bool> existe;
  
  for(int i = 0; i < n; i++){
    if(!existe[v[i]]){
      existe[v[i]] = true;
    }else{
      return v[i];
    }
  }
  return 0;
}

int main(){
  int v[] = {16,19,22,8,42,39,33,22,29,48};
  int n = 10;

  auto res = acha_repetido(v, n);
  cout << res << endl;
}
