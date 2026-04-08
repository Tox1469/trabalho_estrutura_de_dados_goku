# Atividade Avaliativa 1 - Lista de 10 Exercicios em C

## Exercicio 1 - Palavras na Ordem Inversa
**Arquivo:** `ex01_palavras_inversas.c`

Le 3 palavras do teclado e imprime na ordem inversa. Usa `scanf` para ler cada palavra em uma variavel separada e depois imprime de tras pra frente.

**Compilar e rodar:**
```bash
gcc ex01_palavras_inversas.c -o ex01 && ./ex01
```

## Exercicio 2 - Vetor Inverso
**Arquivo:** `ex02_vetor_inverso.c`

Cria um vetor de 5 inteiros, le os valores do teclado e imprime na ordem inversa usando um `for` decremental (de 4 ate 0).

**Compilar e rodar:**
```bash
gcc ex02_vetor_inverso.c -o ex02 && ./ex02
```

## Exercicio 3 - Matriz Multiplicada por 5
**Arquivo:** `ex03_matriz_multiplicada.c`

Le uma matriz 3x3 com dois `for` aninhados, multiplica cada elemento por 5 usando o operador `*=` e imprime o resultado.

**Compilar e rodar:**
```bash
gcc ex03_matriz_multiplicada.c -o ex03 && ./ex03
```

## Exercicio 4 - Matriz Identidade
**Arquivo:** `ex04_matriz_identidade.c`

Monta a matriz identidade 3x3 (1 na diagonal, 0 no resto). Faz a multiplicacao da matriz original pela identidade usando 3 `for` aninhados e compara o resultado com a original para provar que A * I = A.

**Compilar e rodar:**
```bash
gcc ex04_matriz_identidade.c -o ex04 && ./ex04
```

## Exercicio 5 - Vetor x Colunas da Matriz
**Arquivo:** `ex05_vetor_x_matriz.c`

Le um vetor de 3 elementos e uma matriz 3x3. Calcula a multiplicacao do vetor pelas colunas da matriz: `resultado[j] = soma de vetor[i] * matriz[i][j]` para cada coluna j.

**Compilar e rodar:**
```bash
gcc ex05_vetor_x_matriz.c -o ex05 && ./ex05
```

## Exercicio 6 - Alunos Aprovados e Reprovados
**Arquivo:** `ex06_alunos_aprovados.c`

Usa uma `struct Aluno` com nome, matricula e media. Le dados de 10 alunos, separa em dois vetores (aprovados com media >= 5.0 e reprovados) e exibe cada grupo.

**Compilar e rodar:**
```bash
gcc ex06_alunos_aprovados.c -o ex06 && ./ex06
```

## Exercicio 7 - Busca de Livro
**Arquivo:** `ex07_busca_livro.c`

Usa `struct Livro` com titulo (max 30), autor (max 15) e ano. Le 5 livros, pergunta um titulo ao usuario e busca usando `strcmp`. Mostra todos os livros com aquele titulo.

**Compilar e rodar:**
```bash
gcc ex07_busca_livro.c -o ex07 && ./ex07
```

## Exercicio 8 - Ponteiros e Dobro
**Arquivo:** `ex08_ponteiros_dobro.c`

Cria um array de 5 inteiros e usa apenas aritmetica de ponteiros (`*(ptr + i)`) para ler e imprimir o dobro de cada valor. Nenhum acesso por indice `arr[i]`.

**Compilar e rodar:**
```bash
gcc ex08_ponteiros_dobro.c -o ex08 && ./ex08
```

## Exercicio 9 - Ordenacao por Referencia
**Arquivo:** `ex09_ordena_referencia.c`

Le 3 inteiros e chama uma funcao que recebe os 3 por referencia (ponteiros). A funcao ordena os valores nas proprias variaveis usando troca (bubble sort simplificado) e retorna 1 se todos forem iguais, 0 caso contrario.

**Compilar e rodar:**
```bash
gcc ex09_ordena_referencia.c -o ex09 && ./ex09
```

## Exercicio 10 - Maior Nota (Alocacao Dinamica)
**Arquivo:** `ex10_maior_nota.c`

Define `struct Aluno` com nome e nota. Le a quantidade `n`, aloca dinamicamente com `malloc`, le os dados usando ponteiros (`(alunos + i)->campo`) e chama a funcao `maiorNota` que percorre o array por ponteiros e retorna um ponteiro para o aluno com a maior nota.

**Restricoes atendidas:**
- Sem variaveis globais
- Sem vetor estatico
- Acesso apenas por ponteiros

**Compilar e rodar:**
```bash
gcc ex10_maior_nota.c -o ex10 && ./ex10
```
