#include "tarefa1.hpp"
#include "tarefa2.hpp"
#include "tarefa3.hpp"
#include "tarefa4.hpp"
#include "tarefa5.hpp"
#include "tarefa6.hpp"
#include "tarefa7.hpp"
#include "tarefa8.hpp"
#include "tarefa9.hpp"
#include <iostream>

inline void imprime_matriz(int n, int m, float** mat){
    std::cout << "[" << std::endl;;
    for(int i = 0; i < n; i++){
        std::cout << "   " << "[";
        for(int j = 0; j < m; j++){
            std::cout << mat[i][j] << ", ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
}
