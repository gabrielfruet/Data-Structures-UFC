#include <iostream>
#include <algorithm>

using namespace std;

class inverse_three{
public:
    static bool greather_than(int a, int b){return cmp_inverse_3(a,b) > 0;}
    static bool equal(int a, int b){return cmp_inverse_3(a,b) == 0;}
    static bool less_than(int a, int b){return cmp_inverse_3(a,b) < 0;}
private:
    static int cmp_inverse_3(int a, int b){
        if(a/3 == b/3){
            return (b%3) - (a%3);
        }
        return a - b;
    }
};

void bubble(int n, int *L){
    bool sorted;
    do{
        sorted = true;
        for(int i = 0; i < n-1; i++){
            if(inverse_three::greather_than(L[i], L[i+1])){
                swap(L[i], L[i+1]);
                sorted = false;
            }
        }
    }while(!sorted);
}

int main(){
    int L[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int n = 21;
    bubble(n, L);
    for_each(L, L+n, [](int& el){
            cout << el << ", ";
            });
    return 0;
}
