#ifndef VENDA_H
#define VENDA_H

#include "produto.h"

#define MAX_VENDAS 20

typedef struct {
    int codigoProduto;
    char nomeProduto[50];
    int quantidade;
    float valorTotal;
} Venda;

void registrarVenda(Produto produtos[], int totalProdutos,
                    Venda vendas[], int *totalVendas);
void listarVendas(Venda vendas[], int totalVendas);
void relatorioVendas(Produto produtos[], int totalProdutos,
                     Venda vendas[], int totalVendas);
int carregarVendas(Venda vendas[]);
void salvarVendas(Venda vendas[], int totalVendas);

#endif
