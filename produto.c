#include <stdio.h>
#include <string.h>
#include "produto.h"

void cadastrarProduto(Produto produtos[], int *total) {
    int codigo, i;

    if (*total >= MAX_PRODUTOS) {
        printf("\nLimite de produtos atingido!\n");
        return;
    }

    printf("\nCodigo: ");
    scanf("%d", &codigo);

    for (i = 0; i < *total; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Ja existe um produto com esse codigo!\n");
            return;
        }
    }

    produtos[*total].codigo = codigo;

    printf("Nome: ");
    scanf(" %49[^\n]", produtos[*total].nome);

    printf("Preco: ");
    scanf("%f", &produtos[*total].preco);

    printf("Quantidade em estoque: ");
    scanf("%d", &produtos[*total].estoque);

    if (produtos[*total].preco < 0 || produtos[*total].estoque < 0) {
        printf("Preco e estoque nao podem ser negativos!\n");
        return;
    }

    (*total)++;
    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos(Produto produtos[], int total) {
    int i;

    if (total == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    printf("\n===== LISTA DE PRODUTOS =====\n");
    for (i = 0; i < total; i++) {
        printf("\nCodigo: %d\n", produtos[i].codigo);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preco: R$ %.2f\n", produtos[i].preco);
        printf("Estoque: %d\n", produtos[i].estoque);
    }
}

void buscarProduto(Produto produtos[], int total) {
    int opcao, codigo, i, encontrou = 0;
    char nome[50];

    printf("\nBuscar por:\n1 - Codigo\n2 - Nome\nOpcao: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        printf("Digite o codigo: ");
        scanf("%d", &codigo);

        for (i = 0; i < total; i++) {
            if (produtos[i].codigo == codigo) {
                printf("\nCodigo: %d | Nome: %s | Preco: R$ %.2f | Estoque: %d\n",
                       produtos[i].codigo, produtos[i].nome,
                       produtos[i].preco, produtos[i].estoque);
                encontrou = 1;
            }
        }
    } else if (opcao == 2) {
        printf("Digite o nome ou parte dele: ");
        scanf(" %49[^\n]", nome);

        for (i = 0; i < total; i++) {
            if (strstr(produtos[i].nome, nome) != NULL) {
                printf("\nCodigo: %d | Nome: %s | Preco: R$ %.2f | Estoque: %d\n",
                       produtos[i].codigo, produtos[i].nome,
                       produtos[i].preco, produtos[i].estoque);
                encontrou = 1;
            }
        }
    } else {
        printf("Opcao invalida!\n");
        return;
    }

    if (!encontrou) {
        printf("Nenhum produto encontrado.\n");
    }
}

void editarProduto(Produto produtos[], int total) {
    int codigo, i, confirma;

    printf("\nCodigo do produto que deseja editar: ");
    scanf("%d", &codigo);

    for (i = 0; i < total; i++) {
        if (produtos[i].codigo == codigo) {
            printf("\nProduto encontrado: %s\n", produtos[i].nome);
            printf("Deseja alterar os dados? (1-Sim / 0-Nao): ");
            scanf("%d", &confirma);

            if (confirma == 1) {
                printf("Novo nome: ");
                scanf(" %49[^\n]", produtos[i].nome);

                printf("Novo preco: ");
                scanf("%f", &produtos[i].preco);

                printf("Novo estoque: ");
                scanf("%d", &produtos[i].estoque);

                if (produtos[i].preco < 0 || produtos[i].estoque < 0) {
                    printf("Valores invalidos. Confira os dados!\n");
                    return;
                }

                printf("Produto alterado!\n");
            }
            return;
        }
    }

    printf("Produto nao encontrado.\n");
}

void removerProduto(Produto produtos[], int *total) {
    int codigo, i, j, confirma;

    printf("\nCodigo do produto que deseja remover: ");
    scanf("%d", &codigo);

    for (i = 0; i < *total; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Deseja remover %s? (1-Sim / 0-Nao): ", produtos[i].nome);
            scanf("%d", &confirma);

            if (confirma == 1) {
                for (j = i; j < *total - 1; j++) {
                    produtos[j] = produtos[j + 1];
                }
                (*total)--;
                printf("Produto removido!\n");
            }
            return;
        }
    }

    printf("Produto nao encontrado.\n");
}

int carregarProdutos(Produto produtos[]) {
    FILE *arquivo = fopen("produtos.dat", "rb");
    int total = 0;

    if (arquivo == NULL) {
        return 0;
    }

    fread(&total, sizeof(int), 1, arquivo);
    if (total < 0 || total > MAX_PRODUTOS) {
        fclose(arquivo);
        return 0;
    }

    fread(produtos, sizeof(Produto), total, arquivo);
    fclose(arquivo);
    return total;
}

void salvarProdutos(Produto produtos[], int total) {
    FILE *arquivo = fopen("produtos.dat", "wb");

    if (arquivo == NULL) {
        printf("Erro ao salvar os produtos!\n");
        return;
    }

    fwrite(&total, sizeof(int), 1, arquivo);
    fwrite(produtos, sizeof(Produto), total, arquivo);
    fclose(arquivo);
}
