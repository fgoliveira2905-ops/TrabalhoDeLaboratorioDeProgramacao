/**
 * @file functions-1.c
 * @brief Funções utilitárias para manipulação de vetores e operações matemáticas.
 *
 * @mainpage
 * # Documentação das Funções
 * Este arquivo contém funções para leitura, escrita e manipulação de vetores de inteiros, além de operações matemáticas e uma página de ajuda.
 *
 * - @subpage page_vetores
 * - @subpage page_operacoes
 * - @subpage page_ajuda
 */

/**
 * @page page_vetores Leitura e escrita de vetores
 * Funções para ler e escrever vetores de inteiros, garantindo que os valores estejam dentro dos limites especificados.
 * - lerArray()
 * - escreverArray()
 */

/**
 * @page page_operacoes Operações matemáticas
 * Funções para operações matemáticas sobre vetores, como cálculo de média, filtragem, ordenação, criação de matriz e cálculo de raiz quadrada.
 * - mediaArray()
 * - maioresValoresDivisiveisPor5()
 * - vetorDecrescente()
 * - matrizDoisPorCatorze()
 * - calculoDaRaizQuadrada()
 * - determinante()
 */

/**
 * @page page_ajuda Página de ajuda
 * Função que imprime a explicação das opções disponíveis para o usuário.
 * - ajuda()
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief Lê os valores de um vetor dentro de um intervalo específico.
 *
 * Esta função solicita ao utilizador valores entre -5 e 32 e armazena-os
 * no vetor fornecido.
 *
 * @param nome - Vetor onde os valores serão armazenados.
 * @param tamanho - Número de elementos a serem lidos.
 */

void lerArray(int nome[], int tamanho) {
    
    int i;
    for(i = 0; i < tamanho; i++) {
        do {
            printf("Insira o %d elemento do vetor entre -5 e 32: ", i+1);
            scanf("%d", &nome[i]);
        } while(nome[i] < -5 || nome[i] > 32);
    }
    
    
}

/**
 * @brief Escreve no ecrã os elementos de um vetor.
 *
 * Imprime todos os valores do vetor separados por espaços.
 *
 * @param nome - Vetor a ser escrito.
 * @param tamanho - Número de elementos do vetor.
 */

void escreverArray(int nome[], int tamanho) {
    
    int i;
    
    for (i = 0; i < tamanho; i++) {
        printf("%d ", nome[i]);
    }
    printf("\n");
}

/**
 * @brief Calcula a média dos elementos de um vetor.
 *
 * Soma todos os elementos e divide pelo número total de posições.
 *
 * @param nome - Vetor cujos valores serão utilizados.
 * @param tamanho - Número de elementos do vetor.
 * @return Média dos valores presentes no vetor.
 */

float mediaArray(int nome[], int tamanho) {
    
    int i;
    int soma = 0, media;
    
    for (i = 0; i < tamanho; i++) {
        soma = soma + nome[i];
    }
    
    media = soma / tamanho;
    
    return media;
}


/**
 * @brief Cria e escreve um vetor com valores maiores que 2 e divisíveis por 5.
 *
 * Filtra o vetor original e armazena apenas os elementos que são maiores
 * que 2 e múltiplos de 5, escrevendo o resultado no ecrã.
 *
 * @param A - Vetor original a ser filtrado.
 * @param tamanho - Número de elementos do vetor original.
 */

void maioresValoresDivisiveisPor5(int A[], int tamanho) {
    int i, contador = 0;

    // Primeiro contamos quantos elementos servem
    for (i = 0; i < tamanho; i++) {
        if (A[i] > 2 && A[i] % 5 == 0) {
            contador++;
        }
    }

    // Criamos um array só para os valores válidos
    int *validos = calloc(contador, sizeof(int));

    int j = 0;
    for (i = 0; i < tamanho; i++) {
        if (A[i] > 2 && A[i] % 5 == 0) {
            validos[j] = A[i];
            j++;
        }
    }

    // Escrevemos
    escreverArray(validos, contador);

    free(validos);
}

/**
 * @brief Cria e escreve um vetor ordenado por ordem decrescente.
 *
 * Esta função recebe um vetor e cria um novo vetor B onde os elementos
 * aparecem por ordem decrescente a do vetor original. No fim, escreve o vetor
 * resultante no ecrã.
 *
 * @param nome - Vetor original.
 * @param tamanho - Número de elementos do vetor.
 */

void vetorDecrescente(int nome[], int tamanho) {
    int *B = calloc(tamanho, sizeof(int));
    
    // Copiar os valores para não modificar o original
    for (int i = 0; i < tamanho; i++) {
        B[i] = nome[i];
    }

    // Bubble sort decrescente
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (B[j] < B[j + 1]) { // trocar se o da frente for menor
                int aux = B[j];
                B[j] = B[j + 1];
                B[j + 1] = aux;
            }
        }
    }

    // Escrever vetor ordenado
    escreverArray(B, tamanho);

    free(B);
}

/**
 * @brief Cria uma matriz 2×N composta pelo vetor original e pelo vetor original ordenado por ordem crescente.
 *
 * Esta função recebe um vetor A, calcula o vetor B correspondente a A
 * ordenado por ordem crescente e cria uma matriz C com duas linhas:
 * - Linha 0: elementos do vetor A.
 * - Linha 1: elementos do vetor B.
 *
 * No final, imprime a matriz resultante.
 *
 * @param A - Vetor original.
 * @param tamanho - Número de elementos do vetor.
 */

void matrizDoisPorCatorze(int A[], int tamanho) {
    int C[2][tamanho];
    int i, j, aux;

    // Copiar vetor original para B
    int *B = calloc(tamanho, sizeof(int));
    for (i = 0; i < tamanho; i++) {
        B[i] = A[i];
    }

    // Bubble sort crescente
    // Bubble sort - é um algorítmo que ordena uma lista comparando dois elementos de cada vez e trocando-os se estiverem na ordem errada.
    // Neste caso, ele compara cada elemento do vetor original e verifica se é maior ou menor que o próximo elemento, se for maior, ele troca os elementos de lugar.
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) { // "j < tamanho - i - 1" garante que não vão ser comparados valores que já estão no lugar certo (a cada loop, os maiores vão se acumulando no fim do vetor)
            if (B[j] > B[j + 1]) { // trocar se o da frente for maior
                aux = B[j];
                B[j] = B[j + 1];
                B[j + 1] = aux;
            }
        }
    }

    // Construir a matriz
    for (i = 0; i < tamanho; i++) {
        C[0][i] = A[i]; // vetor original
        C[1][i] = B[i]; // vetor ordenado crescente
    }

    // Escrever matriz
    for (i = 0; i < 2; i++) {
        for (j = 0; j < tamanho; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    free(B);
}

/**
 * @brief Calcula a raiz quadrada de todos os elementos do vetor
 *
 *Esta função recebe um vetor "nome[]" e calcula a raiz quadrada de todos os elementos do vetor e transfere-os para um novo vetor "**matrizDaRaiz[]**"
 *
 *No final, imprime o novo vetor "matrizDaRaiz[]"
 *
 * @param nome - Vetor original.
 * @param tamanho - Número de elementos no vetor
 */
void calculoDaRaizQuadrada(int nome[], int tamanho) {
    
    int matrizDaRaiz[tamanho], i;
    

    for (i = 0; i < tamanho; i++) {
        matrizDaRaiz[i] = sqrt(nome[i]);
    }

    escreverArray(matrizDaRaiz, tamanho);
}

/**
 *@brief Página de ajuda
 *
 *Esta função dá uma breve explicação do que cada opção que o usuário pode ultilizar fazer
 *
 */

void ajuda(void) {
    printf("=== PAGINA DE AJUDA ===\n");
    printf("1 - Ler um vetor de 14 numeros inteiros: Permite ao utilizador inserir 14 valores para serem armazenados no vetor.\n");
    printf("2 - Calcular a media dos elementos: Calcula a media aritmetica de todos os numeros do vetor.\n");
    printf("3 - Devolver valores maiores que 2 e divisiveis por 5: Mostra apenas os elementos do vetor que satisfazem essas condicoes.\n");
    printf("4 - Ordenar o vetor em ordem decrescente: Reorganiza os elementos do vetor do maior para o menor.\n");
    printf("5 - Construir uma matriz 2x14 com o vetor original e o vetor ordenado: Cria uma matriz onde a primeira linha e o vetor original e a segunda linha e o vetor ordenado.\n");
    printf("6 - Calcular a raiz quadrada de todos os elementos: Mostra a raiz quadrada de cada elemento do vetor.\n");
    printf("7 - Identificar o minimo dos elementos: Retorna o menor valor presente no vetor.\n");
    printf("8 - Calcular o minimo multiplo comum de pares de elementos: Calcula o MMC de cada par de numeros consecutivos do vetor.\n");
    printf("9 - Gerar produtos e somas de vetores: Permite criar um novo vetor e calcula o produto do vetor inicial com este novo vetor, gerando uma matriz 14x14.\n");
    printf("10 - Calcular o determinante da matriz anterior: Calcula o determinante da matriz 14x14 obtida na opcao 9.\n");
    printf("11 - Leitura de um novo vetor e soma com o dobro do segundo vetor: Permite criar um novo vetor e soma o vetor inicial com o dobro deste novo vetor.\n");
    printf("========================\n");
}

/**
 * @brief Devolve o valor mínimo do vetor
 *
 *Esta função recebe um vetor "nome[]" e compara todos os seus elementos.
 *
 * No final, devolve o valor mínimo entre os elementos do vetor
 *
 * @param A - Vetor original.
 * @param tamanho - Número de elementos no vetor
 * @return - O menor valor encontrado no vetor.
 */
int minimo(int A[], int tamanho) {
    int min, i;
    
    min = A[0];
    for (i = 1; i < tamanho; i++) {
        if (A[i] <= min) {
            min = A[i];
        }
    }
    return min;
}

/**
 * @brief Devolve o valor do mínimo divisor comum de dois numeros inteiros.
 *
 *Esta função recebe um valor de @p a e @p b e então devolve o mínimo divisor comum entre esses
 *números ultilzando o Algoritmo de Euclides.
 *
 *@param a - Primeiro valor recebido.
 *@param b - Segundo valor recebido.
 *@return - Devolve só o valor de @p a
 *
 *@note No final do loop, se @p b = 0, então MDC(a, b) = a.
 *@see mmc() Para calcular o mínimo múltiplo comum usando o MDC.
 *@see mdcDoVetor() Essa função é apenas usada na função mdcDoVetor.
 * */
int mdc(int a, int b) {
    int aux;
    
    while(b != 0) {
        aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

/**
 *@brief Devolve o valor do máximo múltiplo comum
 *
 *Está função depende da função mdc() para funcionar.
 *Ultiliza da fórmula mmc(a, b) = (a x b) / mdc(a, b) para calcular o máximo múltiplo comum.
 *
 *@param a - Primeiro valor recebido.
 *@param b - Segundo valor recebido.
 *@return - Devolve o valor do máximo múltiplo comum entre @p a e @p b.
 *
 *@see mdc() Essa função depende da função mdc() para funcionar.
 *@see mdcDoVetor() Essa função é apenas usada na função mdcDoVetor.
 */

int mmc(int a, int b) {
    return (a * b)/mdc(a, b);
}

/**
 * @brief Calcula o mínimo múltiplo comum (MMC) de elementos consecutivos de um vetor.
 *
 * Esta função recebe um vetor @p A de inteiros e calcula o MMC de cada par de elementos
 * consecutivos, armazenando os resultados num vetor auxiliar @p B. Por fim, imprime
 * todos os valores calculados.
 *
 * @param A - Vetor de inteiros fornecido pelo usuário.
 * @param tamanho - Número de elementos do vetor @p A.
 *
 * @note O vetor resultante @p B terá tamanho igual a @p tamanho - 1,
 * pois cada elemento representa o MMC de um par de elementos consecutivos do vetor original.
 *
 * @note Essa função depende de da função mmc() e mdc().
 * @see mmc() Para calcular o mínimo múltiplo comum entre dois inteiros.
 * @see mdc() Para calcular o mínimo divisor comum entre dois inteiros.
 */
void mmcDoVetor(int A[],int tamanho) {
    
    int i, *B;
    
    B = calloc(tamanho - 1, sizeof(int));
    
    for(i = 0; i < tamanho - 1; i++) {
        B[i] = mmc(A[i], A[i + 1]);
    }
    printf("Mínimos multiplos comuns entre dois elementos do vetor inserido: \n");
    escreverArray(B, tamanho - 1);
    
    free(B);
    
}

/**
 * @brief Soma um vetor original com o dobro de um segundo vetor inserido pelo utilizador.
 *
 * Esta função lê um novo vetor @p B com @p N elementos fornecidos pelo utilizador,
 * duplica todos os seus valores e, em seguida, soma cada posição do vetor original @p A
 * com o vetor @p B já transformado.
 *
 * O resultado dessa soma é armazenado num vetor auxiliar e impresso no ecrã.
 *
 * @param A Vetor original.
 * @param N Número de elementos dos vetores.
 *
 * @note O vetor inserido pelo utilizador é modificado para conter o dobro dos seus valores
 * antes da operação de soma.
 */
void somaDeVetores(int A[], int N) {
    int B[N];
    int i, VetorSoma[N];
    
    //Lê o novo vetor
    for (i = 0; i < N; i++) {
        printf("Insira o %d elemento do novo vetor: ", i + 1);
        scanf("%d", &B[i]);
    }
    
    //Transforma os elementos do vetor inserido no dobro deles
    for (i = 0; i < N; i++) {
        B[i] = 2 * B[i];
    }
    
    //Soma os dois vetores
    for(i = 0; i < N; i++) {
        VetorSoma[i] = A[i] + B[i];
    }
        
    //Imprime o novo vetor resultante da soma
    printf("Soma do vetor original pelo dobro do segundo vetor inserido: \n");
    escreverArray(VetorSoma, N);
}

/**
 @brief Cálculo de uma matriz NxN
 *
 * Esta função utiliza expansão por Laplace de forma recursiva para calcular
 * o determinante de uma matriz quadrada de dimensão N. A cada passo, é criada
 * uma submatriz (menor complementar) removendo a primeira linha e a coluna atual.
 *
 * @param matriz Matriz quadrada NxN cujos valores serão usados no cálculo.
 * @param n Dimensão atual da matriz (N > 1).
 * @return Valor inteiro correspondente ao determinante da matriz.
 *
 */
int determinante(int matriz[][100], int n) {

    int submatriz[n][n];
    int det = 0, x;

    for (x = 0; x < n; x++) {

        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;

                submatriz[subi][subj] = matriz[i][j];
                subj++;
            }
            subi++;
        }

        int sinal = (x % 2 == 0) ? 1 : -1;
        det = det + sinal * matriz[0][x] * determinante(submatriz, n - 1);
    }

    return det;
}
    
/**
 *@brief Devolução de uma matriz 14x14
 *
 *
 *
 */
void matriz(int A[], int N) {
    
    int b[N], i, k;
    int matriz[N][N];
    int soma = 0;
    char option;
    int det;
    
    printf("Insira um novo vetor de 14 elementos. \n");
    ecreverArray(b, N);
    
    //Matriz resultante da multiplicação das anteriores
    for(i = 0; i < N; i++) {
        for (k = 0; k < N; i++) {
            matriz[i][k] = A[i] * B[k];
        }
    }

    //Escrita da matriz
    for (i = 0; i < N; i++) {
        for (k = 0; k < N; k++) {
            printf("%d ", matriz[i][j]);
        }
    }
    
    printf("Deseja calular o determinante da matriz (Y - Sim / N - Nao)?\n");
    scanf("%c ", &option);
    
    switch (option) {
        case 'y' || 'Y':
            det = determinante(matriz, N);
            printf("Determinante da matriz: %d", det);
            break;
        case 'n' || 'N':
        
            break;
    }
    
}
