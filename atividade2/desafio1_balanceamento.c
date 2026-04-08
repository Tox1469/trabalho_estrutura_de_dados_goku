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

void liberarPilha(Pilha *p) {
    while (!isEmpty(p)) {
        pop(p);
    }
}

// Retorna o caractere de abertura correspondente ao de fechamento
char correspondente(char fechamento) {
    if (fechamento == ')') return '(';
    if (fechamento == ']') return '[';
    if (fechamento == '}') return '{';
    return '\0';
}

int verificarBalanceamento(char *expressao) {
    Pilha pilha;
    inicializar(&pilha);
    int i;

    for (i = 0; i < strlen(expressao); i++) {
        char c = expressao[i];

        // Se for abertura, empilha
        if (c == '(' || c == '[' || c == '{') {
            push(&pilha, c);
        }
        // Se for fechamento, verifica correspondencia
        else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(&pilha)) {
                return 0; // fechamento sem abertura
            }
            char topo = pop(&pilha);
            if (topo != correspondente(c)) {
                liberarPilha(&pilha);
                return 0; // nao corresponde
            }
        }
    }

    int resultado = isEmpty(&pilha); // se pilha vazia, esta balanceado
    liberarPilha(&pilha);
    return resultado;
}

int main() {
    char expressao[200];

    printf("Digite a expressao com (), [], {}:\n");
    scanf(" %[^\n]", expressao);

    if (verificarBalanceamento(expressao))
        printf("Expressao VALIDA (balanceada).\n");
    else
        printf("Expressao INVALIDA (nao balanceada).\n");

    return 0;
}
