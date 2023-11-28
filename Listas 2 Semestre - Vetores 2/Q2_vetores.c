/*Enunciado:Q2
ALTURAS – Crie uma aplicação console, esta aplicação deve ser capaz de armazenar 10 valores
numéricos reais (alturas), para manipular este vetor, deve-se criar o menu com as opções abaixo.
MENU
1 - Adicionar (deverá solicitar a POSIÇÃO e VALOR do usuário, o valor fornecido, deverá ser adicionado
na posição informada, caso a posição informada não exista, deverá exibir msg para o usuário
informando que a posição é inválida).
2 - Ler (Deverá solicitar do usuário uma posição qualquer do vetor e então exibir o valor existente nesta
posição, validar se a posição existe antes de ler o valor).
3 - Somar (Deve somar todos os valores do vetor e apresentar o resultado da soma).
4 - Contar (Deve percorrer o vetor e contar quantos valores maior que zero existem no vetor).
5 - Contar posições vazias
9 - Sair.
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>

#define TAMANHO 10

void adicionarAltura(float *alturas, int posicao, float valor) {
    if (posicao >= 0 && posicao < TAMANHO) {
        alturas[posicao] = valor;
        printf("Altura adicionada na posicao %d com sucesso!\n", posicao);
    } else {
        printf("Posicao invalida!\n");
    }
}

void lerAltura(float *alturas, int posicao) {
    if (posicao >= 0 && posicao < TAMANHO) {
        printf("Altura na posicao %d: %.2f\n", posicao, alturas[posicao]);
    } else {
        printf("Posicao invalida!\n");
    }
}

float somarAlturas(float *alturas) {
    float soma = 0;
    for (int i = 0; i < TAMANHO; i++) {
        soma += alturas[i];
    }
    return soma;
}

int contarMaioresQueZero(float *alturas) {
    int contador = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (alturas[i] > 0) {
            contador++;
        }
    }
    return contador;
}

int contarPosicoesVazias(float *alturas) {
    int contador = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (alturas[i] == 0) {
            contador++;
        }
    }
    return contador;
}

void imprimirMenu() {
    printf("\n..:: MENU ::..\n");
    printf("1. Adicionar\n");
    printf("2. Ler\n");
    printf("3. Somar\n");
    printf("4. Contar valores maiores que zero\n");
    printf("5. Contar posicoes vazias\n");
    printf("9. Sair\n");
}

int main() {
    float alturas[TAMANHO] = {0};
    int opcao, posicao;
    float valor;

    do {
        imprimirMenu();
        printf("Escolha uma opcao (1-5, 9): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a posicao e a altura: ");
                scanf("%d %f", &posicao, &valor);
                adicionarAltura(alturas, posicao, valor);
                break;
            case 2:
                printf("Digite a posicao para ler a altura: ");
                scanf("%d", &posicao);
                lerAltura(alturas, posicao);
                break;
            case 3:
                printf("A soma das alturas e: %.2f\n", somarAlturas(alturas));
                break;
            case 4:
                printf("Quantidade de alturas maiores que zero: %d\n", contarMaioresQueZero(alturas));
                break;
            case 5:
                printf("Quantidade de posicoes vazias: %d\n", contarPosicoesVazias(alturas));
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
