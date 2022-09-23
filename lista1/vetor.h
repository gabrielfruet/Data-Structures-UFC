//
// Created by gabrielfruet on 8/15/22.
//

#ifndef LISTA1_VETOR_H
#define LISTA1_VETOR_H
#include <iostream>

class Vetor {
private:
    int *vetor;
    int cap;
    int tam;
public:
    Vetor(int cap);
    bool append(int n, const int elements[]);
    std::string to_string();
    std::string to_string(int qntd);
    void troca(int pos_a, int pos_b);
    int primeiro();
    int ultimo();

    void questao_1();
    void questao_2();
    void questao_3();
    void questao_4();
    void questao_5();

};

#endif //LISTA1_VETOR_H
