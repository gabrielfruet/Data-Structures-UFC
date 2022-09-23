#include <iostream>

using namespace std;

int count_inverses(int n, int* L){
    int count = 0;

    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(L[i] > L[j])
                count++;

    return count;
}

int main(){
    int L[] = {1,5,3,7,4};
    int r = count_inverses(5, L);

    cout << r << endl;

    return 0;
}
