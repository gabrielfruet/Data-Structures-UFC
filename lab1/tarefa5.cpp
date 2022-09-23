#include "tarefas.hpp"
#include <iostream>

void zerar_posicao_acima (int i , int j , float ** M , int n , int m ){
// Zera a posi � � o M [ i ][ j ] da matriz M , onde i < j
    if(M[j][j] == 0){
        bool trocou = false;
        for(int k = j-1; k >= 0 && !trocou; k--){
            if(M[k][j] != 0){
                trocar_linhas(j, k, M, n, m);
                trocou = true;
            }
        }
    }
    float fator = M[i][j]/M[j][j];
    for(int k = 0; k < m; k++){
        M[i][k] = M[i][k] - fator*M[j][k];
    }
}
