#include <iostream>
#include <cmath>

using namespace std;

struct Registro{
    int chave;
    Registro* prox;
    Registro(int chave = 0, Registro* prox = nullptr): chave(chave), prox(prox){}
};

struct TabelaDispersao_EE_Multiplicacao{
    Registro* tabela;
    int m;
    int cont;
    TabelaDispersao_EE_Multiplicacao(int tamanho){
        m = tamanho;
        cont = 0;
        tabela = new Registro[tamanho];
    };
    int metodo_multiplicacao(int c){
        double partint;
        double partfrac;
        const double A = 0.9;
        partfrac = modf(c*A, &partint);
        modf(partfrac*m, &partint);
         
        return (int)(partfrac*m);
    }
    void inserir(Registro* reg){
        int pos = metodo_multiplicacao(reg->chave);
        Registro* lista_insercao = &tabela[pos];
    
        reg->prox = lista_insercao->prox;
        lista_insercao->prox = reg;
        cont++;
    }
     
    Registro* buscar(int chave){
        int pos = metodo_multiplicacao(chave);
        Registro* lista_busca = &tabela[pos];

        while(lista_busca->prox && lista_busca->prox->chave != chave){
            lista_busca = lista_busca->prox;
        }

        if(!lista_busca->prox) {
            return nullptr; 
        }

        return lista_busca->prox;
    }
    
    Registro* remover(int chave){
        int pos = metodo_multiplicacao(chave);
        Registro* lista_remocao = &tabela[pos];

        while(lista_remocao->prox && lista_remocao->prox->chave != chave){
            lista_remocao = lista_remocao->prox;
        }
        
        if(!lista_remocao->prox) {
            return nullptr; 
        }
        
        Registro* removido = lista_remocao->prox;
        lista_remocao->prox = lista_remocao->prox->prox;
        cont--;
        return removido;
    }
    void eliminar(int chave){
        delete remover(chave);
    }
    void imprimir(){
        for(int i = 0; i < m; i++){
            cout << i << " : ";
            Registro* lista = &tabela[i];
            cout << "sentinela -> ";
            while(lista->prox){
                lista = lista->prox;
                cout << "{chave:" <<lista->chave << "} -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main(){
    TabelaDispersao_EE_Multiplicacao tab(10);
    for(int i = 0; i < 20; i++){
        tab.inserir(new Registro(i));
    }
    tab.imprimir();

    return 0;
}
