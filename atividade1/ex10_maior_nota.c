#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float nota;
} Aluno;

Aluno* maiorNota(Aluno *alunos, int n) {
    Aluno *maior = alunos; // ponteiro para o primeiro aluno
    int i;

    for (i = 1; i < n; i++) {
        if ((alunos + i)->nota > maior->nota) {
            maior = (alunos + i);
        }
    }

    return maior;
}

int main() {
    int n, i;
    Aluno *alunos;
    Aluno *melhor;

    printf("Quantos alunos? ");
    scanf("%d", &n);

    // Alocacao dinamica
    alunos = (Aluno*) malloc(n * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", (alunos + i)->nome);
        printf("Nota: ");
        scanf("%f", &(alunos + i)->nota);
    }

    melhor = maiorNota(alunos, n);

    printf("\n========== ALUNO COM MAIOR NOTA ==========\n");
    printf("Nome: %s\n", melhor->nome);
    printf("Nota: %.1f\n", melhor->nota);

    free(alunos);

    return 0;
}
