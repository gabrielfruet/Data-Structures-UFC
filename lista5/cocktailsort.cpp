#include <iostream>
#include <algorithm>

using namespace std;

bool sweep_to_right(int n, int* L){
    int swept = 0;
    for(int i = n-1; i >= 0; i--){
        if(L[i] < L[i-1]){
            swap(L[i], L[i-1]);
            swept++;
        }
    }
    return swept == 0;
}

bool sweep_to_left(int n, int* L){
    int swept = 0;
    for(int i = 0; i < n-1; i++){
        if(L[i] > L[i+1]){
            swap(L[i], L[i+1]);
            swept++;
        }
    }
    return swept == 0;
}
void cocktail(int n, int* L){
    bool sorted;
    do{
        sorted = sweep_to_right(n, L) || sweep_to_left(n, L);
    }while(!sorted);
}

int main(){
    int L[] = {1,5,1202,381,273,15,3,1,23,5,1,69,263,18};
    int n = 14;
    cocktail(n, L);
    for_each(L, L+n, [](int& el){
            cout << el << ", ";
            });
    return 0;
}
