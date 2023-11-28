/*Enunciado:Q2
ARES FIGURAS GEOMETRICAS (utilize procedimentos e funções) – Escreva uma aplicação de console
em C que corresponderá a um sistema responsável pelo cálculo da área de figuras geométricas, todos
as operações devem ser executadas através de rotinas/métodos que serão invocados a partir de
alguma das opções do menu descrito abaixo. Observação: A aplicação abaixo deverá solicitar do
usuário os parâmetros necessários para realizar o cálculo das áreas das figuras geométricas.
AREAS
1 – Retângulo
2 – Triângulo
3 – Quadrado
4 – Círculo
5 – Paralelepípedo
6 – Losango
7 – Cone
8 – Trapézio
9 – Sair 
Lucas Timponi Mercadante Castro | Ra: 2304913*/

#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

// Funções para cálculo das áreas

float areaRetangulo(float base, float altura) {
    return base * altura;
}

float areaTriangulo(float base, float altura) {
    return (base * altura) / 2.0;
}

float areaQuadrado(float lado) {
    return lado * lado;
}

float areaCirculo(float raio) {
    return PI * raio * raio;
}

float areaParalelepipedo(float comprimento, float largura, float altura) {
    return 2 * (comprimento * largura + comprimento * altura + largura * altura);
}

float areaLosango(float diagonalMaior, float diagonalMenor) {
    return (diagonalMaior * diagonalMenor) / 2.0;
}

float areaCone(float raio, float altura) {
    return PI * raio * (raio + sqrt(altura * altura + raio * raio));
}

float areaTrapezio(float baseMaior, float baseMenor, float altura) {
    return ((baseMaior + baseMenor) * altura) / 2.0;
}

// Procedimento para exibição das mensagens
void mostrarResultado(float area) {
    printf("A area eh: %.2f\n", area);
}

int main() {
    int opcao;
    float valor1, valor2, valor3;

    do {
        printf("\nCALCULO DE AREAS DE FIGURAS GEOMETRICAS\n");
        printf("1 - Retangulo\n");
        printf("2 - Triangulo\n");
        printf("3 - Quadrado\n");
        printf("4 - Circulo\n");
        printf("5 - Paralelepipedo\n");
        printf("6 - Losango\n");
        printf("7 - Cone\n");
        printf("8 - Trapezio\n");
        printf("9 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a base e a altura do retangulo: ");
                scanf("%f %f", &valor1, &valor2);
                mostrarResultado(areaRetangulo(valor1, valor2));
                break;
            case 2:
                printf("Digite a base e a altura do triangulo: ");
                scanf("%f %f", &valor1, &valor2);
                mostrarResultado(areaTriangulo(valor1, valor2));
                break;
            case 3:
                printf("Digite o lado do quadrado: ");
                scanf("%f", &valor1);
                mostrarResultado(areaQuadrado(valor1));
                break;
            case 4:
                printf("Digite o raio do circulo: ");
                scanf("%f", &valor1);
                mostrarResultado(areaCirculo(valor1));
                break;
            case 5:
                printf("Digite o comprimento, largura e altura do paralelepipedo: ");
                scanf("%f %f %f", &valor1, &valor2, &valor3);
                mostrarResultado(areaParalelepipedo(valor1, valor2, valor3));
                break;
            case 6:
                printf("Digite as diagonais do losango: ");
                scanf("%f %f", &valor1, &valor2);
                mostrarResultado(areaLosango(valor1, valor2));
                break;
            case 7:
                printf("Digite o raio e a altura do cone: ");
                scanf("%f %f", &valor1, &valor2);
                mostrarResultado(areaCone(valor1, valor2));
                break;
            case 8:
                printf("Digite as bases e a altura do trapezio: ");
                scanf("%f %f %f", &valor1, &valor2, &valor3);
                mostrarResultado(areaTrapezio(valor1, valor2, valor3));
                break;
            case 9:
                printf("Saindo do calculo de areas.\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                continue;
        }
    } while (opcao != 9);

    return 0;
}
