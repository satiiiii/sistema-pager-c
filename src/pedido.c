#include <stdio.h>
#include "pedido.h"

Pedido pedidos[MAX_PEDIDOS];
int totalPedidos = 0;

// Função para criar um novo pedido
void criarPedido() {
    if (totalPedidos >= MAX_PEDIDOS) {
        printf("\nErro: Limite de pedidos atingido!\n");
        return;
    }

    Pedido p;
    p.id = totalPedidos + 1;

    printf("Id do pager: ");
    scanf("%d", &p.pagerId);

    p.pronto = 0; // 0 significa "Em preparo"

    pedidos[totalPedidos++] = p;

    printf("Pedido criado com sucesso! Id do pedido: %d\n", p.id);
}

void listarPedidos() {
    printf("\n=== PEDIDOS EM PREPARO ===\n");
    int encontrou = 0;
    
    for(int i = 0; i < totalPedidos; i++) {
        if (pedidos[i].pronto == 0) {
            printf("Pedido #%d | Pager %d (CHAMAR)\n", 
                    pedidos[i].id, 
                    pedidos[i].pagerId);
            encontrou = 1;
        }
    }
    
    if (!encontrou) {
        printf("Nenhum pedido em preparo no momento.\n");
    }
    printf("==========================\n\n");
}

void marcarPronto() {
    int idBusca;
    printf("Digite o ID do pedido para marcar como pronto: ");
    scanf("%d", &idBusca);

    for(int i = 0; i < totalPedidos; i++) {
        if (pedidos[i].id == idBusca) {
            if (pedidos[i].pronto == 1) {
                printf("Este pedido já foi entregue/finalizado!\n");
            } else {
                pedidos[i].pronto = 1;
                printf("Sucesso! Pedido #%d pronto para retirada.\n", idBusca);
            }
            return;
        }
    }
    printf("Pedido com ID %d não encontrado.\n", idBusca);
}