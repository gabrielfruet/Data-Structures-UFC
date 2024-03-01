#include <iostream>
#include <algorithm>
#include <exception>
#define N 20
#define ll long long
#define vec vector<int>
#define iosync ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;

struct Noh{
    int elem;
    Noh *esq, *dir;
};

int bin_insercao(Noh** r, int* v, int ini, int fim){
    if(ini >= fim) return 0;
    try{
        int m = (ini+fim)/2, err = 0;
        *r = new Noh{v[m], nullptr, nullptr};
        err = bin_insercao(&(*r)->esq, v, ini, m);
        if(err) return 1;
        err = bin_insercao(&(*r)->dir, v, m+1, fim);
        if(err) return 1;
        else return 0;
    }catch(exception &e){
        return 1;
    }
}

void desalocar(Noh* r){
    if(r){
        desalocar(r->esq);
        desalocar(r->dir);
        delete r;
    }
}

Noh* converter(int* v, int n){
    int err = 0;
    Noh* raiz = nullptr;
    err = bin_insercao(&raiz, v, 0, n);
    if(err) return nullptr;
    else return raiz;
}

void imprime_arvore(Noh* r, int space){
    if(r){
        imprime_arvore(r->dir, space + 5);
        for(int i = 0; i < space; i++){
            cout << " ";
        }
        cout << r->elem << endl << endl;
        imprime_arvore(r->esq, space + 5);
    }
}

int main(){
    int v[N];
    for(int i = 0; i < N; i++){
        v[i] = i;
    }
    Noh* raiz = converter(v, N);
    imprime_arvore(raiz, 0);
    
    return 0;
}

