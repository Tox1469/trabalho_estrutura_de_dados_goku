#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int tempoAtendimento;
} Cliente;

typedef struct No {
    Cliente dado;
    struct No *proximo;
} No;

typedef struct {
    No *frente;
    No *tras;
    int tamanho;
} Fila;

void inicializar(Fila *f) {
    f->frente = NULL;
    f->tras = NULL;
    f->tamanho = 0;
}

int isEmpty(Fila *f) {
    return f->frente == NULL;
}

void enqueue(Fila *f, Cliente c) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = c;
    novo->proximo = NULL;

    if (isEmpty(f)) {
        f->frente = novo;
        f->tras = novo;
    } else {
        f->tras->proximo = novo;
        f->tras = novo;
    }
    f->tamanho++;
}

Cliente dequeue(Fila *f) {
    No *temp = f->frente;
    Cliente c = temp->dado;

    f->frente = temp->proximo;
    if (f->frente == NULL) {
        f->tras = NULL;
    }

    free(temp);
    f->tamanho--;
    return c;
}

int main() {
    Fila fila;
    inicializar(&fila);
    int n, i;
    int tempoEspera = 0;

    printf("Quantos clientes? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        Cliente c;
        c.id = i + 1;
        printf("Tempo de atendimento do cliente %d (minutos): ", c.id);
        scanf("%d", &c.tempoAtendimento);
        enqueue(&fila, c);
    }

    printf("\n========== SIMULACAO DE ATENDIMENTO ==========\n");

    while (!isEmpty(&fila)) {
        Cliente c = dequeue(&fila);
        printf("Cliente %d | Tempo de espera: %d min | Tempo de atendimento: %d min\n",
               c.id, tempoEspera, c.tempoAtendimento);
        tempoEspera += c.tempoAtendimento;
    }

    printf("\nTempo total de atendimento: %d minutos\n", tempoEspera);

    return 0;
}
