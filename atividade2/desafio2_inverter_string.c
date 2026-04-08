#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desafio 2 - Inverter uma string usando Pilha
// A propriedade LIFO da pilha (ultimo a entrar, primeiro a sair) inverte naturalmente.
// Empilho letra por letra da esquerda para direita, depois desempilho (que sai da direita para esquerda).

// Mesma estrutura de No e Pilha do desafio anterior
typedef struct No {
    char dado;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
    int tamanho;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = NULL;
    p->tamanho = 0;
}

int isEmpty(Pilha *p) {
    return p->topo == NULL;
}

// Push: cria no, liga ao topo atual, vira o novo topo
void push(Pilha *p, char valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = p->topo;
    p->topo = novo;
    p->tamanho++;
}

// Pop: remove do topo, libera memoria, retorna o valor
char pop(Pilha *p) {
    if (isEmpty(p)) return '\0';

    No *temp = p->topo;
    char valor = temp->dado;
    p->topo = temp->proximo;
    free(temp);
    p->tamanho--;
    return valor;
}

int main() {
    char str[200];
    Pilha pilha;
    int i;

    inicializar(&pilha);

    printf("Digite uma string:\n");
    scanf(" %[^\n]", str);

    // Passo 1: empilho cada caractere da string da esquerda para direita
    // strlen retorna o numero de caracteres da string (sem contar o '\0' do final)
    for (i = 0; i < strlen(str); i++) {
        push(&pilha, str[i]);
    }

    // Passo 2: desempilho e imprimo direto na tela
    // Como LIFO inverte a ordem, o ultimo empilhado (ultimo da string) sai primeiro
    printf("\nString invertida:\n");
    while (!isEmpty(&pilha)) {
        printf("%c", pop(&pilha)); // %c imprime um unico caractere
    }
    printf("\n");

    return 0;
}
