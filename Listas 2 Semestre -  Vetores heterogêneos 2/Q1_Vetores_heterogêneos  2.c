/*Enunciado:Q1
SORTEIO – Crie uma aplicação console em C que permita realizar a gestão e controle de sorteio de
alunos para eventos e brindes em geral. A base de dado do sistema deverá ser configurada para
permitir armazenar até 30 alunos (esta será a versão gratuita do sistema, a versão paga permitirá
cadastrar mais alunos). O sistema deverá armazenar as seguintes informações de cada aluno: RA,
CURSO (sigla), PERÍODO (equivalente ao semestre), e NOME.
O sistema deverá conter as opções descritas no menu abaixo.
::ATENÇÃO:: O campo RA será o campo CHAVE, ou seja, o sistema não deverá permitir que existam
dois ou mais alunos com o mesmo RA armazenado.
SORTEIO FACIL
1. Inserir
2. Alterar
3. Excluir (ra)
4. Pesquisar (ra)
5. Imprimir inscritos
6. Número inscritos
7. Sortear (deverá realizar um sorteio randômico de números entre 0 e 29, para cada sorteio deverá
verificar se a posição do vetor está preenchida, caso não esteja, deverá realizar outro sorteio até que
um número sorteado represente um número de posição que esteja com um valor cadastrado)
9. Sair
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALUNOS 30
#define RA_LENGTH 10
#define CURSO_LENGTH 5
#define NOME_LENGTH 50

struct Aluno {
    char ra[RA_LENGTH];
    char curso[CURSO_LENGTH];
    int periodo;
    char nome[NOME_LENGTH];
};

void imprimirAlunos(struct Aluno alunos[], int count) {
    printf("\nAlunos Inscritos:\n");
    for (int i = 0; i < count; ++i) {
        printf("RA: %s, Curso: %s, Período: %d, Nome: %s\n",
               alunos[i].ra, alunos[i].curso, alunos[i].periodo, alunos[i].nome);
    }
}

int buscarAluno(struct Aluno alunos[], char ra[], int count) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(alunos[i].ra, ra) == 0) {
            return i;
        }
    }
    return -1;
}

int numeroInscritos(int count) {
    return count;
}

void realizarSorteio(struct Aluno alunos[], int count) {
    int posSorteada;
    srand(time(NULL));

    do {
        posSorteada = rand() % MAX_ALUNOS;
    } while (posSorteada >= count || alunos[posSorteada].ra[0] == '\0');

    printf("\nAluno sorteado: %s\n", alunos[posSorteada].nome);
}

int main() {
    struct Aluno alunos[MAX_ALUNOS];
    int alunoCount = 0;

    int choice;
    do {
        printf("\nSORTEIO FACIL\n");
        printf("1. Inserir\n");
        printf("2. Alterar\n");
        printf("3. Excluir\n");
        printf("4. Pesquisar\n");
        printf("5. Imprimir inscritos\n");
        printf("6. Número inscritos\n");
        printf("7. Sortear\n");
        printf("9. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 7:
                realizarSorteio(alunos, alunoCount);
                break;
            // Adicione o restante das opções do menu
            default:
                printf("Opção inválida!\n");
        }
    } while (choice != 9);

    return 0;
}
