#include <iostream>
#include <ctime>
#include <cmath>    

using namespace std;

class no_arvore{
public:
    int chave;
    no_arvore *esq = nullptr;
    no_arvore *dir = nullptr;
    no_arvore *pai = nullptr;

    no_arvore(int chave = 0): chave(chave){}
};


no_arvore* no_insere(no_arvore* inserir, no_arvore* raiz){
    if(!raiz){
        return inserir;
    }
    no_arvore *pai = nullptr;
    no_arvore *atual = raiz;
    while(atual){
        pai = atual; 
        if(inserir->chave <= atual->chave){
            atual = atual->esq;
        }else{
            atual = atual->dir;
        }
    }
    atual = inserir;
    atual->pai = pai;
    if(inserir->chave <= pai->chave){
        pai->esq = atual;
    }else{
        pai->dir = atual;
    }
    return raiz;
}

no_arvore* no_minimo(no_arvore* no){
    while(no->esq){
        no = no->esq;
    }
    return no;
}

no_arvore* no_maximo(no_arvore* no){
    while(no->dir){
        no = no->dir;
    }
    return no;
}

no_arvore* no_sucessor(no_arvore* no){
    if(!no) return nullptr;

    if(no->dir){
        return no_minimo(no->dir);
    }
    while(no->pai && no->pai->dir == no){
        no = no->pai;
    }
    return no->pai;
}
no_arvore* no_antecessor(no_arvore* no){
    if(!no) return nullptr;

    if(no->esq){
        return no_maximo(no->esq);
    }
    while(no->pai && no->pai->esq == no){
        no = no->pai;
    }
    return no->pai;
}

class arvore_binaria{
public:
    no_arvore* raiz;
    void insere(int chave){
        if(!raiz){
            raiz = new no_arvore(chave);
        }
        no_arvore *pai = nullptr;
        no_arvore *atual = raiz;
        while(atual){
            pai = atual; 
            if(chave <= atual->chave){
                atual = atual->esq;
            }else{
                atual = atual->dir;
            }
        }
        atual = new no_arvore(chave);
        atual->pai = pai;
        if(chave <= pai->chave){
            pai->esq = atual;
        }else{
            pai->dir = atual;
        }
    }
    void transplantar(no_arvore* a, no_arvore* b){
        if(!a->pai){
            raiz = b;
        }else if(a->pai->esq == a){
            a->pai->esq = b;
        }else{
            a->pai->dir = b;
        }

        if(b != NULL){
            b->pai = a->pai;
        }
    }
    no_arvore* buscar(int chave){
        no_arvore* it = raiz;
        while(it){
            if(chave < it->chave){
                it = it->esq;
            }else if(chave > it->chave){
                it = it->dir;
            }else{
                return it;
            }
        }
        return nullptr;
    }
    void remover(no_arvore* rm){
        if(rm->esq == nullptr){
            transplantar(rm, rm->dir);
        }else if(rm->dir == nullptr){
            transplantar(rm, rm->esq);
        }else{
            no_arvore* s = no_minimo(rm->dir);
            if(s->pai != rm){
                transplantar(s, s->dir);
                s->dir = rm->dir;
                s->dir->pai = s;
            }
            transplantar(rm, s);
            s->esq = rm->esq;
            s->esq->pai = s;
        }
    }
};


void imprime_arvore(no_arvore* r, int space){
    if(r){
        imprime_arvore(r->dir, space + 5);
        for(int i = 0; i < space; i++){
            cout << " ";
        }
        cout << r->chave << endl << endl;
        imprime_arvore(r->esq, space + 5);
    }
}


int main(){
    arvore_binaria arv;
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        arv.insere(rand() % 100);
    }
    arv.insere(7);
    imprime_arvore(arv.raiz, 0);
    no_arvore *it = no_minimo(arv.raiz);
    while(it){
        cout << it->chave << " ";
        it = no_sucessor(it);
    }
    no_arvore *it2 = no_maximo(arv.raiz);
    cout << endl;
    while(it2){
        cout << it2->chave << " ";
        it2 = no_antecessor(it2);
    }
    cout << endl;
    arv.remover(arv.buscar(7));
    imprime_arvore(arv.raiz, 0);
}
