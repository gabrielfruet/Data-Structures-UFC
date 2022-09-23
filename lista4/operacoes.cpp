#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

void insert(int n, int& tam, int* L, int x){
    if(tam >= n) return;
    L[tam++] = x;
    for(int i = tam; L[i-1] > L[i];i--){
        swap(L[i], L[i-1]);
    }
}

void remove(int n, int& tam, int* L, int x){
    int s = 0, e = tam-1, m;
    bool found = false;
    while(s < e || !found){
        m = (s + e)/2;
        if(x > L[m]){
            s = e + 1;
        }else if(x < L[m]){
            e = s - 1;
        }else{
            found = true;
        }
    }
}

int main(){
    int L[20] = {1,5,9,10,12,13,15,19,22};
    int tam = 9;
    int n = 20;

    for_each(L, L+20, [](int& el){
            cout << el << ", ";
            });
    cout << endl;

    insert(n, tam, L, 33);
    insert(n, tam, L, 18);

    for_each(L, L+20, [](int& el){
            cout << el << ", ";
            });
    cout << endl;

    remove(n, tam, L, 33);
    
    for_each(L, L+20, [](int& el){
            cout << el << ", ";
            });

    return 0;
}
