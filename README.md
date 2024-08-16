# -- Project --
# Sistema de Cadastro de Produtos

Este projeto é um sistema de cadastro de produtos na linguagem C, que permite ao usuário cadastrar, listar, atualizar e remover produtos em diferentes categorias: Tecnologia, Cosmético e Alimentício.

## Requisitos

Para compilar e executar o projeto, você precisará de:

- Um compilador C (como GCC)
- Um sistema operacional que suporte a execução do compilador C (Linux, macOS, Windows)

## Estrutura do Projeto

O projeto é composto pelos seguintes arquivos principais:

- `produtos.h`: Arquivo de cabeçalho que define as estruturas de dados e declara as funções.
- `produtos.c`: Implementação das funções declaradas em `produtos.h`.
- `main.c`: Arquivo principal que contém a função `main()` e chama o menu.


## Funcionalidade de cada função

- `void menu()`: Exibe na tela as opções iniciais que levarão o usuario aonde desejar dentro do sistema.

- `void cadastrar_produto()`: De acordo com a categoria que for informada pelo usuário o programa o levará para se cadastrar o produto desejado com exito.

- `void listar_produto()`: Mostra a lista da categoria informada pelo usuario com os produtos cadastrados pelo mesmo no sistema.

- `void atualizar()`: Possibilita ao usuario, fazer mudanças no Nome e no Preço do produto que for informado na sua digitação.

-`void remover_produto()`: Guia e dá opções ao usuário para poder excluir um produto de categoria desejada pelo próprio usuário.

- `void limpar_buffer()`: Limpa o buffer de entrada padrão, removendo quaisquer caracteres extras que possam ter sido deixados na entrada do usuário. Isso é útil para garantir que a entrada do usuário seja processada corretamente sem resíduos de dados inesperados.

- `void remover_newline(char *str)`: void remover_newline(char *str): Remove o caractere de nova linha ('\n') do final de uma string. Essa função é útil para processar strings que foram lidas do usuário, onde o caractere de nova linha pode ser deixado após a entrada e precisa ser removido para evitar problemas na manipulação da string.


## Melhorias futuras

-`Verificações`: Optar por mais verificações na entrada padrão, para maior e melhor controle sobre o usuário, e melhor desempenho do sistema. 
