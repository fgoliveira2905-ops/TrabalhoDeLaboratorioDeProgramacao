#include <stdio.h>
#include <math.h>
#include "functions-team-2.h"
#define MAX_SIZE 14

/**
 * @file main-team-2.c
 * @mainpage Trabalho de Laboratorio de Programação
 * @brief Programa principal que permite ao utilizador manipular um vetor de inteiros e executar várias operações.
 *
 */

/**
 * Mais informações sobre o projeto podem ser encontradas nas páginas de documentação:
 * - @ref introducao
 * - @ref funcoes
 * - @ref operacoes_matematicas
 */

 /**
 * * Variáveis locais utilizadas:
 * - `N`: tamanho do vetor
 * - `A`: vetor principal de inteiros
 * - `option`: opção escolhida pelo utilizador
 * - `media`: valor da média dos elementos
 * - `min`: valor mínimo encontrado
 *
 * @author Tiago Cardoso
 * @author João Freitas
 * @author Matheus Cipriano
 * @author Fernando Oliveira
 * @date 2025
 */

int main(int argc, char *argv[]) {
    // Verifica flags de linha de comandos (--help)
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0) {
            ajuda();
            return 0;
        }
    }

    int N = MAX_SIZE;
    int A[N];
    int option;
    int media;
    int min;

    /* Tela que pede que o ultilizador pressione ENTER para continuar */
    do {
        printf("Bem vindo ao programa feito para o trabalho de Laboratorio de Programacao\nDigite ENTER para continuar. \n");
    } while (getchar() != '\n');

    /* Pede para o usuário inserir um vetor */
    printf("Escreva os numeros do vetor entre -5 e 32.\n");
    lerArray(A, N);

    /* Ecrã de opções */
    printf("Escolha uma das opcoes:\n");
    printf("1 - Cálculo da média de todos os elementos no vetor\n");
    printf("2 - Devolução dos valores maiores que dois e divisíveis por cinco\n");
    printf("3 - Devolução do vetor ordenado por ordem decrescente\n");
    printf("4 - Construção de uma matriz dois por 14, em que cada linha é composta pelo vetor lido e pelo vetor ordenado por ordem crescente\n");
    printf("5 - Cálculo da raíz quadrada de todos os elementos no vetor\n");
    printf("6 - Identificação do mínimo de todos os elementos do vetor\n");
    printf("7 - Ajuda\n");
    printf("8 - Cálculo do mínimo múltiplo comum de cada dois números seguidos do vetor\n");
    printf("9 - Leitura  de  um novo vetor  1x14,  cálculo  e  devolução  da  matriz 14x14 resultante do produto do vetor inicial com o novo vetor gerado\n");
    printf("10 − Determinante da matriz anterior (nota: carregar no 9 primeiro para obter a matriz)\n");
    printf("11 - Leitura de um novo vetor, cálculo e devolução da  soma  do  primeiro vetor com o dobro do segundo\n");

    do {
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\n");
                media = mediaArray(A, N);
                printf("Media dos elementos do vetor: %d\n", media);
                break;
            case 2:
                printf("\n");
                maioresValoresDivisiveisPor5(A, N);
                break;
            case 3:
                printf("\n");
                vetorDecrescente(A, N);
                break;
            case 4:
                printf("\n");
                matrizDoisPorCatorze(A, N);
                break;
            case 5:
                calculoDaRaizQuadrada(A, N);
                break;
            case 6:
                min = minimo(A, N);
                printf("Valor minimo do vetor: %d\n", min);
                break;
            case 7:
                printf("\n");
                ajuda();
                printf("\n");
                break;
            case 8:
                mmcDoVetor(A, N);
                break;
            case 9:
                ConstruirMatriz(A, N);
                break;
            case 10:
                printf("E necessario outra matriz para esta opcao (Carregue 9 primeiro).\nInserir outro numero: ");
                break;
            case 11:
                somaDeVetores(A, N);
                break;
        }
    } while (option < 1 || option > 11 || option == 10);
    
    return 0;
}

/**
 * @page introducao Introdução
 *
 * Este projeto foi desenvolvido no contexto da unidade curricular de Laboratório
 * de Programação e tem como objetivo principal reforçar conceitos fundamentais
 * de algoritmia e manipulação de vetores e matrizes em linguagem C.
 *
 * Além disso, visa aperfeiçoar o uso de ferramentas de documentação como Doxygen
 * e a integração de notação matemática com LaTeX para melhorar a clareza e a
 * apresentação da documentação técnica.
 *
 * O utilizador interage com um vetor de 14 inteiros e pode executar operações
 * como cálculo de média, ordenação, filtragem, construção de matrizes,
 * operações matemáticas e análises específicas.
 * 
 */

/**
 * @page funcoes Funções
 *
 * Esta página descreve as principais funções disponibilizadas pelo programa,
 * todas elas declaradas em `functions-team-2.h` e implementadas no respetivo
 * ficheiro `.c`. As funções operam sobre um array de inteiros e permitem ao
 * utilizador executar operações de processamento, análise e construção de matrizes.
 *
 * Lista de funções:
 *
 * - `mediaArray()` — calcula a média aritmética dos elementos do array.
 * - `maioresValoresDivisiveisPor5()` — imprime valores maiores que 2 e divisíveis por 5.
 * - `vetorDecrescente()` — ordena o array por ordem decrescente e imprime-o.
 * - `matrizDoisPorCatorze()` — constrói uma matriz 2×N usando o array original e o ordenado.
 * - `calculoDaRaizQuadrada()` — calcula e imprime a raiz quadrada para cada elemento.
 * - `minimo()` — devolve o menor valor presente no array.
 * - `mmcDoVetor()` — calcula o MMC para cada par consecutivo do array.
 * - `mmc()` — calcula o mínimo múltiplo comum entre dois inteiros.
 * - `mdc()` — calcula o máximo divisor comum entre dois inteiros.
 * - `somaDeVetores()` — soma o array original com o dobro de um novo array introduzido.
 * - `MultiplicarMatrizes()` — efetua a multiplicação entre duas matrizes.
 * - `ConstruirMatriz()` — constrói a matriz 14×14 resultante do produto externo entre dois arrays.
 *
 * @page operacoes_matematicas Operações Matemáticas
 *
 * Esta página descreve todas as operações matemáticas realizadas no âmbito do
 * programa, permitindo ao utilizador analisar o comportamento numérico do vetor.
 *
 * Operações abordadas:
 *
 * - **Cálculo da média:** soma dos elementos dividida pelo número total.
 * - **Cálculo da raiz quadrada:** transformação de cada elemento para sua raiz.
 * - **Mínimo dos elementos:** identificação do menor valor presente.
 * - **Ordenação:** organização do vetor de forma crescente ou decrescente.
 * - **MMC de pares de números:** cálculo do mínimo múltiplo comum entre elementos consecutivos.
 * - **Produto de vetores para formar matriz:** criação de uma matriz 14x14 a partir do vetor inicial.
 * - **Soma de um vetor pelo dobro de um segundo vetor inserido pelo usuário**
 * - **Mínimo Múltiplo Comum:** cálculo do mínimo múltiplo comum de dois elementos consecutivos de um vetor.
 * - **Multiplicação de matrizes:** cálculo da múltiplicação de duas matrizes.
 */
