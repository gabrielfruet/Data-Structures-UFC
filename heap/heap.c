#include <stdio.h>
#include <stdlib.h>

#define PAI(i) (i-1)/2
#define ESQ(i) 2*i+1
#define DIR(i) 2*i+2

#define HEAP_MAX(h) h[0]

typedef struct heap{
    int* v; 
    int tam, n;
}heap_t;

void troca(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int which_max(int a, int b){
    return b > a ? 2 : 1;
}

heap_t heap_init(int tam){
    heap_t h = {malloc(sizeof(int)*tam), tam, 0};
    return h;
}

void heap_insere(heap_t h, int e){
    if(h.n >= h.tam) return;
    int i = h.n; 
    h.v[h.n++] = e;
    while(h.v[i] < h.v[PAI(i)]){
        troca(h.v + i, h.v + PAI(i));
        i = PAI(i);
    }
}

void heap_remove(heap_t h){
    h.n--;
    troca(h.v, h.v + h.n);
    int i = 0, trocar = 1;
    do{
        int filhos[2] = {ESQ(i), DIR(i)};
        if(filhos[1] < h.n){
            int i_max = which_max(h.v[filhos[0]], h.v[filhos[1]]);
            if(h.v[i] < h.v[filhos[i_max]]){
                troca(h.v + i, h.v + filhos[i_max]);
            }
        }else if(filhos[0] < h.n && h.v[i] < h.v[filhos[0]]){
            troca(h.v + i, h.v + filhos[0]);
        }else{
            trocar = 0;
        }
    }while(trocar);
}

int main(){
    
    return 0;
}
