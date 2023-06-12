#include <stdio.h>

int main() {
    int opcao;

    printf("Escolha uma opção:\n");
    printf("1 - Inserir novo registro\n");
    printf("2 - Editar registro\n");
    printf("3 - Excluir registro\n");
    printf("4 - Listar registros\n");
    printf("5 - Sair\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Opção escolhida: Inserir novo registro\n");
            // Código para inserir novo registro
            break;
        case 2:
            printf("Opção escolhida: Editar registro\n");
            // Código para editar registro
            break;
        case 3:
            printf("Opção escolhida: Excluir registro\n");
            // Código para excluir registro
            break;
        case 4:
            printf("Opção escolhida: Listar registros\n");
            // Código para listar registros
            break;
        case 5:
            printf("Opção escolhida: Sair\n");
            // Código para encerrar o programa
            break;
        default:
            printf("Opção inválida\n");
            break;
    }

    return 0;
}