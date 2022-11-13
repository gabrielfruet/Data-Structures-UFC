#include <iostream>
#include <iomanip>
#include <climits>
//#define PRINT_H_B
#define W 6

using namespace std;

struct ArvAVL{
    struct NoAVL{int elem, h; NoAVL *esq, *dir;};
    static NoAVL* nil;
    NoAVL* raiz = nil;
    void insere(int e){
        NoAVL* no = new NoAVL{e,1,nil,nil};
        r_insere(&raiz, no);
    }
    void r_insere(NoAVL** r, NoAVL* no){
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
    void remover(int e){
        delete r_remocao(&raiz, e);
    }
    NoAVL* r_remocao(NoAVL** r, int e){
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
                substituto = r_remocao(&(*r)->dir, min_max_alt((*r)->dir));
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
    void corrigir(NoAVL** r){
        (*r)->h = h(*r);
        if(fb(*r) > 1){
            if(fb((*r)->dir) < 0){
                rot_dir(&(*r)->dir);
            }
            rot_esq(r);
        }else if(fb(*r) < -1){
            if(fb((*r)->esq) > 0){
                rot_esq(&(*r)->esq);
            }
            rot_dir(r);
        }
    }
    int min_max_alt(NoAVL* r){
        static int alternator = 0;
        if((alternator++) % 2 == 0){
            return min(r);
        }else{
            return max(r);
        }
    }
    static int min(NoAVL* r){
        while(r->esq != nil) r = r->esq;
        return r->elem;
    }
    static int max(NoAVL* r){
        while(r->dir != nil) r = r->dir;
        return r->elem;
    }
    static int h(NoAVL* no){
        return (no->esq->h > no->dir->h) ? no->esq->h + 1: no->dir->h + 1;
    }
    static int fb(NoAVL* no){
        return (no == nil) ? 0 : no->dir->h - no->esq->h;
    }
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
    void print(){
        printarv(raiz, 0);
    }
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

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ArvAVL a; 
    int n = 20;
    for(int i = 0; i < n; i++){
        a.insere(rand() % n);
        a.print();
        cout << endl;
        for(int j = 0; j < 50; j++) cout << "-";
        cout << endl;
    }
    for(int i = 0; i < n; i++){
        a.remover(i);
        a.print();
        cout << endl;
        for(int j = 0; j < 50; j++) cout << "-";
        cout << endl;
    }
    return 0;
}
