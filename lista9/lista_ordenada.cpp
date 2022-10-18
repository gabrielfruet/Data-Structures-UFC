#include <iostream>
#include <algorithm>

using namespace std;

class Registro {
public :
    int chave ;
    int dado ;
    Registro(int chave, int dado): chave(chave), dado(dado){};
};
class ListaOrdenada {
public :
    Registro ** L ; // vetor de ponteiros de registros
    int tam_max ; // tamanho m á ximo da lista
    int cont ; // n ú mero de elementos na lista
    // m é todo construtor , inicializa a lista
    //
    ListaOrdenada ( int tamanho ){
        tam_max = tamanho ;
        L = new Registro*[tam_max];
        cont = 0;
    }
    int busca_insercao(int chave){
        int l = 0, r = cont-1, m;
        while(l <= r){
            m = (l+r)/2;
            if(chave > L[m]->chave){
                l = m + 1;
            }else if(chave < L[m]->chave){
                r = m - 1;
            }else{
                return m;
            }
        }
        return r+1;
    }
    // m é todo inserir , retorna a posi ç ã o do registro inserido no vetor
    int inserir ( Registro * reg){
        if(cont == 0){
            L[cont++] = reg;
            return 0; 
        }
        int p = busca_insercao(reg->chave);
        L[cont++] = reg;
        for(int i = cont-1; i > p; i--){
            swap(L[i], L[i-1]);
        }
        return p;
    }
    // m é todo buscar , implementa busca binária
    Registro* buscar (int chave){
        int l = 0, r = cont-1, m;
        while(l <= r){
            m = (l+r)/2;
            if(chave > L[m]->chave){
                l = m + 1;
            }else if(chave < L[m]->chave){
                r = m - 1;
            }else{
                return L[m];
            }
        }
        return nullptr;
    }
    // m é todo remover , retira da lista e devolve ponteiro para o registro removido
    Registro* remover ( int chave ){
        int l = 0, r = cont-1, m;
        while(l <= r){
            m = (l+r)/2;
            if(chave > L[m]->chave){
                l = m + 1;
            }else if(chave < L[m]->chave){
                r = m - 1;
            }else{
                for(int i = m; i < cont-1; i++){
                    swap(L[i], L[i+1]);
                }
                return L[cont--];
            }
        }
        return nullptr;
    }
};

void print(ListaOrdenada L){
    int n = L.cont;
    Registro** V = L.L;
    for(int i = 0; i < n; i++){
        cout << "{" << V[i]->chave << ", " << V[i]->dado << "} ";
    }
}

int main(){
    ListaOrdenada l(10);
    print(l);
}
