#include <stdio.h>
#include "pedido.h"

int main() {
    int opcao;

    do {
        printf("\n--- SISTEMA PAGER ---\n");
        printf("1. Criar pedido\n");
        printf("2. Listar pedidos\n");
        printf("3. Marcar pedido como pronto\n");
        printf("0. Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            while(getchar() != '\n'); // limpa buffer
            continue;
        }

        switch(opcao) {
            case 1:
                criarPedido();
                break;
            case 2:
                listarPedidos();
                break;
            case 3:
                marcarPronto();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}