#include <iostream>
#include <algorithm>
#include <type_traits>
#define PAI(i) (i-1)/2
#define ESQ(i) 2*i+1
#define DIR(i) 2*i+2
#define PRINT_VECTOR(v,n) for(int i = 0; i < n || (std::cout << std::endl && 0); i++) std::cout << v[i] << " ";

class Monte{
    public:
    double *v;
    int tam_max, n;
    bool sorting;

    Monte(int tam_max): tam_max(tam_max),n(0), v(new double[tam_max]), sorting(false){}
    Monte(double* v, int tam_vetor): tam_max(tam_vetor), n(0), v(v), sorting(true){
        for(int i = 0; i < tam_vetor; i++) inserir(v[i]);
    }
    ~Monte(){if(!sorting) delete[] v;}
    void inserir(double elem){
        if(n >= tam_max) 
            throw std::runtime_error("Tentativa de insercao em monte cheio.");
        int i = n;
        v[n++] = elem;
        while(v[i] > v[PAI(i)]){
            std::swap(v[i], v[PAI(i)]);
            i = PAI(i);
        }
    }
    void remover(){
        if(n == 0)
            throw std::runtime_error("Tentativa de remocao em monte vazio.");
        std::swap(v[0], v[--n]);
        int i = 0;
        while(1){
            int i_max = 0;
            if(ESQ(i) >= n) break;
            i_max = ESQ(i);
            if(DIR(i) < n && v[DIR(i)] > v[ESQ(i)]){
                i_max = DIR(i);
            }
            if(v[i] < v[i_max]){
                std::swap(v[i], v[i_max]);
                i = i_max;
            }else break;
        }
    }
    void esvaziar_ordenado(){
        for(int i = 0; i < tam_max; i++) remover();
    }
    double consultar(){
        if(n <= 0)
            throw std::runtime_error("Tentativa de consulta em monte vazio.");
        return v[0];
    }
    int capacidade(){return tam_max;};
    int num_elementos(){return n;};
};

#define W 10
void print_heap(double* v, int i, int n, int spaces){
    if(i < n){
        print_heap(v, DIR(i), n, spaces + W);
        for(int i = 0; i < spaces; i++)
            std::cout << " ";
        std::cout << v[i] << std::endl;
        print_heap(v, ESQ(i), n, spaces + W);
    }
}

#define N 100

int main(){
    double v[10] = {6,1,23,57,9,12,3,4,10,23};
    Monte m(v,10);
    m.esvaziar_ordenado();
    PRINT_VECTOR(v,10);
    return 0;
}
