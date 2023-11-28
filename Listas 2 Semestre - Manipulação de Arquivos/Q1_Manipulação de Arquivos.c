/*Enunciado:Q1
CONTROLE DE RA’s – Crie uma aplicação console em C que permita realizar a manipulação de
INSERÇÃO, PESQUISA, EXCLUSÃO e ALTERAÇÃO (famoso CRUD) de ao menos 100 RA’s de alunos, a
aplicação deverá conter as opções conforme o menu abaixo.
CONTROLE DE RAs
1. Inserir (não deve permitir inserir RA repetido, sendo assim, antes deverá pesquisar, se não achar RA
igual deve localizar uma posição vazia e então inserir)
2. Alterar (deve solicitar o RA de origem e o RA de destino, deve localizar o RA de origem e alterar o
valor pelo RA de destino)
3. Excluir (deve solicitar um RA e então pesquisá-lo, ao encontrar deve removê-lo)
4. Pesquisar
5. Imprimir analítico (imprime todas as posições e seus valores)
6. Imprimir sintético (imprime somente as posições que contiver RA)
7. Contar (deverá contar o número de RA’s cadastrados)
8. Salvar em banco (deverá criar um arquivo contendo todos os RA’s cadastrados)
9. Carregar do banco (deverá ler o arquivo salvo com os RA’s e carregar no sistema)
20. Sair
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>
#include <string.h>
#define MAX_RAS 100
#define RA_LENGTH 10

void imprimirRA(char ras[][RA_LENGTH], int count) {
    printf("\nRA's Cadastrados:\n");
    for (int i = 0; i < count; ++i) {
        if (ras[i][0] != '\0') {
            printf("%s\n", ras[i]);
        }
    }
}

int buscarRA(char ras[][RA_LENGTH], char ra[], int count) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(ras[i], ra) == 0) {
            return i;
        }
    }
    return -1;
}

int inserirRA(char ras[][RA_LENGTH], int count) {
    if (count >= MAX_RAS) {
        printf("Limite de RAs atingido!\n");
        return count;
    }

    char novoRA[RA_LENGTH];
    printf("Digite o RA a ser inserido: ");
    scanf("%s", novoRA);

    if (buscarRA(ras, novoRA, count) != -1) {
        printf("RA já existe na base de dados!\n");
        return count;
    }

    strcpy(ras[count], novoRA);
    return count + 1;
}

void alterarRA(char ras[][RA_LENGTH], int count) {
    char raOrigem[RA_LENGTH], raDestino[RA_LENGTH];
    printf("Digite o RA de origem: ");
    scanf("%s", raOrigem);
    printf("Digite o RA de destino: ");
    scanf("%s", raDestino);

    int index = buscarRA(ras, raOrigem, count);
    if (index == -1) {
        printf("RA de origem não encontrado!\n");
        return;
    }

    strcpy(ras[index], raDestino);
    printf("RA alterado com sucesso!\n");
}

void excluirRA(char ras[][RA_LENGTH], int count) {
    char ra[RA_LENGTH];
    printf("Digite o RA que deseja excluir: ");
    scanf("%s", ra);

    int index = buscarRA(ras, ra, count);
    if (index == -1) {
        printf("RA não encontrado!\n");
        return;
    }

    memset(&ras[index], 0, sizeof(char) * RA_LENGTH);
    printf("RA excluído com sucesso!\n");
}

void pesquisarRA(char ras[][RA_LENGTH], int count) {
    char ra[RA_LENGTH];
    printf("Digite o RA que deseja pesquisar: ");
    scanf("%s", ra);

    int index = buscarRA(ras, ra, count);
    if (index == -1) {
        printf("RA não encontrado!\n");
    } else {
        printf("RA encontrado na posição %d!\n", index);
    }
}

int contarRAs(char ras[][RA_LENGTH], int count) {
    int counter = 0;
    for (int i = 0; i < count; ++i) {
        if (ras[i][0] != '\0') {
            counter++;
        }
    }
    return counter;
}

void salvarEmBanco(char ras[][RA_LENGTH], int count) {
    FILE *file = fopen("ras.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar arquivo!\n");
        return;
    }

    for (int i = 0; i < count; ++i) {
        if (ras[i][0] != '\0') {
            fprintf(file, "%s\n", ras[i]);
        }
    }

    fclose(file);
    printf("RAs salvos no arquivo com sucesso!\n");
}

int carregarDoBanco(char ras[][RA_LENGTH]) {
    FILE *file = fopen("ras.txt", "r");
    if (file == NULL) {
        printf("Arquivo não encontrado!\n");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%s", ras[count]) != EOF && count < MAX_RAS) {
        count++;
    }

    fclose(file);
    printf("RAs carregados do arquivo com sucesso!\n");
    return count;
}

int main() {
    char ras[MAX_RAS][RA_LENGTH];
    int raCount = 0;
    int opcao;

    do {
        printf("\nCONTROLE DE RAs\n");
        printf("1. Inserir\n");
        printf("2. Alterar\n");
        printf("3. Excluir\n");
        printf("4. Pesquisar\n");
        printf("5. Imprimir analítico\n");
        printf("6. Imprimir sintético\n");
        printf("7. Contar\n");
        printf("8. Salvar em banco\n");
        printf("9. Carregar do banco\n");
        printf("20. Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                raCount = inserirRA(ras, raCount);
                break;
            case 2:
                alterarRA(ras, raCount);
                break;
            case 3:
                excluirRA(ras, raCount);
                break;
            case 4:
                pesquisarRA(ras, raCount);
                break;
            case 5:
                imprimirRA(ras, raCount);
                break;
            case 6:
                printf("Imprimir sintético:\n");
                for (int i = 0; i < raCount; ++i) {
                    if (ras[i][0] != '\0') {
                        printf("%s\n", ras[i]);
                    }
                }
                break;
            case 7:
                printf("Total de RAs cadastrados: %d\n", contarRAs(ras, raCount));
                break;
            case 8:
                salvarEmBanco(ras, raCount);
                break;
            case 9:
                raCount = carregarDoBanco(ras);
                break;
            case 20:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 20);

    return 0;
}
