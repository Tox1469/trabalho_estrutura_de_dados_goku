#include <stdio.h>

int main() {
    int matriz[3][3];
    int i, j;

    printf("Digite os elementos da matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz original:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Multiplica cada elemento por 5
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
