/**
 * @file functions-team-2.c
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
 * - MultiplicarMatrizes()
 */

/**
 * @page page_ajuda Página de ajuda
 * Função que imprime a explicação das opções disponíveis para o usuário.
 * - ajuda()
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "functions-team-2.h"
#define TAM 14

int **Array2D(int i, int j)
{
    int **Matriz = (int**)malloc(i * sizeof(int *));
    for (int cont = 0; cont < i; cont++)
        Matriz[cont] = (int*)malloc(j * sizeof(int));
    return Matriz;
}

void escreverArray2D(int **Matriz, int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%5d", Matriz[i][j]);
        }
        printf("\n");
    }
}

void lerArray(int nome[], int tamanho) {
    
    int i;
    for(i = 0; i < tamanho; i++) {
        do {
            printf("Insira o %d elemento do vetor entre -5 e 32: ", i+1);
            scanf("%d", &nome[i]);
        } while(nome[i] < -5 || nome[i] > 32);
    }
    
    
}

void escreverArray(int nome[], int tamanho) {
    
    int i;
    
    for (i = 0; i < tamanho; i++) {
        printf("%d ", nome[i]);
    }
    printf("\n");
}

float mediaArray(int *A, int tamanho) {
    
    int i;
    int soma = 0, media;
    
    for (i = 0; i < tamanho; i++) {
        soma = soma + A[i];
    }
    
    media = soma / tamanho;
    
    return media;
}

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




void calculoDaRaizQuadrada(int A[], int tamanho) {
    int i;
    printf("Raiz quadrada dos elementos do vetor:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%.2f ", sqrt(A[i]));
    }
    printf("\n");
}

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

int mdc(int a, int b) {
    int aux;
    
    while(b != 0) {
        aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

int mmc(int a, int b) {
    return (a * b)/mdc(a, b);
}

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

int **MultiplicarMatrizes(int **Matriz_a, int la, int ca, int **Matriz_b, int lb, int cb)
{
    int **resultado = Array2D(la, cb);
    for (int i = 0; i < la; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            resultado[i][j] = 0;
            for (int w = 0; w < ca; w++)
            {
                resultado[i][j] += (Matriz_a[i][w] * Matriz_b[w][j]);
            }
        }
    }
    return resultado;
}

void ConstruirMatriz(int *A_1D, int N) {
    
    int **B_matrix;
    int **A_matrix;
    int **matriz_result;
    int i;
    
    //Aloca um espaço para o novo vetor
    B_matrix = Array2D(N, 1);

    //Aloca espaço para o novo array de 2 dimensões e passa os elementos de A_matriz para lá.
    A_matrix = Array2D(1, N);
    for (i = 0; i < N; i++) {
        A_matrix[0][i] = A_1D[i];
    }
    
    printf("Insira o segundo vetor.\n");
    for (i = 0; i < N; i++) {
        printf("Insira o %d elemento do vetor: ", i+1);
        scanf("%d", &B_matrix[i][0]);
    }
    
    matriz_result = MultiplicarMatrizes(B_matrix, N, 1, A_matrix, 1, N);
    printf("\n");
    
    printf("Matriz gerada:\n");
    escreverArray2D(matriz_result, N, N);
    
    //liberta o array B_matrix
    for (i = 0; i < N; i++) {
        free(B_matrix[i]);
    }
    free(B_matrix);

    for (i = 0; i < 1; i++) { //A_matrix só precisa de ter os elementos eliminados de uma "linha"
        free(A_matrix[i]);
    }
    free(A_matrix);
    
    int choice;
    printf("Deseja calcular o determiante da matriz inserida (1 - Sim / 0 - Nao)? ");
    scanf("%d", &choice);
    if (choice == 1) {
        determinante(matriz_result);
        
        //Liberta a matriz_result
        for (i = 0; i < N; i++) {
            free(matriz_result[i]);
        }
        free(matriz_result);
    } else if (choice == 2) {
        //Liberta a matriz_result
        for (i = 0; i < N; i++) {
            free(matriz_result[i]);
        }
        free(matriz_result);
        
    }
    
}

void determinante(int **matriz) {

    // Vamos usar uma c�pia para n�o mudar a matriz original durante o c�lculo
    float CopiaMatriz[TAM][TAM];
    float determinante = 1;
    float fator;


    // Copia a matriz
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            CopiaMatriz[i][j] = matriz[i][j];
        }
    }

    // Método de Eliminação de Gauss-Jordan
    for (int i = 0; i < TAM; i++) {
        // Se encontrar 0 na diagonal, assumimos det = 0.
        if (CopiaMatriz[i][i] == 0) {
            determinante = 0;
            break;
        }
        for (int k = i + 1; k < TAM; k++) {
            // Calcula quanto temos de subtrair para dar reset naquele número
            fator = CopiaMatriz[k][i] / CopiaMatriz[i][i];
            // Subtrai a linha inteira
            for (int j = i; j < TAM; j++) {
                CopiaMatriz[k][j] -= fator * CopiaMatriz[i][j];
            }
        }
    }

    // Se não deu reset no meio do caminho, multiplica a diagonal principal
    if (determinante != 0) {
        for (int i = 0; i < TAM; i++) {
            determinante *= CopiaMatriz[i][i];
        }
    }

    printf("\nDeterminante: %f\n", determinante);
}
