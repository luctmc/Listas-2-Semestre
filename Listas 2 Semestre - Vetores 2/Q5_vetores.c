/*Enunciado:Q5
VETORES A & B – Crie uma aplicação console, esta aplicação deverá conter dois vetores, cada vetor
deverá armazenar 10 números inteiros, os métodos a serem criados para manipulação deverá atender
a necessidade do menu abaixo descrito, é importante lembrar que somente através dos métodos da
classe os vetores devem ser acessados e manipulados.
MENU - VETORES A e B
1 - Adicionar vetor A
2 - Adicionar vetor B
3 - Remover do vetor A valor da posição X
4 - Remover do vetor B valor da posição X
5 - Imprimir vetor A
6 - Imprimir vetor B
7 - Contar valores vetor A
8 - Contar valores vetor B
9 - Somar valores de cada vetor e apresentar
10 - Qual vetor tem maior quantidade de valores?
11 - Qual vetor tem a maior soma de valores?
12 - Transferir valores Pares do vetor A para o B
13 - Transferir valores Ímpares do vetor B para o A
14 - Media de valores de cada vetor
15 - Qual vetor apresenta a maior média?
16 - Maior valor de cada vetor
17 - Menor valor de cada vetor
18 - Qual vetor apresenta o maior valor?
99 - Sair.
Digite a opção desejada:
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>
#include <stdbool.h>

#define TAM_VETOR 10

void adicionarVetor(int vetor[], int vetorNum) {
    printf("Adicionar valores ao vetor %c:\n", vetorNum == 1 ? 'A' : 'B');
    for (int i = 0; i < TAM_VETOR; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

void removerValorPosicao(int vetor[], int posicao, char vetorLetra) {
    if (posicao >= 0 && posicao < TAM_VETOR) {
        vetor[posicao] = 0;
        printf("Valor na posicao %d do vetor %c removido.\n", posicao, vetorLetra);
    } else {
        printf("Posicao invalida no vetor %c.\n", vetorLetra);
    }
}

void imprimirVetor(int vetor[], char vetorLetra) {
    printf("Vetor %c:\n", vetorLetra);
    for (int i = 0; i < TAM_VETOR; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int contarValores(int vetor[]) {
    int contador = 0;
    for (int i = 0; i < TAM_VETOR; i++) {
        if (vetor[i] != 0) {
            contador++;
        }
    }
    return contador;
}

int somarValores(int vetor[]) {
    int soma = 0;
    for (int i = 0; i < TAM_VETOR; i++) {
        soma += vetor[i];
    }
    return soma;
}

void transferirParesImpares(int vetorA[], int vetorB[]) {
    for (int i = 0; i < TAM_VETOR; i++) {
        if (vetorA[i] % 2 == 0) {
            vetorB[i] = vetorA[i];
            vetorA[i] = 0;
        } else if (vetorB[i] % 2 != 0) {
            vetorA[i] = vetorB[i];
            vetorB[i] = 0;
        }
    }
}

float calcularMedia(int vetor[]) {
    int soma = 0, contador = 0;
    for (int i = 0; i < TAM_VETOR; i++) {
        if (vetor[i] != 0) {
            soma += vetor[i];
            contador++;
        }
    }
    return (float)soma / contador;
}

int maiorValor(int vetor[]) {
    int maior = vetor[0];
    for (int i = 1; i < TAM_VETOR; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

int menorValor(int vetor[]) {
    int menor = vetor[0];
    for (int i = 1; i < TAM_VETOR; i++) {
        if (vetor[i] < menor && vetor[i] != 0) {
            menor = vetor[i];
        }
    }
    return menor;
}

int main() {
    int vetorA[TAM_VETOR] = {0};
    int vetorB[TAM_VETOR] = {0};

    int opcao;
    do {
        printf("\nMENU - VETORES A e B\n");
        printf("1 - Adicionar vetor A\n");
        printf("2 - Adicionar vetor B\n");
        printf("3 - Remover do vetor A valor da posicao X\n");
        printf("4 - Remover do vetor B valor da posicao X\n");
        printf("5 - Imprimir vetor A\n");
        printf("6 - Imprimir vetor B\n");
        printf("7 - Contar valores vetor A\n");
        printf("8 - Contar valores vetor B\n");
        printf("9 - Somar valores de cada vetor e apresentar\n");
        printf("10 - Qual vetor tem maior quantidade de valores?\n");
        printf("11 - Qual vetor tem a maior soma de valores?\n");
        printf("12 - Transferir valores Pares do vetor A para o B\n");
        printf("13 - Transferir valores Impares do vetor B para o A\n");
        printf("14 - Media de valores de cada vetor\n");
        printf("15 - Qual vetor apresenta a maior media?\n");
        printf("16 - Maior valor de cada vetor\n");
        printf("17 - Menor valor de cada vetor\n");
        printf("18 - Qual vetor apresenta o maior valor?\n");
        printf("99 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarVetor(vetorA, 1);
                break;
            case 2:
                adicionarVetor(vetorB, 2);
                break;
            case 3: {
                int posicao;
                printf("Digite a posicao a ser removida no vetor A: ");
                scanf("%d", &posicao);
                removerValorPosicao(vetorA, posicao, 'A');
                break;
            }
            case 4: {
                int posicao;
                printf("Digite a posicao a ser removida no vetor B: ");
                scanf("%d", &posicao);
                removerValorPosicao(vetorB, posicao, 'B');
                break;
            }
            case 5:
                imprimirVetor(vetorA, 'A');
                break;
            case 6:
                imprimirVetor(vetorB, 'B');
                break;
            case 7:
                printf("Quantidade de valores no vetor A: %d\n", contarValores(vetorA));
                break;
            case 8:
                printf("Quantidade de valores no vetor B: %d\n", contarValores(vetorB));
                break;
            case 9:
                printf("Soma dos valores do vetor A: %d\n", somarValores(vetorA));
                printf("Soma dos valores do vetor B: %d\n", somarValores(vetorB));
                break;
            case 10:
                printf("Vetor com maior quantidade de valores: %s\n", contarValores(vetorA) > contarValores(vetorB) ? "A" : "B");
                break;
            case 11:
                printf("Vetor com maior soma de valores: %s\n", somarValores(vetorA) > somarValores(vetorB) ? "A" : "B");
                break;
            case 12:
                transferirParesImpares(vetorA, vetorB);
                break;
            case 13:
                transferirParesImpares(vetorB, vetorA);
                break;
            case 14:
                printf("Media do vetor A: %.2f\n", calcularMedia(vetorA));
                printf("Media do vetor B: %.2f\n", calcularMedia(vetorB));
                break;
            case 15:
                printf("Vetor com maior media: %s\n", calcularMedia(vetorA) > calcularMedia(vetorB) ? "A" : "B");
                break;
            case 16:
                printf("Maior valor do vetor A: %d\n", maiorValor(vetorA));
                printf("Maior valor do vetor B: %d\n", maiorValor(vetorB));
                break;
            case 17:
                printf("Menor valor do vetor A: %d\n", menorValor(vetorA));
                printf("Menor valor do vetor B: %d\n", menorValor(vetorB));
                break;
            case 18:
                printf("Vetor com maior valor: %s\n", maiorValor(vetorA) > maiorValor(vetorB) ? "A" : "B");
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
