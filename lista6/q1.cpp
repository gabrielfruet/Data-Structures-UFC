#include <cstdio>
#include <cstdlib>

class FilaInt {
public :
    int *v ;
    int tam_max ;
    int ini ;
    int fim ;
    int cont ;
    // m é todo construtor , inicializa a fila
    FilaInt(int tamanho){
        v = new int [ tamanho ]; // cria vetor de inteiros com o tamanho desejado
        tam_max = tamanho ;
        ini = 0;
        fim = -1;
        cont = 0;
    }
    // m é todo enfileirar
    void enfileirar(int x){
        if(cont < tam_max){
            fim = (fim+1)%tam_max;
            cont++;
            v[fim] = x;
        }
    }
    // m é todo desenfileirar
    int desenfileirar(){
        if(cont >= 0){
            ini = (ini+1)%tam_max;
            cont--;
            return v[ini];
        }
        throw "Impossivel retirar de fila vazia";
    }
    // m é todo fila vazia
    int vazia(){
        return cont == 0;
    }
};

int main(){
    FilaInt f(10); // cria fila de tamanho 10
    for(int i = 0; i < 10; i++){
        f.enfileirar(i );
    }
    for(int i = 0; i < 5; i++){
        printf(" %d , " , f.desenfileirar());
    }
    printf("\n");
    for(int i = 0; i < 5; i++){
        f.enfileirar(i );
    }
    while(!f.vazia()){
        printf(" %d , " , f.desenfileirar());
    }
}
