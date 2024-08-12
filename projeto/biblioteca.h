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
//rever tipo "categoria"
typedef struct{
    int tecnologia;
    int cosmetico;

}categoria;


int estoque=0;
int produto=0;
product produtos;
//projetos de funções
void menu();
void cadastrar_produto();
void listar_produto();
void atualizar();


//funções
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
    //deve haver aqui uma verificação de numero inteiro
    scanf("%d", &opcao);
    if(opcao <= 0 || opcao >= 6){
        printf("Numero digitado inválido!\nTente novamente\n");
    }
}while (opcao <= 0 || opcao >= 6);
   

}



