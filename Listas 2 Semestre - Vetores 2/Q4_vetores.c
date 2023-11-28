/*Enunciado:Q4
SALÁRIOS – Crie uma aplicação console, esta aplicação deverá ser capaz de armazenar até 100
diferentes salários de funcionários. Logo abaixo é apresentado um menu de console que deverá realizar
N operações sobre os diferentes salários armazenados.
MENU - SALÁRIOS
01 - Adicionar
02 - Remover posição Y (remove um salário de uma posição informada pelo usuário, é importante
validar se a posição informada existe no vetor).
03 - Imprimir todos
04 - Pesquisar salário X (deverá solicitar do usuário o salário desejado e pesquisar se existe no vetor,
caso exista (na primeira ocorrência dele), deverá exibir a posição que ele está armazenado e parar a
execução do processamento)
05 - Adicionar na posição (deverá solicitar do usuário o valor do salário e posição que deseja armazenálo no vetor caso ela não esteja ocupada, é importante validar se aposição informada pelo usuário existe
no vetor)
06 - Pesquisar a quantidade salários X (deverá solicitar do usuário um salário e contar quantas vezes
este salário existe no vetor)
07 - Somar salários
08 - Somar salários X (deverá percorrer o vetor e somar os valores com as ocorrências de igual valor)
09 - Contar salários
10 - Contar salários X (deverá percorrer o vetor e contar quantas vezes o salário X aparece no mesmo)
11 - Contar salários maiores que X
12 - Maior salário
13 - Menor salário
14 - Média salários
15 - Remover salários valor X
16 - Remover todos os salários
17 - Imprimir salário posição Y
18 - Imprimir salários menores que X
19 - Aplicar acréscimo de Z% em todos os salários
20 - Aplicar desconto de Z% em salários maiores que X
99 - Sair.
Digite a opção desejada:o | Ra: 2304913*/
#include <stdio.h>

#define TAMANHO 100

void adicionarSalario(float *salarios, int posicao, float salario) {
    if (posicao >= 0 && posicao < TAMANHO) {
        salarios[posicao] = salario;
        printf("Salario adicionado na posicao %d com sucesso!\n", posicao);
    } else {
        printf("Posicao invalida!\n");
    }
}

void removerSalarioNaPosicao(float *salarios, int posicao) {
    if (posicao >= 0 && posicao < TAMANHO) {
        salarios[posicao] = 0;
        printf("Salario removido da posicao %d com sucesso!\n", posicao);
    } else {
        printf("Posicao invalida!\n");
    }
}

void imprimirTodosOsSalarios(float *salarios) {
    printf("Todos os salarios armazenados:\n");
    for (int i = 0; i < TAMANHO; i++) {
        if (salarios[i] != 0) {
            printf("Posicao %d: %.2f\n", i, salarios[i]);
        }
    }
}

int pesquisarSalario(float *salarios, float salario) {
    for (int i = 0; i < TAMANHO; i++) {
        if (salarios[i] == salario) {
            printf("Salario %.2f encontrado na posicao %d.\n", salario, i);
            return i;
        }
    }
    printf("Salario nao encontrado.\n");
    return -1;
}

void adicionarNaPosicao(float *salarios, int posicao, float salario) {
    if (posicao >= 0 && posicao < TAMANHO) {
        if (salarios[posicao] == 0) {
            salarios[posicao] = salario;
            printf("Salario adicionado na posicao %d com sucesso!\n", posicao);
        } else {
            printf("Posicao ocupada, nao foi possivel adicionar o salario.\n");
        }
    } else {
        printf("Posicao invalida!\n");
    }
}

int pesquisarQuantidadeSalarios(float *salarios, float salario) {
    int contador = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (salarios[i] == salario) {
            contador++;
        }
    }
    return contador;
}

float somarSalarios(float *salarios) {
    float soma = 0;
    for (int i = 0; i < TAMANHO; i++) {
        soma += salarios[i];
    }
    return soma;
}

float somarSalariosX(float *salarios, float salario) {
    float soma = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (salarios[i] == salario) {
            soma += salario;
        }
    }
    return soma;
}

int contarSalarios(float *salarios) {
    int contador = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (salarios[i] != 0) {
            contador++;
        }
    }
    return contador;
}

int contarSalariosX(float *salarios, float salario) {
    int contador = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (salarios[i] == salario) {
            contador++;
        }
    }
    return contador;
}

int contarSalariosMaioresQueX(float *salarios, float valor) {
    int contador = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (salarios[i] > valor) {
            contador++;
        }
    }
    return contador;
}

float encontrarMaiorSalario(float *salarios) {
    float maior = salarios[0];
    for (int i = 1; i < TAMANHO; i++) {
        if (salarios[i] > maior) {
            maior = salarios[i];
        }
    }
    return maior;
}

float encontrarMenorSalario(float *salarios) {
    float menor = salarios[0];
    for (int i = 1; i < TAMANHO; i++) {
        if (salarios[i] != 0 && salarios[i] < menor) {
            menor = salarios[i];
        }
    }
    return menor;
}

float calcularMediaSalarios(float *salarios) {
    float soma = 0;
    int contador = 0;
    for (int i = 0; i < TAMANHO; i++) {
        if (salarios[i] != 0) {
            soma += salarios[i];
            contador++;
        }
    }
    return contador > 0 ? soma / contador : 0;
}

void removerSalariosValorX(float *salarios, float valor) {
    for (int i = 0; i < TAMANHO; i++) {
        if (salarios[i] == valor) {
            salarios[i] = 0;
        }
    }
    printf("Salarios com valor %.2f removidos!\n", valor);
}

void removerTodosOsSalarios(float *salarios) {
    for (int i = 0; i < TAMANHO; i++) {
        salarios[i] = 0;
    }
    printf("Todos os salarios removidos!\n");
}

void imprimirSalarioNaPosicao(float *salarios, int posicao) {
    if (posicao >= 0 && posicao < TAMANHO) {
        if (salarios[posicao] != 0) {
            printf("Salario na posicao %d: %.2f\n", posicao, salarios[posicao]);
        } else {
            printf("Nao existe salario na posicao %d.\n", posicao);
        }
    } else {
        printf("Posicao invalida!\n");
    }
}

void imprimirSalariosMenoresQueX(float *salarios, float valor) {
    printf("Salarios menores que %.2f:\n", valor);
    for (int i = 0; i < TAMANHO; i++) {
        if (salarios[i] != 0 && salarios[i] < valor) {
            printf("%.2f ", salarios[i]);
        }
    }
    printf("\n");
}

void aplicarAcrescimoEmTodosOsSalarios(float *salarios, float percentual) {
    for (int i = 0; i < TAMANHO; i++) {
        if (salarios[i] != 0) {
            salarios[i] *= (1 + percentual / 100);
        }
    }
    printf("Acrescimo de %.2f%% aplicado em todos os salarios!\n", percentual);
}

void aplicarDescontoEmSalariosMaioresQueX(float *salarios, float valor, float percentual) {
    for (int i = 0; i < TAMANHO; i++) {
        if (salarios[i] > valor) {
            salarios[i] *= (1 - percentual / 100);
        }
    }
    printf("Desconto de %.2f%% aplicado em salarios maiores que %.2f!\n", percentual, valor);
}

int main() {
    float salarios[TAMANHO] = {0};

    int opcao;
    do {
        printf("\nMENU - SALARIOS\n");
        printf("01 - Adicionar\n");
        printf("02 - Remover posicao Y\n");
        printf("03 - Imprimir todos\n");
        printf("04 - Pesquisar salario X\n");
        printf("05 - Adicionar na posicao\n");
        printf("06 - Pesquisar a quantidade salarios X\n");
        printf("07 - Somar salarios\n");
        printf("08 - Somar salarios X\n");
        printf("09 - Contar salarios\n");
        printf("10 - Contar salarios X\n");
        printf("11 - Contar salarios maiores que X\n");
        printf("12 - Maior salario\n");
        printf("13 - Menor salario\n");
        printf("14 - Media salarios\n");
        printf("15 - Remover salarios valor X\n");
        printf("16 - Remover todos os salarios\n");
        printf("17 - Imprimir salario posicao Y\n");
        printf("18 - Imprimir salarios menores que X\n");
        printf("19 - Aplicar acrescimo de Z%% em todos os salarios\n");
        printf("20 - Aplicar desconto de Z%% em salarios maiores que X\n");
        printf("99 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int pos;
                float salario;
                printf("Digite a posicao e o salario a adicionar: ");
                scanf("%d %f", &pos, &salario);
                adicionarSalario(salarios, pos, salario);
                break;
            }
            case 2: {
                int pos;
                printf("Digite a posicao para remover o salario: ");
                scanf("%d", &pos);
                removerSalarioNaPosicao(salarios, pos);
                break;
            }
            case 3:
                imprimirTodosOsSalarios(salarios);
                break;
            case 4: {
                float salarioPesquisa;
                printf("Digite o salario a pesquisar: ");
                scanf("%f", &salarioPesquisa);
                pesquisarSalario(salarios, salarioPesquisa);
                break;
            }
            case 5: {
                int pos;
                float salario;
                printf("Digite a posicao e o salario a adicionar: ");
                scanf("%d %f", &pos, &salario);
                adicionarNaPosicao(salarios, pos, salario);
                break;
            }
            case 6: {
                float salario;
                printf("Digite o salario para pesquisar a quantidade: ");
                scanf("%f", &salario);
                printf("Quantidade de salarios %.2f: %d\n", salario, pesquisarQuantidadeSalarios(salarios, salario));
                break;
            }
            case 7:
                printf("Soma dos salarios: %.2f\n", somarSalarios(salarios));
                break;
            case 8: {
                float salario;
                printf("Digite o salario para somar: ");
                scanf("%f", &salario);
                printf("Soma dos salarios %.2f: %.2f\n", salario, somarSalariosX(salarios, salario));
                break;
            }
            case 9:
                printf("Quantidade de salarios: %d\n", contarSalarios(salarios));
                break;
            case 10: {
                float salario;
                printf("Digite o salario para contar: ");
                scanf("%f", &salario);
                printf("Quantidade de salarios %.2f: %d\n", salario, contarSalariosX(salarios, salario));
                break;
            }
            case 11: {
                float valor;
                printf("Digite o valor para contar salarios maiores: ");
                scanf("%f", &valor);
                printf("Quantidade de salarios maiores que %.2f: %d\n", valor, contarSalariosMaioresQueX(salarios, valor));
                break;
            }
            case 12:
                printf("Maior salario: %.2f\n", encontrarMaiorSalario(salarios));
                break;
            case 13:
                printf("Menor salario: %.2f\n", encontrarMenorSalario(salarios));
                break;
            case 14:
                printf("Media dos salarios: %.2f\n", calcularMediaSalarios(salarios));
                break;
            case 15: {
                float valor;
                printf("Digite o valor do salario a ser removido: ");
                scanf("%f", &valor);
                removerSalariosValorX(salarios, valor);
                break;
            }
            case 16:
                removerTodosOsSalarios(salarios);
                break;
            case 17: {
                int pos;
                printf("Digite a posicao para imprimir o salario: ");
                scanf("%d", &pos);
                imprimirSalarioNaPosicao(salarios, pos);
                break;
            }
            case 18: {
                float valor;
                printf("Digite o valor para imprimir salarios menores: ");
                scanf("%f", &valor);
                imprimirSalariosMenoresQueX(salarios, valor);
                break;
            }
            case 19: {
                float percentual;
                printf("Digite o percentual de acrescimo: ");
                scanf("%f", &percentual);
                aplicarAcrescimoEmTodosOsSalarios(salarios, percentual);
                break;
            }
            case 20: {
                float valor, percentual;
                printf("Digite o valor para aplicar desconto: ");
                scanf("%f", &valor);
                printf("Digite o percentual de desconto: ");
                scanf("%f", &percentual);
                aplicarDescontoEmSalariosMaioresQueX(salarios, valor, percentual);
                break;
            }
            case 99:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 99);

    return 0;
}
