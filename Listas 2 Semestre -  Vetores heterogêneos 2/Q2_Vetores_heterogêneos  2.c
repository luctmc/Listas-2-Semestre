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
5. Pesquisar NOME (o usuário deverá informar parte do nome, o sistema deverá exibir todos os clientes
que contenham essa parte do nome informada pelo usuário (pesquisar sobre a o método strcmp),
exemplo, se o usuário informar ‘AN’ os clientes com o nome ANA, AMANDA, ANTONIO devem ser
exibidos).
6. Imprimir TODOS (deverá imprimir todos os clientes cadastrados, os espaços vazios não devem ser
impressos)
7. Relatório por GENERO (deverá imprimir as informações: MASCULINO: a) Número de clientes; b)
Idade média; c) Salário médio; d) Soma salários. FEMININO: (as mesmas informações do masculino).
Nota técnica: Para fazer a comparação textual pesquise sobre o método strcmp.
8. Relatório por SALÁRIO (deverá exibir: a) Cliente com o maior salário; b) Cliente com o menor salário;
c) Salário médio geral; d) Soma dos salários; e) Número de clientes com salário menor que 1 salário
mínimo).
9. Sair
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>
#include <string.h>
#define MAX_CLIENTES 100
#define CPF_LENGTH 12
#define NOME_LENGTH 50

struct Cliente {
    char cpf[CPF_LENGTH];
    char rg[CPF_LENGTH];
    char nome[NOME_LENGTH];
    int idade;
    char sexo;
    float salario;
};

void imprimirCliente(struct Cliente cliente) {
    printf("CPF: %s\nRG: %s\nNome: %s\nIdade: %d\nSexo: %c\nSalário: %.2f\n\n",
           cliente.cpf, cliente.rg, cliente.nome, cliente.idade, cliente.sexo, cliente.salario);
}

void imprimirClientes(struct Cliente clientes[], int count) {
    printf("\nClientes Cadastrados:\n");
    for (int i = 0; i < count; ++i) {
        if (clientes[i].cpf[0] != '\0') {
            imprimirCliente(clientes[i]);
        }
    }
}

int buscarClienteCPF(struct Cliente clientes[], char cpf[], int count) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            return i;
        }
    }
    return -1;
}

int inserirCliente(struct Cliente clientes[], int count) {
    if (count >= MAX_CLIENTES) {
        printf("Limite de clientes atingido!\n");
        return count;
    }

    struct Cliente novoCliente;
    printf("CPF: ");
    scanf("%s", novoCliente.cpf);

    if (buscarClienteCPF(clientes, novoCliente.cpf, count) != -1) {
        printf("CPF já existe na base de dados!\n");
        return count;
    }

    printf("RG: ");
    scanf("%s", novoCliente.rg);
    printf("Nome: ");
    scanf("%s", novoCliente.nome);
    printf("Idade: ");
    scanf("%d", &novoCliente.idade);
    printf("Sexo (M/F): ");
    scanf(" %c", &novoCliente.sexo);
    printf("Salário: ");
    scanf("%f", &novoCliente.salario);

    clientes[count] = novoCliente;
    return count + 1;
}

void alterarCliente(struct Cliente clientes[], int count) {
    char cpf[CPF_LENGTH];
    printf("Digite o CPF do cliente que deseja alterar: ");
    scanf("%s", cpf);

    int index = buscarClienteCPF(clientes, cpf, count);
    if (index == -1) {
        printf("Cliente não encontrado!\n");
        return;
    }

    printf("Novo RG: ");
    scanf("%s", clientes[index].rg);
    printf("Novo Nome: ");
    scanf("%s", clientes[index].nome);
    printf("Nova Idade: ");
    scanf("%d", &clientes[index].idade);
    printf("Novo Sexo (M/F): ");
    scanf(" %c", &clientes[index].sexo);
    printf("Novo Salário: ");
    scanf("%f", &clientes[index].salario);
}

void excluirCliente(struct Cliente clientes[], int count) {
    char cpf[CPF_LENGTH];
    printf("Digite o CPF do cliente que deseja excluir: ");
    scanf("%s", cpf);

    int index = buscarClienteCPF(clientes, cpf, count);
    if (index == -1) {
        printf("Cliente não encontrado!\n");
        return;
    }

    memset(&clientes[index], 0, sizeof(struct Cliente));
    printf("Cliente excluído com sucesso!\n");
}

void pesquisarPorNome(struct Cliente clientes[], char parteNome[], int count) {
    printf("\nClientes encontrados:\n");
    for (int i = 0; i < count; ++i) {
        if (strstr(clientes[i].nome, parteNome) != NULL) {
            imprimirCliente(clientes[i]);
        }
    }
}

// Implemente as outras funções do menu

int main() {
    struct Cliente clientes[MAX_CLIENTES];
    int clienteCount = 0;
    int opcao;

    do {
        printf("\nSISGESCLI - SISTEMA DE GESTÃO DE CLIENTES\n");
        printf("1. Inserir\n");
        printf("2. Alterar\n");
        printf("3. Excluir\n");
        printf("4. Pesquisar CPF\n");
        printf("5. Pesquisar NOME\n");
        printf("6. Imprimir TODOS\n");
        printf("7. Relatório por GENERO\n");
        printf("8. Relatório por SALÁRIO\n");
        printf("9. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                clienteCount = inserirCliente(clientes, clienteCount);
                break;
            case 2:
                alterarCliente(clientes, clienteCount);
                break;
            case 3:
                excluirCliente(clientes, clienteCount);
                break;
            case 4:
                // Implemente a pesquisa por CPF
                break;
            case 5: {
                char parteNome[NOME_LENGTH];
                printf("Digite parte do nome para pesquisar: ");
                scanf("%s", parteNome);
                pesquisarPorNome(clientes, parteNome, clienteCount);
                break;
            }
            case 6:
                imprimirClientes(clientes, clienteCount);
                break;
            // Implemente os outros casos do menu
            case 9:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 9);

    return 0;
}
