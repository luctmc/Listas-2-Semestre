/*Enunciado:Q6
CADASTRO ALUNOS – Crie uma aplicação que deverá ser capaz de armazenar até 5 registros de
diferentes alunos, as informações que deverão ser armazenadas são: RA, PRIMEIRO NOME e
MENSALIDADE. A aplicação deverá conter as seguintes opções de manipulação.
CONTROLE DE ALUNOS
1 – Cadastrar (deverá solicitar do usuário cada uma das informações de cada aluno).
2 – Relatório (deverá exibir na tela os dados de todos os alunos cadastrados de forma organizada,
durante a exibição, caso tenha algum aluno sem RA deverá pular esse registro e não exibir).
3 – Pesquisar RA (deverá solicitar um RA do usuário e então pesquisar, se existir deverá exibir os dados
do aluno referente ao RA, caso não exista deverá exibir uma mensagem informando).
4 – Remover (RA) (deverá solicitar um RA do usuário, e caso encontre um aluno com tal RA deverá
apagar os dados).
5 – Média Mensalidades (deverá calcular a média das mensalidades existentes, atenção, pois podem
existir posições do vetor sem mensalidade e esta posição não deverá ser considerada na média).
6 – Menor Mensalidade (deverá exibir os dados do aluno com menor mensalidade).
7 – Limpar Base (deverá remover todos os registros cadastrados, após utilizar essa opção a opção de
Relatório não deverá exibir qualquer informação).
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ALUNOS 5
#define TAM_NOME 50

struct Aluno {
    int RA;
    char nome[TAM_NOME];
    float mensalidade;
    bool ativo;
};

void cadastrarAluno(struct Aluno alunos[]) {
    for (int i = 0; i < MAX_ALUNOS; i++) {
        if (!alunos[i].ativo) {
            printf("Cadastro do aluno %d:\n", i + 1);
            printf("RA: ");
            scanf("%d", &alunos[i].RA);
            printf("Nome: ");
            scanf("%s", alunos[i].nome);
            printf("Mensalidade: ");
            scanf("%f", &alunos[i].mensalidade);
            alunos[i].ativo = true;
            printf("Aluno cadastrado com sucesso!\n");
            return;
        }
    }
    printf("Limite de alunos atingido!\n");
}

void exibirRelatorio(struct Aluno alunos[]) {
    printf("\nRelatorio de Alunos:\n");
    for (int i = 0; i < MAX_ALUNOS; i++) {
        if (alunos[i].ativo) {
            printf("RA: %d | Nome: %s | Mensalidade: %.2f\n", alunos[i].RA, alunos[i].nome, alunos[i].mensalidade);
        }
    }
}

void pesquisarRA(struct Aluno alunos[]) {
    int ra;
    printf("Digite o RA a ser pesquisado: ");
    scanf("%d", &ra);

    for (int i = 0; i < MAX_ALUNOS; i++) {
        if (alunos[i].ativo && alunos[i].RA == ra) {
            printf("Aluno encontrado:\n");
            printf("RA: %d | Nome: %s | Mensalidade: %.2f\n", alunos[i].RA, alunos[i].nome, alunos[i].mensalidade);
            return;
        }
    }
    printf("Aluno com RA %d nao encontrado.\n", ra);
}

void removerAluno(struct Aluno alunos[]) {
    int ra;
    printf("Digite o RA do aluno a ser removido: ");
    scanf("%d", &ra);

    for (int i = 0; i < MAX_ALUNOS; i++) {
        if (alunos[i].ativo && alunos[i].RA == ra) {
            alunos[i].ativo = false;
            printf("Aluno removido com sucesso!\n");
            return;
        }
    }
    printf("Aluno com RA %d nao encontrado.\n", ra);
}

float calcularMediaMensalidades(struct Aluno alunos[]) {
    float soma = 0;
    int contador = 0;

    for (int i = 0; i < MAX_ALUNOS; i++) {
        if (alunos[i].ativo) {
            soma += alunos[i].mensalidade;
            contador++;
        }
    }

    if (contador != 0) {
        return soma / contador;
    }
    return 0;
}

void exibirMenorMensalidade(struct Aluno alunos[]) {
    float menor = -1;
    int indiceMenor = -1;

    for (int i = 0; i < MAX_ALUNOS; i++) {
        if (alunos[i].ativo) {
            if (menor == -1 || alunos[i].mensalidade < menor) {
                menor = alunos[i].mensalidade;
                indiceMenor = i;
            }
        }
    }

    if (indiceMenor != -1) {
        printf("Menor mensalidade:\n");
        printf("RA: %d | Nome: %s | Mensalidade: %.2f\n", alunos[indiceMenor].RA, alunos[indiceMenor].nome, alunos[indiceMenor].mensalidade);
    } else {
        printf("Nenhum aluno ativo encontrado.\n");
    }
}

void limparBase(struct Aluno alunos[]) {
    for (int i = 0; i < MAX_ALUNOS; i++) {
        alunos[i].ativo = false;
    }
    printf("Base de alunos limpa com sucesso!\n");
}

int main() {
    struct Aluno alunos[MAX_ALUNOS] = {0};

    int opcao;
    do {
        printf("\nCONTROLE DE ALUNOS\n");
        printf("1 - Cadastrar\n");
        printf("2 - Relatorio\n");
        printf("3 - Pesquisar RA\n");
        printf("4 - Remover (RA)\n");
        printf("5 - Media Mensalidades\n");
        printf("6 - Menor Mensalidade\n");
        printf("7 - Limpar Base\n");
        printf("99 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAluno(alunos);
                break;
            case 2:
                exibirRelatorio(alunos);
                break;
            case 3:
                pesquisarRA(alunos);
                break;
            case 4:
                removerAluno(alunos);
                break;
            case 5: {
                float media = calcularMediaMensalidades(alunos);
                printf("Media das mensalidades: %.2f\n", media);
                break;
            }
            case 6:
                exibirMenorMensalidade(alunos);
                break;
            case 7:
                limparBase(alunos);
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
