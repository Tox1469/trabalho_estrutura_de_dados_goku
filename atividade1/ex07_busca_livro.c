#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[31];
    char autor[16];
    int ano;
} Livro;

int main() {
    Livro livros[5];
    char busca[31];
    int i, encontrou = 0;

    for (i = 0; i < 5; i++) {
        printf("--- Livro %d ---\n", i + 1);
        printf("Titulo (max 30 letras): ");
        scanf(" %[^\n]", livros[i].titulo);
        printf("Autor (max 15 letras): ");
        scanf(" %[^\n]", livros[i].autor);
        printf("Ano: ");
        scanf("%d", &livros[i].ano);
    }

    printf("\nDigite o titulo a buscar: ");
    scanf(" %[^\n]", busca);

    printf("\n========== RESULTADOS ==========\n");
    for (i = 0; i < 5; i++) {
        if (strcmp(livros[i].titulo, busca) == 0) {
            printf("Titulo: %s | Autor: %s | Ano: %d\n",
                   livros[i].titulo, livros[i].autor, livros[i].ano);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum livro encontrado com o titulo \"%s\".\n", busca);
    }

    return 0;
}
