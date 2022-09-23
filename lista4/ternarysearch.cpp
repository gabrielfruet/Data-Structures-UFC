#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int ternary_search(int n, int* L, int x){
    int start = 0;
    int end = n - 1;
    int midleft;
    int midright;

    while(start < end){
        midleft = start + (end - start)/3;
        midright = end - (end - start)/3;
        
        if(x < L[midleft]){
            end = midleft - 1;
        }
        else if(x == L[midleft]){
            return midleft; 
        }   
        else if(x < L[midright]){
            start = midleft + 1;
            end = midright - 1;
        }
        else if(x == L[midright]){
            return midright; 
        }
        else{
            start = midright + 1;
        }
    }
    return -1;
}

int main (){
    int L[] = {1,3,6,8,10,15,20,21,24,25,28,31,33,40,56,99,102,122,132,133,144,150,180,200,210,222};
    int val;
    cin >> val;
    int i = ternary_search(26, L, val);
    cout << i << endl;
    return 0;
}
