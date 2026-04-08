#include <stdio.h>

int main() {
    int matriz[3][3], identidade[3][3], resultado[3][3];
    int i, j, k;

    printf("Digite os elementos da matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Monta a matriz identidade
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

    // Multiplicacao: matriz * identidade = resultado
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            resultado[i][j] = 0;
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

    // Verifica se resultado == original
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
