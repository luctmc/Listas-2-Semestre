/*Enunciado:Q3
MÉDIAS ESCOLARES (crie funções para obter cada uma das médias, e crie apenas um procedimento
que receberá a média como parâmetro e então avaliará se foi aprovado ou não) – Escreva uma
aplicação de console em C que corresponderá a um sistema responsável pelo cálculo das diferentes
médias escolares, a alunos será aprovado se sua média final for igual o superior a 5.0.
MÉDIAS ESCOLARES
1 – Média 1 (Prova A, Prova B)
2 – Média 2 (Prova A, Prova B, Prova C)
3 – Média 3 (Prova A = 40%, Prova B = 40%, Atividade C = 20%)
4 – Média 4 (Prova A = 30%, Prova B = 30%, Atividade C = 20%, Pluridisciplinar = 20%)
5 – Média 5 (Prova A = 30%, Prova B = 30%, Atividades C = 20% (3 atividades), Pluridisciplinar = 20%)
6 – Média 6 ((NP1 + NP2) / 2)
Considere: (NP1 = [Atividade 30% + Prova A 70%], NP2 = [Atividades 20% (2 atividades) +
Pluridisciplinar 20% + Prova B 60%])
9 – Sair 
Lucas Timponi Mercadante Castro | Ra: 2304913*/
#include <stdio.h>

float media1(float provaA, float provaB) {
    return (provaA + provaB) / 2.0;
}

float media2(float provaA, float provaB, float provaC) {
    return (provaA + provaB + provaC) / 3.0;
}

float media3(float provaA, float provaB, float atividadeC) {
    return (provaA * 0.4) + (provaB * 0.4) + (atividadeC * 0.2);
}

float media4(float provaA, float provaB, float atividadeC, float pluridisciplinar) {
    return (provaA * 0.3) + (provaB * 0.3) + (atividadeC * 0.2) + (pluridisciplinar * 0.2);
}

float media5(float provaA, float provaB, float atividadeC1, float atividadeC2, float atividadeC3, float pluridisciplinar) {
    return (provaA * 0.3) + (provaB * 0.3) + ((atividadeC1 + atividadeC2 + atividadeC3) / 3.0 * 0.2) + (pluridisciplinar * 0.2);
}

float media6(float provaA, float atividadeA, float atividadeB, float pluridisciplinar, float provaB) {
    float NP1 = (atividadeA * 0.3) + (provaA * 0.7);
    float NP2 = ((atividadeB + pluridisciplinar) / 2.0 * 0.2) + (provaB * 0.6);
    return (NP1 + NP2) / 2.0;
}

void avaliarAprovacao(float media) {
    if (media >= 5.0) {
        printf("Aluno aprovado com media %.2f\n", media);
    } else {
        printf("Aluno reprovado com media %.2f\n", media);
    }
}

int main() {
    int opcao;
    float provaA, provaB, provaC, atividadeC, pluridisciplinar, atividadeC1, atividadeC2, atividadeC3, atividadeA, atividadeB;
    
    do {
        printf("\nMEDIAS ESCOLARES\n");
        printf("1 - Media 1 (Prova A, Prova B)\n");
        printf("2 - Media 2 (Prova A, Prova B, Prova C)\n");
        printf("3 - Media 3 (Prova A = 40%%, Prova B = 40%%, Atividade C = 20%%)\n");
        printf("4 - Media 4 (Prova A = 30%%, Prova B = 30%%, Atividade C = 20%%, Pluridisciplinar = 20%%)\n");
        printf("5 - Media 5 (Prova A = 30%%, Prova B = 30%%, Atividades C = 20%% (3 atividades), Pluridisciplinar = 20%%)\n");
        printf("6 - Media 6 ((NP1 + NP2) / 2)\n");
        printf("9 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Digite a nota da Prova A: ");
                scanf("%f", &provaA);
                printf("Digite a nota da Prova B: ");
                scanf("%f", &provaB);
                avaliarAprovacao(media1(provaA, provaB));
                break;
            case 2:
                printf("Digite a nota da Prova A: ");
                scanf("%f", &provaA);
                printf("Digite a nota da Prova B: ");
                scanf("%f", &provaB);
                printf("Digite a nota da Prova C: ");
                scanf("%f", &provaC);
                avaliarAprovacao(media2(provaA, provaB, provaC));
                break;
            case 3:
                printf("Digite a nota da Prova A: ");
                scanf("%f", &provaA);
                printf("Digite a nota da Prova B: ");
                scanf("%f", &provaB);
                printf("Digite a nota da Atividade C: ");
                scanf("%f", &atividadeC);
                avaliarAprovacao(media3(provaA, provaB, atividadeC));
                break;
            case 4:
                printf("Digite a nota da Prova A: ");
                scanf("%f", &provaA);
                printf("Digite a nota da Prova B: ");
                scanf("%f", &provaB);
                printf("Digite a nota da Atividade C: ");
                scanf("%f", &atividadeC);
                printf("Digite a nota da Pluridisciplinar: ");
                scanf("%f", &pluridisciplinar);
                avaliarAprovacao(media4(provaA, provaB, atividadeC, pluridisciplinar));
                break;
            case 5:
                printf("Digite a nota da Prova A: ");
                scanf("%f", &provaA);
                printf("Digite a nota da Prova B: ");
                scanf("%f", &provaB);
                printf("Digite a nota da Atividade C 1: ");
                scanf("%f", &atividadeC1);
                printf("Digite a nota da Atividade C 2: ");
                scanf("%f", &atividadeC2);
                printf("Digite a nota da Atividade C 3: ");
                scanf("%f", &atividadeC3);
                printf("Digite a nota da Pluridisciplinar: ");
                scanf("%f", &pluridisciplinar);
                avaliarAprovacao(media5(provaA, provaB, atividadeC1, atividadeC2, atividadeC3, pluridisciplinar));
                break;
            case 6:
                printf("Digite a nota da Prova A: ");
                scanf("%f", &provaA);
                printf("Digite a nota da Atividade A: ");
                scanf("%f", &atividadeA);
                printf("Digite a nota da Atividade B: ");
                scanf("%f", &atividadeB);
                printf("Digite a nota da Pluridisciplinar: ");
                scanf("%f", &pluridisciplinar);
                printf("Digite a nota da Prova B: ");
                scanf("%f", &provaB);
                avaliarAprovacao(media6(provaA, atividadeA, atividadeB, pluridisciplinar, provaB));
                break;
            case 9:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 9);
    
    return 0;
}
