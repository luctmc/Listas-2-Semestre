/*Enunciado:Q2
MENSALIDADES – Crie uma aplicação console em C responsável por armazenar 10 valores de
mensalidades, a aplicação deverá conter um menu interativo com as opções abaixo relacionadas:
 ..:: MENSALIDADES ::..
1. Zerar (deverá percorrer o vetor e atribuir valor zero a todos os endereços)
2. Carregar (deverá solicitar do usuário 10 mensalidades, cada mensalidade informada deverá ser
armazenada em uma posição do vetor).
3. Imprimir (deverá percorrer o vetor e exibir todas as mensalidades, exiba também a posição em
que a mensalidade está armazenada no vetor)
4. Somar (Deverá percorrer o vetor, somar todas as mensalidades e exibir o resultado).
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>

#define TAMANHO 10

void zerarMensalidades(float *mensalidades) {
    for (int i = 0; i < TAMANHO; i++) {
        mensalidades[i] = 0;
    }
}

void carregarMensalidades(float *mensalidades) {
    printf("Digite as 10 mensalidades:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("Mensalidade %d: ", i + 1);
        scanf("%f", &mensalidades[i]);
    }
}

void imprimirMensalidades(float *mensalidades) {
    printf("\nAs mensalidades armazenadas sao:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("Posicao %d: %.2f\n", i, mensalidades[i]);
    }
}

void somarMensalidades(float *mensalidades) {
    float soma = 0;
    for (int i = 0; i < TAMANHO; i++) {
        soma += mensalidades[i];
    }
    printf("\nA soma das mensalidades e: %.2f\n", soma);
}

int main() {
    float mensalidades[TAMANHO];
    int opcao;

    do {
        printf("\n..:: MENSALIDADES ::..\n");
        printf("1. Zerar\n");
        printf("2. Carregar\n");
        printf("3. Imprimir\n");
        printf("4. Somar\n");
        printf("Escolha uma opcao (1-4): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                zerarMensalidades(mensalidades);
                printf("Mensalidades zeradas!\n");
                break;
            case 2:
                carregarMensalidades(mensalidades);
                break;
            case 3:
                imprimirMensalidades(mensalidades);
                break;
            case 4:
                somarMensalidades(mensalidades);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao >= 1 && opcao <= 4);

    return 0;
}
