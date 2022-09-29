#include <iostream>

using namespace std;

class No {
    public:
    int chave;
    No* prox;
    No(int chave = 0, No* prox = NULL):chave(chave), prox(prox){}
};

No* nova_lista_encadeada(int n){
    if(n <= 0) return NULL;

    No* cabeca = new No();
    No* it = cabeca;

    for(int i = 1; i < n; i++){
        it->prox = new No();
        it = it->prox;
    }

    return cabeca;
}

void deleta_lista_encadeada(No* cabeca){
    No* it = cabeca;
    No* removido;
    while(it){
        removido = it; 
        it = it->prox;
        delete removido;
    }
}

void imprime_nao_recursivo(No* cabeca){
    No* it = cabeca;
    while(it){
        cout << it->chave << " -> ";
        it = it->prox;
    }
}

void imprime_recursivo(No* cabeca){
    if(!cabeca) return;

    cout << cabeca->chave << " -> ";
    imprime_recursivo(cabeca->prox);
}

class NoDE{
public:
    int chave;
    NoDE* prox;
    NoDE* ant;
    NoDE(int chave = 0, NoDE* prox = NULL, NoDE* ant = NULL): chave(chave), prox(prox), ant(ant){}
};

class ListaDE{
public:
    NoDE* sentinela = new NoDE();
    int cont = 0;

    void inserir(NoDE* no, int pos){
        NoDE* it = sentinela; 
        int chave = no->chave;
        while(it->prox && it->prox->chave < chave){
            it = it->prox; 
        }
        no->prox = it->prox;
        it->prox = no;
    }

    NoDE* remover(int chave){
        NoDE* it = sentinela;
        while(it->prox && it->prox->chave != chave){
            it = it->prox;
        }
        NoDE* removido = it->prox;
        it->prox = it->prox->prox;
        return removido;
    }
};

class NoMat{
public:
    int chave;
    NoMat* direita;
    NoMat* embaixo;
    NoMat(
        int chave = 0, 
        NoMat* direita = NULL,
        NoMat* embaixo = NULL
    ): 
        chave(chave),
        direita(direita),
        embaixo(embaixo)
    {}
};

NoMat* matriz_linha(int n){
    NoMat* cabeca = new NoMat();
    NoMat* it = cabeca;
    for(int i = 1; i < n; i++){
        it->direita = new NoMat();
        it = it->direita;
    }
    return cabeca;
}

void imprime_matriz(NoMat* cabeca){
    NoMat* it_linha = cabeca;
    cout << "[" << endl;
    while(it_linha){
        NoMat* it_coluna = it_linha;
        cout << "[ ";
        while(it_coluna){
            cout << it_coluna->chave << " ";
            it_coluna = it_coluna->direita;
        }
        cout << "]" << endl;
        it_linha = it_linha->embaixo;
    }
    cout << "]" << endl;
}

void costura_matriz(NoMat* cima, NoMat* baixo){
    NoMat* it_cima = cima;
    NoMat* it_baixo = baixo;
    while(it_cima->embaixo){
        it_cima = it_cima->embaixo;
    }

    while(it_cima && it_baixo){
        it_cima->embaixo = it_baixo;
        
        it_cima = it_cima->direita;
        it_baixo = it_baixo->direita;
    }
}

int procura_na_matriz(NoMat* cabeca, int linha, int coluna){
    NoMat* it_linha = cabeca;
    NoMat* it_coluna = cabeca;
    for(int i = 0; i <= linha && it_linha; i++){
        it_coluna = it_linha;
        for(int j = 0; j < coluna && it_coluna; j++){
            it_coluna = it_coluna->direita;
        }
        it_linha = it_linha->embaixo;
    }
    return it_coluna->chave;
}

int main(){
    NoMat* a = matriz_linha(10);
    NoMat* b = matriz_linha(10);
    imprime_matriz(a);
    imprime_matriz(b);
    costura_matriz(a,b);
    imprime_matriz(a);
}
