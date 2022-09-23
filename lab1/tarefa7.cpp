#include "tarefas.hpp"


void triangular_inferior ( float ** M , int n , int m ){
// Zera as posi ç õ es da matriz M acima da diagonal principal
    for(int j = n - 1; j >= 0; j--){
        zerar_coluna_acima(j, M, n, m);
    }
}
