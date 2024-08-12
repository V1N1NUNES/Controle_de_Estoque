//Desenvolver um sistema básico de para cadastro de produtos em estoque

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define tam 200

//declarações
typedef struct{
    char nome[tam];;
    int quant;
    float preco;
}product;
typedef struct{
    product tecnologia[tam];
    product cosmetico[tam];
    product alimenticio[tam];
}categoria;
int estoque=0;
int produto=0;

//projetos de funções
void menu();
void cadastrar_produto();
void listar_produto();
void atualizar();
void remover_produto();
void limpar_buffer();


//funções
void limpar_buffer(){
    int clean;
    while((clean = getchar()) != '\n' && clean != EOF);
}

void cadastrar_produto(){
    char resposta[20];

    printf("Qual seria a categoria do produto que deseja cadastrar?\n- Tecnologia\nCosméticos\nAlimenticio\n");
    limpar_buffer();
    fgets(resposta, tam, stdin);
//verificação da inserção do usuario
    if(strcmp(resposta, "tecnologia") != 0 || strcmp(resposta, "cosmetico") != 0 || strcmp(resposta, "alimenticio") != 0 ){
        do{
            int resposta;
        printf("Categoria informada não reconhecida.\n");
        printf("1) Voltar para o Menu\n2) Cadastrar outro produto\n");
        scanf("%", &resposta);
        if(resposta <= 0 || resposta >= 3){
            printf("Numero digitado inválido.\nTente novamente\n\n");
        }
        }while(resposta <= 0 || resposta >= 3);
        

    }
}

int main(){
    int opcao;

    do{
    printf("Sistema de cadastro de produtos.\n");
    printf("Escolha uma das opções abaixo:\n");
    printf("1) Cadastrar produto em estoque.");
    printf("2) Listar produtos cadastrados.\n");
    printf("3) Atualizar informações do produto.\n");
    printf("4) Remover produto do estoque.\n");
    printf("5) Sair.\n");
    //deve haver aqui uma verificação de numero inteiro digitado por parte do usuario
    scanf("%d", &opcao);
    if(opcao <= 0 || opcao >= 6){
        printf("Numero digitado inválido!\nTente novamente\n");
    }
}while (opcao <= 0 || opcao >= 6);
   
   switch(opcao){
    case 1:
       cadastrar_produto();
       break;
    case 2:
      listar_produto();
      break;
    case 3:
      atualizar();
    case 4: 
      remover_produto();
      break;
    case 5:
       printf("Até logo!! ;)\n");
       sleep(1.2);
       exit(1);
   }

   return 0;

}



