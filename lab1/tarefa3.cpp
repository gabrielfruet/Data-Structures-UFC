#include <iostream>
#include "tarefas.hpp"

void zerar_coluna_abaixo (int j , float ** M , int n , int m ){
// Zera as posi ç õ es da coluna j da matriz M abaixo da diagonal principal
    for(int i = j + 1; i < n; i++){
        zerar_posicao_abaixo(i, j, M, n, m);
    }
}
