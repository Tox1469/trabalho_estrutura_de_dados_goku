#include <stdio.h>

int ordenar(int *a, int *b, int *c) {
    int temp;

    // Ordena os 3 valores em ordem crescente usando troca (bubble)
    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }
    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }

    // Retorna 1 se todos iguais, 0 se diferentes
    if (*a == *b && *b == *c)
        return 1;
    else
        return 0;
}

int main() {
    int x, y, z, resultado;

    printf("Digite tres valores inteiros:\n");
    printf("Valor 1: ");
    scanf("%d", &x);
    printf("Valor 2: ");
    scanf("%d", &y);
    printf("Valor 3: ");
    scanf("%d", &z);

    resultado = ordenar(&x, &y, &z);

    printf("\nValores ordenados:\n");
    printf("Primeiro (menor): %d\n", x);
    printf("Segundo (meio):   %d\n", y);
    printf("Terceiro (maior): %d\n", z);

    if (resultado)
        printf("\nOs tres valores sao iguais (retorno = 1).\n");
    else
        printf("\nExistem valores diferentes (retorno = 0).\n");

    return 0;
}
