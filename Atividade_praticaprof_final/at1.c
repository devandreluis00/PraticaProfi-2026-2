
#include <stdio.h>

int main() {
    char nome[50];
    float consumo, tarifa, valor;

    printf("Digite o nome do consumidor: ");
    scanf(" %[^\n]", nome);

    printf("Digite o consumo em kWh: ");
    scanf("%f", &consumo);

    if (consumo < 0) {
        printf("Consumo invalido!\n");
    }
    else {
        if (consumo <= 100) {
            tarifa = 0.60;
        }
        else if (consumo <= 200) {
            tarifa = 0.75;
        }
        else {
            tarifa = 0.90;
        }

        valor = consumo * tarifa;

        printf("\n===== CONTA DE ENERGIA =====\n");
        printf("Consumidor: %s\n", nome);
        printf("Consumo: %.2f kWh\n", consumo);
        printf("Tarifa: R$ %.2f\n", tarifa);
        printf("Valor a pagar: R$ %.2f\n", valor);
    }

    return 0;
}
