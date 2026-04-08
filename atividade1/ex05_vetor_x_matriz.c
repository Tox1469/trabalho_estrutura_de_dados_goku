#include <stdio.h>

// Exercicio 05 - Multiplicacao de vetor por matriz (vetor-linha x colunas da matriz)
// Na multiplicacao vetor x matriz, cada posicao do resultado e o produto do vetor
// pelos elementos de uma coluna inteira da matriz, somando tudo.
// resultado[j] = vetor[0]*matriz[0][j] + vetor[1]*matriz[1][j] + vetor[2]*matriz[2][j]

int main() {
    int vetor[3], matriz[3][3], resultado[3];
    int i, j;

    printf("Digite os 3 elementos do vetor:\n");
    for (i = 0; i < 3; i++) {
        printf("Vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("\nDigite os elementos da matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Para cada coluna j, percorro todas as linhas i e acumulo o produto
    // O laco externo e por coluna (j) porque o resultado tem uma posicao por coluna da matriz
    for (j = 0; j < 3; j++) {
        resultado[j] = 0;
        for (i = 0; i < 3; i++) {
            resultado[j] += vetor[i] * matriz[i][j];
        }
    }

    printf("\nVetor: ");
    for (i = 0; i < 3; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\nMatriz:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nResultado (vetor x colunas da matriz): ");
    for (j = 0; j < 3; j++) {
        printf("%d ", resultado[j]);
    }
    printf("\n");

    return 0;
}
