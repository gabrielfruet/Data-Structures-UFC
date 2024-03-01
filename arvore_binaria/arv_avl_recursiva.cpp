#include <iostream>
#include <iomanip>
#include <climits>
#include <stack>
//#define PRINT_H_B
#define W 6

using namespace std;

struct ArvAVL{
    struct NoAVL{int elem, h; NoAVL *esq, *dir;};
    static NoAVL* nil;
    NoAVL* raiz = nil;
    void insere(int e){r_insere(&raiz, new NoAVL{e, 1, nil, nil});}
    static void r_insere(NoAVL** r, NoAVL* no){
        if(*r == nil){
            *r = no;
            return;
        }else{
            if(no->elem <= (*r)->elem){
                r_insere(&(*r)->esq, no);
            }else{
                r_insere(&(*r)->dir, no);
            }
        }
        corrigir(r);
    }
    void remover(int e){delete r_remocao(&raiz, e);}
    static NoAVL* r_remocao(NoAVL** r, int e){
        if(*r == nil) return nullptr;
        NoAVL* removido;
        if(e < (*r)->elem){
            removido = r_remocao(&(*r)->esq, e);
        }else if(e > (*r)->elem){
            removido = r_remocao(&(*r)->dir, e);
        }else{
            NoAVL* substituto;
            if((*r)->esq == nil){
                substituto = (*r)->dir;
            }else if((*r)->dir == nil){
                substituto = (*r)->esq;
            }else{
                cout << substituto->elem << endl;
                substituto = rm_min_max(r);
                substituto->esq = (*r)->esq;
                substituto->dir = (*r)->dir;
            }
            removido = *r;
            *r = substituto;
        }
        if(*r != nil){
            corrigir(r);
        }
        return removido;
    }
    static void corrigir(NoAVL** r){
        (*r)->h = h(*r);
        if(b(*r) > 1){
            if(b((*r)->dir) < 0){
                rot_dir(&(*r)->dir);
            }
            rot_esq(r);
        }else if(b(*r) < -1){
            if(b((*r)->esq) > 0){
                rot_esq(&(*r)->esq);
            }
            rot_dir(r);
        }
    }
    static NoAVL* rm_min_max(NoAVL** r){
        static int alternator = 0; 
        if((alternator++) % 2 == 0){
            return rm_min(r);
        }else{
            return rm_max(r);
        }
    }
    static NoAVL* rm_min(NoAVL** r){
        while((*r)->esq != ArvAVL::nil){
            r = &(*r)->esq;
        }
        return r_remocao(r, (*r)->elem);
    }
    static NoAVL* rm_max(NoAVL** r){
        while((*r)->dir != ArvAVL::nil){
            r = &(*r)->dir;
        }
        return r_remocao(r, (*r)->elem);
    }
    static int min(NoAVL* r){while(r->esq != nil) r = r->esq;return r->elem;}
    static int max(NoAVL* r){while(r->dir != nil) r = r->dir; return r->elem;}
    static int h(NoAVL* no){return (no->esq->h > no->dir->h) ? no->esq->h + 1: no->dir->h + 1;}
    static int b(NoAVL* no){return (no == nil) ? 0 : no->dir->h - no->esq->h;}
    static void rot_esq(NoAVL** r){
        NoAVL* x = *r; 
        NoAVL* y = (*r)->dir;
        x->dir = y->esq; 
        y->esq = x;
        *r = y;
        x->h = h(x);
        y->h = h(y);
    }
    static void rot_dir(NoAVL** r){
        NoAVL* x = *r; 
        NoAVL* y = (*r)->esq;
        x->esq = y->dir; 
        y->dir = x;
        *r = y;
        x->h = h(x);
        y->h = h(y);
    }
    void print(){printarv(raiz, 0);}
    void printarv(NoAVL *r, int s){
        if(r != nil){
            printarv(r->dir, s + W);
            for(int i = 0; i < s; i++) {
                cout << " ";
            }
            #if defined PRINT_H
                cout << "{e:" << r->elem << ", h:" << r->h << "}"<< endl;
            #elif defined PRINT_H_B
                cout << "{e:" << r->elem << ", fb:" << fb(r) << ", h:" << r->h << "}"<< endl;
            #else
                cout << r->elem << endl;
            #endif
            printarv(r->esq, s + W);
        }
    }
};

ArvAVL::NoAVL* ArvAVL::nil = new ArvAVL::NoAVL{0,0,nullptr,nullptr};

void imprime_decrescente(ArvAVL& arv){
    ArvAVL::NoAVL* atual = arv.raiz, *topo;
    stack<ArvAVL::NoAVL*> p;
    while(atual->dir != ArvAVL::nil){
        p.push(atual);
        atual = atual->dir;
    }
    while(!p.empty()){
        cout << atual->elem << endl;
        if(atual->esq != ArvAVL::nil){
            atual = atual->esq;
            while(atual->dir != ArvAVL::nil){
                p.push(atual);
                atual = atual->dir;
            }
        }else{
            atual = p.top();
            p.pop();
        }
    }
}

void imprime_decrescente_recursivo(ArvAVL::NoAVL* r){
    if(r != ArvAVL::nil){
        imprime_decrescente_recursivo(r->dir);
        cout << r->elem << endl;
        imprime_decrescente_recursivo(r->esq);
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ArvAVL a; 
    int n = 20;
    for(int i = 0; i < n; i++){
        a.insere(i);
        a.print();
        cout << endl;
        for(int j = 0; j < 50; j++) cout << "-";
        cout << endl;
    }
    imprime_decrescente(a);
    return 0;
}
