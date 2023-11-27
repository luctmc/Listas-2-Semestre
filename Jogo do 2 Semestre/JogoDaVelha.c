/* Lucas Timponi Mercadante Castro | Ra: 2304913
--------------------------------------------------
Atividade - Extra ( JOGO DA VELHA )
*/

#include <stdio.h>
#include <stdbool.h>

void exibirTabuleiro(char tabuleiro[3][3]) {
    printf("\n  Tabuleiro Atual:\n");
    printf("  1 2 3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

bool verificarVencedor(char tabuleiro[3][3], char jogador) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador)
            return true;
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)
            return true;
    }

    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)
        return true;
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)
        return true;

    return false;
}

int main() {
    char tabuleiro[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int linha, coluna;
    char jogador1[20], jogador2[20];
    bool empate = false;
    int jogadas = 0;

    printf("Digite o nome do Jogador 1 (X): ");
    scanf("%s", jogador1);
    printf("Digite o nome do Jogador 2 (O): ");
    scanf("%s", jogador2);

    while (true) {
        exibirTabuleiro(tabuleiro);

        char jogador = (jogadas % 2 == 0) ? 'X' : 'O';
        char* nomeJogador = (jogador == 'X') ? jogador1 : jogador2;

        printf("\n%s, digite a linha e a coluna (Ex: 1 2): ", nomeJogador);
        scanf("%d %d", &linha, &coluna);

        if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha - 1][coluna - 1] != ' ') {
            printf("Jogada inválida! Tente novamente.\n");
            continue;
        }

        tabuleiro[linha - 1][coluna - 1] = jogador;
        jogadas++;

        if (verificarVencedor(tabuleiro, jogador)) {
            exibirTabuleiro(tabuleiro);
            printf("\nParabéns! %s venceu!\n", nomeJogador);
            break;
        } else if (jogadas == 9) {
            exibirTabuleiro(tabuleiro);
            printf("\nEmpate!\n");
            empate = true;
            break;
        }
    }

    return 0;
}
