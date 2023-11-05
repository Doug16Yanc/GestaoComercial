#include "sgc.h"

void controleMenuUsuario(struct Produto *produto, struct Usuario *usuario, int tamanho, int tam) {

    interageUsuario(produto, usuario, &tamanho, tam);
    
}

void interageUsuario(struct Produto *produto, struct Usuario *usuario, int *tamanho, int tam){
    struct Pedido *pedido; 
    int tamPedido;

    int opcao;
    
    do{
        printf("                    PÁGINA DO USUÁRIO                   \n");
        printf("********************************************************\n");
        printf("* Bem-vindo(a), caríssimo(a), %s, o que temos para hoje? *\n", usuario->nomeUser);
        printf("        (1) - Fazer pedidos           \n");
        printf("        (2) - Listar produtos         \n");
        printf("        (3) - Listar pedidos          \n");
        printf("        (4) - Retornar ao início      \n");
        
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                fazerPedidos(produto, pedido, tamanho, &tamPedido);
                break;
            case 2:
                listarProdutos(produto, *tamanho);
                break;
            case 3:
                listaPedidos(pedido, &tamPedido);
                break;
            case 4:
                printf("Retornando...\n");
                return;
                break;
            default:
                printf("Alternativa impossível.\n");
                break;
                
        }

    }
    while(opcao != 4);
}

void fazerPedidos(struct Produto *produto, struct Pedido *pedido, int *tamanho, int *tamPedido){
    
    int codigo;
    
    printf("Solicitando operação para realizar pedidos...\n");
    
    if (*tamanho > 0){

        do{
            printf("Digite o id do produto ou a saída do programa com -1:\n");
            scanf("%d", &codigo);
            
            if (codigo == -1){
                break;
            }
            
            for (int i = 0; i < *tamanho; i++){
                if (codigo == produto[i].idProd){
                    printf("Digite a quantidade de %s : ", produto[i].nomeProd);
                    scanf("%d", &pedido[i].quanti);
                    
                    if (pedido[i].quanti <= produto[i].quantidade){
                        printf("%d adicionados(as) ao carrinho de compras.\n", pedido[i].quanti);
                        pedido[(*tamPedido)++];
                        produto[i].quantidade -= pedido[i].quanti;
                        pedido[i].valorTotal += pedido[i].quanti * produto[i].preco;
                        salvarPedidos(pedido, tamPedido);

                    }
                    else{
                        printf("Não há estoque suficiente dessa mercadoria.\n");
                    }
                }
                else{
                    printf("Id de produto inexistente.\n");
                }
            }
        
        }
        while(1);
    }
    else{
        printf("Sem estoque ainda.\n");
    }
}

void listaPedidos(struct Pedido *pedido, int *tamPedido) {
    
    struct Produto *produto;
    struct Usuario *usuario;
    int tamanho, tam;
    
    if (*tamPedido > 0){
        printf("Lista de Pedidos:\n");
        for (int i = 0; i < *tamPedido; i++) {
            printf(" > Id do pedido: %d\n", pedido[i].idPedido);
            printf(" > Id do produto : %d \n", produto[i].idProd);
            printf(" > Nome : %s \n", produto[i].nomeProd);
            printf(" > Quantidade : %d\n", pedido[i].quanti);
            printf(" > Preço unitário : R$ %.2f\n", produto[i].preco);
            printf("\n");
        
        }
    }
    else{
        printf("Sem pedidos feitos.\n");
    }
    interageAdmin(produto, usuario, &tamanho, tam);

    
}

void salvarPedidos(struct Pedido *pedido, int *tamPedido) {
    FILE *fp;
    fp = fopen("pedido.txt", "w");
    
    if (fp == NULL) {
        printf("Erro na abertura do arquivo de pedidos.\n");
        exit(1);
    }
    
    for (int i = 0; i < *tamPedido; i++) {
        fprintf(fp, "Id : %d\n Quantidade : %d\n Valor total : %.2f\n", pedido[i].idPedido, pedido[i].quanti, pedido[i].valorTotal);
    }
    
    fclose(fp);
}
