#include <stdio.h>
#include <string.h>

// Exercicio 06 - Separar alunos aprovados e reprovados
// Uso struct para agrupar dados relacionados (nome, matricula, media) em um unico tipo.
// typedef struct cria um apelido para nao precisar escrever "struct Aluno" toda hora.

typedef struct {
    char nome[50];
    int matricula;
    float media; // float guarda numeros com casas decimais (ex: 7.5)
} Aluno;

int main() {
    Aluno alunos[10], aprovados[10], reprovados[10];
    int i, qtdAprov = 0, qtdReprov = 0; // contadores iniciam em 0

    // Leio os dados dos 10 alunos
    for (i = 0; i < 10; i++) {
        printf("--- Aluno %d ---\n", i + 1);
        printf("Nome: ");
        // scanf(" %[^\n]" le a linha inteira incluindo espacos (diferente do %s que para no espaco)
        // o espaco antes do % descarta o enter que ficou do scanf anterior
        scanf(" %[^\n]", alunos[i].nome);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Media Final: ");
        scanf("%f", &alunos[i].media);
    }

    // Percorro o vetor de alunos e separo em dois vetores diferentes
    for (i = 0; i < 10; i++) {
        if (alunos[i].media >= 5.0) {
            // Copia o struct inteiro para o vetor de aprovados e avanca o contador
            aprovados[qtdAprov] = alunos[i];
            qtdAprov++;
        } else {
            reprovados[qtdReprov] = alunos[i];
            qtdReprov++;
        }
    }

    printf("\n========== APROVADOS ==========\n");
    for (i = 0; i < qtdAprov; i++) {
        // %.1f mostra o float com 1 casa decimal
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
