#include <stdio.h>

// Exercicio 08 - Usar ponteiros para acessar e dobrar valores de um vetor
// Ponteiro e uma variavel que guarda um endereco de memoria, nao um valor direto.
// int *ptr = arr; faz ptr apontar para o inicio do vetor (arr ja e um ponteiro para arr[0]).
// Acessar *(ptr + i) e o mesmo que arr[i], mas usando aritmetica de ponteiros.

int main() {
    int arr[5];
    int *ptr = arr; // ptr aponta para o primeiro elemento do vetor
    int i;

    printf("Digite 5 numeros inteiros:\n");
    for (i = 0; i < 5; i++) {
        printf("Numero %d: ", i + 1);
        // (ptr + i) e o endereco do elemento i, mesmo que &arr[i]
        scanf("%d", (ptr + i));
    }

    printf("\nDobro de cada valor:\n");
    for (i = 0; i < 5; i++) {
        // *(ptr + i) desreferencia o ponteiro: acessa o valor no endereco (ptr + i)
        printf("%d * 2 = %d\n", *(ptr + i), *(ptr + i) * 2);
    }

    return 0;
}
