#include <iostream>
#include "simualoc.hpp"

using namespace std;

int main(){
    SimulAloc s;
    int end;
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

    return 0;
}

