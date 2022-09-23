#include <iostream>
#include <algorithm>

using namespace std;
void printer(int& el){cout << el << ", ";}

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

int* merge(int n, int* L){
    int *R =  new int[n];
    int inserted = 0;
    int i = 0, j = n/2;

    while(inserted < n){
        while(i < n/2 && j < n && L[i] <= L[j]){
            R[inserted++] = L[i++];
        }
        while(i < n/2 && j < n && L[j] <= L[i]){
            R[inserted++] = L[j++];
        }
        while(i < n/2 && j >= n){
            R[inserted++] = L[i++];
        }
        while(i >= n/2 && j < n){
            R[inserted++] = L[j++];
        }
    }
    return R;
}

/*
 * Numero de execucoes de instrucoes: ((n/2)^2)/2 + ((n/2)^2)/2 + 4n = n(n/4 + 4);
 */
int* half(int n, int* L){
    bubble(n/2, L);
    bubble(n/2, L+n/2);
    for_each(L, L+n, printer);
    cout << endl;
    return merge(n, L);
}


int main(){
    int L[] = {1,5,1202,381,273,15,3,1,23,5,1,69,263,18};
    int n = 14;
    int *R = half(n, L);
    for_each(R, R+n, printer);
    return 0;
}
