// Desenvolver um sistema básico de para cadastro de produtos em estoque

// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define tam 200

// declarações
typedef struct{
    char nome[tam];
    float preco;
} product;
typedef struct{
    product tecnologia[tam];
    product cosmetico[tam];
    product alimenticio[tam];
} categoria;
int quant_tec=0;
int quant_cosm=0;
int quant_ali=0;


// projeto de funções
void menu();
void cadastrar_produto();
void listar_produto();
void atualizar();
void remover_produto();
void limpar_buffer();


// funções
void limpar_buffer(){//(ok)
    int clean;
    while ((clean = getchar()) != '\n' && clean != EOF)
        ;
}

void cadastrar_produto(){

    char cat[20];
    printf("Digite a categoria do produto que deseja cadastrar:\n");
    printf("- Tecnologia\n- Cosmetico\n- Alimennticio\n");
    limpar_buffer();
    fgets(cat, 20, stdin);
//verificação do digitado do usuario
    if(strcmp(cat, "tecnologia") == 0)
    {
//verificação de estoque cheio
        for(int i=0;i<quant_tec;i++){
            printf("Digite o nome do produto:\n");
            limpar_buffer();
            fgets(categoria->tecnologia[i].nome, tam, stdin);
            printf("Digite o preço de venda do produto:\n");
            scanf("%f", &categoria->tecnologia[i].preco);
        }

        
    }
    else if(strcmp(cat, "cosmetico") == 0)
    {

    }
    else if(strcmp(cat, "alimenticia") == 0)
    {

    }
    else//(ok)
    {
        printf("Categoria digitada não encontrada.\n");
        menu();
    }

}

//void listar_produto(){

}

//void atualizar(){
}

//void remover_produto(){

}

void menu(){//(process)
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
        //listar_produto();
        break;
    case 3:
        //atualizar();
        break;
    case 4:
        //remover_produto();
        break;
    case 5://(ok)
        printf("Até logo ;)");
        sleep(1.2);
        exit(1);
    }
}