#include <stdio.h>
#define PAI(i) (i-1)/2
#define ESQ(i) 2*i + 1
#define DIR(i) 2*i + 2
#define PRINT_VECTOR(v,n) for(int i = 0; i < n || (printf("\n") && 0); i++) printf("%d ", v[i]);

void troca(int* a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int ultimo_nivel_ordenado(int *v, int n){
    int i = 0;
    while(ESQ(i) < n) i = ESQ(i);
    short ordenado = 1;
    for(;i + 1 < n; i++){
        if(v[i] > v[i+1]){
            ordenado = 0;
            break;
        }
    }
    return ordenado;
}


void heapify(int* v, int n){
    int h_size = 0;
    for(;h_size < n; h_size++){
        int i = h_size;
        while(v[i] > v[PAI(i)]){
            troca(v + i, v + PAI(i));
            i = PAI(i);
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
int main(){
    int v[] = {16,15,14,13,12,11,10,9,8,7,6,5,4,3,2};
    int n = 15;
    PRINT_VECTOR(v,n);
    heapify(v, n);
    PRINT_VECTOR(v,n);
    print_heap(v,0,n,0);
    printf(ultimo_nivel_ordenado(v,n) ? "SIM\n" : "NAO\n");
    return 0;
}
