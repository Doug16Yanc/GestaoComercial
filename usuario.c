#include "sgc.h"

void controleMenuUsuario(struct Produto *produto, struct Usuario *usuario, int tamanho, int tam) {
    struct Pedido *pedido = (struct Pedido *)malloc(sizeof(struct Pedido) * MAX_PEDIDOS); 
    if (pedido == NULL) {
        printf("Não há memória disponível.\n");
        exit(1);
    }

    interageUsuario(produto, pedido, usuario, &tamanho, tam);
    free(pedido);
}

void interageUsuario(struct Produto *produto, struct Pedido *pedido, struct Usuario *usuario, int *tamanho, int tam){
    int tamPedido = 0;

    int opcao;
    
    do{
        printf("                    PÁGINA DO USUÁRIO                   \n");
        printf("********************************************************\n");
        printf("        Bem-vindo(a) ao supermercado Sonata das Compras         \n");
        printf("* Bem-vindo(a), caríssimo(a), o que temos para hoje? *\n");
        printf("        (1) - Fazer pedidos           \n");
        printf("        (2) - Listar produtos         \n");
        printf("        (3) - Listar pedidos          \n");
        printf("        (4) - Cancelar pedidos        \n");
        printf("        (5) - Retornar ao início      \n");
        
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                fazerPedidos(produto, pedido, tamanho, &tamPedido);
                break;
            case 2:
                listarProdutos(produto, *tamanho);
                break;
            case 3:
                listaPedidos(pedido, tamPedido);
                break;
            case 4:
                cancelarPedidos(produto, pedido, tamanho, &tamPedido);
                break;
            case 5:
                printf("Retornando...\n");
                interageAdmin(produto, usuario, tamanho, &tam);
                break;
            default:
                printf("Alternativa impossível.\n");
                break;
                
        }

    }
    while(opcao != 5);
}

void fazerPedidos(struct Produto *produto, struct Pedido *pedido, int *tamanho, int *tamPedido){

    int determina, codigo = 0, produtoEncontrado = 0;
    
    printf("Solicitando operação para realizar pedidos...\n");
    
    if (*tamanho > 0){
        
        printf("Digite qualquer outro número para continuar ou -1 para encerrar:");
        scanf("%d", &determina);

        while(determina != -1){
            printf("Digite o id do produto ou a saída do programa com -1:\n");
            scanf("%d", &codigo);
            
            for (int i = 0; i < *tamanho; i++){
                if (codigo == produto[i].idProd){
                    printf("Digite a quantidade de %s : ", produto[i].nomeProd);
                    scanf("%d", &pedido[i].quanti);
                    produtoEncontrado = 1;
                    
                    if (pedido[i].quanti <= produto[i].quantidade){
                        printf("%d adicionado(a)(s) ao carrinho de compras.\n", pedido[i].quanti);
                        strcpy(pedido[*tamPedido].nomeProd, produto[i].nomeProd);
                        (pedido[*tamPedido].idProd = produto[i].idProd);
                        (pedido[*tamPedido].preco = produto[i].preco);
                        (*tamPedido)++;
                        produto[i].quantidade -= pedido[i].quanti;
                        pedido[i].valorTotal += pedido[i].quanti * produto[i].preco;
                        salvarPedidos(pedido, tamPedido);
                    }
                    else{
                        printf("Não há estoque suficiente dessa mercadoria.\n");
                    }
                }
            }
            if (!produtoEncontrado){
                printf("Id de produto não encontrado.\n");
            }
            printf("Digite qualquer outro número para continuar ou -1 para encerrar:");
            scanf("%d", &determina);
        }
    }
    else{
        printf("Sem estoque ainda.\n");
    }
}

void listaPedidos(struct Pedido *pedido, int tamPedido) {
    
    struct Produto *produto;
    struct Usuario *usuario;
    int tamanho, tam;
    
    if (tamPedido > 0){
        printf("Lista de Pedidos:\n");
        for (int i = 0; i < tamPedido; i++) {
            printf(" > Id do pedido: %d\n", i + 1);
            printf(" > Id do produto : %d \n", pedido[i].idProd);
            printf(" > Nome : %s \n", pedido[i].nomeProd);
            printf(" > Quantidade : %d\n", pedido[i].quanti);
            printf(" > Preço unitário : R$ %.2f\n", pedido[i].preco);
            printf(" > Preço total : R$ %.2f\n", pedido[i].valorTotal);
            printf("\n");
        }
    }
    else{
        printf("Sem pedidos feitos.\n");
    }
}

void cancelarPedidos(struct Produto *produto, struct Pedido *pedido, int *tamanho, int *tamPedido){
    int id;
    
    printf("Digite o id do produto a ser cancelado por pedido.\n");
    scanf("%d", &id);
    
    for (int i = 0; i < *tamanho; i++){
        if (id == produto[i].idProd){
            printf("Produto encontrado com os seguintes dados...\n");
            printf(" > Id do produto : %d \n", pedido[i].idProd);
            printf(" > Nome : %s \n", pedido[i].nomeProd);
            printf(" > Quantidade : %d\n", pedido[i].quanti);
            printf(" > Preço unitário : R$ %.2f\n", pedido[i].preco);
            printf(" > Preço total : R$ %.2f\n", pedido[i].valorTotal);
            printf("\n");
            (*tamPedido)--;
            produto[i].quantidade += pedido[i].quanti;
        }
    }
}

void salvarPedidos(struct Pedido *pedido, int *tamPedido) {
    FILE *fp;
    fp = fopen("pedido.txt", "w");
    
    if (fp == NULL) {
        printf("Erro na abertura do arquivo de pedidos.\n");
        exit(1);
    }
    
    for (int i = 0; i < *tamPedido; i++) {
        fprintf(fp, "Id do produto: %d\n Descrição : %s\n Quantidade : %d\n Preço unitário : %.2f\n Valor total : %.2f\n", pedido[i].idProd, pedido[i].nomeProd, pedido[i].quanti, pedido[i].preco, pedido[i].valorTotal);
    }
    
    fclose(fp);
}

