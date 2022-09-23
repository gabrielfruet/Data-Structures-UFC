#include "tarefa3.hpp"

void triangular_superior (float ** M , int n , int m ){
// Zera as posi ç õ es da matriz M abaixo da diagonal principal
    for(int j = 0; j < n; j++){
        zerar_coluna_abaixo(j, M, n, m);
    }
}

