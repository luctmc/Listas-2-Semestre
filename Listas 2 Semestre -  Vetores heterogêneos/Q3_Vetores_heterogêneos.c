/*Enunciado:Q3
ESTACIONAMENTO – Crie uma aplicação console que seja responsável pela gestão de um
estacionamento de veículos com capacidade máxima de 05 veículos, a aplicação deverá possibilitar o
controle de entrada, saída, localização, impressão, e outros controles a respeito dos veículos. Logo
abaixo existe uma relação de funcionalidades que o sistema deverá conter. Os dados armazenados de
cada veículo deverão ser: PLACA, MARCA, MODELO, VALOR ESTACIONAMENTO, TELEFONE
PROPRIETÁRIO.
Dicas: a) Pesquise por comparação de caracteres (strcmp) pois a chave de pesquisa dos veículos será a
plac;. b) A aplicação deverá fazer um controle do número máximo de veículos cadastrados, mas
atenção, pois quando “sair” um veículo libera-se uma vaga e então outro veículo poderá ocupar a vaga;
c) Crie a aplicação utilizando métodos, sugiro criar um método que localize um veículo a partir da placa
e retorne o índice do mesmo e um método que localize uma posição vazia.
SYSCAR
1. Registrar entrada (Deverá localizar uma posição vazia e inserir o registro de entrada, caso não exista
uma posição vazia deverá exibir uma mensagem para o usuário)
2. Registrar saída (Deverá localizar verificar se a placa informada existe, caso exista a posição em que
o veículo está armazenado deverá ser liberada, caso não exista deverá exibir uma mensagem
informando que o veículo não existe).
3. Localizar (Deverá localizar o veículo a partir da placa e exibir mensagem se o veículo existe ou não
existe na base de dados).
4. Relatório (Deverá exibir na tela os veículos cadastrados na base de dados, atenção, pois as posições
vazias não devem serem impressas).
5. Saldo caixa (Deverá exibir o valor total correspondente a todos os veículos que registraram entrada,
sempre que um veículo entrar o valor deste veículo deverá ser acumulado, e sempre que essa
opção for utilizada deverá exibir o valor total acumulado)
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>
#include <string.h>

#define MAX_VEHICLES 5
#define MAX_PLATE_LENGTH 10
#define MAX_BRAND_LENGTH 20
#define MAX_MODEL_LENGTH 20

struct Vehicle {
    char plate[MAX_PLATE_LENGTH];
    char brand[MAX_BRAND_LENGTH];
    char model[MAX_MODEL_LENGTH];
    float parkingFee;
    char ownerPhone[15];
};

void printVehicle(struct Vehicle vehicles[], int count) {
    printf("\nVeículos cadastrados:\n");
    for (int i = 0; i < count; ++i) {
        printf("Placa: %s, Marca: %s, Modelo: %s, Valor Estacionamento: %.2f, Telefone Proprietário: %s\n",
               vehicles[i].plate, vehicles[i].brand, vehicles[i].model, vehicles[i].parkingFee, vehicles[i].ownerPhone);
    }
}

int findEmptySpot(struct Vehicle vehicles[], int count) {
    for (int i = 0; i < count; ++i) {
        if (vehicles[i].plate[0] == '\0') {
            return i;
        }
    }
    return -1;
}

int findVehicle(struct Vehicle vehicles[], char plate[], int count) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(vehicles[i].plate, plate) == 0) {
            return i;
        }
    }
    return -1;
}

float totalParkingFee(struct Vehicle vehicles[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; ++i) {
        total += vehicles[i].parkingFee;
    }
    return total;
}

int main() {
    struct Vehicle vehicles[MAX_VEHICLES];
    int vehicleCount = 0;

    int choice;
    do {
        printf("\nSYSCAR\n");
        printf("1. Registrar entrada\n");
        printf("2. Registrar saída\n");
        printf("3. Localizar\n");
        printf("4. Relatório\n");
        printf("5. Saldo caixa\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (vehicleCount < MAX_VEHICLES) {
                    int emptySpot = findEmptySpot(vehicles, MAX_VEHICLES);
                    if (emptySpot != -1) {
                        printf("\nRegistrar entrada de veículo:\n");
                        printf("Placa: ");
                        scanf("%s", vehicles[emptySpot].plate);
                        printf("Marca: ");
                        scanf("%s", vehicles[emptySpot].brand);
                        printf("Modelo: ");
                        scanf("%s", vehicles[emptySpot].model);
                        printf("Valor Estacionamento: ");
                        scanf("%f", &vehicles[emptySpot].parkingFee);
                        printf("Telefone Proprietário: ");
                        scanf("%s", vehicles[emptySpot].ownerPhone);
                        vehicleCount++;
                    } else {
                        printf("Estacionamento cheio!\n");
                    }
                } else {
                    printf("Estacionamento cheio!\n");
                }
                break;
            }
            // Restante das opções do menu
            case 5:
                printf("Saldo do Caixa: %.2f\n", totalParkingFee(vehicles, vehicleCount));
                break;
            case 6:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (choice != 6);

    return 0;
}
