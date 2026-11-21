
#include <stdio.h>

int main() {
    int vagas[2][3];
    int i, j;
    int ocupadas = 0;
    int livres = 0;

    printf("===== CONTROLE DE ESTACIONAMENTO =====\n");

    // Preenchendo a matriz
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {

            do {
                printf("Digite a situacao da vaga [%d][%d] (0-Livre / 1-Ocupada): ", i, j);
                scanf("%d", &vagas[i][j]);

                if (vagas[i][j] != 0 && vagas[i][j] != 1) {
                    printf("Valor invalido! Digite 0 ou 1.\n");
                }

            } while (vagas[i][j] != 0 && vagas[i][j] != 1);

            if (vagas[i][j] == 1) {
                ocupadas++;
            }
            else {
                livres++;
            }
        }
    }

    // Exibindo a matriz
    printf("\n===== SITUACAO DAS VAGAS =====\n");

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d  ", vagas[i][j]);
        }
        printf("\n");
    }

    printf("\nVagas ocupadas: %d\n", ocupadas);
    printf("Vagas livres: %d\n", livres);

    return 0;
}
