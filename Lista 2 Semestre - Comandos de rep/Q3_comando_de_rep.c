/*Enunciado:Q3
IMPRIMIR 3 CONTAGENS – Crie uma aplicação que solicite do usuário 3 valores inteiros, para cada um
dos valores informados, imprima uma contagem que variará de 1 até o número informado, entre cada
contagem imprima o texto “Impressao contagem do valor X” (onde x corresponde a um dos números
informados). Por exemplo, se o usuário informar os inteiros 2, 4 e 3, deverá ser impresso:
Lucas Timponi Mercadante Castro | Ra: 2304913*/

#include <stdio.h>

void imprimirContagem(int valor) {
    for (int i = 1; i <= valor; i++) {
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
        imprimirContagem(valores[i]);
        printf("\nImpressao contagem do valor %d\n", valores[i]);
    }

    return 0;
}
