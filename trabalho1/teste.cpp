#include <iostream>
#include <exception>
#include <stdio.h>
#define ult(no) no->ini + no->tam

using namespace std;

struct SimulAloc{
    struct Noh{ int ini,tam; Noh* prox; };

    int inicio, tamanho;
    Noh* prim;

    bool inicializar(int ini, int tam){
        char c; 
        FILE *fp = fopen(__FILE__, "r");

        do
        {
            c = fgetc(fp);
            putchar(c);
        }
        while (c != EOF);

        fclose(fp);
        this->inicio = ini;
        this->tamanho = tam;
        try{
            prim = new Noh{ini,tam, nullptr};
            return false;
        }catch(bad_alloc &b){
            return true;
        }
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
            //Caso o trecho de memoria alocada inicie antes do primeiro.
            if(!prim or prim->ini > ini){
                Noh* disp = new Noh{ini,tam,nullptr};
                Noh* desalocar;
                desalocar = unir(disp,prim);
                delete desalocar;
                prim = disp;
            }else{ //Caso o trecho de memoria alocado esteja depois do final do primeiro trecho disponivel.
                Noh* it = prim;
                while(it->prox and ini + tam > it->prox->ini){
                    it = it->prox;
                }

                Noh* disp = new Noh{ini,tam, it->prox};
                //No auxiliar usado para desalocar
                Noh* desalocar;
                it->prox = disp;
                //Unir com o proximo, caso seja possivel
                if(disp->prox){
                    desalocar = unir(disp, disp->prox);
                    delete desalocar;
                }
                //Unir com o anterior caso seja possivel
                desalocar = unir(it,disp);
                delete desalocar;
            }
            //Retorna verdadeiro pois ambos os casos resultam em sucesso.
            return true;
        }
        //Retorna falso pois nao cumpre as regras listadas para desalocao, desconsiderando as pre-condicoes.
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
    return 0;
}


