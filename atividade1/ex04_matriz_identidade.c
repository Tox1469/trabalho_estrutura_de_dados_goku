#include <stdio.h>

// Exercicio 04 - Multiplicacao de matriz pela identidade
// A matriz identidade tem 1 na diagonal principal e 0 no resto.
// Propriedade: qualquer matriz multiplicada pela identidade da ela mesma (A * I = A).
// Usei isso para comprovar a propriedade na pratica.

int main() {
    int matriz[3][3], identidade[3][3], resultado[3][3];
    int i, j, k; // k e usado no terceiro laco da multiplicacao

    printf("Digite os elementos da matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Monta a matriz identidade: 1 onde linha == coluna (diagonal), 0 no resto
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (i == j)
                identidade[i][j] = 1;
            else
                identidade[i][j] = 0;
        }
    }

    printf("\nMatriz original:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz identidade:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%4d ", identidade[i][j]);
        }
        printf("\n");
    }

    // Multiplicacao de matrizes: resultado[i][j] = soma dos produtos da linha i de A pela coluna j de B
    // Preciso de tres lacos: i (linha do resultado), j (coluna do resultado), k (elemento acumulado)
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            resultado[i][j] = 0; // inicio em 0 para acumular a soma
            for (k = 0; k < 3; k++) {
                resultado[i][j] += matriz[i][k] * identidade[k][j];
            }
        }
    }

    printf("\nResultado (matriz * identidade):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%4d ", resultado[i][j]);
        }
        printf("\n");
    }

    // Verifico se resultado e igual a matriz original elemento por elemento
    // Uso uma flag (variavel booleana): começa como 1 (verdadeiro) e vira 0 se achar alguma diferenca
    int igual = 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (resultado[i][j] != matriz[i][j]) {
                igual = 0;
            }
        }
    }

    if (igual)
        printf("\nProva: A * I = A -> Confirmado que e a matriz identidade!\n");
    else
        printf("\nErro: os resultados nao coincidem.\n");

    return 0;
}
