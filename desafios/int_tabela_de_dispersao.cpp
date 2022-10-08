#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <random>

using namespace std;

class registro{
public:
    string nome = "dummy";
    int chave = 0;
    registro* prox = nullptr;
    registro(int chave, string nome): chave(chave), nome(nome){}
    registro(){};
};

class tabela_de_dispersao{
public:
    registro* tabela; 
    int cont = 0; 
    int cap;
    tabela_de_dispersao(int cap = 20){
        this->cap = cap;
        this->tabela = new registro[cap];
    }
    int dispersao(int chave){
        return chave % cap;
    }
    void insere(registro *reg){
        int pos = dispersao(reg->chave);
        registro* lista_insercao = &tabela[pos];
        
        reg->prox = lista_insercao->prox;;
        lista_insercao->prox = reg;
        cont++;
    }
    registro* busca(int chave){
        int pos = dispersao(chave);
        registro* lista_busca = &tabela[pos];

        while(lista_busca->prox && lista_busca->prox->chave != chave){
            lista_busca = lista_busca->prox;
        }

        return lista_busca->prox;
    }

    registro* remover(int chave){
        int pos = dispersao(chave);
        registro* lista_remocao = &tabela[pos];

        while(lista_remocao->prox && lista_remocao->prox->chave != chave){
            lista_remocao = lista_remocao->prox;
        }

        if(!lista_remocao->prox){
            return nullptr;
        }

        registro* removido = lista_remocao->prox;
        lista_remocao->prox = lista_remocao->prox->prox;
        cont--;

        return removido;
    }
    void eliminar(int chave){
        registro* deletar = remover(chave);
        delete deletar;
    }
    void imprime(){
        cout << "-----------------------------------" << endl;
        for(int i = 0; i < cap; i++){
            registro* lista = &tabela[i];
            cout << i << " : ";
            while(lista){
                cout << "{ " << lista->chave << "," << lista->nome << " } -> ";
                lista = lista->prox;
            }
            cout << endl;
        }
        cout << "-----------------------------------" << endl;
    }

};

int main(){
    tabela_de_dispersao t;
    registro registros[20];
    string nomes[20] = {
        "Cloris",
        "Clotilda",
        "Clovis",
        "Codee",
        "Codi",
        "Codie",
        "Cody",
        "Coleen",
        "Colene",
        "Coletta",
        "Colette",
        "Colleen",
        "Collen",
        "Collete",
        "Collette",
        "Collie",
        "Colline",
        "Colly",
        "Con",
        "Concettina",
    };
    for(int i = 0; i < 20; i++){
        registros[i] = registro(rand() % 100, nomes[i]);
        t.insere(&registros[i]);
    }

    t.imprime();
    t.remover(77);
    t.remover(93);
    t.imprime();
    return 0;
}
