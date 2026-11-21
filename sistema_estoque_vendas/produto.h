#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_PRODUTOS 10

typedef struct {
    int codigo;
    char nome[50];
    float preco;
    int estoque;
} Produto;

void cadastrarProduto(Produto produtos[], int *total);
void listarProdutos(Produto produtos[], int total);
void buscarProduto(Produto produtos[], int total);
void editarProduto(Produto produtos[], int total);
void removerProduto(Produto produtos[], int *total);
int carregarProdutos(Produto produtos[]);
void salvarProdutos(Produto produtos[], int total);

#endif
