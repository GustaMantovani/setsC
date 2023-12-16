//Gustavo Mantovani - 30/08/23 

#include "sets.h"
#include <stdio.h>
#include <stdlib.h>

int veirificaRepeticao(int *vet, int i, int elemento) {
  for (int cont = 0; cont < i; cont++) {
    if (elemento == vet[cont]) {
      return -1;
    }
  }
  return 0;
}

int partition(int vetor[], int inicio, int fim) {
  int menores = inicio - 1;
  int pivo = vetor[fim];
  for (int maiores = inicio; maiores < fim; maiores++) {
    if (vetor[maiores] <= pivo) {
      menores++;
      int aux = vetor[menores];
      vetor[menores] = vetor[maiores];
      vetor[maiores] = aux;
    }
  }
  int aux = vetor[menores + 1];
  vetor[menores + 1] = vetor[fim];
  vetor[fim] = aux;
  return menores + 1;
}

void quicksort(int vetor[], int inicio, int fim) {
  if (inicio < fim) {
    int iPartition = partition(vetor, inicio, fim);
    quicksort(vetor, inicio, iPartition - 1);
    quicksort(vetor, iPartition + 1, fim);
  }
}

int intersecao(int *a, int cardA, int *b, int cardB, int **c, int *cardC) { // elementos comuns em ambos os conjuntos
  *cardC = 0;
  int contC;
  for (int i = 0; i <= (cardA - 1); i++) {
    for (int j = 0; j <= (cardB - 1); j++) {
      if (a[i] == b[j]) {
        (*cardC)++;
      }
    }
  }

  if (*cardC>0) {
    *c = (int *)malloc(*cardC * sizeof(int));
    if (*c == NULL) {
      printf("Erro ao alocar memória para o array A.\n");
      return -1;
    }

    contC = 0;
    for (int i = 0; i <= (cardA - 1); i++) {
      for (int j = 0; j <= (cardB - 1); j++) {
        if (a[i] == b[j]) {
          (*c)[contC] = a[i];
          contC++;
        }
      }
    }
  }
  quicksort(*c, 0, *cardC-1);
  return 0;
}

int diferenca(int *a, int cardA, int *b, int cardB, int **c, int *cardC) { // A-B ou B-A
  int val, contC;
  *cardC = 0;
  for (int i = 0; i <= (cardA - 1); i++) {
    val = 0; // validation
    for (int j = 0; j <= (cardB - 1); j++) {
      if (a[i] == b[j]) {
        val++;
      }
    }
    if (!val) {
      (*cardC)++;
    }
  }

  if (*cardC>0) {
    *c = (int *)malloc(*cardC * sizeof(int));
    if (*c == NULL) {
      printf("Erro ao alocar memória para o array A.\n");
      return -1;
    }

    contC = 0;
    for (int i = 0; i <= (cardA - 1); i++) {
      val = 0; // validation
      for (int j = 0; j <= (cardB - 1); j++) {
        if (a[i] == b[j]) {
          val++;
        }
      }
      if (!val) {
        (*c)[contC] = a[i];
        contC++;
      }
    }
  }
  quicksort(*c, 0, *cardC-1);
  return 0;
}

int soma(int *a, int cardA, int *b, int cardB, int **c, int *cardC) {

  int contC = 0;

  *cardC = cardA + cardB;

  if (*cardC>0) {
    *c = (int *)malloc(*cardC * sizeof(int));
    if (*c == NULL) {
      printf("Erro ao alocar memória para o array A.\n");
      return -1;
    }
  }

  for (int i = 0; i <= (cardA - 1); i++) {
    (*c)[contC] = a[i];
    contC++;
  }

  for (int i = 0; i <= (cardB - 1); i++) {
    (*c)[contC] = b[i];
    contC++;
  }
  quicksort(*c, 0, *cardC-1);
  return 0;
}

int uniao(int *a, int cardA, int *b, int cardB, int **c, int *cardC) { // A + (B − (A ∩ B))
  int *iAB = NULL, *dBIAB = NULL;
  int cardIAB, cardDBIAB, v;

  v = intersecao(a, cardA, b, cardB, &iAB, &cardIAB);
  if (v == -1) {
    return -1;
  }
  v = diferenca(b, cardB, iAB, cardIAB, &dBIAB, &cardDBIAB);
  if (v == -1) {
    if (iAB != NULL) {
      free(iAB);
      iAB = NULL;
    }
    return -1;
  }
  v = soma(a, cardA, dBIAB, cardDBIAB, c, cardC);


  if (iAB != NULL) {
    free(iAB);
    iAB = NULL;
  }

  if (dBIAB != NULL) {
    free(dBIAB);
    dBIAB = NULL;
  }

  if (v == -1) {
    return -1;
  }
  
  quicksort(*c, 0, *cardC-1);
  return 0;
}

int diferencaSimetrica(int *a, int cardA, int *b, int cardB, int **c, int *cardC) { //(A − B) ∪ (B − A).
  int *dAB = NULL, *dBA = NULL;
  int cardDAB, cardDBA, v;

  v = diferenca(a, cardA, b, cardB, &dAB, &cardDAB);
  if (v == -1) {
    return -1;
  }
  v = diferenca(b, cardB, a, cardA, &dBA, &cardDBA);
  if (v == -1) {
    if (dAB != NULL) {
      free(dAB);
      dAB = NULL;
    }
    return -1;
  }
  v = uniao(dAB, cardDAB, dBA, cardDBA, c, cardC);

  if (dAB != NULL) {
    free(dAB);
    dAB = NULL;
  }

  if (dBA != NULL) {
    free(dBA);
    dBA = NULL;
  }
  
  if (v == -1) {
    return -1;
  }
  quicksort(*c, 0, *cardC-1);
  return 0;
}

int produtoCartesiano(int *a, int cardA, int *b, int cardB, int **c, int *cardC) { // A.B

  int cont = 0;

  *cardC = (cardA * cardB) * 2;

  if (*cardC>0) {
    *c = (int *)malloc(*cardC * sizeof(int));
    if (*c == NULL) {
      printf("Erro ao alocar memória para o array A.\n");
      return -1;
    }
    quicksort(a, 0, cardA-1);
    quicksort(b, 0, cardB-1);
  }

  for (int i = 0; i < cardA; i++) {
    for (int j = 0; j < cardB; j++) {
      (*c)[cont++] = a[i];
      (*c)[cont++] = b[j];
    }
  }
  return 0;
}
