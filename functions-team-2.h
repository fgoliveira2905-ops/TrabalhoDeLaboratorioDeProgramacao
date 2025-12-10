/**
 * @file functions-team-2.h
 * @brief Declarações de funções auxiliares para manipulação de arrays e matrizes.
 *
 * Este ficheiro contém as interfaces das funções utilizadas no programa principal
 * para leitura, processamento e apresentação de dados armazenados em arrays e
 * matrizes de inteiros.
 *
 * As funções incluem cálculos numéricos, operações sobre arrays, construção de
 * matrizes e outras utilidades.
 *
 * @authors Fernando Oliveira, Matheus Cipriano,
 *          João Miguel Freitas, Tiago Isac Cardoso
 * @date 2025
 */

#ifndef FUNCTIONS_TEAM_2_H
#define FUNCTIONS_TEAM_2_H

#include <stdio.h>
#include <math.h>

/**
 *@brief Recebe valores de um array de duas dimensões.
 *
 *Recebe o numero de linhas (@p i ) e o numero de colunas (@p j) e devolve um array de duas dimensões.
 *
 *@param i - Número de linhas do array.
 *@param j - Número de colunas do array.
 *@return Retorna um ponteiro para o array contruido.
 */
int **Array2D(int i, int j);

/**
 *@brief Escreve um array de duas dimensões.
 *
 *Recebe um array de duas dimensões (@p Matriz ), seu número de linhas (@p l ), seu número de colunas (@p c ) e imprime na tela o array.
 *
 *@param Matriz - Array de duas dimensões.
 *@param l - Número de linhas do array.
 *@param c - Número de colunas do arrray.
 *@return void
 */
void escreverArray2D(int **Matriz, int l, int c);

/**
 * @brief Lê um array de inteiros a partir da entrada do utilizador.
 *
 * Preenche o array fornecido com valores introduzidos pelo utilizador.
 *
 * @param A Ponteiro para o array a preencher.
 * @param tamanho Número de elementos a ler.
 * @return void
 */
void lerArray(int *A, int tamanho);

/**
 * @brief Calcula a média dos elementos de um array.
 *
 * A média é devolvida como valor em virgula flutuante.
 *
 * @param A Array de inteiros.
 * @param tamanho Número de elementos.
 * @return float Média calculada.
 */
float mediaArray(int *A, int tamanho);

/**
 * @brief Imprime valores maiores que 2 e divisíveis por 5.
 *
 * Percorre o array e imprime apenas os valores que cumprem as condições.
 *
 * @param A Array de inteiros.
 * @param tamanho Número de elementos.
 * @return void
 */
void maioresValoresDivisiveisPor5(int *A, int tamanho);

/**
 * @brief Ordena e imprime o array em ordem decrescente.
 *
 * @param A Array de inteiros.
 * @param tamanho Número de elementos.
 * @return void
 */
void vetorDecrescente(int *A, int tamanho);

/**
 * @brief Constrói e imprime uma matriz 2xN.
 *
 * A primeira linha contém o array original e a segunda o array ordenado
 * crescentemente.
 *
 * @param A Array original.
 * @param tamanho Número de elementos.
 * @return void
 */
void matrizDoisPorCatorze(int *A, int tamanho);

/**
 * @brief Calcula e imprime a raiz quadrada de cada elemento.
 *
 * @param A Array de inteiros.
 * @param tamanho Número de elementos.
 * @return void
 */
void calculoDaRaizQuadrada(int *A, int tamanho);

/**
 * @brief Imprime a ajuda do programa.
 *
 * @return void
 */
void ajuda(void);

/**
 * @brief Devolve o valor mínimo de um array.
 *
 * @param A Array de inteiros.
 * @param tamanho Número de elementos.
 * @return int Menor valor encontrado.
 */
int minimo(int *A, int tamanho);

/**
 * @brief Calcula o MMC entre pares consecutivos do array.
 *
 * @param A Array de inteiros.
 * @param tamanho Número de elementos.
 * @return void
 */
void mmcDoVetor(int A[], int tamanho);

/**
 * @brief Calcula o mínimo múltiplo comum entre dois inteiros.
 *
 * @param a Primeiro inteiro.
 * @param b Segundo inteiro.
 * @return int MMC de a e b.
 */
int mmc(int a, int b);

/**
 * @brief Calcula o máximo divisor comum entre dois inteiros.
 *
 * @param a Primeiro inteiro.
 * @param b Segundo inteiro.
 * @return int MDC de a e b.
 */
int mdc(int a, int b);

/**
 * @brief Soma o array original com o dobro de um segundo array fornecido.
 *
 * Lê um array B, duplica os valores e soma à posição correspondente de A.
 *
 * @param A Array original.
 * @param N Número de elementos.
 * @return void
 */
void somaDeVetores(int A[], int N);

/**
 * @brief Multiplica duas matrizes.
 *
 *
 *
 * @param Matriz_a Primeira matriz.
 * @param la Linhas da primeira matriz.
 * @param ca Colunas da primeira matriz.
 * @param Matriz_b Segunda matriz.
 * @param lb Linhas da segunda matriz.
 * @param cb Colunas da segunda matriz.
 * @return int** Matriz resultante.
 */
int **MultiplicarMatrizes(int **Matriz_a, int la, int ca, int **Matriz_b, int lb, int cb);

/**
 * @brief Constrói e imprime uma matriz quadrada a partir de um array.
 *
 * @param A Array de inteiros.
 * @param N Número de elementos.
 * @return void
 */
void ConstruirMatriz(int *A, int N);


void determinante(int **A);

#endif
