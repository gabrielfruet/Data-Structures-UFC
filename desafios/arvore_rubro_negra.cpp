#include <iostream>
#include <ctime>
#include <cmath>    
#define PRINTWRAPPER(content) cout << "------------------------------------" << endl;content;cout << "--------------------------------------------" << endl;
#define RUBRO 0
#define NEGRO 1

/*
 * REGRAS:
 * 1. Todo nó é rubro ou negro.
 * 2. A raiz é negra.
 * 3. Toda folha(nil) é negra.
 * 4. Se um nó é rubro, então seus filhos são negros
 * 5. Para cada nó, todos os caminhos simples dele ate uma folha descendente 
 * possui a mesma quantidade de negros.
 */

using namespace std;

class no_rb{
public:
    int chave;
    int cor;
    no_rb *esq = nullptr;
    no_rb *dir = nullptr;
    no_rb *pai = nullptr;

    no_rb(int chave = 0, int cor = RUBRO): chave(chave), cor(cor){}
};

namespace rb{
    no_rb* nil = new no_rb(0, NEGRO);
}


no_rb* no_insere(no_rb* inserir, no_rb* raiz){
    if(!raiz){
        return inserir;
    }
    no_rb *pai = rb::nil;
    no_rb *atual = raiz;
    while(atual != rb::nil){
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

no_rb* no_minimo(no_rb* no){
    while(no->esq != rb::nil){
        no = no->esq;
    }
    return no;
}

no_rb* no_maximo(no_rb* no){
    while(no->dir != rb::nil){
        no = no->dir;
    }
    return no;
}

no_rb* no_sucessor(no_rb* no){
    if(!no) return rb::nil;

    if(no->dir != rb::nil){
        return no_minimo(no->dir);
    }
    while(no->pai != rb::nil && no->pai->dir == no){
        no = no->pai;
    }
    return no->pai;
}
no_rb* no_antecessor(no_rb* no){
    if(!no) return rb::nil;

    if(no->esq != rb::nil){
        return no_maximo(no->esq);
    }
    while(no->pai != rb::nil && no->pai->esq == no){
        no = no->pai;
    }
    return no->pai;
}

class arvore_rubro_negra{
public:
    no_rb* raiz = rb::nil;
    void insere(int chave){
        no_rb* no = new no_rb(chave);
        no_rb* it_p = rb::nil;
        no_rb* it = raiz;

        while(it != rb::nil){
            it_p = it;
            if(chave <= it->chave){
                it = it->esq;
            }else{
                it = it->dir;
            }
        }
        no->pai = it_p;
        if(it_p == rb::nil){
            raiz = no;
        }else if(chave <= it_p->chave){
            it_p->esq = no;
        }else{
            it_p->dir = no; 
        }
        no->dir = no->esq = rb::nil;
        ajeitar_insercao(no);
    }
    void transplantar(no_rb* a, no_rb* b){
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
    no_rb* buscar(int chave){
        no_rb* it = raiz;
        while(it){
            if(chave < it->chave){
                it = it->esq;
            }else if(chave > it->chave){
                it = it->dir;
            }else{
                return it;
            }
        }
        return rb::nil;
    }
    void remover(no_rb* rm){
        if(rm->esq == rb::nil){
            transplantar(rm, rm->dir);
        }else if(rm->dir == rb::nil){
            transplantar(rm, rm->esq);
        }else{
            no_rb* s = no_minimo(rm->dir);
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
    void ajeitar_insercao(no_rb* no){
    /*
     * REGRAS:
     * 1. Todo nó é rubro ou negro. V
     * 2. A raiz é negra. F
     * 3. Toda folha(nil) é negra. V
     * 4. Se um nó é rubro, então seus filhos são negros F
     * 5. Para cada nó, todos os caminhos simples dele ate uma folha descendente 
     * possui a mesma quantidade de negros. V
     */
        while(no->pai->cor == RUBRO){
            no_rb* pai = no->pai;
            no_rb* avo = no->pai->pai;
            if(avo && pai == avo->esq){
                no_rb* tio = avo->dir;
                if(tio->cor == RUBRO){
                    avo->cor = RUBRO;
                    tio->cor = NEGRO;
                    pai->cor = NEGRO;
                    no = avo;
                }else if(no == pai->dir){
                    no = pai; 
                    rotacao_esquerda(no);
                }

            }else if(avo && pai == avo->dir){
                no_rb* tio = avo->esq;
                if(tio->cor == RUBRO){
                    avo->cor = RUBRO;
                    tio->cor = NEGRO;
                    pai->cor = NEGRO;
                    no = avo;
                }
            }
            
        }
        raiz->cor = NEGRO;
    }
    void rotacao_direita(no_rb* no){
        no_rb* rotar = no->esq;
        no->esq = rotar->dir;
        if(rotar->dir != rb::nil){
            rotar->dir->pai = no;
        }
        rotar->pai = no->pai;
        if(no->pai == rb::nil){
            raiz = rotar;
        }else if(no->pai->dir == no){
            no->pai->dir = rotar;
        }else{
            no->pai->esq = rotar;
        }
        rotar->dir = no;
        no->pai = rotar;
    }
    void rotacao_esquerda(no_rb* no){
        no_rb* rotar = no->dir;
        no->dir = rotar->esq;
        if(rotar->esq != rb::nil){
            rotar->esq->pai = no;
        }
        rotar->pai = no->pai;
        if(no->pai == rb::nil){
            raiz = rotar;
        }else if(no->pai->dir == no){
            no->pai->dir = rotar;
        }else{
            no->pai->esq = rotar;
        }
        rotar->esq = no;
        no->pai = rotar;
    }
};


void imprime_arvore(no_rb* r, int space){
    if(r != rb::nil){
        imprime_arvore(r->dir, space + 5);
        for(int i = 0; i < space; i++){
            cout << " ";
        }
        cout << r->chave << ":" << (r->cor == RUBRO ? "R" : "N") << endl << endl;
        imprime_arvore(r->esq, space + 5);
    }
}


int main(){
    arvore_rubro_negra arv;
    for(int i = 0; i < 10; i += 2){
        arv.insere(i);
        PRINTWRAPPER(imprime_arvore(arv.raiz, 0));
    }
    PRINTWRAPPER(imprime_arvore(arv.raiz, 0));
    no_rb* rotar = arv.buscar(5);
    arv.rotacao_esquerda(rotar);
    PRINTWRAPPER(imprime_arvore(arv.raiz, 0));
}
