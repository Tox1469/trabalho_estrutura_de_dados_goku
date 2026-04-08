#include <stdio.h>

int main() {
    int vetor[5];
    int i;

    printf("Digite 5 numeros inteiros:\n");
    for (i = 0; i < 5; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor na ordem inversa:\n");
    for (i = 4; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
