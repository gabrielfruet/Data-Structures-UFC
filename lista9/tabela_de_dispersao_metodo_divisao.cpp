#include <iostream>

using namespace std;

struct Registro{
    int chave;
    Registro* prox;
    Registro(int chave = 0, Registro* prox = nullptr): chave(chave), prox(prox){}
};

struct TabelaDispersao_EE_Divisao{
    Registro* tabela;
    int m;
    int cont;
    TabelaDispersao_EE_Divisao(int tamanho){
        m = tamanho;
        cont = 0;
        tabela = new Registro[tamanho];
    };
    int metodo_divisao(int c){
        return c % m;
    }
    void inserir(Registro* reg){
        int pos = metodo_divisao(reg->chave);
        Registro* lista_insercao = &tabela[pos];
    
        reg->prox = lista_insercao->prox;
        lista_insercao->prox = reg;
        cont++;
    }
     
    Registro* buscar(int chave){
        int pos = metodo_divisao(chave);
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
        int pos = metodo_divisao(chave);
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
    TabelaDispersao_EE_Divisao tab(10);
    for(int i = 0; i < 20; i++){
        tab.inserir(new Registro(i));
    }
    tab.imprimir();

    return 0;
}
