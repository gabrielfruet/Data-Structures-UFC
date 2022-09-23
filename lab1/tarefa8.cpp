#include "tarefas.hpp"

void diagonal(float** M, int m, int n){
// Zera as posi ç õ es da matriz M acima da diagonal principal
    triangular_inferior(M, n, m);
    triangular_superior(M, n, m);
}
