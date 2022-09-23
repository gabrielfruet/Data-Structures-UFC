#include <iostream>
#include "vetor.h"

using namespace std;

int main() {
    Vetor v = Vetor(20);
    int a[10] = {16,19,41,8,42,39,33,22,29,48};
    v.append(10, a);
    cout << v.to_string() << endl;
    v.questao_3();
    cout << v.to_string() << endl;
}
