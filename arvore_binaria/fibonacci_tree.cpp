#include <iostream>

using std::cout;
using std::endl;

struct Noh{
    Noh *esq,*dir;
    double chave;
};

void r_fib_tree(Noh** r, int h, double c){
    if(h <= 0) return;
    *r = new Noh{nullptr,nullptr,c};
    r_fib_tree(&(*r)->esq, h-1, c - 1);
    r_fib_tree(&(*r)->dir, h-2, c + 1);
}

#define W 4
void printarv(Noh *r, int s){
    if(r != nullptr){
        printarv(r->dir, s + W);
        for(int i = 0; i < s; i++) {
            cout << " ";
        }
        cout << r->chave << endl;
        printarv(r->esq, s + W);
    }
}
int main(){
    Noh* r = nullptr; 
    int h = 0;
    std::cin >> h;
    r_fib_tree(&r,h, 16);
    printarv(r,0);
    return 0;
}
