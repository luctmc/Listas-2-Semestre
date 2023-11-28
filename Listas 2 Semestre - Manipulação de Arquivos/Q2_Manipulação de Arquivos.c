/*Enunciado:Q2
CLIENTES – Crie uma aplicação console em C para manipulação de um cadastro de clientes, a base de
dados do sistema deverá permitir armazenar no máximo 100 clientes. O sistema deverá controlar
através das operações descritas no menu abaixo os clientes, e cada cliente deverá conter as seguintes
informações: CPF*, RG, NOME, IDADE, SEXO, SALÁRIO.
:: ATENÇÃO :: O campo CPF será o campo CHAVE, ou seja, o sistema não deverá permitir que existam
clientes com o mesmo CPF na base de dados (nota técnica: as operações de ‘inserção’ e ‘alteração’
devem verificar essa consistência.
SISGESCLI – SISTEMA DE GESTÃO DE CLIENTES
1. Inserir (não permitir 2 CPFs iguais na base)
2. Alterar (não permitir 2 CPFs iguais na base)
3. Excluir
4. Pesquisar CPF
5. Pesquisar NOME
6. Imprimir TODOS (deverá imprimir todos os clientes cadastrados, os espaços vazios não devem ser
impressos)
7. Relatório por GENERO (deverá imprimir as informações: MASCULINO: a) Número de clientes; b)
Idade média; c) Salário médio; d) Soma salários. FEMININO: (as mesmas informações do masculino).
Nota técnica: Para fazer a comparação textual pesquise sobre o método strcmp.
8. Relatório por SALÁRIO (deverá exibir: a) Cliente com o maior salário; b) Cliente com o menor salário;
c) Salário médio geral; d) Soma dos salários; e) Número de clientes com salário menor que 1 salário
mínimo).
9. Salvar em banco
10. Ler do banco
20. Sair
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CLIENTES 100
#define TAM_CPF 12
#define TAM_RG 15
#define TAM_NOME 50
#define TAM_SEXO 2

struct Cliente {
    char cpf[TAM_CPF];
    char rg[TAM_RG];
    char nome[TAM_NOME];
    int idade;
    char sexo[TAM_SEXO];
    float salario;
};

struct Cliente clientes[MAX_CLIENTES];
int numClientes = 0;

// Protótipos das funções
void inserirCliente();
void alterarCliente();
void excluirCliente();
void pesquisarCPF();
void pesquisarNome();
void imprimirTodos();
void relatorioGenero();
void relatorioSalario();
void salvarEmBanco();
void lerDoBanco();

int main() {
    int opcao;

    do {
        printf("\nSISGESCLI - SISTEMA DE GESTAO DE CLIENTES\n");
        printf("1. Inserir\n");
        printf("2. Alterar\n");
        printf("3. Excluir\n");
        printf("4. Pesquisar CPF\n");
        printf("5. Pesquisar NOME\n");
        printf("6. Imprimir TODOS\n");
        printf("7. Relatorio por GENERO\n");
        printf("8. Relatorio por SALARIO\n");
        printf("9. Salvar em banco\n");
        printf("10. Ler do banco\n");
        printf("20. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirCliente();
                break;
            case 2:
                alterarCliente();
                break;
            case 3:
                excluirCliente();
                break;
            case 4:
                pesquisarCPF();
                break;
            case 5:
                pesquisarNome();
                break;
            case 6:
                imprimirTodos();
                break;
            case 7:
                relatorioGenero();
                break;
            case 8:
                relatorioSalario();
                break;
            case 9:
                salvarEmBanco();
                break;
            case 10:
                lerDoBanco();
                break;
            case 20:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 20);

    return 0;
}

// Função para verificar se um CPF já está cadastrado
bool cpfExiste(const char *cpf) {
    for (int i = 0; i < numClientes; ++i) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            return true; // CPF já existe
        }
    }
    return false; // CPF não encontrado
}

void inserirCliente() {
    if (numClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    struct Cliente novoCliente;
    printf("CPF: ");
    scanf("%s", novoCliente.cpf);

    if (cpfExiste(novoCliente.cpf)) {
        printf("CPF ja cadastrado. Operacao cancelada.\n");
        return;
    }

    printf("RG: ");
    scanf("%s", novoCliente.rg);
    printf("Nome: ");
    scanf("%s", novoCliente.nome);
    printf("Idade: ");
    scanf("%d", &novoCliente.idade);
    printf("Sexo (M/F): ");
    scanf("%s", novoCliente.sexo);
    printf("Salario: ");
    scanf("%f", &novoCliente.salario);

    clientes[numClientes++] = novoCliente;
    printf("Cliente inserido com sucesso!\n");
}

void alterarCliente() {
    char cpf[TAM_CPF];
    printf("Digite o CPF do cliente a ser alterado: ");
    scanf("%s", cpf);

    for (int i = 0; i < numClientes; ++i) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            printf("Digite os novos dados do cliente:\n");
            printf("RG: ");
            scanf("%s", clientes[i].rg);
            printf("Nome: ");
            scanf("%s", clientes[i].nome);
            printf("Idade: ");
            scanf("%d", &clientes[i].idade);
            printf("Sexo (M/F): ");
            scanf("%s", clientes[i].sexo);
            printf("Salario: ");
            scanf("%f", &clientes[i].salario);

            printf("Cliente alterado com sucesso!\n");
            return;
        }
    }

    printf("Cliente com CPF %s nao encontrado.\n", cpf);
}

void excluirCliente() {
    char cpf[TAM_CPF];
    printf("Digite o CPF do cliente a ser excluido: ");
    scanf("%s", cpf);

    for (int i = 0; i < numClientes; ++i) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            for (int j = i; j < numClientes - 1; ++j) {
                clientes[j] = clientes[j + 1];
            }
            numClientes--;
            printf("Cliente excluido com sucesso!\n");
            return;
        }
    }

    printf("Cliente com CPF %s nao encontrado.\n", cpf);
}

void pesquisarCPF() {
    char cpf[TAM_CPF];
    printf("Digite o CPF do cliente a ser pesquisado: ");
    scanf("%s", cpf);

    for (int i = 0; i < numClientes; ++i) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            printf("CPF: %s\n", clientes[i].cpf);
            printf("RG: %s\n", clientes[i].rg);
            printf("Nome: %s\n", clientes[i].nome);
            printf("Idade: %d\n", clientes[i].idade);
            printf("Sexo: %s\n", clientes[i].sexo);
            printf("Salario: %.2f\n", clientes[i].salario);
            return;
        }
    }

    printf("Cliente com CPF %s nao encontrado.\n", cpf);
}

void pesquisarNome() {
    char nome[TAM_NOME];
    printf("Digite o nome do cliente a ser pesquisado: ");
    scanf("%s", nome);

    for (int i = 0; i < numClientes; ++i) {
        if (strcmp(clientes[i].nome, nome) == 0) {
            printf("CPF: %s\n", clientes[i].cpf);
            printf("RG: %s\n", clientes[i].rg);
            printf("Nome: %s\n", clientes[i].nome);
            printf("Idade: %d\n", clientes[i].idade);
            printf("Sexo: %s\n", clientes[i].sexo);
            printf("Salario: %.2f\n", clientes[i].salario);
        }
    }
}

void imprimirTodos() {
    if (numClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("LISTA DE CLIENTES:\n");
    for (int i = 0; i < numClientes; ++i) {
        printf("CPF: %s\n", clientes[i].cpf);
        printf("RG: %s\n", clientes[i].rg);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Idade: %d\n", clientes[i].idade);
        printf("Sexo: %s\n", clientes[i].sexo);
        printf("Salario: %.2f\n", clientes[i].salario);
        printf("\n");
    }
}

void relatorioGenero() {
    int contMasculino = 0, contFeminino = 0;
    int somaIdadeMasculino = 0, somaIdadeFeminino = 0;
    float somaSalarioMasculino = 0, somaSalarioFeminino = 0;

    for (int i = 0; i < numClientes; ++i) {
        if (strcmp(clientes[i].sexo, "M") == 0) {
            contMasculino++;
            somaIdadeMasculino += clientes[i].idade;
            somaSalarioMasculino += clientes[i].salario;
        } else if (strcmp(clientes[i].sexo, "F") == 0) {
            contFeminino++;
            somaIdadeFeminino += clientes[i].idade;
            somaSalarioFeminino += clientes[i].salario;
        }
    }

    if (contMasculino > 0) {
        printf("MASCULINO:\n");
        printf("a) Numero de clientes: %d\n", contMasculino);
        printf("b) Idade media: %.2f\n", (float)somaIdadeMasculino / contMasculino);
        printf("c) Salario medio: %.2f\n", somaSalarioMasculino / contMasculino);
        printf("d) Soma dos salarios: %.2f\n", somaSalarioMasculino);
    }

    if (contFeminino > 0) {
        printf("\nFEMININO:\n");
        printf("a) Numero de clientes: %d\n", contFeminino);
        printf("b) Idade media: %.2f\n", (float)somaIdadeFeminino / contFeminino);
        printf("c) Salario medio: %.2f\n", somaSalarioFeminino / contFeminino);
        printf("d) Soma dos salarios: %.2f\n", somaSalarioFeminino);
    }
}

void relatorioSalario() {
    if (numClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    float maiorSalario = clientes[0].salario;
    float menorSalario = clientes[0].salario;
    float somaSalario = 0;
    int contSalarioMenorQueUmMinimo = 0;
    float salarioMinimo = 1000.0; // Exemplo de salário mínimo

    for (int i = 0; i < numClientes; ++i) {
        somaSalario += clientes[i].salario;

        if (clientes[i].salario > maiorSalario) {
            maiorSalario = clientes[i].salario;
        }

        if (clientes[i].salario < menorSalario) {
            menorSalario = clientes[i].salario;
        }

        if (clientes[i].salario < salarioMinimo) {
            contSalarioMenorQueUmMinimo++;
        }
    }

    printf("a) Cliente com maior salario: %.2f\n", maiorSalario);
    printf("b) Cliente com menor salario: %.2f\n", menorSalario);
    printf("c) Salario medio geral: %.2f\n", somaSalario / numClientes);
    printf("d) Soma dos salarios: %.2f\n", somaSalario);
    printf("e) Numero de clientes com salario menor que 1 salario minimo: %d\n", contSalarioMenorQueUmMinimo);
}

void salvarEmBanco() {
    FILE *arquivo;
    arquivo = fopen("clientes.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < numClientes; ++i) {
        fprintf(arquivo, "%s %s %s %d %s %.2f\n", clientes[i].cpf, clientes[i].rg, clientes[i].nome, clientes[i].idade, clientes[i].sexo, clientes[i].salario);
    }

    fclose(arquivo);
    printf("Dados salvos no banco com sucesso!\n");
}

void lerDoBanco() {
    FILE *arquivo;
    arquivo = fopen("clientes.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo nao encontrado.\n");
        return;
    }

    numClientes = 0;
    while (fscanf(arquivo, "%s %s %s %d %s %f\n", clientes[numClientes].cpf, clientes[numClientes].rg, clientes[numClientes].nome, &clientes[numClientes].idade, clientes[numClientes].sexo, &clientes[numClientes].salario) != EOF) {
        numClientes++;
    }

    fclose(arquivo);
    printf("Dados lidos do banco com sucesso!\n");
}
