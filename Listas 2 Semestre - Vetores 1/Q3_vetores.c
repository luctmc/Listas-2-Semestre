/*Enunciado:Q3
IDADES – Crie uma aplicação console em C responsável por armazenar 8 idades de alunos, a aplicação
deverá conter um menu interativo com as opções abaixo relacionadas:
 ..:: IDADES ::..
1. Zerar (deverá percorrer o vetor e atribuir valor zero a todos os endereços)
2. Carregar (deverá solicitar do usuário 8 idades que serão armazenadas)
3. Imprimir (deverá percorrer o vetor e exibir todas as idades do vetor)
4. Somar (Deverá percorrer o vetor, somar todas as idades e exibir o resultado)
5. Pares (Deverá percorrer o vetor e exibir todas as idades pares)
6. Contar pares (Deverá percorrer o vetor, contar todas as idades pares e exibir a contagem)
7. Somar pares (Deverá percorrer o vetor, somar todas as idades que são pares e exibir a soma)
8. Menores idade (Deverá percorrer o vetor e exibir todas as idades que menores que 18)
2
9. Contar maiores idade (Deverá percorrer o vetor e contar o número de idades maiores ou igual
a 18 anos e exibir o resultado da contagem).
10. Somar maiores idade (Deverá percorrer o vetor e somar as idades maiores ou igual a 18 anos e
exibir o resultado da soma).
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>

#define TAMANHO 8

void zerarIdades(int *idades) {
    for (int i = 0; i < TAMANHO; i++) {
        idades[i] = 0;
    }
}

void carregarIdades(int *idades) {
    printf("Digite as 8 idades:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("Idade %d: ", i + 1);
        scanf("%d", &idades[i]);
    }
}

void imprimirIdades(int *idades) {
    printf("\nAs idades armazenadas sao:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("Posicao %d: %d\n", i, idades[i]);
    }
}

int somarIdades(int *idades) {
    int soma = 0;
    for (int i = 0; i < TAMANHO; i++) {
        soma += idades[i];
    }
    printf("\nA soma das idades e: %d\n", soma);
    return soma;
}

void exibirPares(int *idades) {
    printf("\nAs idades pares sao:\n");
    for (int i = 0; i < TAMANHO; i++) {
        if (idades[i] % 2 == 0) {
            printf("%d ", idades[i]);
        }
    }
    printf("\n");
}

int contarPares(int *idades) {
    int contador = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (idades[i] % 2 == 0) {
            contador++;
        }
    }
    printf("\nTotal de idades pares: %d\n", contador);
    return contador;
}

int somarPares(int *idades) {
    int soma = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (idades[i] % 2 == 0) {
            soma += idades[i];
        }
    }
    printf("\nA soma das idades pares e: %d\n", soma);
    return soma;
}

void exibirMenores18(int *idades) {
    printf("\nAs idades menores que 18 sao:\n");
    for (int i = 0; i < TAMANHO; i++) {
        if (idades[i] < 18) {
            printf("%d ", idades[i]);
        }
    }
    printf("\n");
}

int contarMaioresIgual18(int *idades) {
    int contador = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (idades[i] >= 18) {
            contador++;
        }
    }
    printf("\nTotal de idades maiores ou iguais a 18: %d\n", contador);
    return contador;
}

int somarMaioresIgual18(int *idades) {
    int soma = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (idades[i] >= 18) {
            soma += idades[i];
        }
    }
    printf("\nA soma das idades maiores ou iguais a 18 e: %d\n", soma);
    return soma;
}

int main() {
    int idades[TAMANHO];
    int opcao;

    do {
        printf("\n..:: IDADES ::..\n");
        printf("1. Zerar\n");
        printf("2. Carregar\n");
        printf("3. Imprimir\n");
        printf("4. Somar\n");
        printf("5. Pares\n");
        printf("6. Contar pares\n");
        printf("7. Somar pares\n");
        printf("8. Menores idade\n");
        printf("9. Contar maiores idade\n");
        printf("10. Somar maiores idade\n");
        printf("Escolha uma opcao (1-10): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                zerarIdades(idades);
                printf("Idades zeradas!\n");
                break;
            case 2:
                carregarIdades(idades);
                break;
            case 3:
                imprimirIdades(idades);
                break;
            case 4:
                somarIdades(idades);
                break;
            case 5:
                exibirPares(idades);
                break;
            case 6:
                contarPares(idades);
                break;
            case 7:
                somarPares(idades);
                break;
            case 8:
                exibirMenores18(idades);
                break;
            case 9:
                contarMaioresIgual18(idades);
                break;
            case 10:
                somarMaioresIgual18(idades);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao >= 1 && opcao <= 10);

    return 0;
}
