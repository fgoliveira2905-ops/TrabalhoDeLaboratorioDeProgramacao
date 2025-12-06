/**
 * @file functions-1.h
 * @brief Declaração das funções auxiliares para manipulação de vetores e matrizes.
 *
 * Este arquivo contém as funções principais usadas pelo programa
 * principal para operações com vetores de inteiros, como cálculo de média,
 * ordenação, filtragem e construção de matrizes.
 *
 * @author Fernando Oliveira
 * @author Matheus Cipriano
 * @author João Miguel Freitas
 * @author Tiago Isac Cardoso
 * @date 2025
 */

#ifndef FUNCTIONS_TEAM_2_H
#define FUNCTIONS_TEAM_2_H

#include <stdio.h>
#include <math.h>
#include <ctype.h>

/**
 * @brief Lê elementos inteiros de um vetor do usuário.
 *
 * @param A - Ponteiro para o vetor a ser preenchido.
 * @param tamanho - Número de elementos do vetor.
 *
 * Exemplo de uso:
 * @code
 * int vetor[14];
 * lerArray(vetor, 14);
 * @endcode
 */
void lerArray(int *A, int tamanho);

/**
 * @brief Calcula a média dos elementos de um vetor de inteiros.
 *
 * @param A - Ponteiro para o vetor.
 * @param tamanho - Número de elementos do vetor.
 * @return int Média inteira dos elementos.
 *
 * Exemplo de uso:
 * @code
 * int vetor[14] = {1,2,3,...};
 * int media = mediaArray(vetor, 14);
 * @endcode
 */
float mediaArray(int *A, int tamanho);

/**
 * @brief Imprime os valores do vetor maiores que 2 e divisíveis por 5.
 *
 * @param A - Ponteiro para o vetor.
 * @param tamanho - Número de elementos do vetor.
 *
 * Exemplo de uso:
 * @code
 * maioresValoresDivisiveisPor5(vetor, 14);
 * @endcode
 */
void maioresValoresDivisiveisPor5(int *A, int tamanho);

/**
 * @brief Ordena e imprime o vetor em ordem decrescente.
 *
 * @param A - Ponteiro para o vetor.
 * @param tamanho - Número de elementos do vetor.
 *
 * Exemplo de uso:
 * @code
 * vetorDecrescente(vetor, 14);
 * @endcode
 */
void vetorDecrescente(int *A, int tamanho);

/**
 * @brief Constrói e imprime uma matriz 2x14.
 *
 * A primeira linha contém o vetor original e a segunda linha o vetor
 * ordenado em ordem crescente.
 *
 * @param A - Ponteiro para o vetor original.
 * @param tamanho - Número de elementos do vetor.
 *
 * Exemplo de uso:
 * @code
 * matrizDoisPorCatorze(vetor, 14);
 * @endcode
 */
void matrizDoisPorCatorze(int *A, int tamanho);

/**
 * @brief Calcula e imprime a raiz quadrada de cada elemento do vetor.
 *
 * @param A - Ponteiro para o vetor.
 * @param tamanho - Número de elementos do vetor.
 *
 * Exemplo de uso:
 * @code
 * calculoDaRaizQuadrada(vetor, 14);
 * @endcode
 */
void calculoDaRaizQuadrada(int *A, int tamanho);

/**
 * @brief Imprime instruções de ajuda para o usuário.
 *
 * Fornece informações sobre as funcionalidades do programa e como
 * utilizá-las.
 *
 * Exemplo de uso:
 * @code
 * ajuda();
 * @endcode
 */
void ajuda(void);

/**
 * @brief Devolve o valor mínimo do vetor
 *
 * Compara todos os valores do vetor e devolve o menor deles.
 *
 * @param A - Ponteiro para o vetor original.
 * @param tamanho - Tamanho do vetor origianl.
 *
 * Exemplo de uso:
 * @code
 * minimo(vetor[], 14);
 * @endcode
 */
int minimo(int *A, int tamanho);

/**
 * @brief Calcula e imprime o mínimo múltiplo comum (MMC) de elementos consecutivos de um vetor.
 *
 * Para cada par de elementos consecutivos do vetor @p A, calcula o MMC utilizando
 * a função @ref mmc() e armazena os resultados num vetor auxiliar, que é impresso.
 *
 * @param A - Vetor de inteiros.
 * @param tamanho - Número de elementos do vetor.
 *
 * Exemplo de uso:
 * @code
 * int vetor[14] = {4, 6, 8, 12, ...};
 * mdcDoVetor(vetor, 14);
 * @endcode
 *
 * @see mmc()
 */
void mmcDoVetor(int A[], int tamanho);

/**
 * @brief Calcula o mínimo múltiplo comum (MMC) entre dois inteiros.
 *
 * Recebe dois inteiros @p a e @p b e devolve o seu MMC, utilizando a relação
 * entre MMC e MDC.
 *
 * @param a Primeiro inteiro.
 * @param b Segundo inteiro.
 * @return int O mínimo múltiplo comum de @p a e @p b.
 *
 * Exemplo de uso:
 * @code
 * int resultado = mmc(6, 8); // resultado = 24
 * @endcode
 *
 * @see mdc()
 */
int mmc(int a, int b);

/**
 * @brief Calcula o máximo divisor comum (MDC) entre dois inteiros.
 *
 * Recebe dois inteiros @p a e @p b e devolve o seu MDC utilizando o Algoritmo de Euclides.
 *
 * @param a Primeiro inteiro.
 * @param b Segundo inteiro.
 * @return int O máximo divisor comum de @p a e @p b.
 *
 * Exemplo de uso:
 * @code
 * int resultado = mdc(12, 18); // resultado = 6
 * @endcode
 *
 * @see mmc()
 */
int mdc(int a, int b);


/**
 * @brief Soma o vetor original com o dobro de um segundo vetor fornecido pelo utilizador.
 *
 * Lê um novo vetor @p B com @p N elementos fornecidos pelo utilizador,
 * duplica cada um dos seus valores e soma cada posição de @p A com o vetor
 * já transformado. O resultado é armazenado num vetor auxiliar e impresso.
 *
 * @param A Vetor original.
 * @param N Número de elementos dos vetores.
 *
 * Exemplo de uso:
 * @code
 * somaDeVetores(vetor, 14);
 * @endcode
 */
void somaDeVetores(int A[], int N);

/**
 * @brief Calcula o determinante de uma matriz quadrada NxN usando expansão de Laplace.
 *
 * @param n Dimensão atual da matriz (n x n).
 * @param a Matriz quadrada n x n.
 * @return Determinante da matriz.
 */
long long detLaplace(int n, long long a[n][n]);


/**
 * @brief Calcula o determinante de uma matriz quadrada NxN.
 *
 * Esta função aplica a expansão por Laplace de forma recursiva
 * para determinar o valor do determinante. A cada chamada, é construída
 * uma submatriz menor removendo a primeira linha e uma coluna específica.
 *
 * @param matriz Matriz quadrada NxN usada no cálculo.
 * @param n Dimensão atual da matriz.
 * @return int Determinante da matriz.
 *
 * Exemplo de uso:
 * @code
 * int M[3][100] = {{1,2,3},{0,1,4},{5,6,0}};
 * int det = determinante(M, 3);
 * @endcode
 */

/**
 *@brief
 *
 *Esta função calcula uma matriz 14x14 resultante do vetor inserido inicialmente pelo usuário e de um segundo com o mesmo numero de elementos lido pela função.
 *
 *@param A vetores inseridos pelo usuário.
 *@param N Dimensão da matriz.
 *
 *Exemplo de uso:
 *@code
 *int A[5] = { 1, 2, 3, 4, 5 }
 *matriz(A, 5);
 *@endcode
 */

int **SubMatrix(int **matriz, int o, int l, int c);
// Cria matriz long long
long long **CreateMatrixLongLong(int linhas, int colunas);

// Multiplicação matricial clássica
long long **MultipliMatrix(long long **Matriz_a, int la, int ca, long long **Matriz_b, int lb, int cb);

// Determinante (usando eliminação Gaussiana)
long long det(long long **matriz, int n);

// Função da opção 9
void matriz(int A[], int N);

#endif

