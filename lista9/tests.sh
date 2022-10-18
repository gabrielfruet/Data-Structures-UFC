#!/usr/bin/env sh

c++ ./performanceI.cpp -o PI
c++ ./performanceII.cpp -o PII
c++ ./performanceIII.cpp -o PIII

echo "METODO DA DIVISAO: "
./PI
echo "METODO DA MULTIPLICACAO: "
./PII
echo "LISTA ORDENADA: "
./PIII

