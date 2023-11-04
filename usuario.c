#include "sgc.h"

void controleMenuUsuario(struct Produto *produto, struct Usuario *usuario, int tamanho, int tam) {
    
    struct Pedido pedido;
    int id, acessou = 0, tentativas = 0, possibilidades = 3, chances = 3, usuarioEncontrado = 0;
    char senha[20];
    
    printf("Digite seu id :");
    scanf("%d", &id);
    
    for (int i = 0; i < tam; i++){
        if (id == usuario[i].idUser){
            printf("Usuário encontrado com sucesso!\n");
            usuarioEncontrado = 1;
        
            do {
                printf("Digite sua senha:");
                scanf("%s", senha);
            
                if (strcmp(senha, usuario[i].senha) == 0) {
                    acessou = 1;
                    interageUsuario(produto, usuario, &tamanho, tam);
                } else {
                    possibilidades--;
                    tentativas++;
                    printf("Senha inválida, ainda resta(m) mais %d chance(s).\n", possibilidades);
                }
            } 
            while (tentativas < chances && !acessou);
            
            if (tentativas >= chances && !acessou) {
                printf("Tentativas de login fracassadas com sucesso, parabéns pela competência, até mais!\n");
                return;
            }
        }
    }
    if (!usuarioEncontrado){
        printf("Usuário não encontrado.\n");
    }
    printf("\n");
    
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
                listaPedidos(pedido, tamPedido);
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
    
    int codigo, quant;
    
    printf("Solicitando operação para realizar pedidos...\n");
    
    if (*tamanho > 0){

        do{
            printf("Digite o id do produto ou a saída do programa com -1:\n");
            scanf("%d", &codigo);
            
            for (int i = 0; i < *tamanho; i++){
                if (codigo == produto[i].idProd){
                    printf("Digite a quantidade de %s : ", produto[i].nomeProd);
                    scanf("%d", &quant);
                    
                    if (quant <= produto[i].quantidade){
                        printf("%d adicionados(as) ao carrinho de compras.\n", quant);
                        pedido[(*tamPedido)++];
                        produto[i].quantidade -= quant;
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
        while(codigo != -1);
    }
    else{
        printf("Sem estoque ainda.\n");
    }
}

void listaPedidos(struct Pedido *pedido, int tamPedido) {
    printf("Lista de Pedidos:\n");
    for (int i = 0; i < tamPedido; i++) {
        printf("ID do Pedido: %d\n", pedido[i].idPedido);
        printf("\n");
        
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
        fprintf(fp, "%d %d %.2f\n", pedido[i].idPedido, pedido[i].quanti, pedido[i].valorTotal);
    }
    
    fclose(fp);
}

