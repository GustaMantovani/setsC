#include "../src/sets.h"
#include <stdio.h>

int main() {
    int conjuntoA[] = {1, 2, 3, 4, 5};
    int cardA = 5;
    int conjuntoB[] = {3, 4, 5, 6, 7};
    int cardB = 5;
    int *resultado;
    int cardResultado;

    // Exemplo de cálculo da interseção
    int status = intersecao(conjuntoA, cardA, conjuntoB, cardB, &resultado, &cardResultado);

    if (status == 0) {
        printf("Interseção: ");
        for (int i = 0; i < cardResultado; i++) {
            printf("%d ", resultado[i]);
        }
        printf("\n");
        free(resultado);
    } else {
        printf("Erro ao calcular a interseção.\n");
    }

    return 0;
}

