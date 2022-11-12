#include <iostream>
#include <algorithm>
#define W 10

using namespace std;

struct ArvAVL{
    struct NoAVL{int elem, h;NoAVL *esq, *dir, *pai;};
    NoAVL *raiz, *nil;
    ArvAVL(){
        nil = new NoAVL{0,0,nullptr,nullptr,nullptr};
        raiz = nil;
    }
    ~ArvAVL(){arvore_desalocar(raiz);}
    void insere(int e){
        NoAVL* pai = nil;
        NoAVL** atual = &raiz;
        while(*atual != nil){
            pai = *atual;
            if(e <= (*atual)->elem){
                atual = &(*atual)->esq;
            }else{
                atual = &(*atual)->dir;
            }
        }
        *atual = new NoAVL{e, 1, nil, nil, pai};
        corrigir_insercao(*atual);
    }
    int altura(NoAVL* x){
        return x == nil ? 0 : max(x->esq->h, x->dir->h) + 1;
    }
    void corrigir_insercao(NoAVL* inserido){
        NoAVL* it = inserido->pai;
        int h, fb;
        while(it != nil){
            it->h = max(it->esq->h, it->dir->h) + 1;
            if(fator(it) == 2){
                if(fator(it->esq) == -1){
                    print();
                    rot_esq(it->esq);
                    cout << "----------------------ROT_ESQ------------------" << endl;
                    cout << it->elem << endl;
                    print();
                    cout << "-----------------------------------------------" << endl;
                }
                print();
                rot_dir(it);
                cout << "----------------------ROT_DIR------------------" << endl;
                cout << it->elem << endl;
                print();
                cout << "-----------------------------------------------" << endl;
            }else if(fator(it) == -2){
                if(fator(it->dir) == 1){
                    print();
                    rot_dir(it->dir);
                    cout << "----------------------ROT_DIR------------------" << endl;
                    cout << it->elem << endl;
                    print();
                    cout << "-----------------------------------------------" << endl;
                }
                print();
                rot_esq(it);
                cout << "----------------------ROT_ESQ------------------" << endl;
                cout << it->elem << endl;
                print();
                cout << "-----------------------------------------------" << endl;
            }
            it = it->pai;
        }
    }
    static int fator(NoAVL* no){
        return no->esq->h - no->dir->h;
    }
    NoAVL* busca(int e){
        NoAVL* atual = raiz;
        while(atual != nil){
            if(e <= atual->elem){
                atual = atual->esq;
            }else{
                atual = atual->dir;
            }
        }
        return atual;
    }
    bool pertence(int e){
        return busca(e) != nil;
    }
    void remove(int e){
        NoAVL* pai = nil;
        NoAVL** atual = &raiz;  
        NoAVL* desalocar;
        while((*atual)->elem != e){
            pai = *atual;
            if(e <= (*atual)->elem){
                atual = &(*atual)->esq;
            }else{
                atual = &(*atual)->dir;
            }
        }
        if(*atual == nil) return;

        if((*atual)->esq == nil){
            desalocar = *atual; 
            (*atual) = (*atual)->dir;
        }else if((*atual)->dir == nil){
            desalocar = *atual;
            (*atual) = (*atual)->esq;
        }else{
            NoAVL** it_sucessor = &(*atual)->dir;
            while((*it_sucessor)->esq){
                (*it_sucessor) = (*it_sucessor)->esq;
            }
            NoAVL* sucessor = *it_sucessor;
            *it_sucessor = (*it_sucessor)->dir;
            desalocar = *atual;
            sucessor->dir = (*atual)->dir;
            sucessor->esq = (*atual)->esq;
            *atual = sucessor;
        }
        delete desalocar;
    }
    void arvore_desalocar(NoAVL* r){
        if(r != nil){
            arvore_desalocar(r->esq);
            arvore_desalocar(r->dir);
            delete r;
        }
    }
    void rot_esq(NoAVL* x){
        NoAVL* y = x->dir;
        NoAVL* p = x->pai;
        if(y->esq != nil){
            y->esq->pai = x;
        }
        x->dir = y->esq;

        y->esq = x;
        y->esq->pai = y;

        if(p == nil){
            this->raiz = y;
        }else if(p->esq == x){
            p->esq = y; 
        }else{
            p->dir = y; 
        }
        y->pai = p;

        x->h = altura(x);
        y->h = altura(y);
        p->h = altura(p);
    }
    void rot_dir(NoAVL* x){
        NoAVL* y = x->esq;
        NoAVL* p = x->pai;
        if(y->dir != nil){
            y->dir->pai = x;
        }
        x->esq = y->dir;

        y->dir = x;
        y->dir->pai = y;

        if(p == nil){
            this->raiz = y;
        }else if(p->esq == x){
            p->esq = y; 
        }else{
            p->dir = y; 
        }
        y->pai = p;

        x->h = altura(x);
        y->h = altura(y);
        p->h = altura(p);
    }
    void print(){
        printarv(raiz, 0);
    }
    void printarv(NoAVL *r, int s){
        if(r != nil){
            printarv(r->dir, s + W);
            for(int i = 0; i < s; i++) {
                cout << " ";
            }
            //cout << "{e:" << r->elem << ", h:" << r->h << "}"<< endl;
            cout << r->elem << endl;
            printarv(r->esq, s + W);
        }
    }
};

void imprimir_crescente(ArvAVL::NoAVL* r){  
    if(r){
        imprimir_crescente(r->esq);
        cout << r->elem << endl;
        imprimir_crescente(r->dir);
    }
}
void insere_zig_zag(ArvAVL& a, int l, int r){
    if(l < r){
        int m = (l+r)/2;
        a.insere(m);
        insere_zig_zag(a, m + 1, r);
        insere_zig_zag(a, l, m - 1);
    }
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ArvAVL a;
    int n = 200;
    int m = 1024;
    insere_zig_zag(a, 0, 32);
    return 0;
}
