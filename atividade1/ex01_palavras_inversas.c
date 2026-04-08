#include <stdio.h>
#include <string.h>

int main() {
    char palavra1[50], palavra2[50], palavra3[50];

    printf("Digite tres palavras:\n");
    scanf("%s", palavra1);
    scanf("%s", palavra2);
    scanf("%s", palavra3);

    printf("\nPalavras na ordem inversa:\n");
    printf("%s\n", palavra3);
    printf("%s\n", palavra2);
    printf("%s\n", palavra1);

    return 0;
}
