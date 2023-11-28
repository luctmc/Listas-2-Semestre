/*Enunciado:Q6
PRODUTO INTERVALO 3 VALORES – Crie uma aplicação baseada no exercício Q5, a diferença consistirá
apenas que ao invés de realizar soma, esta versão irá realizar o produto dos valores, exemplo: a = 3
(1*2*3 = 6), b = 2 (1*2=2), c = 4 (1*2*3*4=24), no final do processamento deverão ser apresentadas
as mesmas informações do exercício Q5 (considerando o produto dos valores).
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>

void ordenarValores(int *valores, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (valores[j] > valores[j + 1]) {
                int temp = valores[j];
                valores[j] = valores[j + 1];
                valores[j + 1] = temp;
            }
        }
    }
}

int calcularProduto(int valor) {
    int produto = 1;
    for (int i = 1; i <= valor; i++) {
        produto *= i;
    }
    return produto;
}

int main() {
    int valores[3];
    int produtos[3];

    printf("Digite 3 valores inteiros diferentes:\n");
    for (int i = 0; i < 3; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valores[i]);
        produtos[i] = calcularProduto(valores[i]);
    }

    printf("\nResultados dos produtos de cada intervalo:\n");
    for (int i = 0; i < 3; i++) {
        printf("Produto do intervalo para o valor %d: %d\n", valores[i], produtos[i]);
    }

    // Encontrar menor e maior produto
    int menor = produtos[0];
    int maior = produtos[0];
    for (int i = 1; i < 3; i++) {
        if (produtos[i] < menor) {
            menor = produtos[i];
        }
        if (produtos[i] > maior) {
            maior = produtos[i];
        }
    }

    printf("\nMenor produto: %d\n", menor);
    printf("Maior produto: %d\n", maior);

    // Ordenar os valores informados
    ordenarValores(valores, 3);

    printf("\nValores ordenados do menor para o maior:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", valores[i]);
    }
    printf("\n");

    return 0;
}
