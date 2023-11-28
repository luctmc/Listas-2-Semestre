/*Enunciado:Q1
CALCULADORA SIMPLES (utilize apenas procedimentos) – Escreva uma aplicação de console em C que
corresponderá a uma calculadora simples, todos as operações devem ser executadas através de
rotinas/métodos que serão invocados a partir de alguma das opções do menu descrito abaixo.
Observação: A aplicação abaixo deverá solicitar um ou dois valores do usuário de acordo com a opção
do menu utilizada.
CALCULADORA
1 - Somar
2 - Subtrair
3 - Multiplicar
4 - Dividir
5 - Quadrado
6 - Raiz quadrada (pesquisar como fazer)
9 - Sair.
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>
#include <math.h>

void somar(float a, float b) {
    printf("Resultado da soma: %.2f\n", a + b);
}

void subtrair(float a, float b) {
    printf("Resultado da subtracao: %.2f\n", a - b);
}

void multiplicar(float a, float b) {
    printf("Resultado da multiplicacao: %.2f\n", a * b);
}

void dividir(float a, float b) {
    if (b != 0) {
        printf("Resultado da divisao: %.2f\n", a / b);
    } else {
        printf("Nao e possivel dividir por zero!\n");
    }
}

void quadrado(float a) {
    printf("Resultado do quadrado: %.2f\n", a * a);
}

void raizQuadrada(float a) {
    if (a >= 0) {
        printf("Resultado da raiz quadrada: %.2f\n", sqrt(a));
    } else {
        printf("Nao e possivel calcular a raiz de um numero negativo!\n");
    }
}

int main() {
    int opcao;
    float valor1, valor2;

    do {
        printf("\nCALCULADORA\n");
        printf("1 - Somar\n");
        printf("2 - Subtrair\n");
        printf("3 - Multiplicar\n");
        printf("4 - Dividir\n");
        printf("5 - Quadrado\n");
        printf("6 - Raiz quadrada\n");
        printf("9 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            case 2:
            case 3:
            case 4:
                printf("Digite dois valores: ");
                scanf("%f %f", &valor1, &valor2);
                break;
            case 5:
            case 6:
                printf("Digite um valor: ");
                scanf("%f", &valor1);
                break;
            case 9:
                printf("Saindo da calculadora.\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                continue;
        }

        switch (opcao) {
            case 1:
                somar(valor1, valor2);
                break;
            case 2:
                subtrair(valor1, valor2);
                break;
            case 3:
                multiplicar(valor1, valor2);
                break;
            case 4:
                dividir(valor1, valor2);
                break;
            case 5:
                quadrado(valor1);
                break;
            case 6:
                raizQuadrada(valor1);
                break;
        }
    } while (opcao != 9);

    return 0;
}
