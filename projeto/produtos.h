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


// FUNÇÕES
void limpar_buffer()//(ok)
{ //(ok)
    int clean;
    while ((clean = getchar()) != '\n' && clean != EOF)
        ;
}

void remover_newline(char *str)//(ok)
{ //(ok)
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

void cadastrar_produto()//(process...)
{
    char categoria[20];
    char resposta[10];

    printf("\nEscolha a categoria do produto que deseja cadastrar.\n- Tecnologia\n- Cosmetica\n- Alimenticia\n:");
    limpar_buffer();
    fgets(categoria, sizeof(categoria), stdin);
    remover_newline(categoria);

    if (strcmp(categoria, "tecnologia") == 0 || strcmp(categoria, "Tecnologia") == 0)
    {
        do
        {
            printf("\nDigite o nome do produto:\n");
            fgets(estoque.tecnologia[quant_tec].nome, sizeof(estoque.tecnologia[quant_tec].nome), stdin);
            remover_newline(estoque.tecnologia[quant_tec].nome);

            printf("\nDigite o preço de venda do produto:\n");
            scanf("%f", &estoque.tecnologia[quant_tec].preco);
            limpar_buffer();

            printf("Produto cadastrado com sucesso!!\n");
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
    else
    {
        printf("\nCategoria digitada invalida ou inexistente.\nVoltando ao menu...\n\n");
        sleep(1.2);
        menu();
        return;
    }
}

void listar_produto()//(process...)
{
    char resposta[10];
    char categoria[20];

    do
    {
        printf("\nQual a categoria do produto que deseja listar?\n- Tecnologia\n- Cosmetica\n- Alimenticia\n");
        limpar_buffer();
        fgets(categoria, sizeof(categoria), stdin);
        remover_newline(categoria);

        if (strcmp(categoria, "Tecnologia") == 0 || strcmp(categoria, "tecnologia") == 0)
        {
            if (quant_tec <= 0)
            {
                char resp[10];
                printf("\nestoque de tecnologia vazio.\nDeseja listar outra categoria?\n");
                fgets(resp, sizeof(resp), stdin);
                remover_newline(resp);

                if (strcmp(resp, "sim") == 0 || strcmp(resp, "Sim") == 0)
                {
                    listar_produto();
                    return;
                }
                else
                {
                    printf("\nVoltando ao menu...\n\n");
                    sleep(1.2);
                    menu();
                    return;
                }
            }
            printf("Lista dos produtos de tecnologia:\n\n");
            for (int i = 0; i < quant_tec; i++)
            {
                printf("nome do produto: %s \npreço do produto: %.2f\n\n", estoque.tecnologia[i].nome, estoque.tecnologia[i].preco);
            }

            printf("Pressione qualquer tecla para continuar...\n");
            getch();
            // continue;
        }
        else
        {
            printf("\nCategoria digitada invalida ou inexistente.\nVoltando ao menu...\n\n");
            sleep(1.2);
            menu();
            return;
        }

        printf("\nDeseja listar mais alguma categoria de produtos?\n");
        fgets(resposta, sizeof(resposta), stdin);
        remover_newline(resposta);

        if (strcmp(resposta, "sim") == 0 || strcmp(resposta, "Sim") == 0)
        {
            continue;
        }
        else
        {
            printf("Voltando ao menu...");
            sleep(1.2);
            menu();
            return;
        }

    } while (strcmp(resposta, "sim") == 0 || strcmp(resposta, "Sim") == 0);

    menu();
}

void atualizar()//continua...
{
    char categoria[20];
    char resposta[10];

    do
    {
        printf("\nDigite a categoria do produto que deseja editar:\n");
        limpar_buffer();
        fgets(categoria, sizeof(categoria), stdin);
        remover_newline(categoria);

        if (strcmp(categoria, "tecnologia") == 0 || strcmp(categoria, "Tecnologia") == 0)
        {
            char nome[tam];

            if (quant_tec <= 0)
            {
                char resp[10];
                printf("\nEstoque de tecnologia vazio.\nDeseja editar outro produto?\n");
                fgets(resp, sizeof(resp), stdin);
                remover_newline(resp);

                if (strcmp(resp, "sim") == 0 || strcmp(resp, "Sim") == 0)
                {
                    atualizar();
                    return;
                }
                else
                {
                    printf("\nVoltando ao menu...\n\n");
                    sleep(1.2);
                    menu();
                    return;
                }
            }
            printf("\nDigite o nome do produto que deseja modificar:\n");
            fgets(nome, sizeof(nome), stdin);
            remover_newline(nome);

            // laço para procurar o produto
            for (int i = 0; i < quant_tec; i++)
            {
                if (strcmp(nome, estoque.tecnologia[i].nome) == 0)
                {
                    char mudanca[30];
                    char novo[tam];
                    char resp[10];

                    do
                    {
                        printf("\nOque deseja mudar?\n- Nome\n- Preço\n");
                        fgets(mudanca, sizeof(mudanca), stdin);
                        remover_newline(mudanca);

                        if (strcmp(mudanca, "nome") == 0 || strcmp(mudanca, "Nome") == 0)
                        {

                            printf("\nDigite o novo nome do produto:\n");
                            fgets(novo, sizeof(novo), stdin);
                            remover_newline(novo);

                            strcpy(estoque.tecnologia[i].nome, novo);

                            printf("\nNome alterado com sucesso!!\n\n");
                            printf("\nDeseja alterar outro produto no estoque de tecnologia?\n");
                            fgets(resp, sizeof(resp), stdin);
                            remover_newline(resp);

                            if (strcmp(resp, "sim") == 0 || strcmp(resp, "Sim") == 0)
                            {
                                atualizar();
                                return;
                            }
                            else
                            {
                                printf("Voltando para o menu...");
                                sleep(1.2);
                                menu();
                                return;
                            }
                        }
                        else
                        {
                            printf("\nNOme digitado não encontrado..\nDeseja modificar outro produto?\n");
                        }
                    } while (strcmp(resp, "sim") == 0 || strcmp(resp, "Sim") == 0);

                    menu();
                }
            }
        }
    } while(strcmp(resposta, "sim") == 0 || strcmp(resposta, "Sim") == 0);
    
    menu();
    return;
}

// void remover_produto()//(incompleted)

void menu()//(process)
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
        // atualizar();
        break;
    case 4:
        // remover_produto();
        break;
    case 5: //(ok)
        printf("Até logo ;)");
        sleep(1.2);
        exit(1);
    }
}