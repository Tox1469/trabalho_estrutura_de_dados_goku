#include <stdio.h>
#include <string.h>

// Exercicio 01 - Palavras na ordem inversa
// A ideia e simples: leio tres palavras e imprimo de traz pra frente.
// Nao preciso de logica de inversao, so mudo a ordem do printf.

int main() {
    // Cada variavel guarda ate 49 letras + o '\0' que o C coloca no final de toda string
    char palavra1[50], palavra2[50], palavra3[50];

    printf("Digite tres palavras:\n");

    // scanf com "%s" le uma palavra por vez (para no espaco ou enter)
    scanf("%s", palavra1);
    scanf("%s", palavra2);
    scanf("%s", palavra3);

    // Imprimo na ordem 3, 2, 1 para ficar invertido
    printf("\nPalavras na ordem inversa:\n");
    printf("%s\n", palavra3);
    printf("%s\n", palavra2);
    printf("%s\n", palavra1);

    return 0;
}
