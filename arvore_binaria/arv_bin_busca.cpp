#include <iostream>
#define W 4

using namespace std;

struct ArvBinaria{
    struct NoArv{int elem;NoArv *esq, *dir;};
    NoArv *raiz;
    ArvBinaria(): raiz(nullptr){}
    void insere(int e){
        NoArv** atual = &raiz;
        while(*atual){
            if(e <= (*atual)->elem){
                atual = &(*atual)->esq;
            }else{
                atual = &(*atual)->dir;
            }
        }
        *atual = new NoArv{e, nullptr, nullptr};
    }
    NoArv* busca(int e){
        NoArv* atual = raiz;
        while(atual){
            if(e <= atual->elem){
                atual = atual->esq;
            }else{
                atual = atual->dir;
            }
        }
        return atual;
    }
    bool pertence(int e){
        return busca(e) != nullptr;
    }
    void remove(int e){
        NoArv** atual = &raiz;  
        NoArv* desalocar;
        while((*atual)->elem != e){
            if(e <= (*atual)->elem){
                atual = &(*atual)->esq;
            }else{
                atual = &(*atual)->dir;
            }
        }
        if(*atual == nullptr) return;

        if((*atual)->esq == nullptr){
            desalocar = *atual; 
            (*atual) = (*atual)->dir;
        }else if((*atual)->dir == nullptr){
            desalocar = *atual;
            (*atual) = (*atual)->esq;
        }else{
            NoArv** it_sucessor = &(*atual)->dir;
            while((*it_sucessor)->esq){
                (*it_sucessor) = (*it_sucessor)->esq;
            }
            NoArv* sucessor = *it_sucessor;
            *it_sucessor = (*it_sucessor)->dir;
            desalocar = *atual;
            sucessor->dir = (*atual)->dir;
            sucessor->esq = (*atual)->esq;
            *atual = sucessor;
        }
        delete desalocar;
    }
};

void imprimir_crescente(ArvBinaria::NoArv* r){  
    if(r){
        imprimir_crescente(r->esq);
        cout << r->elem << endl;
        imprimir_crescente(r->dir);
    }
}

void arvore_desalocar(ArvBinaria::NoArv* r){
   if(r){
        arvore_desalocar(r->esq);
        arvore_desalocar(r->dir);
        delete r;
    }
}

void printarv(ArvBinaria::NoArv *r, int s){
    if(r != nullptr){
        printarv(r->dir, s + W);
        for(int i = 0; i < s; i++) {
            cout << " ";
        }
        cout << r->elem << endl;
        printarv(r->esq, s + W);
    }
}

int main(){
    ArvBinaria a;
    for(int i = 0; i < 5; i++){
        a.insere(rand() % 100);
    }
    imprimir_crescente(a.raiz);

    return 0;
}
