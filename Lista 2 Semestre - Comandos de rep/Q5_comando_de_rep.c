/*Enunciado:Q5
SOMAR INTERVALOS 3 VALORES – Crie uma aplicação que solicite do usuário 3 valores (a, b, c) inteiros
diferentes, a aplicação deverá realizar a soma de todos os valores de 1 até o valor informado pelo
usuário individualmente, exemplo: a = 3 (1+2+3 = 6), b = 2 (1+2=3), c = 4 (1+2+3+4=10), no final deverá
apresentar:
a) Resultado da soma de cada intervalo;
b) O menor valor de soma;
c) O maior valor de soma;
d) Os valores ordenados do menor para o maior.
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

int calcularSoma(int valor) {
    int soma = 0;
    for (int i = 1; i <= valor; i++) {
        soma += i;
    }
    return soma;
}

int main() {
    int valores[3];
    int somas[3];

    printf("Digite 3 valores inteiros diferentes:\n");
    for (int i = 0; i < 3; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valores[i]);
        somas[i] = calcularSoma(valores[i]);
    }

    printf("\nResultados das somas de cada intervalo:\n");
    for (int i = 0; i < 3; i++) {
        printf("Soma do intervalo para o valor %d: %d\n", valores[i], somas[i]);
    }

    // Encontrar menor e maior soma
    int menor = somas[0];
    int maior = somas[0];
    for (int i = 1; i < 3; i++) {
        if (somas[i] < menor) {
            menor = somas[i];
        }
        if (somas[i] > maior) {
            maior = somas[i];
        }
    }

    printf("\nMenor soma: %d\n", menor);
    printf("Maior soma: %d\n", maior);

    // Ordenar os valores informados
    ordenarValores(valores, 3);

    printf("\nValores ordenados do menor para o maior:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", valores[i]);
    }
    printf("\n");

    return 0;
}
