/*Enunciado:Q3
LINHAS X COLUNAS 2 – Crie uma matriz capaz de armazenar 30 valores inteiros, baseado nesta matriz
implemente o menu abaixo, cada uma das opções do menu deverá executar uma ação sobre a matriz.
MENU – LINHAS X COLUNAS 2
1. Carregar aleatório (considerar valores entre 0 e 50)
2. Imprimir todos
3. Soma por linha (apresente o número de cada linha e a soma dos valores da linha correspondente)
4. Soma por coluna (apresente o número de cada coluna e a soma dos valores da coluna)
5. Linha com a maior soma (apresente a linha que contém a maior soma dentre as somas das linhas)
6. Coluna com maior soma (idem ao item 4)
7. Maior soma linha x coluna y (solicite o número de uma linha e coluna do usuário, some os valores
da linha e da coluna e verifique qual contém o maior valor, é importante verificar se o número da linha
e coluna fornecido existe na matriz)
9. Sair
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 5
#define COLUNAS 6

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

void somaPorLinha(int matriz[LINHAS][COLUNAS]) {
    printf("Soma por linha:\n");
    for (int i = 0; i < LINHAS; i++) {
        int soma = 0;
        for (int j = 0; j < COLUNAS; j++) {
            soma += matriz[i][j];
        }
        printf("Linha %d: Soma = %d\n", i, soma);
    }
}

void somaPorColuna(int matriz[LINHAS][COLUNAS]) {
    printf("Soma por coluna:\n");
    for (int j = 0; j < COLUNAS; j++) {
        int soma = 0;
        for (int i = 0; i < LINHAS; i++) {
            soma += matriz[i][j];
        }
        printf("Coluna %d: Soma = %d\n", j, soma);
    }
}

int maiorSomaLinha(int matriz[LINHAS][COLUNAS]) {
    int maior = 0, linhaMaior = 0;
    for (int i = 0; i < LINHAS; i++) {
        int soma = 0;
        for (int j = 0; j < COLUNAS; j++) {
            soma += matriz[i][j];
        }
        if (soma > maior) {
            maior = soma;
            linhaMaior = i;
        }
    }
    return linhaMaior;
}

int maiorSomaColuna(int matriz[LINHAS][COLUNAS]) {
    int maior = 0, colunaMaior = 0;
    for (int j = 0; j < COLUNAS; j++) {
        int soma = 0;
        for (int i = 0; i < LINHAS; i++) {
            soma += matriz[i][j];
        }
        if (soma > maior) {
            maior = soma;
            colunaMaior = j;
        }
    }
    return colunaMaior;
}

void maiorSomaLinhaColuna(int matriz[LINHAS][COLUNAS], int linha, int coluna) {
    if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS) {
        int somaLinha = 0, somaColuna = 0;
        for (int j = 0; j < COLUNAS; j++) {
            somaLinha += matriz[linha][j];
        }
        for (int i = 0; i < LINHAS; i++) {
            somaColuna += matriz[i][coluna];
        }
        if (somaLinha > somaColuna) {
            printf("A linha %d possui a maior soma: %d\n", linha, somaLinha);
        } else if (somaColuna > somaLinha) {
            printf("A coluna %d possui a maior soma: %d\n", coluna, somaColuna);
        } else {
            printf("A soma da linha %d e coluna %d é igual: %d\n", linha, coluna, somaLinha);
        }
    } else {
        printf("Linha ou coluna inválida na matriz.\n");
    }
}

int main() {
    int matriz[LINHAS][COLUNAS] = {{0}};

    int opcao, linha, coluna;
    do {
        printf("\nMENU - LINHAS X COLUNAS 2\n");
        printf("1. Carregar aleatório\n");
        printf("2. Imprimir todos\n");
        printf("3. Soma por linha\n");
        printf("4. Soma por coluna\n");
        printf("5. Linha com a maior soma\n");
        printf("6. Coluna com maior soma\n");
        printf("7. Maior soma linha x coluna y\n");
        printf("9. Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                carregarAleatorio(matriz);
                break;
            case 2:
                imprimirMatriz(matriz);
                break;
            case 3:
                somaPorLinha(matriz);
                break;
            case 4:
                somaPorColuna(matriz);
                break;
            case 5:
                printf("Linha com maior soma: %d\n", maiorSomaLinha(matriz));
                break;
            case 6:
                printf("Coluna com maior soma: %d\n", maiorSomaColuna(matriz));
                break;
            case 7:
                printf("Digite o número da linha e da coluna: ");
                scanf("%d %d", &linha, &coluna);
                maiorSomaLinhaColuna(matriz, linha, coluna);
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
