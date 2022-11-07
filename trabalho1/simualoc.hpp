#ifndef __SIMUALOC_H__
#define __SIMUALOC_H__
#define ult(no) no->ini + no->tam

struct SimulAloc{
    struct Noh{ int ini,tam; Noh* prox; };

    int inicio, tamanho;
    Noh* prim;

    bool inicializar(int ini, int tam);
    int alocar(int tam);
    bool desalocar(int ini, int tam);
    void terminar();
    Noh* unir(Noh* a, Noh* b);
    void imprimir();
};

#endif
