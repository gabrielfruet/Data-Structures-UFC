#include <iostream>
#include <climits>

using namespace std;

struct NoDE{ int chave; NoDE* prox, *ant; };

class DequeInt{
public:
    NoDE *esq, *dir;

    int consultar_esq(){
        return esq->prox->chave;
    }
    int consultar_dir(){
        return dir->ant->chave;
    }
    DequeInt(){
        esq = new NoDE{0, nullptr, nullptr};
        dir = new NoDE{0, nullptr, nullptr};

        esq->prox = dir;
        dir->ant = esq;
    }
    ~DequeInt(){
        NoDE* it = esq, *remover;
        while(it->prox){
            remover = it;
            it = it->prox;
            delete remover;
        }
    }

    void inserir_esq(int e){
        NoDE* novo = new NoDE{e, nullptr, nullptr};
        novo->prox = esq->prox;
        novo->ant = esq;
        novo->prox->ant = novo;
        esq->prox = novo;
    }
    void inserir_dir(int e){
        NoDE* novo = new NoDE{e, nullptr, nullptr};
        novo->ant = dir->ant;
        novo->prox = dir;
        novo->ant->prox = novo;
        dir->ant = novo;
    }

    void remover_esq(){
        if(vazio()) return;
        NoDE* removido = esq->prox;
        esq->prox = esq->prox->prox;
        esq->prox->ant = esq;
        delete removido;
    }

    void remover_dir(){
        if(vazio()) return;
        NoDE* removido = dir->ant;
        dir->ant = dir->ant->ant;
        dir->ant->prox = dir;
        delete removido;
    }

    bool vazio(){
        return esq->prox == dir;
    }
    void imprime(){
        NoDE* it = esq->prox;
        cout << "-------" << endl;
        while(it != dir){
            cout << it->chave << ", ";
            it = it->prox;
        }
        cout << endl << "-------" << endl;
    }
};

struct No{ double chave; No* prox; };

class ConjuntoDouble{
    No* localiza(int e){
        No* it = sent;
        nil->chave = e;
        while(it->prox->chave != e){
            it = it->prox;
        }
        return it;
    }
public:
    No* sent, *nil;
    ConjuntoDouble(){
        nil = new No{0, nullptr};
        sent = new No{0, nil};
    }
    bool pertence(double e){
        return localiza(e)->prox != nil;
    }
    void inserir_sem_testar(double e){
        No* novo = new No{e, nil};
        novo->prox = sent->prox;
        sent->prox = novo;
    }
    void inserir(double e){
        if(!pertence(e)){
            inserir_sem_testar(e);
        }
    }
    void remover(double e){
        No* remover = localiza(e);
        if(remover->prox != nil){
            No* removido = remover->prox;
            remover->prox = remover->prox->prox;
            delete removido;
        }
    }
    ~ConjuntoDouble(){
        No* it = sent, *remover;
        while(it){
            remover = it;
            it = it->prox;
            delete remover;
        }
    }
    void imprime(){
        cout << "------" << endl;
        No* it = sent;
        while(it->prox != nil){
            cout << it->prox->chave << ", ";
            it = it->prox;
        }
        cout << endl << "------" << endl;
    }
};

class ConjuntoDoubleSentinela{
    No* localiza(int e){
        No* it = sent;
        sent->chave = e;
        while(it->prox->chave != e){
            it = it->prox;
        }
        return it;
    }
public:
    No* sent;
    ConjuntoDoubleSentinela(){
        sent = new No{0, nullptr};
        sent->prox = sent;
    }
    bool pertence(double e){
        return localiza(e)->prox != sent;
    }
    void inserir_sem_testar(double e){
        No* novo = new No{e, sent};
        novo->prox = sent->prox;
        sent->prox = novo;
    }
    void inserir(double e){
        if(!pertence(e)){
            inserir_sem_testar(e);
        }
    }
    void remover(double e){
        No* remover = localiza(e);
        if(remover->prox != sent){
            No* removido = remover->prox;
            remover->prox = remover->prox->prox;
            delete removido;
        }
    }
    ~ConjuntoDoubleSentinela(){
        No* it = sent->prox, *remover;
        while(it != sent){
            remover = it;
            it = it->prox;
            delete remover;
        }
        delete sent;
    }
    void imprime(){
        cout << "------" << endl;
        No* it = sent;
        while(it->prox != sent){
            cout << it->prox->chave << ", ";
            it = it->prox;
        }
        cout << endl << "------" << endl;
    }
};

class DequeIntCircular{
public:
    NoDE sent;

    int consultar_esq(){
        return sent.prox->chave;
    }
    int consultar_dir(){
        return sent.ant->chave;
    }
    DequeIntCircular(){
        sent.prox = sent.ant = &sent;
        sent.chave = INT_MAX;
    }
    ~DequeIntCircular(){
    }

    void inserir_dir(int e){
        NoDE* novo = new NoDE{e, nullptr, nullptr};
        novo->ant = sent.ant;
        novo->prox = &sent;
        novo->ant->prox = novo;
        sent.ant = novo;
    }
    void inserir_esq(int e){
        NoDE* novo = new NoDE{e, nullptr, nullptr};
        novo->prox = sent.prox;
        novo->ant = &sent;
        novo->prox->ant = novo;
        sent.prox = novo;
    }

    void remover_esq(){
        if(vazio()) return;
        NoDE* removido = sent.prox;
        sent.prox = sent.prox->prox;
        sent.prox->ant = &sent;
        delete removido;
    }

    void remover_dir(){
        if(vazio()) return;
        NoDE* removido = sent.ant;
        sent.ant = sent.ant->ant;
        sent.ant->prox = &sent;
        delete removido;
    }

    bool vazio(){
        return sent.prox == &sent;
    }
    void imprime(){
        NoDE* it = sent.prox;
        cout << "-------" << endl;
        while(it != &sent){
            cout << it->chave << ", ";
            it = it->prox;
        }
        cout << endl << "-------" << endl;
    }
};


int main()
{
    DequeInt d;
    cout << "DEQUE: " << endl;
    cout << "Vazio: " << d.vazio() << endl;
    d.inserir_dir(1);
    d.imprime();
    cout << "Vazio: " << d.vazio() << endl;
    d.inserir_dir(2);
    cout << "Vazio: " << d.vazio() << endl;
    d.imprime();
    cout << "Vazio: " << d.vazio() << endl;
    d.inserir_dir(3);
    d.imprime();
    d.inserir_dir(4);
    d.imprime();
    d.inserir_esq(4);
    d.imprime();
    d.inserir_esq(3);
    d.imprime();
    d.inserir_esq(2);
    d.imprime();
    d.inserir_esq(1);
    d.imprime();
    d.remover_esq();
    d.imprime();
    d.remover_esq();
    d.imprime();
    d.remover_esq();
    d.imprime();
    d.remover_dir();
    d.imprime();
    d.remover_dir();
    d.imprime();
    d.remover_dir();
    d.imprime();
    d.remover_dir();
    d.imprime();
    d.remover_dir();
    d.imprime();
    d.remover_esq();
    d.imprime();
    d.remover_esq();
    d.imprime();
    cout << "Vazio: " << d.vazio() << endl;
    cout << "CONJUNTO: " << endl;
    double nums[14] = {1.1, 2.3 , 2.3, 7.5, 8, 7.5, 9.0, 9.0, 9.0, 3.0, 3.3, 4.2, 5.5, 7.8};
    ConjuntoDouble c;
    for(double e: nums){
        c.inserir(e);
        c.imprime();
    }

    ConjuntoDouble c2;
    for(double e: nums){
        c2.inserir(e);
        c2.imprime();
    }
    DequeIntCircular dc;
    cout << "DEQUE INT CIRCULAR: " << endl;
    for(int i = 0; i < 10; i++){
        dc.inserir_dir(i);
        dc.imprime();
    }
    for(int i = 0; i < 10; i++){
        dc.inserir_esq(i);
        dc.imprime();
    }
    for(int i = 0; i < 10; i++){
        dc.remover_dir();
        dc.imprime();
    }
    for(int i = 0; i < 10; i++){
        dc.remover_esq();
        dc.imprime();
    }
    return 0;
}
