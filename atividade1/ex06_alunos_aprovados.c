#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int matricula;
    float media;
} Aluno;

int main() {
    Aluno alunos[10], aprovados[10], reprovados[10];
    int i, qtdAprov = 0, qtdReprov = 0;

    for (i = 0; i < 10; i++) {
        printf("--- Aluno %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Media Final: ");
        scanf("%f", &alunos[i].media);
    }

    // Separa aprovados e reprovados
    for (i = 0; i < 10; i++) {
        if (alunos[i].media >= 5.0) {
            aprovados[qtdAprov] = alunos[i];
            qtdAprov++;
        } else {
            reprovados[qtdReprov] = alunos[i];
            qtdReprov++;
        }
    }

    printf("\n========== APROVADOS ==========\n");
    for (i = 0; i < qtdAprov; i++) {
        printf("Nome: %s | Matricula: %d | Media: %.1f\n",
               aprovados[i].nome, aprovados[i].matricula, aprovados[i].media);
    }

    printf("\n========== REPROVADOS ==========\n");
    for (i = 0; i < qtdReprov; i++) {
        printf("Nome: %s | Matricula: %d | Media: %.1f\n",
               reprovados[i].nome, reprovados[i].matricula, reprovados[i].media);
    }

    return 0;
}
