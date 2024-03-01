#include <iostream>
#include <algorithm>
#define PAI(i) (i-1)/2
#define ESQ(i) 2*i+1
#define DIR(i) 2*i+2
#define PRINT_VECTOR(v,n) for(int i = 0; i < n || (printf("\n") && 0); i++) printf("%d ", v[i]);

void hsort(int *v, int n){
    int h_size = 0;
    //Inserindo na heap
    for(;h_size < n; h_size++){
        int i = h_size;
        while(v[i] > v[PAI(i)]){
            std::swap(v[i], v[PAI(i)]);
            i = PAI(i);
        }
    }
    while(h_size > 0){
        h_size--;
        std::swap(v[0], v[h_size]);
        int i = 0;
        while(1){
            //Caso nao exista esq, saia do loop
            if(ESQ(i) >= h_size) break;
            //Senao, o maximo eh por enquanto a esquerda
            int i_max = ESQ(i);
            //Se tiver direita e a esq for menor que a dir, o maximo eh a dir
            if(DIR(i) < h_size and v[DIR(i)] > v[ESQ(i)]){
                i_max = DIR(i);
            }
            //Se o max for maior que i, troca, senao, sai do loop
            if(v[i] < v[i_max]){
                std::swap(v[i], v[i_max]);
                i = i_max;
            }else break;
        }
    }
}

int main(){
    int v[20];
    srand(5);
    for(int i = 0; i < 20; i++){
        v[i] = rand() % 100;
    }
    PRINT_VECTOR(v,20);
    hsort(v, 20);
    PRINT_VECTOR(v,20);
    return 0;
}
