#include <stdio.h>
#include <string.h>
#include "venda.h"

void registrarVenda(Produto produtos[], int totalProdutos,
                    Venda vendas[], int *totalVendas) {
    int codigo, quantidade, i;

    if (*totalVendas >= MAX_VENDAS) {
        printf("\nLimite de vendas atingido!\n");
        return;
    }

    printf("\nCodigo do produto: ");
    scanf("%d", &codigo);

    for (i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Produto: %s | Estoque: %d\n",
                   produtos[i].nome, produtos[i].estoque);
            printf("Quantidade vendida: ");
            scanf("%d", &quantidade);

            if (quantidade <= 0 || quantidade > produtos[i].estoque) {
                printf("Quantidade invalida ou estoque insuficiente!\n");
                return;
            }

            vendas[*totalVendas].codigoProduto = produtos[i].codigo;
            strcpy(vendas[*totalVendas].nomeProduto, produtos[i].nome);
            vendas[*totalVendas].quantidade = quantidade;
            vendas[*totalVendas].valorTotal = produtos[i].preco * quantidade;

            produtos[i].estoque -= quantidade;
            (*totalVendas)++;

            printf("Venda registrada! Total: R$ %.2f\n",
                   vendas[*totalVendas - 1].valorTotal);
            return;
        }
    }

    printf("Produto nao encontrado.\n");
}

void listarVendas(Venda vendas[], int totalVendas) {
    int i;

    if (totalVendas == 0) {
        printf("\nNenhuma venda registrada.\n");
        return;
    }

    printf("\n===== VENDAS REGISTRADAS =====\n");
    for (i = 0; i < totalVendas; i++) {
        printf("\nProduto: %s\n", vendas[i].nomeProduto);
        printf("Codigo: %d\n", vendas[i].codigoProduto);
        printf("Quantidade: %d\n", vendas[i].quantidade);
        printf("Valor total: R$ %.2f\n", vendas[i].valorTotal);
    }
}

void relatorioVendas(Produto produtos[], int totalProdutos,
                     Venda vendas[], int totalVendas) {
    int i, j, indiceMaior = -1;
    float faturamentoTotal = 0;
    float faturamentoProduto[MAX_PRODUTOS] = {0};

    for (i = 0; i < totalVendas; i++) {
        faturamentoTotal += vendas[i].valorTotal;

        for (j = 0; j < totalProdutos; j++) {
            if (produtos[j].codigo == vendas[i].codigoProduto) {
                faturamentoProduto[j] += vendas[i].valorTotal;
                break;
            }
        }
    }

    printf("\n===== RELATORIO =====\n");
    printf("Faturamento total: R$ %.2f\n", faturamentoTotal);

    for (i = 0; i < totalProdutos; i++) {
        if (indiceMaior == -1 ||
            faturamentoProduto[i] > faturamentoProduto[indiceMaior]) {
            indiceMaior = i;
        }
    }

    if (indiceMaior != -1 && faturamentoTotal > 0) {
        printf("Produto com maior faturamento: %s\n",
               produtos[indiceMaior].nome);
        printf("Faturamento do produto: R$ %.2f\n",
               faturamentoProduto[indiceMaior]);
    } else {
        printf("Ainda nao existem vendas para gerar o relatorio.\n");
    }
}

int carregarVendas(Venda vendas[]) {
    FILE *arquivo = fopen("vendas.dat", "rb");
    int total = 0;

    if (arquivo == NULL) {
        return 0;
    }

    fread(&total, sizeof(int), 1, arquivo);
    if (total < 0 || total > MAX_VENDAS) {
        fclose(arquivo);
        return 0;
    }

    fread(vendas, sizeof(Venda), total, arquivo);
    fclose(arquivo);
    return total;
}

void salvarVendas(Venda vendas[], int totalVendas) {
    FILE *arquivo = fopen("vendas.dat", "wb");

    if (arquivo == NULL) {
        printf("Erro ao salvar as vendas!\n");
        return;
    }

    fwrite(&totalVendas, sizeof(int), 1, arquivo);
    fwrite(vendas, sizeof(Venda), totalVendas, arquivo);
    fclose(arquivo);
}
