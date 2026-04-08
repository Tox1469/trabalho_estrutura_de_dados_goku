# Atividade Avaliativa 2 - Desafios com Pilhas

Ambos os desafios usam pilha dinamica implementada manualmente com `struct` e `malloc`, sem bibliotecas prontas.

A estrutura da pilha:
- `No`: contem o dado (`char`) e um ponteiro para o proximo no
- `Pilha`: contem um ponteiro para o topo e o tamanho
- Operacoes: `push`, `pop`, `isEmpty`

---

## Desafio 1 - Verificacao de Expressao Balanceada
**Arquivo:** `desafio1_balanceamento.c`

Recebe uma expressao com `()`, `[]`, `{}` e verifica se esta balanceada.

**Como funciona:**
1. Percorre cada caractere da expressao
2. Se for abertura (`(`, `[`, `{`), empilha
3. Se for fechamento (`)`, `]`, `}`), desempilha e verifica se corresponde ao par correto
4. No final, se a pilha estiver vazia, a expressao e valida

**Exemplos:**
- `{[()]}` -> VALIDA
- `{[(])}` -> INVALIDA (ordem errada)
- `((()` -> INVALIDA (falta fechamento)

**Compilar e rodar:**
```bash
gcc desafio1_balanceamento.c -o desafio1 && ./desafio1
```

---

## Desafio 2 - Inverter String com Pilha
**Arquivo:** `desafio2_inverter_string.c`

Recebe uma string e imprime invertida usando a pilha.

**Como funciona:**
1. Percorre a string e empilha cada caractere (push)
2. Desempilha todos os caracteres (pop) e imprime direto na tela
3. Como a pilha e LIFO (ultimo a entrar, primeiro a sair), os caracteres saem na ordem inversa

**Restricoes atendidas:**
- Sem funcoes prontas de inversao (tipo `strrev`)
- Sem vetor auxiliar para armazenar a string invertida
- Manipulacao apenas via operacoes da pilha

**Compilar e rodar:**
```bash
gcc desafio2_inverter_string.c -o desafio2 && ./desafio2
```
