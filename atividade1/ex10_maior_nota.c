#include <stdio.h>
#include <stdlib.h>

// Exercicio 10 - Encontrar o aluno com maior nota usando alocacao dinamica e ponteiros
// malloc aloca memoria em tempo de execucao (heap), quando nao sei o tamanho antes do programa rodar.
// A funcao maiorNota retorna um ponteiro para o elemento vencedor dentro do proprio vetor.

typedef struct {
    char nome[50];
    float nota;
} Aluno;

// Recebe o vetor como ponteiro e o tamanho n, retorna ponteiro para o maior elemento
Aluno* maiorNota(Aluno *alunos, int n) {
    Aluno *maior = alunos; // começo assumindo que o primeiro e o maior
    int i;

    // Percorro a partir do segundo (indice 1) comparando com o maior atual
    for (i = 1; i < n; i++) {
        // (alunos + i) e o endereco do elemento i, equivale a &alunos[i]
        // -> acessa campo de um struct atraves de ponteiro (igual ao . mas para ponteiros)
        if ((alunos + i)->nota > maior->nota) {
            maior = (alunos + i); // atualizo o ponteiro para apontar para o novo maior
        }
    }

    return maior; // retorno o endereco do maior dentro do vetor
}

int main() {
    int n, i;
    Aluno *alunos; // ponteiro que vai receber o bloco de memoria do malloc
    Aluno *melhor;

    printf("Quantos alunos? ");
    scanf("%d", &n);

    // malloc(n * sizeof(Aluno)) reserva espaco para n structs do tipo Aluno
    // O cast (Aluno*) converte o void* retornado pelo malloc para o tipo correto
    alunos = (Aluno*) malloc(n * sizeof(Aluno));
    if (alunos == NULL) {
        // malloc retorna NULL se nao conseguir alocar (sem memoria suficiente)
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Nome: ");
        // (alunos + i)->nome acessa o campo nome do elemento i via ponteiro
        scanf(" %[^\n]", (alunos + i)->nome);
        printf("Nota: ");
        scanf("%f", &(alunos + i)->nota);
    }

    melhor = maiorNota(alunos, n);

    printf("\n========== ALUNO COM MAIOR NOTA ==========\n");
    printf("Nome: %s\n", melhor->nome);
    printf("Nota: %.1f\n", melhor->nota);

    // free libera a memoria alocada com malloc (boa pratica: sempre liberar no final)
    free(alunos);

    return 0;
}
