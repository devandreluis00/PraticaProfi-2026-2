#include <stdio.h>
#include "produto.h"
#include "venda.h"

int main() {
    Produto produtos[MAX_PRODUTOS];
    Venda vendas[MAX_VENDAS];

    int totalProdutos = carregarProdutos(produtos);
    int totalVendas = carregarVendas(vendas);
    int opcao;

    printf("Sistema de Controle de Estoque e Vendas\n");
    printf("%d produto(s) e %d venda(s) carregados.\n",
           totalProdutos, totalVendas);

    do {
        printf("\n========== MENU PRINCIPAL ==========\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto\n");
        printf("4 - Editar produto\n");
        printf("5 - Remover produto\n");
        printf("6 - Registrar venda\n");
        printf("7 - Listar vendas\n");
        printf("8 - Relatorio de faturamento\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &totalProdutos);
                salvarProdutos(produtos, totalProdutos);
                break;

            case 2:
                listarProdutos(produtos, totalProdutos);
                break;

            case 3:
                buscarProduto(produtos, totalProdutos);
                break;

            case 4:
                editarProduto(produtos, totalProdutos);
                salvarProdutos(produtos, totalProdutos);
                break;

            case 5:
                removerProduto(produtos, &totalProdutos);
                salvarProdutos(produtos, totalProdutos);
                break;

            case 6:
                registrarVenda(produtos, totalProdutos,
                               vendas, &totalVendas);
                salvarProdutos(produtos, totalProdutos);
                salvarVendas(vendas, totalVendas);
                break;

            case 7:
                listarVendas(vendas, totalVendas);
                break;

            case 8:
                relatorioVendas(produtos, totalProdutos,
                                vendas, totalVendas);
                break;

            case 0:
                salvarProdutos(produtos, totalProdutos);
                salvarVendas(vendas, totalVendas);
                printf("Dados salvos. Saindo do sistema...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
