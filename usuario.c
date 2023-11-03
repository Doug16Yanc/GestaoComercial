#include "sgc.h"

void interageUsuario(struct Produto *produto, struct Usuario *usuario, int *tamanho, int *tam){
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
                fazerPedidos(produto, tamanho);
                break;
            case 2:
                listarProdutos(produto, *tamanho);
                break;
            case 3:
                listaPedidos();
                break;
            case 4:
                printf("Retornando...\n");
                mostraMenu();
                break;
            default:
                printf("Alternativa impossível.\n");
                break;
                
        }

    }
    while(opcao != 4);
}

void fazerPedidos(struct Produto *produto, int *tamanho){
    
}
void listaPedidos(){
    
}
