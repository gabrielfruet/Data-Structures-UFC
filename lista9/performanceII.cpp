#include <iostream>
#include <cmath>

using namespace std;

struct Registro{
    int chave;
    Registro* prox;
    Registro(int chave = 0, Registro* prox = nullptr): chave(chave), prox(prox){}
};

struct TabelaDispersao_EE_Multiplicacaoo{
    Registro* tabela;
    int m;
    int cont;
    TabelaDispersao_EE_Multiplicacaoo(int tamanho){
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

int testeInsercao_TDEED(int m, int n, Registro* Regs){
    TabelaDispersao_EE_Multiplicacaoo tab(m);
    int inicio,fim;
    inicio = clock();
    for(int i = 0; i < n; i++){
        tab.inserir(&Regs[i]);
    }
    fim = clock();
    return fim - inicio;
}

void inicializaChavesAleatorias(int n, Registro* Regs){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        Regs[i].chave = rand();
    }
}

int main(){
    int n = 10000;
    int m = 10;
    Registro* Regs = new Registro[n];
    inicializaChavesAleatorias(n, Regs);

    clock_t duracao = testeInsercao_TDEED(m, n, Regs);

    cout << "Duracao do teste de insercao: " << endl;
    cout << "Tamanho da tabela: " << m << endl;
    cout << "Quantidade de registro: " << n << endl;
    cout << "Tempo decorrido em ms: " << (float)duracao*1000/CLOCKS_PER_SEC << endl;
    return 0;
}
