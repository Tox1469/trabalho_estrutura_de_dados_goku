#include <stdio.h>

// Exercicio 02 - Vetor na ordem inversa
// Vetor e uma sequencia de variaveis do mesmo tipo guardadas juntas na memoria.
// Aqui eu uso um vetor de 5 inteiros e imprimo do ultimo pro primeiro.

int main() {
    int vetor[5]; // reservo espaco para 5 numeros inteiros (indices 0 a 4)
    int i;        // variavel de controle dos lacos for

    printf("Digite 5 numeros inteiros:\n");

    // Preencho o vetor da posicao 0 ate 4
    // O & antes de vetor[i] passa o endereco da posicao para o scanf poder gravar la
    for (i = 0; i < 5; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor na ordem inversa:\n");

    // Começo pelo indice 4 (ultimo) e vou ate o 0 (primeiro)
    for (i = 4; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
