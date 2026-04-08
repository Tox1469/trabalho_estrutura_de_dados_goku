#include <stdio.h>

// Exercicio 09 - Ordenar 3 valores por referencia (passagem por ponteiro)
// Passar por referencia significa passar o endereco da variavel (&x, &y, &z)
// para que a funcao possa alterar o valor original, nao apenas uma copia.
// Se passasse por valor (sem &), as mudancas nao voltariam para o main.

int ordenar(int *a, int *b, int *c) {
    int temp; // variavel auxiliar para troca (swap)

    // Ordena crescente com tres comparacoes (bubble manual para 3 elementos)
    // Passo 1: garante que *a <= *b
    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    // Passo 2: garante que *b <= *c (o maior dos tres vai para *c)
    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }
    // Passo 3: verifica novamente *a e *b pois *c pode ter trazido um valor menor
    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }

    // Retorna 1 se todos iguais, 0 se houver algum diferente
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

    // Passo os enderecos de x, y, z para que a funcao possa alterar eles diretamente
    resultado = ordenar(&x, &y, &z);

    // Apos a chamada, x, y, z ja estao ordenados (foram modificados pela funcao)
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
