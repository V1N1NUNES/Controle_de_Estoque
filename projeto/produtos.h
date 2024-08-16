// Desenvolver um sistema básico de para cadastro de produtos em estoque

// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <conio.h>
#define tam 200

// DECLARAÇÕES
typedef struct
{
    char nome[tam];
    float preco;
} product;
typedef struct
{
    product tecnologia[tam];
    product cosmetico[tam];
    product alimenticio[tam];
} categoria;
categoria estoque;
int quant_tec = 0;
int quant_cosm = 0;
int quant_ali = 0;

// PROJETO DE FUNÇÕES
void menu();
void cadastrar_produto();
void listar_produto();
void atualizar();
void remover_produto();
void limpar_buffer();
void remover_newline(char *str);
// funções p/ arquivos
// void escrever()
// void ler()
// void mostrar()

// FUNÇÕES DE LIMPEZA
void limpar_buffer() //(ok)
{                    //(ok)
    int clean;
    while ((clean = getchar()) != '\n' && clean != EOF)
        ;
}
void remover_newline(char *str) //(ok)
{                               //(ok)
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

// FUNÇÕES
void cadastrar_produto() //(certo)
{
    char categoria[20];
    char resposta[10];

    printf("\nEscolha a categoria do produto que deseja cadastrar.\n- Tecnologia\n- Cosmetica\n- Alimenticia\n:");
    limpar_buffer();
    fgets(categoria, sizeof(categoria), stdin);
    remover_newline(categoria);

    if (strcmp(categoria, "tecnologia") == 0 || strcmp(categoria, "Tecnologia") == 0) // categoria tecnologia
    {
        do
        {
            printf("\nDigite o nome do produto:\n");
            fgets(estoque.tecnologia[quant_tec].nome, sizeof(estoque.tecnologia[quant_tec].nome), stdin);
            remover_newline(estoque.tecnologia[quant_tec].nome);

            printf("\nDigite o preço de venda do produto:\n");
            scanf("%f", &estoque.tecnologia[quant_tec].preco);
            limpar_buffer();

            printf("\nProduto cadastrado com sucesso!!\n");
            quant_tec++;

            if (quant_tec < tam)
            {
                printf("Deseja cadastrar mais algum produto no estoque de tecnologia? (sim/nao)\n");
                fgets(resposta, sizeof(resposta), stdin);
                remover_newline(resposta);

                if (strcmp(resposta, "sim") == 0 || strcmp(resposta, "Sim") == 0)
                {
                    continue;
                }
                else
                {
                    printf("\nVoltando ao Menu...\n");
                    sleep(1.2);
                    menu();
                    return;
                }
            }
            else
            {
                printf("estoque cheio.\nRetornando ao menu...\n\n");
                sleep(1.2);
                menu();
                return;
            }
        } while (strcmp(resposta, "sim") == 0 || strcmp(resposta, "Sim") == 0);

        menu();
        return;
    }

    else if (strcmp(categoria, "alimenticia") == 0 || strcmp(categoria, "Alimenticia") == 0) // categoria alimenticia
    {
        do
        {
            printf("\nDigite o nome do produto:\n");
            fgets(estoque.alimenticio[quant_ali].nome, sizeof(estoque.alimenticio[quant_ali].nome), stdin);
            remover_newline(estoque.alimenticio[quant_ali].nome);

            printf("\nDigite o preço de venda do produto:\n");
            scanf("%f", &estoque.alimenticio[quant_ali].preco);
            limpar_buffer();

            printf("\nProduto cadastrado com sucesso!!\n");
            quant_ali++;

            if (quant_ali < tam)
            {
                printf("Deseja cadastrar mais algum produto no estoque alimenticio? (sim/nao)\n");
                fgets(resposta, sizeof(resposta), stdin);
                remover_newline(resposta);

                if (strcmp(resposta, "sim") == 0 || strcmp(resposta, "Sim") == 0)
                {
                    continue;
                }
                else
                {
                    printf("\nVoltando ao Menu...\n");
                    sleep(1.2);
                    menu();
                    return;
                }
            }
            else
            {
                printf("estoque cheio.\nRetornando ao menu...\n\n");
                sleep(1.2);
                menu();
                return;
            }
        } while (strcmp(resposta, "sim") == 0 || strcmp(resposta, "Sim") == 0);

        menu();
        return;
    }

    else if (strcmp(categoria, "cosmetica") == 0 || strcmp(categoria, "Cosmetica") == 0) // categoria cosmetica
    {
        do
        {
            printf("\nDigite o nome do produto:\n");
            fgets(estoque.cosmetico[quant_cosm].nome, sizeof(estoque.cosmetico[quant_cosm].nome), stdin);
            remover_newline(estoque.cosmetico[quant_cosm].nome);

            printf("\nDigite o preço de venda do produto:\n");
            scanf("%f", &estoque.cosmetico[quant_cosm].preco);
            limpar_buffer();

            printf("\nProduto cadastrado com sucesso!!\n");
            quant_cosm++;

            if (quant_cosm < tam)
            {
                printf("Deseja cadastrar mais algum produto no estoque de Cosmeticos? (sim/nao)\n");
                fgets(resposta, sizeof(resposta), stdin);
                remover_newline(resposta);

                if (strcmp(resposta, "sim") == 0 || strcmp(resposta, "Sim") == 0)
                {
                    continue;
                }
                else
                {
                    printf("\nVoltando ao Menu...\n");
                    sleep(1.2);
                    menu();
                    return;
                }
            }
            else
            {
                printf("estoque cheio.\nRetornando ao menu...\n\n");
                sleep(1.2);
                menu();
                return;
            }
        } while (strcmp(resposta, "sim") == 0 || strcmp(resposta, "Sim") == 0);

        menu();
        return;
    }

    else
    {
        printf("\nCategoria digitada invalida ou inexistente.\nVoltando ao menu...\n\n");
        sleep(1.2);
        menu();
        return;
    }
}

void listar_produto() //(certo)
{
    char resposta[10];
    char categoria[20];

    do
    {
        printf("\nQual a categoria do produto que deseja listar?\n- Tecnologia\n- Cosmetica\n- Alimenticia\n");
        limpar_buffer();
        fgets(categoria, sizeof(categoria), stdin);
        remover_newline(categoria);

        if (strcmp(categoria, "Tecnologia") == 0 || strcmp(categoria, "tecnologia") == 0) // categoria tecnologia
        {
            if (quant_tec <= 0)
            {
                printf("\nestoque de tecnologia vazio.\nVoltando ao menu...\n\n");
                sleep(1.2);
                menu();
                return;
            }
            printf("Lista dos produtos de tecnologia:\n\n");
            for (int i = 0; i < quant_tec; i++)
            {
                printf("nome do produto: %s \npreço do produto: %.2f\n\n", estoque.tecnologia[i].nome, estoque.tecnologia[i].preco);
            }

            printf("Pressione qualquer tecla para continuar...\n");
            getch();
        }

        else if (strcmp(categoria, "Alimenticia") == 0 || strcmp(categoria, "alimenticia") == 0) // categoria alimenticia
        {
            if (quant_ali <= 0)
            {
                printf("\nestoque Alimenticio vazio.\nVoltando ao menu...\n\n");
                sleep(1.2);
                menu();
                return;
            }
            printf("Lista dos produtos Alimenticio:\n\n");
            for (int i = 0; i < quant_ali; i++)
            {
                printf("nome do produto: %s\npreço do produto: %.2f\n\n", estoque.alimenticio[i].nome, estoque.alimenticio[i].preco);
            }

            printf("Pressione qualquer tecla para continuar...\n");
            getch();
        }

        else if (strcmp(categoria, "cosmetica") == 0 || strcmp(categoria, "Cosmetica") == 0) // categoria cosmetico
        {
            if (quant_cosm <= 0)
            {
                printf("\nestoque de cosmeticos vazio.\nVoltando ao menu...\n\n");
                sleep(1.2);
                menu();
                return;
            }
            printf("Lista dos produtos de cosmeticos:\n\n");
            for (int i = 0; i < quant_cosm; i++)
            {
                printf("nome do produto: %s \npreço do produto: %.2f\n\n", estoque.cosmetico[i].nome, estoque.cosmetico[i].preco);
            }

            printf("Pressione qualquer tecla para continuar...\n");
            getch();
        }

        else
        {
            printf("\nCategoria digitada invalida ou inexistente.\nVoltando ao menu...\n\n");
            sleep(1.2);
            menu();
            return;
        }

        printf("Voltando ao menu...");
        sleep(1.2);
        menu();
        return;

    } while (strcmp(resposta, "sim") == 0 || strcmp(resposta, "Sim") == 0);

    menu();
}

void atualizar() // (não modifica além do primeiro produto)
{
    char categoria[20];

    // Procurar por categoria
    printf("Digite a categoria do produto:\n- Tecnologia\n- Cosmetica\n- Alimenticia\n");
    limpar_buffer(); // Limpar buffer antes de ler a entrada
    fgets(categoria, sizeof(categoria), stdin);
    remover_newline(categoria);

    if (strcmp(categoria, "tecnologia") == 0 || strcmp(categoria, "Tecnologia") == 0)
    {
        char nome[tam];

        // Verificação de produtos no estoque
        if (quant_tec <= 0)
        {
            printf("\nEstoque de tecnologia vazio.\nVoltando para o menu...\n\n");
            sleep(1.2);
            menu();
            return;
        }

        printf("Digite o nome do produto que deseja atualizar:\n");
        fgets(nome, sizeof(nome), stdin);
        remover_newline(nome);

        // Procurar o produto na categoria tecnologia
        int produto_encontrado = 0; // Flag para verificar se o produto foi encontrado
        for (int i = 0; i < quant_tec; i++)
        {
            char resposta[10];

            if (strcmp(nome, estoque.tecnologia[i].nome) == 0)
            {
                produto_encontrado = 1; // Produto encontrado
                printf("Digite o que deseja modificar:\n- Nome\n- Preço\n");

                fgets(resposta, sizeof(resposta), stdin);
                remover_newline(resposta);

                if (strcmp(resposta, "Nome") == 0 || strcmp(resposta, "nome") == 0)
                {
                    char novo_nome[tam];
                    printf("Digite o novo nome do produto:\n");
                    fgets(novo_nome, sizeof(novo_nome), stdin);
                    remover_newline(novo_nome);

                    strcpy(estoque.tecnologia[i].nome, novo_nome);

                    printf("\nNome alterado com sucesso!!\nRetornando ao menu...\n\n");
                    sleep(1.2);
                    menu();
                    return;
                }
                else if (strcmp(resposta, "Preco") == 0 || strcmp(resposta, "preco") == 0)
                {
                    float preco;

                    printf("Digite o novo preço do produto:\n");
                    scanf("%f", &preco);
                    limpar_buffer(); // Limpar buffer após scanf

                    estoque.tecnologia[i].preco = preco;

                    printf("\nPreço alterado com sucesso!!\nRetornando ao menu...\n\n");
                    sleep(1.2);
                    menu();
                    return;
                }
            }
        }

        // Mensagem de erro se o produto não for encontrado após o loop
        if (!produto_encontrado)
        {
            printf("\nNome do produto não encontrado.\nVoltando ao menu...\n\n");
            sleep(1.2);
            menu();
        }
    }

    else if (strcmp(categoria, "alimenticia") == 0 || strcmp(categoria, "Alimenticia") == 0)
    {
        char nome[tam];

        // Verificação de produtos no estoque
        if (quant_ali <= 0)
        {
            printf("\nEstoque alimenticio vazio.\nVoltando ao menu...\n\n");
            sleep(1.2);
            menu();
            return;
        }

        printf("Digite o nome do produto que deseja atualizar:\n");
        fgets(nome, sizeof(nome), stdin);
        remover_newline(nome);

        // Procurar o produto na categoria alimentícia
        int produto_encontrado = 0; // Flag para verificar se o produto foi encontrado
        for (int i = 0; i < quant_ali; i++)
        {
            char resposta[10];

            if (strcmp(nome, estoque.alimenticio[i].nome) == 0)
            {
                produto_encontrado = 1; // Produto encontrado
                printf("Digite o que deseja modificar:\n- Nome\n- Preço\n");

                fgets(resposta, sizeof(resposta), stdin);
                remover_newline(resposta);

                if (strcmp(resposta, "Nome") == 0 || strcmp(resposta, "nome") == 0)
                {
                    char novo_nome[tam];
                    printf("Digite o novo nome do produto:\n");
                    fgets(novo_nome, sizeof(novo_nome), stdin);
                    remover_newline(novo_nome);

                    strcpy(estoque.alimenticio[i].nome, novo_nome);

                    printf("\nNome alterado com sucesso!!\nRetornando ao menu...\n\n");
                    sleep(1.2);
                    menu();
                    return;
                }
                else if (strcmp(resposta, "Preco") == 0 || strcmp(resposta, "preco") == 0)
                {
                    float preco;

                    printf("Digite o novo preço do produto:\n");
                    scanf("%f", &preco);
                    limpar_buffer(); // Limpar buffer após scanf

                    estoque.alimenticio[i].preco = preco;

                    printf("\nPreço alterado com sucesso!!\nRetornando ao menu...\n\n");
                    sleep(1.2);
                    menu();
                    return;
                }
            }
        }

        // Mensagem de erro se o produto não for encontrado após o loop
        if (!produto_encontrado)
        {
            printf("\nNome do produto não encontrado.\nVoltando ao menu...\n\n");
            sleep(1.2);
            menu();
        }
    }

    else if (strcmp(categoria, "cosmetica") == 0 || strcmp(categoria, "Cosmetica") == 0)
    {
        char nome[tam];

        // Verificação de produtos no estoque
        if (quant_cosm <= 0)
        {
            printf("\nEstoque de cosmeticos vazio.\nVoltando ao menu...\n\n");
            sleep(1.2);
            menu();
            return;
        }

        printf("Digite o nome do produto que deseja atualizar:\n");
        fgets(nome, sizeof(nome), stdin);
        remover_newline(nome);

        // Procurar o produto na categoria alimentícia
        int produto_encontrado = 0;
        for (int i = 0; i < quant_cosm; i++)
        {
            char resposta[10];

            if (strcmp(nome, estoque.cosmetico[i].nome) == 0)
            {
                produto_encontrado = 1;
                printf("Digite o que deseja modificar:\n- Nome\n- Preço\n");

                fgets(resposta, sizeof(resposta), stdin);
                remover_newline(resposta);

                if (strcmp(resposta, "Nome") == 0 || strcmp(resposta, "nome") == 0)
                {
                    char novo_nome[tam];
                    printf("Digite o novo nome do produto:\n");
                    fgets(novo_nome, sizeof(novo_nome), stdin);
                    remover_newline(novo_nome);

                    strcpy(estoque.cosmetico[i].nome, novo_nome);

                    printf("\nNome alterado com sucesso!!\nRetornando ao menu...\n\n");
                    sleep(1.2);
                    menu();
                    return;
                }
                else if (strcmp(resposta, "Preco") == 0 || strcmp(resposta, "preco") == 0)
                {
                    float preco;

                    printf("Digite o novo preço do produto:\n");
                    scanf("%f", &preco);
                    limpar_buffer(); // Limpar buffer após scanf

                    estoque.cosmetico[i].preco = preco;

                    printf("\nPreço alterado com sucesso!!\nRetornando ao menu...\n\n");
                    sleep(1.2);
                    menu();
                    return;
                }
            }
        }

        // Mensagem de erro se o produto não for encontrado após o loop
        if (!produto_encontrado)
        {
            printf("\nNome do produto não encontrado.\nVoltando ao menu...\n\n");
            sleep(1.2);
            menu();
        }
    }

    else
    {
        // Categoria inválida
        printf("\nCategoria informada inválida ou inexistente.\nVoltando ao menu...\n\n");
        sleep(1.2);
        menu();
    }
}

void remover_produto()
{
    char categoria[40];

    printf("Digite a categoria do produto que deseja excluir:\n- Tecnologia\n- Cosmetico\n- Alimenticia\n");
    limpar_buffer();
    fgets(categoria, sizeof(categoria), stdin);
    remover_newline(categoria);

    if (strcmp(categoria, "tecnologia") == 0 || strcmp(categoria, "Tecnologia") == 0)
    {
        char nome[tam];
        int produto_encontrado = 0;

        printf("Digite o nome do produto que deseja excluir:\n");
        fgets(nome, sizeof(nome), stdin);
        remover_newline(nome);

        for (int i = 0; i < quant_tec; i++)
        {
            if (strcmp(nome, estoque.tecnologia[i].nome) == 0)
            {
                produto_encontrado = 1; 
                char resp[10];

                printf("Tem certeza que deseja excluir o produto?:\nnome:%s\n:preço%.2f\n", estoque.tecnologia[i].nome, estoque.tecnologia[i].preco);
                fgets(resp, sizeof(resp), stdin);
                remover_newline(resp);

                if (strcmp(resp, "sim") == 0 || strcmp(resp, "Sim") == 0)
                {
                    // Remover o produto: deslocar os produtos restantes para preencher o espaço
                    for (int j = i; j < quant_tec - 1; j++)
                    {
                        estoque.tecnologia[j] = estoque.tecnologia[j + 1];
                    }
                    quant_tec--;

                    printf("Produto excluído com sucesso!!\nVoltando ao menu...\n\n");
                    sleep(1.2);
                    menu();
                    return;
                }
                else
                {
                    printf("Voltando ao menu...\n\n");
                    sleep(1.2);
                    menu();
                    return;
                }
            }
        }

        if (!produto_encontrado)
        {
            printf("Produto não encontrado.\nVoltando ao menu...\n\n");
            sleep(1.2);
            menu();
            return;
        }
    }

    else if (strcmp(categoria, "Cosmetico") == 0 || strcmp(categoria, "cosmetico") == 0 || strcmp(categoria, "Cosmetica") == 0 || strcmp(categoria, "cosmetica") == 0)
    {
        char nome[tam];
        int produto_encontrado = 0; 

        printf("Digite o nome do produto que deseja excluir:\n");
        fgets(nome, sizeof(nome), stdin);
        remover_newline(nome);

        for (int i = 0; i < quant_cosm; i++)
        {
            if (strcmp(nome, estoque.cosmetico[i].nome) == 0)
            {
                produto_encontrado = 1; // Produto encontrado
                char resp[10];

                printf("Tem certeza que deseja excluir o produto?:\nnome:%s\n:preço%.2f\n", estoque.cosmetico[i].nome, estoque.cosmetico[i].preco);
                fgets(resp, sizeof(resp), stdin);
                remover_newline(resp);

                if (strcmp(resp, "sim") == 0 || strcmp(resp, "Sim") == 0)
                {
                    // Remover o produto: deslocar os produtos restantes para preencher o espaço
                    for (int j = i; j < quant_cosm - 1; j++)
                    {
                        estoque.cosmetico[j] = estoque.cosmetico[j + 1];
                    }
                    quant_cosm--;

                    printf("Produto excluído com sucesso!!\nVoltando ao menu...\n\n");
                    sleep(1.2);
                    menu();
                    return;
                }
                else
                {
                    printf("Voltando ao menu...\n\n");
                    sleep(1.2);
                    menu();
                    return;
                }
            }
        }

        if (!produto_encontrado)
        {
            printf("Produto não encontrado.\nVoltando ao menu...\n\n");
            sleep(1.2);
            menu();
            return;
        }
    }

    else if (strcmp(categoria, "Alimenticio") == 0 || strcmp(categoria, "alimenticio") == 0 || strcmp(categoria, "Alimenticia") == 0 || strcmp(categoria, "alimenticia"))
    {
        char nome[tam];
        int produto_encontrado = 0;

        printf("Digite o nome do produto que deseja excluir:\n");
        fgets(nome, sizeof(nome), stdin);
        remover_newline(nome);

        for (int i = 0; i < quant_ali; i++)
        {
            if (strcmp(nome, estoque.alimenticio[i].nome) == 0)
            {
                produto_encontrado = 1; // Produto encontrado
                char resp[10];

                printf("Tem certeza que deseja excluir o produto?:\nnome:%s\n:preço%.2f\n", estoque.alimenticio[i].nome, estoque.alimenticio[i].preco);
                fgets(resp, sizeof(resp), stdin);
                remover_newline(resp);

                if (strcmp(resp, "sim") == 0 || strcmp(resp, "Sim") == 0)
                {
                    for (int j = i; j < quant_ali- 1; j++)
                    {
                        estoque.alimenticio[j] = estoque.alimenticio[j + 1];
                    }
                    quant_ali--;

                    printf("Produto excluído com sucesso!!\nVoltando ao menu...\n\n");
                    sleep(1.2);
                    menu();
                    return;
                }
                else
                {
                    printf("Voltando ao menu...\n\n");
                    sleep(1.2);
                    menu();
                    return;
                }
            }
        }

        if (!produto_encontrado)
        {
            printf("Produto não encontrado.\nVoltando ao menu...\n\n");
            sleep(1.2);
            menu();
            return;
        }
    }

    else
    {
        printf("Categoria digitada inválida ou inexistente.\nVoltando ao menu...\n\n");
        sleep(1.2);
        menu();
        return;
    }
}

void menu() //(process)
{
    int opcao;
    do
    {
        printf("Sistema de cadastro de produtos.\n\n");
        sleep(1.2);
        printf("Escolha uma das opções abaixo:\n");
        printf("1) Cadastrar produto em estoque.\n");
        printf("2) Listar produtos cadastrados.\n");
        printf("3) Atualizar informações do produto.\n");
        printf("4) Remover produto do estoque.\n");
        printf("5) Sair.\n");
        scanf("%d", &opcao);
        // verificação de numero inteiro
        if (opcao <= 0 || opcao >= 6)
        {
            printf("Numero digitado inválido!\nTente novamente\n");
        }
    } while (opcao <= 0 || opcao >= 6);

    switch (opcao)
    {
    case 1:
        cadastrar_produto();
        break;
    case 2:
        listar_produto();
        break;
    case 3:
        atualizar();
        break;
    case 4:
        remover_produto();
        break;
    case 5:
        printf("Até logo ;)");
        sleep(1.2);
        exit(1);
    }
}