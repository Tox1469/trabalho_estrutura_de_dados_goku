#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desafio 1 - Verificar se uma expressao esta balanceada usando Pilha
// Pilha e uma estrutura LIFO: Last In, First Out (ultimo a entrar, primeiro a sair).
// A ideia: quando abro um parentese/colchete/chave, empilho. Quando fecho, desempilho
// e verifico se o fechamento corresponde ao que esta no topo. Se no fim a pilha estiver
// vazia, a expressao esta balanceada.

// No e cada "caixinha" da pilha encadeada. Cada no guarda um dado e aponta para o proximo.
typedef struct No {
    char dado;
    struct No *proximo; // ponteiro para o no abaixo na pilha
} No;

// A pilha em si guarda apenas o ponteiro para o topo e o tamanho atual
typedef struct {
    No *topo;
    int tamanho;
} Pilha;

// Inicializa a pilha vazia (topo NULL = pilha sem elementos)
void inicializar(Pilha *p) {
    p->topo = NULL;
    p->tamanho = 0;
}

// Retorna 1 (verdadeiro) se a pilha estiver vazia
int isEmpty(Pilha *p) {
    return p->topo == NULL;
}

// Push: empilha um caractere no topo
// Crio um novo no com malloc, aponto ele para o topo atual, e atualizo o topo
void push(Pilha *p, char valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = p->topo; // o novo aponta para quem era o topo
    p->topo = novo;          // o novo vira o topo
    p->tamanho++;
}

// Pop: remove e retorna o caractere do topo
// Guardo o topo em temp, avanço o topo para o proximo, libero temp com free
char pop(Pilha *p) {
    if (isEmpty(p)) return '\0'; // '\0' = caractere nulo, sinal de pilha vazia

    No *temp = p->topo;
    char valor = temp->dado;
    p->topo = temp->proximo; // topo agora e o segundo elemento
    free(temp);              // libero a memoria do no removido
    p->tamanho--;
    return valor;
}

// Libera todos os nos restantes na pilha (evita vazamento de memoria)
void liberarPilha(Pilha *p) {
    while (!isEmpty(p)) {
        pop(p);
    }
}

// Dado um simbolo de fechamento, retorna o simbolo de abertura correspondente
char correspondente(char fechamento) {
    if (fechamento == ')') return '(';
    if (fechamento == ']') return '[';
    if (fechamento == '}') return '{';
    return '\0';
}

// Percorre a expressao caractere por caractere:
// - Abertura: empilha
// - Fechamento: desempilha e compara com o esperado
// Retorna 1 se balanceada, 0 se nao
int verificarBalanceamento(char *expressao) {
    Pilha pilha;
    inicializar(&pilha);
    int i;

    for (i = 0; i < strlen(expressao); i++) {
        char c = expressao[i];

        if (c == '(' || c == '[' || c == '{') {
            push(&pilha, c); // empilha abertura
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(&pilha)) {
                return 0; // fechamento sem nenhuma abertura na pilha: invalido
            }
            char topo = pop(&pilha);
            if (topo != correspondente(c)) {
                liberarPilha(&pilha);
                return 0; // tipos nao combinam (ex: abri [ mas fechei ))
            }
        }
        // outros caracteres (letras, operadores) sao ignorados
    }

    // Se a pilha ficou vazia, todos os abertos foram fechados corretamente
    int resultado = isEmpty(&pilha);
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
