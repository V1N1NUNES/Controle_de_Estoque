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
void remover_newline();

//funções p/ arquivos
//void escrever()
//void ler()
//void mostrar()


// funções
void limpar_buffer(){//(ok)
    int clean;
    while ((clean = getchar()) != '\n' && clean != EOF)
        ;
}

void remover_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

void cadastrar_produto(){
    categoria estoque;
    char cat[20];
    char resposta[10];
    char resp[10];

    printf("Digite a categoria do produto que deseja cadastrar:\n");
    printf("- Tecnologia\n- Cosmetico\n- Alimenticio\n");
    limpar_buffer();
    fgets(cat, 20, stdin);
    remover_newline(cat);

//verificação do digitado do usuario
    if(strcmp(cat, "tecnologia") == 0)//pendente
    {
//verificação de estoque cheio
        do{
            if(quant_tec >= tam){
                printf("Estoque cheio.\n");
                
            }
            printf("Digite o nome do produto:\n");
            limpar_buffer();
            fgets(estoque.tecnologia[quant_tec].nome, tam, stdin);
            printf("Digite o preço de venda do produto:\n");
            scanf("%f", &estoque.tecnologia[quant_tec].preco);  
        
        quant_tec++;

        printf("Deseja cadastrar mais um produto de tecnologia?:\n");
        limpar_buffer();
        fgets(resposta, 10, stdin);
        if(strcmp(resposta, "nao")==0){
            menu();
        }
        }while(strcmp(resposta, "sim") == 0);
        menu();
    }
    else if(strcmp(cat, "cosmetico") == 0)
    {

    }
    else if(strcmp(cat, "alimenticia") == 0)
    {

    }else//deu algum problema
    {
        printf("Categoria digitada não encontrada.\n\n\n");
        menu();
    }

}

void listar_produto(){
    char cat[20];
    categoria estoque;

    printf("Digite a categoria do produto:\n");
    limpar_buffer();
    fgets(cat, 20, stdin);
    if(strcmp(cat, "tecnologia") == 0)
    {
//verificação de estoque cheio
        for(int i=0;i<quant_tec;i++){
            printf("Nome: %s\n", estoque.tecnologia[i].nome);
            printf("Preço: %f\n", estoque.tecnologia[i].preco);
        }
        menu();
    }

}

//void atualizar(){

//void remover_produto(){


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