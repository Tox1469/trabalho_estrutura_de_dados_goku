#include <stdio.h>
#include <stdlib.h>

// Desafio 1 - Simulacao de fila de atendimento
// Fila e uma estrutura FIFO: First In, First Out (primeiro a entrar, primeiro a sair).
// Diferente da pilha (que remove do topo), a fila remove da frente e insere no final.
// Uso dois ponteiros: frente (onde remove) e tras (onde insere).

typedef struct {
    int id;
    int tempoAtendimento;
} Cliente;

// No da fila encadeada: guarda o dado e aponta para o proximo na fila
typedef struct No {
    Cliente dado;
    struct No *proximo;
} No;

// A fila guarda ponteiro para frente (quem sai primeiro) e para tras (onde entra)
typedef struct {
    No *frente;
    No *tras;
    int tamanho;
} Fila;

// Inicializa a fila vazia
void inicializar(Fila *f) {
    f->frente = NULL;
    f->tras = NULL;
    f->tamanho = 0;
}

// Retorna 1 se a fila estiver vazia
int isEmpty(Fila *f) {
    return f->frente == NULL;
}

// Enqueue: insere um cliente no final da fila (no tras)
void enqueue(Fila *f, Cliente c) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = c;
    novo->proximo = NULL; // o novo sempre vai para o final, entao nao tem proximo

    if (isEmpty(f)) {
        // Fila vazia: frente e tras apontam para o unico elemento
        f->frente = novo;
        f->tras = novo;
    } else {
        // Liga o atual ultimo ao novo, e atualiza o tras
        f->tras->proximo = novo;
        f->tras = novo;
    }
    f->tamanho++;
}

// Dequeue: remove e retorna o cliente da frente da fila
Cliente dequeue(Fila *f) {
    No *temp = f->frente;
    Cliente c = temp->dado;

    f->frente = temp->proximo; // a frente avança para o proximo
    if (f->frente == NULL) {
        f->tras = NULL; // se ficou vazia, tras tambem vai a NULL
    }

    free(temp);
    f->tamanho--;
    return c;
}

int main() {
    Fila fila;
    inicializar(&fila);
    int n, i;
    int tempoEspera = 0; // acumula o tempo que cada cliente espera antes de ser atendido

    printf("Quantos clientes? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        Cliente c;
        c.id = i + 1;
        printf("Tempo de atendimento do cliente %d (minutos): ", c.id);
        scanf("%d", &c.tempoAtendimento);
        enqueue(&fila, c); // insere no final da fila
    }

    printf("\n========== SIMULACAO DE ATENDIMENTO ==========\n");

    // Processo um cliente por vez: o tempo de espera do proximo e o tempo total ja gasto
    while (!isEmpty(&fila)) {
        Cliente c = dequeue(&fila); // retira da frente
        printf("Cliente %d | Tempo de espera: %d min | Tempo de atendimento: %d min\n",
               c.id, tempoEspera, c.tempoAtendimento);
        tempoEspera += c.tempoAtendimento; // o proximo esperara mais esse tempo
    }

    printf("\nTempo total de atendimento: %d minutos\n", tempoEspera);

    return 0;
}
