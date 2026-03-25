#ifndef PEDIDO_H
#define PEDIDO_H

#define MAX_PEDIDOS 1

typedef struct {
    int id;
    int pagerId;
    int pronto;
} Pedido;

void criarPedido();
void listarPedidos();
void marcarPronto();

#endif