/*Enunciado:Q1
CARREGAR E IMPRIMIR VALORES – Crie uma aplicação que seja capaz de armazenar 10 idades
fornecidas pelo usuário em uma estrutura de vetor, logo após carregar as idades, as mesmas deverão
ser exibidas na tela indicando a posição em que se encontram no vetor.
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>

#define TAMANHO 10

int main() {
    int idades[TAMANHO];

    printf("Digite 10 idades:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("Idade %d: ", i + 1);
        scanf("%d", &idades[i]);
    }

    printf("\nAs idades fornecidas sao:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("Posicao %d: %d\n", i, idades[i]);
    }

    return 0;
}
