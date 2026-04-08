# Estruturas de Dados - UniCesumar

Repositorio com as atividades avaliativas da disciplina de Estruturas de Dados.

## Estrutura do Repositorio

```
estrutura-de-dados/
├── atividade1/          10 exercicios em C (vetores, matrizes, structs, ponteiros)
├── atividade2/          2 desafios com Pilhas (balanceamento e inversao de string)
├── atividade3/          2 desafios com Filas (atendimento e fila com prioridade)
└── README.md            Este arquivo
```

## Atividade 1 (1,0 pt) - Lista de Exercicios

10 exercicios cobrindo os fundamentos de C:

| # | Arquivo | Tema |
|---|---------|------|
| 1 | `ex01_palavras_inversas.c` | Ler 3 palavras e imprimir na ordem inversa |
| 2 | `ex02_vetor_inverso.c` | Vetor de 5 inteiros impresso ao contrario |
| 3 | `ex03_matriz_multiplicada.c` | Matriz 3x3 multiplicada por 5 |
| 4 | `ex04_matriz_identidade.c` | Matriz identidade e prova por multiplicacao |
| 5 | `ex05_vetor_x_matriz.c` | Multiplicacao vetor x colunas da matriz |
| 6 | `ex06_alunos_aprovados.c` | Struct Aluno - separar aprovados/reprovados |
| 7 | `ex07_busca_livro.c` | Struct Livro - busca por titulo |
| 8 | `ex08_ponteiros_dobro.c` | Aritmetica de ponteiros - dobro dos valores |
| 9 | `ex09_ordena_referencia.c` | Ordenar 3 valores por referencia |
| 10 | `ex10_maior_nota.c` | Alocacao dinamica - ponteiro para maior nota |

## Atividade 2 (1,0 pt) - Pilhas

2 desafios usando pilha dinamica (struct + malloc, sem bibliotecas prontas):

| # | Arquivo | Tema |
|---|---------|------|
| 1 | `desafio1_balanceamento.c` | Verificar se expressao com ()[]{} esta balanceada |
| 2 | `desafio2_inverter_string.c` | Inverter string usando pilha (sem vetor auxiliar) |

## Atividade 3 (1,0 pt) - Filas

2 desafios usando fila dinamica (struct + ponteiros + malloc/free, sem vetores):

| # | Arquivo | Tema |
|---|---------|------|
| 1 | `desafio1_fila_atendimento.c` | Simulacao de fila de atendimento com tempo de espera |
| 2 | `desafio2_fila_impressao.c` | Fila de impressao com prioridade |

## Como Compilar

```bash
gcc nome_do_arquivo.c -o nome_do_programa
./nome_do_programa
```

## Integrantes

- Luis Boratto - [@Tox1469](https://github.com/Tox1469)
- Igor Schiniegoski - [@igorschiniegoski](https://github.com/igorschiniegoski)
