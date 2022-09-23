#include <iostream>
#include "tarefas.hpp"

using namespace std;

int main()
{
    int n = 0, m = 0;
    cout << "Digite a quantidade de linhas e colunas da matriz: ";
    cin >> n >> m;
    float** M = new float*[n];
    for(int i = 0; i < n; i++){
        M[i] = new float[m];
        cout << "linha " << i << ", ";
        for(int j = 0; j < m; j++){
            cout << "coluna " << j << ": ";
            cin >> M[i][j];
        }
    }
    imprime_matriz(n, m, M);
    matriz_inversa(M, m, n);
    imprime_matriz(n, m, M);
    return 0;
}
