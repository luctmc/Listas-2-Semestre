/*Enunciado:Q4
PROCESSAMENTO – Crie uma matriz capaz de armazenar 1000 valores inteiros, baseado nesta matriz
implemente o menu abaixo (Dica – Crie uma matriz menor para conferir se os métodos irão funcionar
e somente depois aumente o tamanho):
MENU – PROCESSAMENTO
1. Carregar aleatório (considere valores entre 0 e 5000)
2. Imprimir todos
3. Maior valor (percorra a matriz e localize o maior valor existente, imprima a posição e valor)
4. Menor valor (idem item 3)
5. Posição e Núm. de Repetições (solicite do usuário um valor inteiro, percorra a matriz e imprima as
posições onde o valor está contido, no final do processamento imprima a quantidade de vezes que o
valor existe)
6. Pares (percorra a matriz e imprima na tela apenas os números pares)
7. Relatório Pares x Ímpares (percorra a matriz, ao término do processamento exiba as seguintes
informações:
Número de valores pares e ímpares existentes;
Soma dos valores pares e ímpares;
Maior e menor número par;
Maior e menor número ímpar;
Valor médio dos valores pares e ímpares;
Maior soma (compare as somas e exiba o que contiver a maior soma);
Maior contagem (compare a contagem e exiba o que contiver a maior contagem) )
9. Sair
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 10
#define COLUNAS 10

void carregarAleatorio(int matriz[LINHAS][COLUNAS]) {
    srand(time(NULL));
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = rand() % 5001; // Gera valores aleatórios entre 0 e 5000
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

void maiorMenorValor(int matriz[LINHAS][COLUNAS]) {
    int maior = matriz[0][0], menor = matriz[0][0], posMaiorI = 0, posMaiorJ = 0, posMenorI = 0, posMenorJ = 0;

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                posMaiorI = i;
                posMaiorJ = j;
            }
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
                posMenorI = i;
                posMenorJ = j;
            }
        }
    }

    printf("Maior valor: [%d][%d] = %d\n", posMaiorI, posMaiorJ, maior);
    printf("Menor valor: [%d][%d] = %d\n", posMenorI, posMenorJ, menor);
}

void valorRepeticoes(int matriz[LINHAS][COLUNAS]) {
    int valor, count = 0;
    printf("Digite o valor a ser pesquisado: ");
    scanf("%d", &valor);

    printf("Posições onde o valor %d está contido:\n", valor);
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (matriz[i][j] == valor) {
                printf("[%d][%d]\t", i, j);
                count++;
            }
        }
    }
    printf("\nQuantidade de vezes que o valor %d existe na matriz: %d\n", valor, count);
}

void paresImpares(int matriz[LINHAS][COLUNAS]) {
    int countPares = 0, countImpares = 0, somaPares = 0, somaImpares = 0;
    int maiorPar = 0, menorPar = matriz[0][0], maiorImpar = 0, menorImpar = matriz[0][0];

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (matriz[i][j] % 2 == 0) {
                somaPares += matriz[i][j];
                countPares++;
                if (matriz[i][j] > maiorPar) maiorPar = matriz[i][j];
                if (matriz[i][j] < menorPar) menorPar = matriz[i][j];
            } else {
                somaImpares += matriz[i][j];
                countImpares++;
                if (matriz[i][j] > maiorImpar) maiorImpar = matriz[i][j];
                if (matriz[i][j] < menorImpar) menorImpar = matriz[i][j];
            }
        }
    }

    printf("Número de valores pares: %d\n", countPares);
    printf("Número de valores ímpares: %d\n", countImpares);
    printf("Soma dos valores pares: %d\n", somaPares);
    printf("Soma dos valores ímpares: %d\n", somaImpares);
    printf("Maior número par: %d\n", maiorPar);
    printf("Menor número par: %d\n", menorPar);
    printf("Maior número ímpar: %d\n", maiorImpar);
    printf("Menor número ímpar: %d\n", menorImpar);
    printf("Valor médio dos valores pares: %.2f\n", (float)somaPares / countPares);
    printf("Valor médio dos valores ímpares: %.2f\n", (float)somaImpares / countImpares);
    printf("Maior soma: %d\n", (somaPares > somaImpares) ? somaPares : somaImpares);
    printf("Maior contagem: %d\n", (countPares > countImpares) ? countPares : countImpares);
}

int main() {
    int matriz[LINHAS][COLUNAS] = {{0}};

    int opcao;
    do {
        printf("\nMENU – PROCESSAMENTO\n");
        printf("1. Carregar aleatório\n");
        printf("2. Imprimir todos\n");
        printf("3. Maior valor\n");
        printf("4. Menor valor\n");
        printf("5. Posição e Núm. de Repetições\n");
        printf("6. Pares\n");
        printf("7. Relatório Pares x Ímpares\n");
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
                maiorMenorValor(matriz);
                break;
            case 4:
                maiorMenorValor(matriz); // Mesmo método, pois também identifica o menor valor
                break;
            case 5:
                valorRepeticoes(matriz);
                break;
            case 6:
                paresImpares(matriz);
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
