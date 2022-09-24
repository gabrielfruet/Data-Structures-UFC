#include <iostream>

using namespace std;

class Posicao{
public:
    int l, c;
    Posicao(int l, int c): l(l), c(c){}
    Posicao(){}
};

template<typename T>
class Pilha{
public:
    T* L;
    int inicio;
    int fim;
    int tam;
    int count;
    Pilha(int tam){
        this->tam = tam; 
        this->inicio = -1;
        this->fim = -1;
        this->L = new T[tam];
        this->count = 0;
    }
    void empilhar(T x){
        if(count < tam){
            fim = (fim + 1)%tam;
            count++;
            L[fim] = x;
        }
    }
    T desempilhar(){
        T el;
        if(count != 0){
            el = L[fim] ;
            fim = (fim - 1)%tam;
            count--;
            return el;
        }
        return el;
    }
    T ultimo(){
        return L[fim];
    }
    bool vazia(){
        return count == 0;
    }
};

void imprime_matriz(int n, char* M[]){
    for(int i = 0; i < n; i++){
        cout << M[i] << endl;
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
        "# #  #      # # #   ",
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

    Pilha<Posicao> p(100);

    Posicao inicio; 
    for(int i=0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(maze[i][j] == 'i'){
                inicio.l = i;
                inicio.c = j;
            }

    p.empilhar(inicio);
    bool achou_saida = false;
    int iteracoes = 0;

    while(!achou_saida){
        iteracoes++;
        Posicao atual = p.ultimo();
        int i = atual.l;
        int j = atual.c;

        maze[i][j] = '.';

        Posicao proximo;

        achou_saida = i == 0 || i == n-1 || j == 0 || j == m-1;

        if(achou_saida) break;


        Posicao posicoes_adjacentes[4] = {
            Posicao(i-1,j), Posicao(i,j-1), Posicao(i+1,j), Posicao(i,j+1)
        };

        bool dentro_da_matriz;
        bool desempilhar = true;
        int caminhos = 0;
        Pilha<Posicao> temp(4);

        for(Posicao pos : posicoes_adjacentes){
            dentro_da_matriz = i >= 0 && i < n && j >= 0 && j < m;
            if(dentro_da_matriz && maze[pos.l][pos.c] == ' '){
                temp.empilhar(pos);
                desempilhar = false;
                caminhos++;
            }
        }

        if(desempilhar || caminhos <= 1){
            Posicao d = p.desempilhar();
            if(desempilhar){
                maze[d.l][d.c] = '0';
            }
            while(!temp.vazia()){
                p.empilhar(temp.desempilhar());
            }
        }

        for(int i = 0; i < temp.count; i++){
            p.empilhar(temp.desempilhar());
        }

        cout << "--------------------------------" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }
    }
    cout << "iteracoes: " << iteracoes << endl;
    return 0;
}

