#include <iostream>
#include <algorithm>

using namespace std;

void bubble(int n, int *L){
    bool sorted;
    do{
        sorted = true;
        for(int i = 0; i < n-1; i++){
            if(L[i] > L[i+1]){
                swap(L[i], L[i+1]);
                sorted = false;
            }
        }
    }while(!sorted);
}

void insertion(int n, int* L){
    for(int i = 1; i < n; i++){
        for(int j = i; j >= 0; j--){
            if(L[j] < L[j-1]){
                swap(L[j], L[j-1]);
            }else break;
        }
    }
}

void selection(int n, int *L){
    for(int i = 0; i < n; i++){
        int pos_of_smaller = i;
        for(int j = i; j < n; j++){
            if(L[j] < L[pos_of_smaller]){
                pos_of_smaller = j;
            }
        }
        swap(L[i], L[pos_of_smaller]);
    }
}

void printer(int &el){
    cout << el << ", ";
}

int main (){
    int L[] = {1,7,1029,3,51,82,12,33,45,10,201,29377,1726};
    selection(14, L);
    for_each(L, L+14, printer);
    return 0;
}
