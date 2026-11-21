# Sistema de Controle de Estoque e Vendas

Projeto em linguagem C para a Entrega 2 do Projeto Integrador.

## Arquivos
- `main.c`: menu principal e chamada das funcionalidades.
- `produto.h` e `produto.c`: cadastro, listagem, busca, edição, remoção e persistência dos produtos.
- `venda.h` e `venda.c`: registro de vendas, baixa de estoque, listagem, relatório e persistência das vendas.

## Persistência
O programa cria os arquivos `produtos.dat` e `vendas.dat` na mesma pasta em que for executado. Na próxima execução, os dados são carregados automaticamente.

## Limites
- Até 10 produtos.
- Até 20 vendas.

## Testes manuais sugeridos
1. Cadastrar um produto e conferir se aparece na listagem.
2. Tentar cadastrar outro produto com o mesmo código.
3. Buscar um produto pelo código.
4. Buscar usando parte do nome.
5. Editar um produto e confirmar a alteração.
6. Remover um produto e conferir se a listagem continua correta.
7. Registrar uma venda com estoque suficiente.
8. Tentar vender uma quantidade maior que o estoque.
9. Conferir se o estoque diminuiu após a venda.
10. Conferir o faturamento no relatório.
11. Fechar e abrir o programa para verificar se os dados continuam salvos.
12. Digitar uma opção inválida no menu.
