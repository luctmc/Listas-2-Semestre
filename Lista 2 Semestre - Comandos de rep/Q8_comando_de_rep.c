/*Enunciado:Q8
MENU INTERATIVO 6 OPÇÕES – Crie uma aplicação que contenha um menu interativo com as
seguintes opções 1. Contar pares; 2. Contar ímpares; 3. Produto pares; 4. Produto ímpares; 9. Sair. Para
cada uma das opções deverá ser solicitado um número inteiro quando o usuário acessar a opção,
baseado no número informado, percorra de 1 até o número informado e execute cada uma das
operações de acordo com a descrição da opção do menu e no final apresente o resultado da operação. 
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>

int contarPares(int numero) {
    int contador = 0;
    for (int i = 1; i <= numero; i++) {
        if (i % 2 == 0) {
            contador++;
        }
    }
    return contador;
}

int contarImpares(int numero) {
    int contador = 0;
    for (int i = 1; i <= numero; i++) {
        if (i % 2 != 0) {
            contador++;
        }
    }
    return contador;
}

long long int calcularProdutoPares(int numero) {
    long long int produto = 1;
    for (int i = 2; i <= numero; i += 2) {
        produto *= i;
    }
    return produto;
}

long long int calcularProdutoImpares(int numero) {
    long long int produto = 1;
    for (int i = 1; i <= numero; i += 2) {
        produto *= i;
    }
    return produto;
}

int main() {
    int opcao, numero;

    do {
        printf("\nMenu de Opcoes:\n");
        printf("1. Contar pares\n");
        printf("2. Contar impares\n");
        printf("3. Produto pares\n");
        printf("4. Produto impares\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um numero inteiro: ");
                scanf("%d", &numero);
                printf("Quantidade de pares de 1 a %d: %d\n", numero, contarPares(numero));
                break;
            case 2:
                printf("Digite um numero inteiro: ");
                scanf("%d", &numero);
                printf("Quantidade de impares de 1 a %d: %d\n", numero, contarImpares(numero));
                break;
            case 3:
                printf("Digite um numero inteiro: ");
                scanf("%d", &numero);
                printf("Produto dos pares de 1 a %d: %lld\n", numero, calcularProdutoPares(numero));
                break;
            case 4:
                printf("Digite um numero inteiro: ");
                scanf("%d", &numero);
                printf("Produto dos impares de 1 a %d: %lld\n", numero, calcularProdutoImpares(numero));
                break;
            case 9:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 9);

    return 0;
}
