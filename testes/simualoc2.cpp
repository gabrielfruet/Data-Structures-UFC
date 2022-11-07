#include <iostream>
#include <climits>
#include <algorithm>
#define ult(no) no->ini + no->tam

using namespace std;

struct SimulAloc{
    struct Noh{ int ini,tam; Noh* prox; };

    int inicio, tamanho;
    Noh* sent;

    SimulAloc(){
        sent = new Noh;
        sent->ini = sent->tam = INT_MAX;
        sent->prox = sent;
    }

    bool inicializar(int ini, int tam){
        this->inicio = ini;
        this->tamanho = tam;
        //Tenta criar novo no
        try{
            sent->prox = new Noh{ini,tam, sent};
            return true;
        }catch(std::exception){
            return false;
        }
    }
    int alocar(int tam){
        //Caso a memoria alocada seja maior que 0 e haja pelo menos 1 espaco contiguo, procura.
        if(tam > 0 and !vazio()){
            int endereco;
            Noh* it = sent;
            //Procura ate achar um no que satisfaca
            while(it->prox->tam < tam){
                it = it->prox;
            }
            //Caso esse no nao seja a sentinla
            if(it->prox != sent){
                endereco = it->prox->ini + it->prox->tam - tam; 
                it->prox->tam -= tam;

                //Exclui no caso esteja vazio
                if(it->prox->tam == 0){
                    Noh* desalocar = it->prox;
                    it->prox = it->prox->prox;
                    delete desalocar;
                }

                //Retorna o endereco alocado
                return endereco;
            }
        }
        return -1;
    }

    bool desalocar(int ini, int tam){
        /* 
        *Para poder desalocar:
        *1. O ini precisa ser maior ou igual ao inicio  
        *2. O ini precisa ser menor que o endereco final(inicio + tamanho)
        *3. O endereco final a ser desalocado precisar menor que o endereco final do simulador
        */
        if(
            ini >= inicio and 
            ini < inicio + tamanho and 
            ini + tam <= inicio + tamanho
        ){
            Noh* it = sent;

            //Procura o primeiro no que o ultimo endereco desalocada seja
            //menor que o inicio dele.
            while(ini + tam > it->prox->ini){
                it = it->prox;
            }

            //Cria o no da memoria desalocada
            Noh* disp = new Noh{ini,tam, it->prox};
            Noh* desalocar;
            it->prox = disp;

            //Caso ele nao seja o ultimo, tenta unir com o proximo, caso estejam superpostos
            if(disp->prox != sent){
                desalocar = unir(disp,disp->prox);
                delete desalocar;
            }
            //Caso ele nao seja o primeiro, une com o anterior, caso estejam superpostos
            if(it != sent){
                desalocar = unir(it,disp);
                delete desalocar;
            }
            //Retorna true pois a alocacao foi bem sucedida
            return true;
        }
        return false;
    }

    void terminar(){
        Noh* it = sent->prox;
        Noh* del = nullptr;
        while(it){
            del = it; 
            it = it->prox;
            delete del;
        }
        sent->prox = sent;
    }

    Noh* unir(Noh* a, Noh* b){
        if(!a || !b) return nullptr;
        if(ult(a) >= b->ini){
            a->tam = ult(b) - a->ini;
            a->prox = b->prox;
            return b;
        }
        return nullptr;
    }

    bool vazio(){
        return sent->prox == sent;
    }

    void imprimir(){
        Noh* it = sent->prox;
        cout << "sent -> ";
        while(it != sent){
            cout << "{" << it->ini << ", " << it->tam << ", " << it->prox << "} -> ";
            it = it->prox;
        }
        cout << "sent" << endl;;
    }

};

int main(){
    SimulAloc s;
    int end;
    s.inicializar(10,50);
    s.imprimir();
    end = s.alocar(15);
    cout << "Endereco alocado com 15: " << end << endl;
    s.imprimir();
    end = s.alocar(20);
    cout << "Endereco alocado com 20: " << end << endl;
    s.imprimir();
    end = s.alocar(30);
    cout << "Endereco alocado com 30: " << end << endl;
    s.imprimir();
    s.desalocar(45, 15);
    cout << "Desalocando trecho com inicio em 45" << endl;
    s.imprimir();
    cout << "Desalocando do 25 com tamanho 5" << endl;
    s.desalocar(25,5);
    s.imprimir();
    cout << "Desalocando do 35 com tamanho 10" << endl;
    s.desalocar(35,10);
    s.imprimir();
    cout << "Desalocando do 30 com tamanho 5" << endl;
    s.desalocar(30,5);
    s.imprimir();


    return 0;
}

