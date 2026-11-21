
#include <stdio.h>

int main() {
    char nome[50];
    int idade;
    float glicemia, hba1c;

    int classificacaoGlicemia, classificacaoHbA1c;
    int classificacaoGeral;

    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", nome);

    printf("Digite a idade: ");
    scanf("%d", &idade);

    printf("Digite a glicemia de jejum: ");
    scanf("%f", &glicemia);

    printf("Digite a hemoglobina glicada (HbA1c): ");
    scanf("%f", &hba1c);

    if (glicemia < 0 || hba1c < 0 || hba1c > 100) {
        printf("\nValores informados invalidos!\n");
    }
    else {

        // Classificacao da glicemia
        if (glicemia < 100) {
            printf("\nGlicemia: Normal\n");
            classificacaoGlicemia = 1;
        }
        else if (glicemia <= 125) {
            printf("\nGlicemia: Pre-diabetes\n");
            classificacaoGlicemia = 2;
        }
        else {
            printf("\nGlicemia: Diabetes\n");
            classificacaoGlicemia = 3;
        }

        // Classificacao da hemoglobina glicada
        if (hba1c < 5.7) {
            printf("Hemoglobina glicada: Normal\n");
            classificacaoHbA1c = 1;
        }
        else if (hba1c <= 6.4) {
            printf("Hemoglobina glicada: Pre-diabetes\n");
            classificacaoHbA1c = 2;
        }
        else {
            printf("Hemoglobina glicada: Diabetes\n");
            classificacaoHbA1c = 3;
        }

        // Classificacao geral
        if (classificacaoGlicemia > classificacaoHbA1c) {
            classificacaoGeral = classificacaoGlicemia;
        }
        else {
            classificacaoGeral = classificacaoHbA1c;
        }

        printf("\n===== RESULTADO DO PACIENTE =====\n");
        printf("Nome: %s\n", nome);
        printf("Idade: %d anos\n", idade);

        if (classificacaoGeral == 1) {
            printf("Classificacao geral: Normal\n");
        }
        else if (classificacaoGeral == 2) {
            printf("Classificacao geral: Pre-diabetes\n");
        }
        else {
            printf("Classificacao geral: Diabetes\n");
        }
    }

    return 0;
}
