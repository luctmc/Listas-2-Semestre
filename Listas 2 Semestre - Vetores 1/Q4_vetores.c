/*Enunciado:Q4
VALORES ALEATÓRIOS – Crie uma aplicação console em C responsável por armazenar 60 valores
inteiros, a aplicação deverá conter um menu de console com as opções abaixo relacionada:
 ..:: SORTEIO ::..
1. Zerar (deverá percorrer o vetor e atribuir valor -1 a todos os endereços)
2. Carregar aleatório (deverá carregar o vetor com valores inteiros aleatórios entre 1 e 60, o aluno
deverá pesquisar gerar valores aleatórios em C)
3. Imprimir (deverá percorrer o vetor e exibir todos os valores armazenados, exibir também a
posição em que o valor está armazenado)
4. Somar (Deverá percorrer o vetor, somar todos os valores e exibir o resultado)
5. Relatório valores ímpares (Deverá percorrer o vetor e realizar as operações: contar os ímpares,
somar os ímpares e exibir o resultado das operações)
6. Maiores que (Deverá solicitar um valor entre 1 e 60 para o usuário informar, com o valor
informado deve-se percorrer o vetor e exibir todos os valores que contidos maiores que o valor
informado pelo usuário)
7. Quantos existem/repetidos (Deverá solicitar do usuário um valor inteiro entre 1 e 60, o
programa deverá então percorrer o vetor e contar quantas vezes o número informado pelo
usuário existe no vetor e exibir o número de ocorrências encontradas)
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
    srand(time(NULL)); // Inicializa a semente de números aleatórios com o tempo atual
    for (int i = 0; i < TAMANHO; i++) {
        valores[i] = rand() % 60 + 1; // Gera um número aleatório entre 1 e 60
    }
}

void imprimirValores(int *valores) {
    printf("\nOs valores armazenados sao:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("Posicao %d: %d\n", i, valores[i]);
    }
}

int somarValores(int *valores) {
    int soma = 0;
    for (int i = 0; i < TAMANHO; i++) {
        soma += valores[i];
    }
    printf("\nA soma dos valores e: %d\n", soma);
    return soma;
}

void relatorioImpares(int *valores) {
    int contador = 0;
    int soma = 0;

    for (int i = 0; i < TAMANHO; i++) {
        if (valores[i] % 2 != 0) {
            contador++;
            soma += valores[i];
        }
    }

    printf("\nRelatorio valores impares:\n");
    printf("Quantidade de impares: %d\n", contador);
    printf("Soma dos impares: %d\n", soma);
}

void maioresQue(int *valores, int valor) {
    printf("\nValores maiores que %d:\n", valor);
    for (int i = 0; i < TAMANHO; i++) {
        if (valores[i] > valor) {
            printf("%d ", valores[i]);
        }
    }
    printf("\n");
}

void quantosRepetidos(int *valores, int numero) {
    int contador = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (valores[i] == numero) {
            contador++;
        }
    }
    printf("\nQuantidade de vezes que o numero %d se repete: %d\n", numero, contador);
}

int main() {
    int valores[TAMANHO];
    int opcao, valor;

    do {
        printf("\n..:: SORTEIO ::..\n");
        printf("1. Zerar\n");
        printf("2. Carregar aleatorio\n");
        printf("3. Imprimir\n");
        printf("4. Somar\n");
        printf("5. Relatorio valores impares\n");
        printf("6. Maiores que\n");
        printf("7. Quantos existem/repetidos\n");
        printf("Escolha uma opcao (1-7): ");
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
                somarValores(valores);
                break;
            case 5:
                relatorioImpares(valores);
                break;
            case 6:
                printf("Digite um valor entre 1 e 60: ");
                scanf("%d", &valor);
                maioresQue(valores, valor);
                break;
            case 7:
                printf("Digite um numero entre 1 e 60: ");
                scanf("%d", &valor);
                quantosRepetidos(valores, valor);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao >= 1 && opcao <= 7);

    return 0;
}
