#include <iostream>
#include <algorithm>

using namespace std;

void insertion_even(int n, int* L){
    for(int i = 3; i < n; i += 2){
        for(int j = i; j >= 0; j -= 2){
            if(L[j] < L[j-2]){
                swap(L[j], L[j-2]);
            }else break;
        }
    }
}
 
void bubble_odd(int n, int *L){
    bool sorted;
    do{
        sorted = true;
        for(int i = 0; i < n-1; i+=2){
            if(L[i] > L[i+2]){
                swap(L[i], L[i+2]);
                sorted = false;
            }
        }
    }while(!sorted);
}

int main(){

    int L[] = {1,3,7,12,3,61,3,2,1,22,1234,155,681, 15};
    int n = 14;
    bubble_odd(n, L);
    insertion_even(n, L);

    for_each(L, L+14, [](int& el){
            cout << el << ", ";
            });
    return 0;
}       
