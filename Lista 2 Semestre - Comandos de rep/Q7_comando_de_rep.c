/*Enunciado:Q7
SOMAR SALARIOS (MÁXIMO 5 OU ATÉ INFORMAR ‘NÃO’) – Crie uma aplicação que deverá realizar a
soma de valores correspondente a salários, esta aplicação deverá logo de entrada solicitar um salário,
após o usuário informar o valor, deverá perguntar “Deseje informar outro salário (0 = Nao, 1 = Sim)?”
caso o usuário informe “Sim”, deverá solicitar outro salário e repetir o processo até que o usuário
informe “Não”, no final do processamento deverá ser exibida a mensagem “A soma dos salários
informados e: XXX.”. Observação: 5 é o número máximo de salários informados, então mesmo que o
usuário diga que deseja continuar informando, após atingido o número máximo a aplicação deverá
parar
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>

#define MAX_SALARIOS 5

int main() {
    float salario, soma = 0;
    int continuar = 1;
    int contador = 0;

    printf("Informe o salario ou digite 'Nao' para parar: \n");

    while (continuar && contador < MAX_SALARIOS) {
        printf("Salario %d: ", contador + 1);
        if (scanf("%f", &salario) == 1) {
            soma += salario;
            contador++;

            if (contador < MAX_SALARIOS) {
                printf("Deseja informar outro salario? (0 = Nao, 1 = Sim): ");
                scanf("%d", &continuar);
            } else {
                printf("Numero maximo de salarios atingido.\n");
                break;
            }
        } else {
            char nao[4];
            scanf("%s", nao);
            if (nao[0] == 'N' || nao[0] == 'n') {
                break;
            }
        }
    }

    printf("A soma dos salarios informados e: %.2f\n", soma);

    return 0;
}
