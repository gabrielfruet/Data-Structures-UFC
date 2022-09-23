# include <cstdio>
class Posicao {
public:
    int l;
    int c;
};
class FilaPosicao {
public:
    Posicao * v;
    int tam_max;
    int ini;
    int fim;
    int cont;
    // m é todo construtor , inicializa a fila
    FilaPosicao(int tamanho){
        v = new Posicao [ tamanho ]; // cria vetor de posicoes com o tamanho desejad
        tam_max = tamanho;
        ini = -1;
        fim = -1;
        cont = 0;
    }
    // m é todo enfileirar
    void enfileirar(Posicao p){
        if(cont < tam_max){
            fim = (fim+1)%tam_max;
            cont++;
            v[fim] = p;
        }
    }
    // m é todo desenfileirar
    Posicao desenfileirar(){
        if(cont > 0){
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
    FilaPosicao f(10); // cria fila de tamanho 10
    Posicao p;
    for(int i = 0; i < 10; i ++){
        p.l = i * i;
        p.c = i * i * i;
        f.enfileirar(p);
    }
    for(int i = 0; i < 5; i ++){
        p = f.desenfileirar();
        printf("linha %d, coluna %d\n " , p.l , p.c);
    }
    printf ("\n");
    for ( int i = 0; i < 5; i ++){
        p.l = i * i;
        p.c = i * i * i;
        f.enfileirar(p);
    }
    while (!f.vazia()){
        p = f.desenfileirar();
        printf ("linha %d , coluna %d\n", p.l , p.c );
    }
}
 . . . . f .
         i
-1 0 1 2 3 4 
   _,_,_,_,_
