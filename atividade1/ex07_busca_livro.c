#include <stdio.h>
#include <string.h>

// Exercicio 07 - Cadastro e busca de livros por titulo
// Uso struct para representar um livro com titulo, autor e ano.
// A busca e linear: percorro todos os livros comparando o titulo com strcmp.

typedef struct {
    char titulo[31]; // max 30 letras + '\0'
    char autor[16];  // max 15 letras + '\0'
    int ano;
} Livro;

int main() {
    Livro livros[5];
    char busca[31]; // guarda o titulo digitado para a busca
    int i, encontrou = 0; // flag: começa falso (0) e vira 1 se achar algum livro

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

    // Busca linear: comparo um por um ate o fim do vetor
    for (i = 0; i < 5; i++) {
        // strcmp retorna 0 quando as duas strings sao iguais
        // Nao posso usar == para comparar strings em C, preciso do strcmp
        if (strcmp(livros[i].titulo, busca) == 0) {
            printf("Titulo: %s | Autor: %s | Ano: %d\n",
                   livros[i].titulo, livros[i].autor, livros[i].ano);
            encontrou = 1;
        }
    }

    // Se o laco terminou e encontrou ainda e 0, nenhum livro bateu
    if (!encontrou) {
        printf("Nenhum livro encontrado com o titulo \"%s\".\n", busca);
    }

    return 0;
}
