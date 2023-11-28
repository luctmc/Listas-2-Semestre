/*Enunciado:Q1
RA’s – Escreva uma aplicação de console, que ao ser executada, seja capaz armazenar ATE (e não mais
que) 10 números de Registros Acadêmicos (RA's). Toda a manipulação dos RA's deverá ser realizada
através de um MENU.
MENU
1 - Adicionar
2 - Remover (deverá solicitar o RA que deseja ser removido)
3 - Imprimir posição (deverá solicitar o RA e imprimir a posição que ele está armazenado e/ou imprimir
que ele não existe)
4 - Imprimir todos
5 - Contar (deverá contar o número de RA's cadastrados).
9 - Sair.
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>

#define TAMANHO 10

void imprimirRAs(int *ras, int quantidade) {
    printf("\nOs RAs armazenados sao:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Posicao %d: %d\n", i + 1, ras[i]);
    }
}

int encontrarRA(int *ras, int quantidade, int ra) {
    for (int i = 0; i < quantidade; i++) {
        if (ras[i] == ra) {
            return i + 1; // Retorna a posição (começando de 1) se encontrar o RA
        }
    }
    return 0; // Retorna 0 se não encontrar o RA
}

void removerRA(int *ras, int *quantidade, int ra) {
    int posicao = encontrarRA(ras, *quantidade, ra);
    if (posicao != 0) {
        for (int i = posicao - 1; i < *quantidade - 1; i++) {
            ras[i] = ras[i + 1];
        }
        (*quantidade)--;
        printf("RA removido com sucesso!\n");
    } else {
        printf("RA nao encontrado.\n");
    }
}

int main() {
    int ras[TAMANHO];
    int opcao, quantidade = 0, ra;

    do {
        printf("\n..:: MENU ::..\n");
        printf("1. Adicionar\n");
        printf("2. Remover\n");
        printf("3. Imprimir posicao\n");
        printf("4. Imprimir todos\n");
        printf("5. Contar\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao (1-5, 9): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (quantidade < TAMANHO) {
                    printf("Digite o RA: ");
                    scanf("%d", &ras[quantidade]);
                    quantidade++;
                    printf("RA adicionado com sucesso!\n");
                } else {
                    printf("Limite de RAs atingido (limite: %d).\n", TAMANHO);
                }
                break;
            case 2:
                printf("Digite o RA que deseja remover: ");
                scanf("%d", &ra);
                removerRA(ras, &quantidade, ra);
                break;
            case 3:
                printf("Digite o RA que deseja procurar: ");
                scanf("%d", &ra);
                int pos = encontrarRA(ras, quantidade, ra);
                if (pos != 0) {
                    printf("O RA %d esta na posicao %d.\n", ra, pos);
                } else {
                    printf("O RA %d nao foi encontrado.\n", ra);
                }
                break;
            case 4:
                if (quantidade > 0) {
                    imprimirRAs(ras, quantidade);
                } else {
                    printf("Nenhum RA foi adicionado ainda.\n");
                }
                break;
            case 5:
                printf("Quantidade de RAs cadastrados: %d\n", quantidade);
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
