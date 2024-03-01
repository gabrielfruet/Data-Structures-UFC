#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define PAI(i) (i-1)/2
#define ESQ(i) 2*i+1
#define DIR(i) 2*i+2
#define PRINT_VECTOR(v,n) for(int i = 0; i < n || (printf("\n") && 0); i++) printf("%d ", v[i]);

void troca(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void heapify(int* v, int n){
    int h_size = 0;
    while(n > h_size){
        int i = h_size++;
        while(v[i] > v[PAI(i)]){
            troca(v + i, v + PAI(i));
            i = PAI(i);
        }
    }
}

void unheap(int *v, int n){
    int h_size = n;
    while(h_size > 0){
        h_size--;
        troca(v, v + h_size);
        int i = 0;
        while(1){
            if(ESQ(i) >= h_size) break;
            int i_max = ESQ(i);
            if(DIR(i) < h_size && v[DIR(i)] > v[ESQ(i)]){
                i_max = DIR(i);
            }
            if(v[i] > v[i_max]){
                troca(v + i, v + i_max);
                i = i_max;
            }else break;
        }
    }
}

#define W 10
void print_heap(int* v, int i, int n, int spaces){
    if(i < n){
        print_heap(v, DIR(i), n, spaces + W);
        for(int i = 0; i < spaces; i++)
            printf(" ");
        printf("%d\n", v[i]);
        print_heap(v, ESQ(i), n, spaces + W);
    }
}

void hsort(int *v, int n){
    heapify(v, n);
    unheap(v, n);
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
