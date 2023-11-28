/*Enunciado:Q5
VALORES ALEATÓRIOS 2 – Crie uma aplicação console em C responsável por armazenar 60 valores
inteiros, a aplicação deverá conter um menu de console com as opções abaixo relacionada:
 ..:: SORTEIO 2 ::..
1. Zerar (deverá percorrer o vetor e atribuir valor -1 a todos os endereços)
2. Carregar aleatório (deverá carregar o vetor com valores inteiros aleatórios entre 1 e 60)
3. Imprimir (deverá percorrer o vetor e exibir todos os valores armazenados)
4. Entre valores (deverá solicitar dois valores (ambos entre 1 e 60) do usuário, com base nos
valores fornecidos, deverá percorrer o vetor e exibir todos os valores armazenados que estão
3
entre os valores fornecidos, por exemplo, se o usuário informar os valores 13 e 20, todos os
valores armazenados entre 13 e 20 presentes no vetor deverão ser exibidos)
5. Exibir repetidos (deverá percorrer o vetor e então verificar quantas vezes cada valor presente
no vetor existe, somente valores que contiver alguma repetição deverão ser exibidos, por
exemplo, se o valores armazenados são 5, 12, 60, 3, 12, 3, 1, a resposta deverá ser 12 = 2, 3 = 2
pois o números 12 e 3 aparecem 2 vezes. Dicas: a) crie dois loopings, o segundo dentro do
primeiro, o primeiro será responsável por percorrer cada posição do vetor e o segundo contará
a quantidade de repetições que existe para cada posição acessada do primeiro; b) Se
considerarmos o exemplo apresentado, serão apresentadas 4 mensagens, 12 = 2, 3 = 2, 12 = 2
e 3 = 2, isso ocorre por que na primeira ocorrência do número 12 haverá uma contagem e ele
aparece 2x então será exibida a primeira mensagem, quando estiver na segunda ocorrência do
número 12 também será computado que o mesmo aparece 2x, então será novamente exibida
a mensagem, não se preocupe com essa situação de aparecer mensagens repetidas).
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 60

void zerarValores(int *valores) {
    for (int i = 0; i < TAMANHO; i++) {
        valores[i] = -1;
    }
}

void carregarAleatorio(int *valores) {
    srand(time(NULL));
    for (int i = 0; i < TAMANHO; i++) {
        valores[i] = rand() % 60 + 1;
    }
}

void imprimirValores(int *valores) {
    printf("\nOs valores armazenados sao:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("Posicao %d: %d\n", i, valores[i]);
    }
}

void entreValores(int *valores, int valor1, int valor2) {
    int menor, maior;
    if (valor1 < valor2) {
        menor = valor1;
        maior = valor2;
    } else {
        menor = valor2;
        maior = valor1;
    }

    printf("\nValores entre %d e %d:\n", menor, maior);
    for (int i = 0; i < TAMANHO; i++) {
        if (valores[i] > menor && valores[i] < maior) {
            printf("%d ", valores[i]);
        }
    }
    printf("\n");
}

void exibirRepetidos(int *valores) {
    int repetidos[TAMANHO] = {0}; // Array para armazenar quantas vezes cada valor aparece
    int exibido[TAMANHO] = {0}; // Array para controlar quais valores já foram exibidos

    for (int i = 0; i < TAMANHO; i++) {
        if (exibido[i] == 0) {
            int contador = 1;
            for (int j = i + 1; j < TAMANHO; j++) {
                if (valores[i] == valores[j]) {
                    contador++;
                    exibido[j] = 1; // Marca como exibido para não repetir
                }
            }
            if (contador > 1) {
                repetidos[valores[i]] = contador;
            }
        }
    }

    printf("\nValores repetidos:\n");
    for (int i = 1; i <= 60; i++) {
        if (repetidos[i] > 0) {
            printf("%d = %d\n", i, repetidos[i]);
        }
    }
}

int main() {
    int valores[TAMANHO];
    int opcao, valor1, valor2;

    do {
        printf("\n..:: SORTEIO 2 ::..\n");
        printf("1. Zerar\n");
        printf("2. Carregar aleatorio\n");
        printf("3. Imprimir\n");
        printf("4. Entre valores\n");
        printf("5. Exibir repetidos\n");
        printf("Escolha uma opcao (1-5): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                zerarValores(valores);
                printf("Valores zerados!\n");
                break;
            case 2:
                carregarAleatorio(valores);
                printf("Valores carregados aleatoriamente!\n");
                break;
            case 3:
                imprimirValores(valores);
                break;
            case 4:
                printf("Digite dois valores entre 1 e 60: ");
                scanf("%d %d", &valor1, &valor2);
                entreValores(valores, valor1, valor2);
                break;
            case 5:
                exibirRepetidos(valores);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao >= 1 && opcao <= 5);

    return 0;
}
