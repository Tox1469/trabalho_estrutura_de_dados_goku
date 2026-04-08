# Atividade Avaliativa 3 - Desafios com Filas

Ambos os desafios usam fila dinamica implementada manualmente com `struct`, ponteiros e `malloc/free`, sem vetores e sem bibliotecas prontas.

---

## Desafio 1 - Fila de Atendimento
**Arquivo:** `desafio1_fila_atendimento.c`

Simula o atendimento sequencial de clientes em uma fila.

**Estruturas:**
- `Cliente`: contem `id` e `tempoAtendimento`
- `No`: no da lista encadeada com o dado e ponteiro para o proximo
- `Fila`: contem ponteiros para a frente e tras, e o tamanho

**Como funciona:**
1. Le a quantidade de clientes e o tempo de atendimento de cada um
2. Insere todos na fila (enqueue) na ordem de chegada
3. Simula o atendimento (dequeue) calculando o tempo de espera de cada cliente
4. O tempo de espera = soma dos tempos de atendimento de todos os clientes a frente

**Exemplo:**
```
Cliente 1: tempo = 5 min -> espera = 0 min
Cliente 2: tempo = 3 min -> espera = 5 min
Cliente 3: tempo = 8 min -> espera = 8 min
```

**Compilar e rodar:**
```bash
gcc desafio1_fila_atendimento.c -o desafio1 && ./desafio1
```

---

## Desafio 2 - Fila de Impressao com Prioridade
**Arquivo:** `desafio2_fila_impressao.c`

Sistema de fila de impressao onde documentos com menor valor de prioridade sao atendidos primeiro.

**Estruturas:**
- `Documento`: contem `id`, `paginas` e `prioridade`
- `No`: no da lista com o dado, a ordem de chegada e ponteiro para o proximo
- `FilaPrioridade`: contem ponteiro para a frente, tamanho e contador de ordem

**Como funciona:**
1. Le os documentos com suas prioridades
2. No `enqueue`, insere na posicao correta (ordenado por prioridade)
3. Em caso de empate na prioridade, respeita a ordem de chegada (FIFO)
4. O `dequeue` sempre remove da frente (que ja e o de maior prioridade)

**Exemplo:**
```
Doc 1: prioridade 3 -> imprime 3o
Doc 2: prioridade 1 -> imprime 1o
Doc 3: prioridade 1 -> imprime 2o (chegou depois do Doc 2, mesma prioridade)
```

**Restricoes atendidas:**
- Sem estruturas prontas
- Sem funcoes externas de ordenacao (tipo `qsort`)
- Ordenacao feita manualmente na insercao

**Compilar e rodar:**
```bash
gcc desafio2_fila_impressao.c -o desafio2 && ./desafio2
```
