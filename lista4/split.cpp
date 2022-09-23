#include <iostream>
#include <algorithm>

using namespace std;

void split(int n, int* L, int p){
    int i = 1;
    int j = n-1;
    swap(L[0], L[p]);
    while(i <= j){
        while(L[i] <= L[0])
            i++; 
        while(L[j] > L[0])
            j--;
        if(i <= j)
            swap(L[i], L[j]);
    }
    swap(L[i-1], L[0]);
}

int main(){

    int L[] = {10,2,1,26,129,123,12,10,15,25,27,33,35,39,70,57};
    int n = 16;

    split(n, L, 3);

    for(int i = 0; i < n; i++){
        cout << L[i] << ", ";
    }
    
    return 0;
}
