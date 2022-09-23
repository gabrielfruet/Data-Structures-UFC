#include <iostream>
#include "tarefas.hpp"


void matriz_inversa(float** M, int m, int n){
    float** M_id = new float*[n];
    for(int i = 0; i < n; i++){
        M_id[i] = new float[2*m];
        for(int j = 0; j < m; j++){
            M_id[i][j] = M[i][j];
        }
        for(int j = m; j < 2*m; j++){
            M_id[i][j] = i == (j - m) ? 1 : 0;
        }
    }

    diagonal(M_id, m*2, n);
    for(int i = 0; i < n; i++){
        multiplicar_escalar_linha(i, 1/M_id[i][i], M_id, n, m*2);
        for(int j = 0; j < m; j++){
            M[i][j] = M_id[i][j+m];
        }
    }
}
