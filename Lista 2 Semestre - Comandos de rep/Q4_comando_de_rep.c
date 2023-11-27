/*Enunciado:Q4
IMPRIMIR 3 CONTAGENS DECRESCENTE – Crie uma aplicação baseada na Q3, a única alteração é que
nesta versão os valores impressos deverão serem exibidos em ordem decrescente. Dica: É possível
utilizar o comando FOR com decremento ao invés de incremento e iniciar a variável de controle em um
número maior.
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>

void imprimirContagemDecrescente(int valor) {
    for (int i = valor; i >= 1; i--) {
        printf("%d ", i);
    }
}

int main() {
    int valores[3];

    printf("Digite 3 valores inteiros:\n");
    for (int i = 0; i < 3; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valores[i]);
    }

    for (int i = 0; i < 3; i++) {
        imprimirContagemDecrescente(valores[i]);
        printf("\nImpressao contagem decrescente do valor %d\n", valores[i]);
    }

    return 0;
}
