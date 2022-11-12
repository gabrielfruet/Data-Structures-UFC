#include <iostream>
#include <iomanip>
#define W 16

using namespace std;

struct ArvAVL{
    struct NoAVL{int elem, h; NoAVL *esq, *dir;};
    static NoAVL* nil;
    NoAVL* raiz = nil;
    void insere(int e){
        NoAVL* no = new NoAVL{e,1,nil,nil};
        r_insere(&raiz, no);
    }
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

        corrigir_insercao(r);
    }
    static void corrigir_insercao(NoAVL** r){
        (*r)->h = h(*r);
        if(fb(*r) > 1){
            if(fb((*r)->dir) < 0){
                rot_dir(&(*r)->dir);
            }
            rot_esq(r);
        }else if(fb(*r) < 1){
            if(fb((*r)->esq) > 0){
                rot_esq(&(*r)->esq);
            }
            rot_dir(r);
        }
    }
    static int h(NoAVL* no){
        return ((no->esq->h > no->dir->h) ? no->esq->h : no->dir->h) + 1;
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
            //cout << "{e:" << r->elem << ", h:" << r->h << "}"<< endl;
            cout << "{e:" << r->elem << ", fb:" << fb(r) << ", h:" << r->h << "}"<< endl;
            //cout << r->elem << "." << endl;
            printarv(r->esq, s + W);
        }
    }
};

ArvAVL::NoAVL* ArvAVL::nil = new ArvAVL::NoAVL{0,0,nullptr,nullptr};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    ArvAVL a; 
    for(int i = 0; i < 127; i++){
        a.insere(i);
        a.print();
        cout << endl;
        for(int j = 0; j < 50; j++) cout << "-";
        cout << endl;
    }
    return 0;
}
