#include <iostream>
#include <utility>

using namespace std;

pair<int, int> distante(int v[], int n){
  int min = v[0];
  int max = v[0];

  for(int i = 0; i < n; i++){
    if(min > v[i])
      min = v[i];
    else if(max < v[i])
      max = v[i];
  }

  return pair<int, int>(min, max);
}

int main(){
  int v[] = {16,19,41,8,42,39,33,22,29,48};
  int n = 10;

  auto res = distante(v, n);
  cout << res.first << ", " << res.second << endl;;
}
