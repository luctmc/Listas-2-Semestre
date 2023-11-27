/*Enunciado:Q1
IMPRIMIR NOMES X VEZES e REPETIR – Crie uma aplicação console que solicite o NOME e também o
NÚMERO DE REPETIÇÕES do usuário, a aplicação deverá então imprimir um texto composto por um
contador e o nome (X – NOME) onde o contador iniciará em 1 e terminará no número fornecido pelo
usuário. Após o término do processamento, deverá perguntar para o usuário se ele deseja continuar
(“Deseja repetir o processamento? (0 = Não; 1 = Sim)”, se o usuário responder Sim, então o processo
deverá ser novamente executado. Dica: Utilize o comando do ... while.
Lucas Timponi Mercadante Castro | Ra: 2304913*/

#include <stdio.h>

int main() {
    char nome[50];
    int repeticoes, contador;
    int continuar;

    do {
        printf("Digite o nome: ");
        scanf("%s", nome);

        printf("Digite o numero de repeticoes: ");
        scanf("%d", &repeticoes);

        contador = 1;
        while (contador <= repeticoes) {
            printf("%d - %s\n", contador, nome);
            contador++;
        }

        printf("Deseja repetir o processamento? (0 = Nao; 1 = Sim): ");
        scanf("%d", &continuar);
    } while (continuar == 1);

    return 0;
}
