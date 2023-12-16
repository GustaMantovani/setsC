#ifndef _SETS_H
#define _SETS_H

int veirificaRepeticao(int *vet, int i, int elemento);
int partition(int vetor[], int inicio, int fim);
void quicksort(int vetor[], int inicio, int fim);
int intersecao(int *a, int cardA, int *b, int cardB, int **c, int *cardC);
int diferenca(int *a, int cardA, int *b, int cardB, int **c, int *cardC);
int soma(int *a, int cardA, int *b, int cardB, int **c, int *cardC);
int uniao(int *a, int cardA, int *b, int cardB, int **c, int *cardC);
int diferencaSimetrica(int *a, int cardA, int *b, int cardB, int **c, int *cardC);
int produtoCartesiano(int *a, int cardA, int *b, int cardB, int **c, int *cardC);

#endif
