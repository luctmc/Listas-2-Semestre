/*Enunciado:Q2
LINHAS X COLUNAS – Crie uma matriz capaz de armazenar 30 valores inteiros, baseado nesta matriz
implemente o menu abaixo, cada uma das opções do menu deverá executar uma ação sobre a matriz.
MENU – LINHAS X COLUNAS
1. Carregar usuário (deverá solicitar valores inteiros ao usuário e armazenar na matriz)
2. Carregar aleatório (deverá sortear valores aleatórios entre 0 e 50 e armazenar na matriz)
3. Imprimir (Deverá exibir o endereço e o valor contido em cada posição da matriz)
4. Imprimir linhas x (Deverá solicitar um número inteiro que corresponderá a uma linha da matriz,
todos os valores da linha informada deverão ser impressos, atenção é necessário validar se a linha
existe).
5. Somar linha x (Deverá solicitar do usuário um número inteiro que corresponderá a uma linha da
matriz, todos os valores da linha deverão ser somados e o resultado deverá ser apresentado, atenção
é necessário validar se a linha existe na matriz)
6. Imprimir coluna y (Deverá solicitar um número inteiro que corresponderá a uma coluna da matriz,
todos os valores desta coluna deverão ser impressos, atenção pois é necessário verificar se a coluna
existe na matriz.
7 Somar linha x com coluna y (Deverá solicitar do usuário dois valores (x, y) o primeiro corresponderá
a uma linha da matriz e o segundo a uma coluna, todos os valores da linha e coluna informada deverão
serem somados e o resultado apresentado, atenção pois é necessário verificar se a linha/coluna
existem na matriz).
9. Sair
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 5
#define COLUNAS 6

void carregarUsuario(int matriz[LINHAS][COLUNAS]) {
    printf("Preencha a matriz %dx%d:\n", LINHAS, COLUNAS);
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("Posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void carregarAleatorio(int matriz[LINHAS][COLUNAS]) {
    srand(time(0));
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = rand() % 51; // Gera valores aleatórios entre 0 e 50
        }
    }
}

void imprimirMatriz(int matriz[LINHAS][COLUNAS]) {
    printf("Valores na matriz %dx%d:\n", LINHAS, COLUNAS);
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("[%d][%d]: %d\t", i, j, matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimirLinha(int matriz[LINHAS][COLUNAS], int linha) {
    if (linha >= 0 && linha < LINHAS) {
        printf("Valores da linha %d:\n", linha);
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", matriz[linha][j]);
        }
        printf("\n");
    } else {
        printf("Linha inexistente na matriz.\n");
    }
}

int somarLinha(int matriz[LINHAS][COLUNAS], int linha) {
    int soma = 0;
    if (linha >= 0 && linha < LINHAS) {
        for (int j = 0; j < COLUNAS; j++) {
            soma += matriz[linha][j];
        }
    } else {
        printf("Linha inexistente na matriz.\n");
    }
    return soma;
}

void imprimirColuna(int matriz[LINHAS][COLUNAS], int coluna) {
    if (coluna >= 0 && coluna < COLUNAS) {
        printf("Valores da coluna %d:\n", coluna);
        for (int i = 0; i < LINHAS; i++) {
            printf("%d\n", matriz[i][coluna]);
        }
    } else {
        printf("Coluna inexistente na matriz.\n");
    }
}

int somarLinhaComColuna(int matriz[LINHAS][COLUNAS], int linha, int coluna) {
    int soma = 0;
    if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS) {
        for (int i = 0; i < LINHAS; i++) {
            soma += matriz[i][coluna];
        }
        for (int j = 0; j < COLUNAS; j++) {
            soma += matriz[linha][j];
        }
    } else {
        printf("Linha ou coluna inexistente na matriz.\n");
    }
    return soma;
}

int main() {
    int matriz[LINHAS][COLUNAS] = {{0}};

    int opcao, linha, coluna;
    do {
        printf("\nMENU - LINHAS X COLUNAS\n");
        printf("1. Carregar usuário\n");
        printf("2. Carregar aleatório\n");
        printf("3. Imprimir\n");
        printf("4. Imprimir linhas x\n");
        printf("5. Somar linha x\n");
        printf("6. Imprimir coluna y\n");
        printf("7. Somar linha x com coluna y\n");
        printf("9. Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                carregarUsuario(matriz);
                break;
            case 2:
                carregarAleatorio(matriz);
                break;
            case 3:
                imprimirMatriz(matriz);
                break;
            case 4:
                printf("Digite o número da linha: ");
                scanf("%d", &linha);
                imprimirLinha(matriz, linha);
                break;
            case 5:
                printf("Digite o número da linha: ");
                scanf("%d", &linha);
                printf("Soma da linha %d: %d\n", linha, somarLinha(matriz, linha));
                break;
            case 6:
                printf("Digite o número da coluna: ");
                scanf("%d", &coluna);
                imprimirColuna(matriz, coluna);
                break;
            case 7:
                printf("Digite o número da linha e da coluna: ");
                scanf("%d %d", &linha, &coluna);
                printf("Soma da linha %d com a coluna %d: %d\n", linha, coluna, somarLinhaComColuna(matriz, linha, coluna));
                break;
            case 9:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 9);

    return 0;
}
