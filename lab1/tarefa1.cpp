#include <stdio.h>
#include <utility>

void trocar_linhas ( int i , int j , float ** M , int n , int m ){
// Troca as linhas i e j da matriz M de dimens õ es n × m
    for(int k = 0; k < m; k++){
        std::swap<float>(M[i][k], M[j][k]);
    }

}
void multiplicar_escalar_linha (int i , float a , float ** M , int n , int m ){
// Multiplica a linha i da matriz M de dimens õ es n × m
    for(int j = 0; j < m; j++){
        M[i][j] = M[i][j]*a;
    }
}
void somar_linhas (int i , int j , float a , float ** M , int n , int m ){
// Soma à linha i o produto da linha j por a
// na matriz M de dimens õ es n × m
    for(int k = 0; k < m; k++){
        M[i][k] += M[j][k]*a;
    }
}
