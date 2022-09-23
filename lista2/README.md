# PARTE I
## QUESTAO 1.
    ls()
    1 aux = 1
    2 i ← 0
    3 enquanto i < n faça
    4   aux = aux + i
    5   i ← i + 1
    6 retorne aux

1. 1
2. 1
3. n + 1
4. n
5. n
6. 1

#### Total: (1) + (1) + (n+1) + (n) + (n) + (1) = 3n + 4

## QUESTAO 2.
    troca_listas()
    i ← 0
    enquanto i < n faça
      aux = L[i]
      L[i] = V[i]
      V [i] = aux
      i ← i + 1


### Total: (1) + (n+1)  + 4(n) = 5n + 2

# PARTE II
## QUESTAO 3.

    multiplo_tres( )
    1 i ← 0
    2 enquanto i < n faça
    3   se 3 | L[i] então
    4     L[i] = L[i] ∗ 3
    5     L[i] = L[i] ∗ L[i]
    6   i ← i + 1

a) n
b) d
c) (1) + (n + 1) + (n) + (d) + (d) + (n) 
= 3n + 2d + 1
d) 
MELHOR: 3n + 2
PIOR: 5n + 2

## QUESTAO 4.
    triplicidade()
    1 i ← 0
    2 enquanto i < n faça
    3   se 3 % L[i] = 0 então
    4     L[i] = L[i] ∗ 3
    5     L[i] = L[i] ∗ L[i]
    6   senão
    7     se 3 % L[i] = 1 então
    8       imprimir ( ’ Uhuuuuu ! ’ )
    9     senão
    10      se 3 % L[i] = 2 então
    11        L[i] = i ∗ L[i]
    12        L[i] = L[i] / 3
    13        L[i] = L[i] − 1
    14   i ← i + 1

a) n
b) x1
c) 
(1) + (n + 1) + (n) + 2(x0) + 2(n-x0) + (x1) + 2(n-x0-x1) + 3(x2) + (n)
= 7n - 2x0 - 2x1 + 3x2 + 2
d)
MELHOR: 5n + 2
PIOR: 10n + 2
