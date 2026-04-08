#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int paginas;
    int prioridade;
} Documento;

typedef struct No {
    Documento dado;
    int ordem; // ordem de chegada para desempate
    struct No *proximo;
} No;

typedef struct {
    No *frente;
    int tamanho;
    int contadorOrdem;
} FilaPrioridade;

void inicializar(FilaPrioridade *f) {
    f->frente = NULL;
    f->tamanho = 0;
    f->contadorOrdem = 0;
}

int isEmpty(FilaPrioridade *f) {
    return f->frente == NULL;
}

// Insere na posicao correta de acordo com a prioridade
// Menor valor de prioridade = maior prioridade
// Em caso de empate, respeita a ordem de chegada
void enqueue(FilaPrioridade *f, Documento doc) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = doc;
    novo->ordem = f->contadorOrdem;
    f->contadorOrdem++;
    novo->proximo = NULL;

    // Se a fila esta vazia ou o novo tem mais prioridade que o primeiro
    if (isEmpty(f) ||
        doc.prioridade < f->frente->dado.prioridade ||
        (doc.prioridade == f->frente->dado.prioridade && novo->ordem < f->frente->ordem)) {
        novo->proximo = f->frente;
        f->frente = novo;
    } else {
        // Percorre ate achar a posicao correta
        No *atual = f->frente;
        while (atual->proximo != NULL &&
               (atual->proximo->dado.prioridade < doc.prioridade ||
                (atual->proximo->dado.prioridade == doc.prioridade &&
                 atual->proximo->ordem < novo->ordem))) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
    f->tamanho++;
}

Documento dequeue(FilaPrioridade *f) {
    No *temp = f->frente;
    Documento doc = temp->dado;

    f->frente = temp->proximo;
    free(temp);
    f->tamanho--;
    return doc;
}

int main() {
    FilaPrioridade fila;
    inicializar(&fila);
    int n, i;

    printf("Quantos documentos? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        Documento doc;
        printf("\n--- Documento %d ---\n", i + 1);
        doc.id = i + 1;
        printf("Numero de paginas: ");
        scanf("%d", &doc.paginas);
        printf("Prioridade (menor valor = maior prioridade): ");
        scanf("%d", &doc.prioridade);
        enqueue(&fila, doc);
    }

    printf("\n========== ORDEM DE IMPRESSAO ==========\n");

    int posicao = 1;
    while (!isEmpty(&fila)) {
        Documento doc = dequeue(&fila);
        printf("%d. Documento %d | Paginas: %d | Prioridade: %d\n",
               posicao, doc.id, doc.paginas, doc.prioridade);
        posicao++;
    }

    return 0;
}
