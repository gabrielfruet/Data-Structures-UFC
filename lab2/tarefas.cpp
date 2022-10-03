#include <iostream>
#include <memory>
#include <functional>

using namespace std;

class No {
    public:
    int chave;
    No* prox;
    No(
        int chave = 0,
        No* prox = NULL
    ):
        chave(chave),
        prox(prox){}
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
    while(it){
        unique_ptr<No> removido(it);
        it = it->prox;
    }
}

int tamanho_lista(No* cabeca){
    if(!cabeca) return 0;
    int cont = 0;
    while(cabeca){
        cabeca = cabeca->prox;
        cont++;
    }
    return cont;
}

void imprime_nao_recursivo(No* cabeca){
    int tam = tamanho_lista(cabeca);
    int pilha[tam];
    int ult = -1;
    No* it = cabeca;
    for(int i = 0; i < tam; i++){
        pilha[++ult] = it->chave;
        it = it->prox;
    }
    for(int i = tam-1; i >= 0; i--){
        cout << pilha[i] << " <- ";
    }
}

void imprime_recursivo(No* cabeca){
   if(!cabeca) return;
   imprime_recursivo(cabeca->prox);
   cout << cabeca->chave << " <- ";
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
        for(int i = 0;
            i < pos && it->prox;
            i++
        ){
            it = it->prox;
        }
        it->prox->ant = no;
        no->ant = it;
        no->prox = it->prox;
        it->prox = no;
        cont++;
    }

    NoDE* remover(int chave){
        if(cont <= 0) return NULL;
        NoDE* it = sentinela;
        while(it->prox && it->prox->chave != chave){
            it = it->prox;
        }
        NoDE* removido = it->prox;
        it->prox = it->prox->prox;
        it->prox->ant = it;
        cont--;
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
        cout << "    [ ";
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
    for(int i = 0; i < linha; i++){
        it_linha = it_linha->embaixo;
    }
    for(int j = 0; j < coluna; j++){
        it_coluna = it_coluna->direita;
    }
}

void preenche_matriz(NoMat* cabeca, function<int(int,int)> entry_fn){
    NoMat* it_linha = cabeca;
    for(int i = 0; it_linha; i++){
        NoMat* it_coluna = it_linha;
        for(int j = 0; it_coluna; j++){
            it_coluna->chave = entry_fn(i,j);
            it_coluna = it_coluna->direita;
        }
        it_linha = it_linha->embaixo;
    }
}

int main(){
    int n = 20;
    NoMat* matrizes[n];
    for(int i = 0; i < n; i++){
        matrizes[i] = matriz_linha(n);
    }
    NoMat* cabeca = matrizes[0];
    for(NoMat** it = matrizes; it < matrizes + n - 1; it++){
        costura_matriz((it),(it+1));
    }

    auto par = [](int n) -> bool{
        return n % 2 == 0;
    };
    preenche_matriz(cabeca, [n,par](int i, int j) -> int{
                        return par(j) && par(i) ? 1 : 0;
                    });
    imprime_matriz(cabeca);

    No* lista = nova_lista_encadeada(n);
    lista->chave = 1;
    imprime_nao_recursivo(lista);

    return 0;
}
