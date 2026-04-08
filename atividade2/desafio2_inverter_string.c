#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void push(Pilha *p, char valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = p->topo;
    p->topo = novo;
    p->tamanho++;
}

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

    // Empilha cada caractere
    for (i = 0; i < strlen(str); i++) {
        push(&pilha, str[i]);
    }

    // Desempilha para imprimir invertido (direto na tela, sem vetor auxiliar)
    printf("\nString invertida:\n");
    while (!isEmpty(&pilha)) {
        printf("%c", pop(&pilha));
    }
    printf("\n");

    return 0;
}
