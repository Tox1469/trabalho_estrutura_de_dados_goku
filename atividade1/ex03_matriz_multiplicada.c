#include <stdio.h>

// Exercicio 03 - Matriz 3x3 multiplicada por 5
// Matriz e basicamente um vetor de vetores: duas dimensoes [linha][coluna].
// Uso dois lacos for aninhados (um dentro do outro) para percorrer linha por linha.

int main() {
    int matriz[3][3]; // 3 linhas, 3 colunas = 9 posicoes no total
    int i, j;         // i = indice da linha, j = indice da coluna

    printf("Digite os elementos da matriz 3x3:\n");

    // Laco externo percorre as linhas, laco interno percorre as colunas
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz original:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%4d ", matriz[i][j]); // %4d reserva 4 espacos para alinhar os numeros
        }
        printf("\n"); // pulo de linha ao terminar cada linha da matriz
    }

    // Multiplica cada elemento por 5 usando o operador *= (equivale a matriz[i][j] = matriz[i][j] * 5)
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz[i][j] *= 5;
        }
    }

    printf("\nMatriz multiplicada por 5:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
