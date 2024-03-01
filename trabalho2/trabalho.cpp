// -----------------------------------------------------------------------------
// Universidade Federal do Ceará, Centro de Ciências, Departamento de Computação
// Disciplina: Estruturas de Dados - TI0140 2022.2 T02A
// Professor: Pablo Mayckon Silva Farias
// Trabalho 2
// Interface para Implementação de Dicionário baseado em Árvore AVL.
// Autor: Pablo Mayckon Silva Farias, em 22/11/2022.
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// IDENTIFICAÇÃO DO(A) ESTUDANTE:
//
// NOME:      GABRIEL VASCONCELOS FRUET
// MATRÍCULA: 537618
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Tudo o que está presente na interface abaixo deve ser mantido como está,
// pois é essa interface que será utilizada no programa do professor para a
// realização dos testes.
//
// A realização do trabalho consiste portanto em *completar* a implementação
// abaixo, tornando-a funcional e atendendo aos requisitos deste trabalho.
// -----------------------------------------------------------------------------


#include <new>
#include <exception>
#include <iostream>
using namespace std;
struct DicioAVL{
    typedef double TC;  // Tipo das Chaves
    typedef float  TV;  // Tipo dos Valores

    struct Noh {  TC chave;  TV valor;  int altura;  Noh *esq, *dir;  };

    Noh sent, *raiz;  // "sent": Sentinela.

    // Conforme a declaração acima, a implementação deve usar um nó sentinela,
    // que representará as subárvores varias. Assim, por exemplo, os campos
    // "esq" e "dir" das folhas, ao invés de serem ponteiros nulos, apontarão
    // para "sent"; idem para o ponteiro "raiz", quando a árvore estiver vazia.
    // O campo "altura" da sentinela deve sempre valer zero.

    // --------------------------------------------------------------------------

    // Deve criar um dicionário vazio.

    DicioAVL(){
        raiz = &sent;
        sent.dir = nullptr;
        sent.esq = nullptr;
        sent.altura = 0;
    }

    // --------------------------------------------------------------------------

    // Deve desalocar a árvore AVL.

    ~DicioAVL(){
        desalocar_r(raiz);
    }
    void desalocar_r(Noh* r){
        if(r != &sent){
            desalocar_r(r->esq);
            desalocar_r(r->dir);
            delete r;
        }
    }

    // --------------------------------------------------------------------------

    // Deve inserir a chave "c" e o valor "v" no dicionário, partindo da
    // PRÉ-CONDIÇÃO de que a chave "c" não existe no dicionário -- ou seja,
    // a função não precisa nem deve fazer esse teste.
    //
    // A função deve retornar um ponteiro apontando para o novo nó.
    // Em caso de falha de alocação de memória, a função deve retornar nullptr.
    //
    // ATENÇÃO: a chave deve permanecer no mesmo nó enquanto não for removida
    // -------  do dicionário. Isso significa que, antes de tal remoção,
    //          deve ser possível acessar a chave e seu valor a partir do
    //          ponteiro retornado pela função de inserção.

    Noh* inserir(TC c, TV v){
        try{
            Noh* novo = new Noh{c,v,1,&sent, &sent};
            r_insere(&raiz, novo);
            return novo;
        }catch(std::bad_alloc &e){
            return nullptr;
        }
        
    }

    // --------------------------------------------------------------------------

    // Deve retornar um ponteiro para o nó de chave "c", caso essa chave exista
    // no dicionário; caso a chave não esteja presente, deve retornar nullptr.

    Noh* buscar (TC c){
        Noh* it = raiz;
        sent.chave = c;
        if(it == &sent) return nullptr;
        while(it->chave != c){
            if(c < it->chave){
                it = it->esq;
            }else if(c > it->chave){
                it = it->dir;
            }
        }
        return it == &sent ? nullptr : it;
    }
    void r_insere(Noh** r, Noh* no){
        if(*r == &sent){
            *r = no;
            return;
        }else{
            if(no->chave <= (*r)->chave){
                r_insere(&(*r)->esq, no);
            }else{
                r_insere(&(*r)->dir, no);
            }
        }
        corrigir(r);
    }
    void corrigir(Noh** r){
        (*r)->altura = h(*r);
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
    int h(Noh* p){
        return p->esq->altura > p->dir->altura ? p->esq->altura + 1 : p->dir->altura + 1;
    }
    int b(Noh* r){
        return (r == &sent) ? 0 : r->dir->altura - r->esq->altura;
    }
    void rot_esq(Noh** r){
        Noh* x = *r; 
        Noh* y = (*r)->dir;
        x->dir = y->esq; 
        y->esq = x;
        *r = y;
        x->altura = h(x);
        y->altura = h(y);
    }
    void rot_dir(Noh** r){
        Noh* x = *r; 
        Noh* y = (*r)->esq;
        x->esq = y->dir; 
        y->dir = x;
        *r = y;
        x->altura = h(x);
        y->altura = h(y);
    }

}; // DicioAVL  --------------------------------------------------------------
/*int testar ()
{
    DicioAVL D; int i; DicioAVL::Noh* nohs[9];
    for (i = 0; i <= 8; ++i)
        {
            DicioAVL::Noh* n = D.inserir(i, i/4.0);
            if (n == nullptr or n->chave != i or n->valor != i/4.0) return 1;
            nohs[i] = n;
        }
    for (i = 0; i <= 8; ++i)
        {
            if (D.buscar(i) != nohs[i]) return 2;
        }
    if (D.raiz->chave != 3 or D.raiz->esq->valor != 1/4.0 or
        D.raiz->dir->altura != 3 or D.raiz->esq->esq->esq != &D.sent)
    {
        return 3;
    }
    return 0;
}
int main ()
{
    if (testar() != 0) cout << "Erro nos testes b ́asicos!\n";
    else cout << "Testes b ́asicos realizados com sucesso.\n";
}*/
