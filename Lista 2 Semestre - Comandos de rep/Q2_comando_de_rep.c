/*Enunciado:Q2
IMPRIMIR MULTIPLOS – Escreva uma aplicação de console que receba um número inteiro n e um outro
valor numérico p que representa o passo da contagem (valor do incremento) imprimindo uma
contagem de 0 até n (se possível) de p em p. Por exemplo, se fornecido 10 e 3, deverão ser exibidos:
0, 3, 6 e 9. Caso o segundo argumento não seja fornecido, assume-se que p = 1 (contagem simples).
Dica: Utilize o comando FOR
Lucas Timponi Mercadante Castro | Ra: 2304913*/

#include <stdio.h>

int main() {
    int n, p;

    printf("Digite um numero inteiro n: ");
    scanf("%d", &n);

    printf("Digite o valor do passo p (ou pressione Enter para assumir p = 1): ");
    if (scanf("%d", &p) != 1) {
        p = 1;
    }

    printf("Contagem de 0 até %d com passo %d:\n", n, p);
    for (int i = 0; i <= n; i += p) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}
