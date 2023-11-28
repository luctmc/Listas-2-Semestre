/*Enunciado:Q1
BASICO – Crie uma matriz capaz de armazenar 9 valores inteiros quaisquer, baseado nessa matriz
implemente o menu abaixo para manipular as informações desta matriz.
MENU
1. Carregar (Usuário deverá fornecer os dados para preencher cada uma das posições da matriz)
2. Imprimir (Deverá exibir o valor contido em cada uma das posições da matriz)
3. Somar (Deverá somar todos os valores armazenados em cada uma das posições e exibir o resultado)
4. Zerar (Deverá zerar os valores armazenados em cada uma das posições da matriz).
9. Sair
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>

#define TAM_MATRIZ 3

void carregarMatriz(int matriz[TAM_MATRIZ][TAM_MATRIZ]) {
    printf("Preencha a matriz %dx%d:\n", TAM_MATRIZ, TAM_MATRIZ);
    for (int i = 0; i < TAM_MATRIZ; i++) {
        for (int j = 0; j < TAM_MATRIZ; j++) {
            printf("Posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(int matriz[TAM_MATRIZ][TAM_MATRIZ]) {
    printf("Valores na matriz %dx%d:\n", TAM_MATRIZ, TAM_MATRIZ);
    for (int i = 0; i < TAM_MATRIZ; i++) {
        for (int j = 0; j < TAM_MATRIZ; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int somarMatriz(int matriz[TAM_MATRIZ][TAM_MATRIZ]) {
    int soma = 0;
    for (int i = 0; i < TAM_MATRIZ; i++) {
        for (int j = 0; j < TAM_MATRIZ; j++) {
            soma += matriz[i][j];
        }
    }
    return soma;
}

void zerarMatriz(int matriz[TAM_MATRIZ][TAM_MATRIZ]) {
    for (int i = 0; i < TAM_MATRIZ; i++) {
        for (int j = 0; j < TAM_MATRIZ; j++) {
            matriz[i][j] = 0;
        }
    }
}

int main() {
    int matriz[TAM_MATRIZ][TAM_MATRIZ] = {{0}};

    int opcao;
    do {
        printf("\nMENU\n");
        printf("1. Carregar\n");
        printf("2. Imprimir\n");
        printf("3. Somar\n");
        printf("4. Zerar\n");
        printf("9. Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                carregarMatriz(matriz);
                break;
            case 2:
                imprimirMatriz(matriz);
                break;
            case 3:
                printf("Soma dos valores na matriz: %d\n", somarMatriz(matriz));
                break;
            case 4:
                zerarMatriz(matriz);
                printf("Valores da matriz zerados.\n");
                break;
            case 9:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 9);

    return 0;
}
