#include <iostream>
#include <algorithm>

using namespace std;

class Posicao{
public:
    int l,c;
    Posicao(int linha, int coluna): l(linha),c(coluna){}
    Posicao(){}
};

template<typename Tipo>
class Fila{
public:
    Tipo* V; 
    int ini;
    int fim;
    int tam;
    int cont;

    Fila(int tamanho){
        this->V = new Tipo[tamanho];
        this->tam = tamanho;
        this->cont = 0;
        this->ini = -1;
        this->fim = -1;
    }

    void enfileirar(Tipo x){
        if(cont < tam){
            fim = (fim+1)%tam;
            cont++;
            V[fim] = x;
        }
    }

    Tipo desenfileirar(){
        if(cont > 0){
            ini = (ini+1)%tam;
            cont--;
            return V[ini];
        }
        throw "Impossivel desenfileirar, lista vazia.";
    }

    int vazia(){
        return cont == 0;
    }
};

template<size_t n, size_t m>
void imprime_matriz(int(&M)[n][m]){
    for(int i = 0; i < n; i++){
        cout << "-";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){

    size_t n = 10, m = 10;

    int mat[10][10] = {
        {0,0,0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,1,0,0,0,0},
        {0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,1,1,1,0,0,0},
    };

    int dist[10][10];

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            dist[i][j] = -1;
        }
    }

    Fila<Posicao> f(n*m);

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(mat[i][j] == 1){
                f.enfileirar(Posicao(i,j));
                dist[i][j] = 0;
            }
        }
    }

    while(!f.vazia()){
        Posicao atual = f.desenfileirar();

        int i = atual.l;
        int j = atual.c;
        int d = dist[i][j];

        Posicao adjacente[4] = {Posicao(i-1,j), Posicao(i,j-1), Posicao(i+1,j), Posicao(i,j+1)};

        for(Posicao p : adjacente){
            bool esta_dentro = i >= 0 && i < n && j >= 0 && j < m;
            auto pos = &(dist[p.l][p.c]);
            if(esta_dentro &&  *pos == -1){
                f.enfileirar(p);
                *pos = d + 1;
            }
        }
        imprime_matriz(dist);
    }

    return 0;
}
