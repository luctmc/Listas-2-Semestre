/*Enunciado:Q3
IDADES – Crie uma aplicação console, esta aplicação deverá ser capaz de armazenar até 100 Idades. O
menu abaixo deverá ser criado para interagir com as idades, é importante lembrar que cada opção do
menu deverá invocar um método da classe que será responsável pela execução dele.
2
MENU - IDADES
1 - Adicionar
2 - Adicionar Idade na Posição X (deverá solicitar do usuário uma idade e a posição que se deseja
armazenar a idade, caso a posição esteja ocupada, o usuário deverá ser informado que não será
possível adicionar a idade pois a posição está ocupada)
3 - Imprimir Posição X (caso exista uma idade na posição informada, esta idade deverá ser impressa, é
importante validar se a posição informada pelo usuário existe no vetor)
4 - Imprimir Todas
5 - Remover Idade da Posição X (é importante validar se a posição informada pelo usuário existe no
vetor)
6 - Remover Todas (remove todas as idades cadastravas no vetor)
7 - Contar Idades
8 - Somar Idades
9 - Somar Idades Ímpares
10 - Imprimir Idades Pares
99 - Sair.
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>

#define TAMANHO 100

void adicionarIdade(int *idades, int posicao, int idade) {
    if (posicao >= 0 && posicao < TAMANHO) {
        if (idades[posicao] == 0) {
            idades[posicao] = idade;
            printf("Idade adicionada na posicao %d com sucesso!\n", posicao);
        } else {
            printf("Posicao ocupada, nao foi possivel adicionar a idade.\n");
        }
    } else {
        printf("Posicao invalida!\n");
    }
}

void imprimirIdadeNaPosicao(int *idades, int posicao) {
    if (posicao >= 0 && posicao < TAMANHO) {
        if (idades[posicao] != 0) {
            printf("Idade na posicao %d: %d\n", posicao, idades[posicao]);
        } else {
            printf("Nao existe idade na posicao %d.\n", posicao);
        }
    } else {
        printf("Posicao invalida!\n");
    }
}

void imprimirTodasAsIdades(int *idades) {
    printf("Todas as idades armazenadas:\n");
    for (int i = 0; i < TAMANHO; i++) {
        if (idades[i] != 0) {
            printf("Posicao %d: %d\n", i, idades[i]);
        }
    }
}

void removerIdadeNaPosicao(int *idades, int posicao) {
    if (posicao >= 0 && posicao < TAMANHO) {
        if (idades[posicao] != 0) {
            idades[posicao] = 0;
            printf("Idade removida da posicao %d com sucesso!\n", posicao);
        } else {
            printf("Nao existe idade na posicao %d para remover.\n", posicao);
        }
    } else {
        printf("Posicao invalida!\n");
    }
}

void removerTodasAsIdades(int *idades) {
    for (int i = 0; i < TAMANHO; i++) {
        idades[i] = 0;
    }
    printf("Todas as idades removidas!\n");
}

int contarIdades(int *idades) {
    int contador = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (idades[i] != 0) {
            contador++;
        }
    }
    return contador;
}

int somarIdades(int *idades) {
    int soma = 0;
    for (int i = 0; i < TAMANHO; i++) {
        soma += idades[i];
    }
    return soma;
}

int somarIdadesImpares(int *idades) {
    int soma = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (idades[i] % 2 != 0) {
            soma += idades[i];
        }
    }
    return soma;
}

void imprimirIdadesPares(int *idades) {
    printf("Idades pares:\n");
    for (int i = 0; i < TAMANHO; i++) {
        if (idades[i] != 0 && idades[i] % 2 == 0) {
            printf("%d ", idades[i]);
        }
    }
    printf("\n");
}

void imprimirMenu() {
    printf("\nMENU - IDADES\n");
    printf("1 - Adicionar\n");
    printf("2 - Adicionar Idade na Posicao X\n");
    printf("3 - Imprimir Posicao X\n");
    printf("4 - Imprimir Todas\n");
    printf("5 - Remover Idade da Posicao X\n");
    printf("6 - Remover Todas\n");
    printf("7 - Contar Idades\n");
    printf("8 - Somar Idades\n");
    printf("9 - Somar Idades Impares\n");
    printf("10 - Imprimir Idades Pares\n");
    printf("99 - Sair\n");
}

int main() {
    int idades[TAMANHO] = {0};
    int opcao, posicao, idade;

    do {
        imprimirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a idade a ser adicionada: ");
                scanf("%d", &idade);
                adicionarIdade(idades, contarIdades(idades), idade);
                break;
            case 2:
                printf("Digite a posicao e a idade a ser adicionada: ");
                scanf("%d %d", &posicao, &idade);
                adicionarIdade(idades, posicao, idade);
                break;
            case 3:
                printf("Digite a posicao para imprimir a idade: ");
                scanf("%d", &posicao);
                imprimirIdadeNaPosicao(idades, posicao);
                break;
            case 4:
                imprimirTodasAsIdades(idades);
                break;
            case 5:
                printf("Digite a posicao para remover a idade: ");
                scanf("%d", &posicao);
                removerIdadeNaPosicao(idades, posicao);
                break;
            case 6:
                removerTodasAsIdades(idades);
                break;
            case 7:
                printf("Total de idades cadastradas: %d\n", contarIdades(idades));
                break;
            case 8:
                printf("Soma das idades: %d\n", somarIdades(idades));
                break;
            case 9:
                printf("Soma das idades impares: %d\n", somarIdadesImpares(idades));
                break;
            case 10:
                imprimirIdadesPares(idades);
                break;
            case 99:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 99);

    return 0;
}
