#include <iostream>
#include <exception>
#define ult(no) no->ini + no->tam

using namespace std;

struct SimulAloc{
    struct Noh{ int ini,tam; Noh* prox; };

    Noh* prim;

    bool inicializar(int ini, int tam){
        try{
            prim = new Noh{ini,tam, nullptr};
        }catch(bad_alloc &b){
            return true;
        }
        return false;
    }

    int alocar(int tam){
        if(tam != 0 and prim){
            int endereco;
            //Caso a primeira memoria contigua satisfaca
            if(prim->tam >= tam){
                endereco = prim->ini + prim->tam - tam;
                prim->tam -= tam;

                //Caso seja criado um no vazio, remove da lista
                if(prim->tam == 0){
                    Noh* desalocar = prim;
                    prim = prim->prox;
                    delete desalocar;
                }

                return endereco;
            }else{ //Caso seja necessario procurar uma memoria que satisfaca
                Noh* it = prim;
                //Procura ate achar um no que satisfaca ou nao haja mais nos
                while(it->prox and it->prox->tam < tam){
                    it = it->prox;
                }
                //Caso exista esse no
                if(it->prox){
                    endereco = it->prox->ini + it->prox->tam - tam; 
                    it->prox->tam -= tam;

                    //Exclui no caso esteja vazio
                    if(it->prox->tam == 0){
                        Noh* desalocar = it->prox;
                        it->prox = it->prox->prox;
                        delete desalocar;
                    }

                    return endereco;
                }//Else implicito, retornara -1
            }
        }
        return -1;
    }
    bool desalocar(int ini, int tam){
        Noh* disp;
        try{
            disp = new Noh{ini,tam,nullptr};
        }catch(bad_alloc &b){
            return true;
        }
        //Caso o trecho de memoria alocada inicie antes do primeiro.
        if(!prim or prim->ini > ini){
            Noh* resto;
            disp->prox = prim;
            //Tenta unir com o proximo, caso possivel
            resto = unir(disp,prim);
            delete resto;
            //Novo no se torna o primeiro
            prim = disp;
        }else{ //Caso o trecho de memoria alocado esteja depois do final do primeiro trecho disponivel.
            Noh* it = prim;

            while(it->prox and ult(disp) > it->prox->ini){
                it = it->prox;
            }
            //No auxiliar usado para desalocar
            Noh* resto;
            disp->prox = it->prox;
            it->prox = disp;
            //Unir com o proximo, caso seja possivel
            if(disp->prox){
                resto = unir(disp, disp->prox);
                delete resto;
            }
            //Unir com o anterior, caso seja possivel
            resto = unir(it,disp);
            delete resto;
        }
        return false;
    }

    void terminar(){
        Noh* it = prim;
        Noh* del = nullptr;
        //Desaloca todos os nos
        while(it){
            del = it; 
            it = it->prox;
            delete del;
        }
    }

    Noh* unir(Noh* a, Noh* b){
        if(!a or !b) return nullptr;
        if(ult(a) >= b->ini){
            //Recalcula o tamanho ao juntar os nos.
            a->tam = ult(b) - a->ini;
            a->prox = b->prox;
            return b;
        }
        return nullptr;
    }

    void imprimir(){
        Noh* it = prim;
        while(it){
            cout << "[" << it->ini << ";" << it->tam << ";" << (it->prox ? "->" : "nullptr") << " ], ";
            it = it->prox;
        }
        cout << endl;
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

    s.terminar();
    s.inicializar(232,150);
    s.alocar(56);
    s.imprimir();
    s.alocar(68);
    s.imprimir();
    s.desalocar(258,68);
    s.imprimir();
    s.alocar(44);
    s.imprimir();
    s.alocar(30);
    s.imprimir();
    s.desalocar(326, 56);
    s.imprimir();
    s.alocar(20);
    s.imprimir();
    s.desalocar(232, 20);
    s.imprimir();

    cout << "--------------" << endl;

    s.terminar();
    s.inicializar(210,150);
    s.alocar(27);
    s.imprimir();
    s.alocar(33);
    s.imprimir();
    s.desalocar(300,33);
    s.imprimir();
    s.desalocar(333,27);
    s.imprimir();
    s.alocar(122);
    s.imprimir();
    s.alocar(28);
    s.imprimir();
    s.alocar(1);
    s.imprimir();
    s.desalocar(238, 122);
    s.imprimir();
    s.desalocar(210, 28);
    s.imprimir();
    return 0;
}
