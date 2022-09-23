//
// Created by gabrielfruet on 8/15/22.
//
#include "vetor.h"
#include <sstream>
#include <queue>

Vetor::Vetor(int tam) : tam(0), cap(tam*2), vetor(new int[tam*2]){}

bool Vetor::append(int n, const int* elements) {
    if(n + this->tam > this->cap) {
        return false;
    }
    for(int i = 0; i < n; i++){
        this->vetor[i + this->tam] = elements[i];
    }
    this->tam = this->tam + n;
    return true;
}

std::string Vetor::to_string(int qntd) {
    std::ostringstream os;
    os << "{ ";
    for(int i = 0; i < qntd; i++){
        os << this->vetor[i];
        os << ", ";
    }
    os << " }";
    return os.str();
}

std::string Vetor::to_string() {
    return this->to_string(this->tam);
}

int Vetor::primeiro(){
    return this->vetor[0];
}
int Vetor::ultimo(){
    return this->vetor[this->tam - 1];
}

void Vetor::troca(int pos_a, int pos_b){
    int aux = this->vetor[pos_a];
    this->vetor[pos_a] = this->vetor[pos_b];
    this->vetor[pos_b] = aux;
}

void Vetor::questao_1() {
    std::queue<int> par, impar;
    int i = 0;
    for(i = 0; i < this->tam; i++){
        if(this->vetor[i] % 2 == 0)
            par.push(this->vetor[i]);
        else
            impar.push(this->vetor[i]);
        this->vetor[i] = 0;
    }
    this->tam = par.size() >= impar.size() ? (int)par.size()*2 : (int)impar.size()*2;
    for(i = 0; !par.empty(); i += 2){
        this->vetor[i] = par.front();
        par.pop();
    }
    for(i = 1; !impar.empty(); i += 2){
        this->vetor[i] = impar.front();
        impar.pop();
    }
}

void Vetor::questao_2() {
    int primeira = 1, segunda = this->tam/2 + 1;
    for(;segunda < this->tam; primeira += 2, segunda += 2){
        this->troca(primeira,segunda);
    }
}

void Vetor::questao_3(){
    std::queue<int> primeira, segunda;
    for(int i = 1; i <= this->tam/2; i++)
        primeira.push(this->vetor[i]);
    for(int i = this->tam/2; i < this->tam; i++)
        segunda.push(this->vetor[i]);
    for(int i = 0; i < this->tam; i++){
        std::queue<int>* ref;
        if(i % 2 == 0)
            ref = &primeira;
        else
            ref = &segunda;

        this->vetor[i] = ref->front();
        ref->pop();
    }
}

void Vetor::questao_4(){
    for(int i = 0; i < this->tam/2; i++)
        this->troca(i, this->tam - i - 1);
}

void Vetor::questao_5() {
    int ultimo = this->ultimo();

    for(int i = this->tam - 1; i > 0; i--)
        this->vetor[i] = this->vetor[i-1];


    this->vetor[0] = ultimo;
}

