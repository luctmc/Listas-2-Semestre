/*Enunciado:Q1
CIDADES – Crie uma aplicação console em C para manipulação de cidades, a base de dados deverá
permitir inserir até 10 cidades, cada cidade deverá conter as seguintes informações Código, Nome,
Número Habitantes.
MENU
1. Inserir
2. Alterar
3. Excluir
4. Pesquisar (código)
5. Imprimir todas
9. Sair
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>
#include <string.h>

#define MAX_CITIES 10
#define MAX_NAME_LENGTH 50

struct City {
    int code;
    char name[MAX_NAME_LENGTH];
    int population;
};

void printCity(struct City cities[], int count) {
    printf("\nCidades cadastradas:\n");
    for (int i = 0; i < count; ++i) {
        printf("Código: %d, Nome: %s, Habitantes: %d\n", cities[i].code, cities[i].name, cities[i].population);
    }
}

int findCity(struct City cities[], int code, int count) {
    for (int i = 0; i < count; ++i) {
        if (cities[i].code == code) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct City cities[MAX_CITIES];
    int cityCount = 0;

    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Inserir\n");
        printf("2. Alterar\n");
        printf("3. Excluir\n");
        printf("4. Pesquisar (código)\n");
        printf("5. Imprimir todas\n");
        printf("9. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (cityCount < MAX_CITIES) {
                    printf("\nInserir nova cidade:\n");
                    printf("Código: ");
                    scanf("%d", &cities[cityCount].code);
                    printf("Nome: ");
                    scanf("%s", cities[cityCount].name);
                    printf("Número de habitantes: ");
                    scanf("%d", &cities[cityCount].population);
                    cityCount++;
                } else {
                    printf("Limite máximo de cidades atingido!\n");
                }
                break;
            }
            case 2: {
                int code;
                printf("\nAlterar cidade (digite o código): ");
                scanf("%d", &code);
                int index = findCity(cities, code, cityCount);
                if (index != -1) {
                    printf("Novo nome: ");
                    scanf("%s", cities[index].name);
                    printf("Novo número de habitantes: ");
                    scanf("%d", &cities[index].population);
                    printf("Cidade alterada com sucesso!\n");
                } else {
                    printf("Cidade não encontrada!\n");
                }
                break;
            }
            case 3: {
                int code;
                printf("\nExcluir cidade (digite o código): ");
                scanf("%d", &code);
                int index = findCity(cities, code, cityCount);
                if (index != -1) {
                    for (int i = index; i < cityCount - 1; ++i) {
                        cities[i] = cities[i + 1];
                    }
                    cityCount--;
                    printf("Cidade excluída com sucesso!\n");
                } else {
                    printf("Cidade não encontrada!\n");
                }
                break;
            }
            case 4: {
                int code;
                printf("\nPesquisar cidade por código: ");
                scanf("%d", &code);
                int index = findCity(cities, code, cityCount);
                if (index != -1) {
                    printf("Código: %d, Nome: %s, Habitantes: %d\n", cities[index].code, cities[index].name, cities[index].population);
                } else {
                    printf("Cidade não encontrada!\n");
                }
                break;
            }
            case 5:
                printCity(cities, cityCount);
                break;
            case 9:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (choice != 9);

    return 0;
}
