#include <stdio.h>
#include <stdlib.h>

// Desafio 2 - Fila de impressao com prioridade
// Diferente de uma fila normal (FIFO puro), aqui documentos com maior prioridade
// ficam na frente. Menor valor de prioridade = mais urgente (ex: prioridade 1 > prioridade 3).
// Em caso de empate na prioridade, respeito a ordem de chegada (quem chegou antes sai antes).
// Implementei como lista encadeada ordenada: ja insiro na posicao correta.

typedef struct {
    int id;
    int paginas;
    int prioridade; // menor numero = maior urgencia
} Documento;

// No guarda o documento e um contador de ordem de chegada para desempatar
typedef struct No {
    Documento dado;
    int ordem; // numero sequencial de chegada (0, 1, 2, ...)
    struct No *proximo;
} No;

// A fila de prioridade so precisa da frente (ja que insiro ordenado, a frente sempre e o proximo a sair)
typedef struct {
    No *frente;
    int tamanho;
    int contadorOrdem; // incrementa a cada insercao para registrar a ordem de chegada
} FilaPrioridade;

void inicializar(FilaPrioridade *f) {
    f->frente = NULL;
    f->tamanho = 0;
    f->contadorOrdem = 0;
}

int isEmpty(FilaPrioridade *f) {
    return f->frente == NULL;
}

// Insere o documento na posicao correta ja na hora de enfileirar
// Assim o dequeue sempre pega o primeiro, que ja e o de maior prioridade
void enqueue(FilaPrioridade *f, Documento doc) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = doc;
    novo->ordem = f->contadorOrdem; // registro quando chegou
    f->contadorOrdem++;
    novo->proximo = NULL;

    // Caso 1: fila vazia ou novo tem prioridade maior que o primeiro (valor menor)
    if (isEmpty(f) ||
        doc.prioridade < f->frente->dado.prioridade ||
        (doc.prioridade == f->frente->dado.prioridade && novo->ordem < f->frente->ordem)) {
        novo->proximo = f->frente;
        f->frente = novo;
    } else {
        // Caso 2: percorro a fila ate achar o ponto onde o novo deve ser inserido
        // O novo entra antes de qualquer elemento com prioridade MENOR (valor maior)
        // ou com mesma prioridade mas que chegou depois
        No *atual = f->frente;
        while (atual->proximo != NULL &&
               (atual->proximo->dado.prioridade < doc.prioridade ||
                (atual->proximo->dado.prioridade == doc.prioridade &&
                 atual->proximo->ordem < novo->ordem))) {
            atual = atual->proximo;
        }
        // Encaixo o novo entre atual e atual->proximo
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
    f->tamanho++;
}

// Dequeue simples: remove da frente (que ja e o de maior prioridade)
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
        enqueue(&fila, doc); // ja insere na posicao certa
    }

    printf("\n========== ORDEM DE IMPRESSAO ==========\n");

    // O dequeue sempre tira o mais prioritario (a fila ja esta ordenada)
    int posicao = 1;
    while (!isEmpty(&fila)) {
        Documento doc = dequeue(&fila);
        printf("%d. Documento %d | Paginas: %d | Prioridade: %d\n",
               posicao, doc.id, doc.paginas, doc.prioridade);
        posicao++;
    }

    return 0;
}
