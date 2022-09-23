#include "tarefas.hpp"

void zerar_coluna_acima (int j , float ** M , int n , int m ){
// Zera as posi ç õ es da coluna j da matriz M abaixo da diagonal principal
    for(int i = j - 1; i >= 0; i--){
        zerar_posicao_acima(i, j, M, n, m);
    }
}
