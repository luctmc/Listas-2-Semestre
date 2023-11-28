/*Enunciado:Q2
ALUNOS – Crie uma aplicação console em C para manipulação de informações de alunos, a base de
dados deverá permitir inserir até 50 alunos, cada deverá conter as seguintes informações: RA, NOME
(estude como armazenar nomes com espaço), IDADE, VALOR MENSALIDADE.
MENU SYSACAD
1. Inserir
2. Alterar
3. Excluir
4. Pesquisar (ra)
5. Imprimir todas
6. Somar mensalidades
7. Número alunos cadastrados
8. Valor médio mensalidade
9. Valor maior mensalidade
10. Valor menor mensalidade
11. Mensalidade maior valor
12. Mensalidade menor valor
13. Imprimir mensalidade valor maior que X (solicite do usuário o valor)
20. Sair
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50

struct Student {
    int RA;
    char name[MAX_NAME_LENGTH];
    int age;
    float tuitionFee;
};

void printStudent(struct Student students[], int count) {
    printf("\nAlunos cadastrados:\n");
    for (int i = 0; i < count; ++i) {
        printf("RA: %d, Nome: %s, Idade: %d, Mensalidade: %.2f\n", students[i].RA, students[i].name, students[i].age, students[i].tuitionFee);
    }
}

int findStudent(struct Student students[], int RA, int count) {
    for (int i = 0; i < count; ++i) {
        if (students[i].RA == RA) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;

    int choice;
    do {
        printf("\nMENU SYSACAD\n");
        printf("1. Inserir\n");
        printf("2. Alterar\n");
        printf("3. Excluir\n");
        printf("4. Pesquisar (RA)\n");
        printf("5. Imprimir todas\n");
        printf("6. Somar mensalidades\n");
        printf("7. Número alunos cadastrados\n");
        printf("8. Valor médio mensalidade\n");
        printf("9. Valor maior mensalidade\n");
        printf("10. Valor menor mensalidade\n");
        printf("11. Mensalidade maior valor\n");
        printf("12. Mensalidade menor valor\n");
        printf("13. Imprimir mensalidade valor maior que X\n");
        printf("20. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (studentCount < MAX_STUDENTS) {
                    printf("\nInserir novo aluno:\n");
                    printf("RA: ");
                    scanf("%d", &students[studentCount].RA);
                    printf("Nome: ");
                    scanf(" %[^\n]s", students[studentCount].name);
                    printf("Idade: ");
                    scanf("%d", &students[studentCount].age);
                    printf("Mensalidade: ");
                    scanf("%f", &students[studentCount].tuitionFee);
                    studentCount++;
                } else {
                    printf("Limite máximo de alunos atingido!\n");
                }
                break;
            }
            case 2: {
                int RA;
                printf("\nAlterar aluno (digite o RA): ");
                scanf("%d", &RA);
                int index = findStudent(students, RA, studentCount);
                if (index != -1) {
                    printf("Novo nome: ");
                    scanf(" %[^\n]s", students[index].name);
                    printf("Nova idade: ");
                    scanf("%d", &students[index].age);
                    printf("Nova mensalidade: ");
                    scanf("%f", &students[index].tuitionFee);
                    printf("Aluno alterado com sucesso!\n");
                } else {
                    printf("Aluno não encontrado!\n");
                }
                break;
            }
            // ... Restante das opções do menu

            case 20:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (choice != 20);

    return 0;
}
