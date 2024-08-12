#include <stdio.h>
#include <stdlib.h>  // Para usar a função exit()

int main() {
    int opcao;
    char ch;

    printf("Digite uma opção (1 a 5): ");
    
    // Tenta ler um número inteiro
    if (scanf("%d", &opcao) != 1) {
        // Se a entrada não for um número inteiro válido
        printf("Entrada inválida. Encerrando o programa.\n");

        // Limpa o buffer de entrada
        while ((ch = getchar()) != '\n' && ch != EOF);

        // Encerra o programa com código de erro
        exit(EXIT_FAILURE);
    }

    // Verifica se o número está no intervalo de 1 a 5
    if (opcao < 1 || opcao > 5) {
        printf("Opção fora do intervalo permitido. Encerrando o programa.\n");
        exit(EXIT_FAILURE);
    }

    // Se a entrada for válida, o programa continua
    printf("Você escolheu a opção: %d\n", opcao);

    // Outras operações podem continuar aqui...

    return 0;
}
