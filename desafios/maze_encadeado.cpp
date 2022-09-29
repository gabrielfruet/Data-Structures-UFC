#include <iostream>

using namespace std;

class Posicao{
public:
    int l, c;
    Posicao(int l, int c): l(l), c(c){}
    Posicao(){}
};

template<typename T>
class No{
public:
    T data;
    No* prox;
    No(T data, No* prox = nullptr){
        this->data = data;
        this->prox = prox;
    }
    No(){}
};

template<typename T>
class Pilha{
public:
    No<T>* sentinela;
    int tam;
    Pilha(){
        this->sentinela = new No<T>;
        this->tam = 0;
    }
    void empilhar(T x){
        auto novo = new No<T>(x, sentinela->prox);
        sentinela->prox = novo;
        tam++;
    }
    T desempilhar(){
        if(vazia())
            throw "Lista vazia";

        auto removido = sentinela->prox;
        sentinela->prox = removido ? removido->prox : nullptr;
        T data = removido->data;
        delete removido;
        tam--;
        return data;
    }
    T ultimo(){
        if(vazia()){
            throw "Lista vazia";
        }
        return sentinela->prox->data;
    }
    bool vazia(){
        return tam == 0;
    }
    void print(){
        auto it = sentinela;
        while(it->prox){
            it = it->prox;
            cout << it->data << ", ";
        }
    }
};

template<size_t n, size_t m>
void print_maze(char (&maze)[n][m]){
    cout << "--------------------------------" << endl;
    for(auto line : maze){
        for(int i = 0; i < m-1; i++){
            cout << line[i] << " ";
        }
        cout << endl;
    }
}

int main ()
{
    char maze2[12][21] = {
        "####################",
        "#i                 #",
        "### ###### # # ## ##",
        "# # #    # ### ## ##",
        "#     ## ##    ## ##",
        "#### ##  ## ###   ##",
        "#    ## # ###   # ##",
        "## #### # #   #   ##",
        "#  #      # ##### ##",
        "#### ###### ## ## ##",
        "####   #    #     ##",
        "########## #########",
    };

    char maze[12][21] = {
        "####################",
        "# #  #      # # #  s",
        "# # # ### ## # # # #",
        "# # # #    # # # # #",
        "# # # # # ## # # # #",
        "#        i         #",
        "## # # ## #### #####",
        "## # # ## ## #     #",
        "#  # #       ## # ##",
        "## # #### ##      ##",
        "## #   ## ##########",
        "####################",
    };
    int n = 12, m = 20;

    Pilha<Posicao> p;

    Posicao inicio; 
    for(int i=0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maze[i][j] == 'i'){
                inicio.l = i;
                inicio.c = j;
            }
        }
    }

    p.empilhar(inicio);
    bool achou_saida = false;
    int iteracoes = 0;

    while(!achou_saida){
        iteracoes++;
        Posicao atual = p.ultimo();
        int i = atual.l;
        int j = atual.c;

        if(maze[i][j] == 's') break;

        maze[i][j] = '.';

        Posicao posicoes_adjacentes[4] = {
            Posicao(i-1,j), Posicao(i,j-1), Posicao(i+1,j), Posicao(i,j+1)
        };

        bool dentro_da_matriz;
        bool desempilhar = true;

        for(Posicao pos : posicoes_adjacentes){
            dentro_da_matriz = i >= 0 && i < n && j >= 0 && j < m;
            if(dentro_da_matriz && maze[pos.l][pos.c] != '#' && maze[pos.l][pos.c] != '.'){
                desempilhar = false;
                p.empilhar(pos);
            }
        }

        if(desempilhar) {
            p.desempilhar();
        }

        print_maze(maze);
    }
    cout << "iteracoes: " << iteracoes << endl;
    return 0;
}

