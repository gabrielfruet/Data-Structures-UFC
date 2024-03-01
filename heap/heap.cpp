#include <iostream>
#include <algorithm>
#define PAI(i) (i-1)/2
#define ESQ(i) 2*i+1
#define DIR(i) 2*i+2

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

struct Heap{
    int *v, tam, n;
    Heap(int tam): n(0), tam(tam), v(new int[tam]){}
    ~Heap(){delete[] v;};
    void inserir(int e){
        if(n >= tam) return;
        int i = n;
        v[n++] = e;
        while(v[i] > v[PAI(i)]){
            std::swap(v[i], v[PAI(i)]);
            i = PAI(i);
        }
    }
    void remover(){
        std::swap(v[0], v[--n]);
        int i = 0;
        bool troca = true;
        do{
            int dir = DIR(i), esq = ESQ(i);
            int max, i_max;
            if(dir < n){
                max = std::max(v[esq],v[dir]);
                if(v[i] < max){
                    i_max = max == v[esq] ? esq : dir;
                    std::swap(v[i], v[i_max]);
                    i = i_max;
                }
            }else if(esq < n and v[i] < v[esq]){
                std::swap(v[i], v[esq]);
                i = esq;
            }else{
                troca = false;
            }
        }while(troca);
    }
    int consultar(){
        return v[0];
    }

};


int main(){
    Heap h(100);
    for(int i = 0; i < 10; i++){
        h.inserir(i);
        printf("----\n");
        print_heap(h.v, 0, h.n, 0);
        printf("----\n");
        for(int j = 0; j < h.n; j++)
            printf("%d ", h.v[j]);
        printf("\n");
    }
    for(int i = 0; i < 10; i++){
        printf("v: %d\n", h.consultar());
        h.remover();
    }
    return 0;
}
