#include "sgc.h"

int main(void) {
    struct Administrador admin[MAX_USUARIOS];
    struct Administrador novoAdmin;
    struct Usuario usuario[MAX_USUARIOS];
    int tam = 0;

    printf("*************************************************************\n");
    printf("Seja mais que bem-vindo(a) ao supermercado Sonata das Compras\n");
    printf("Faça o cadastro de um primeiro administrador:\n");
    printf("Digite o nome do novo administrador: ");
    scanf(" %[^\n]s", novoAdmin.nomeAdmin);

    printf("Digite a senha do novo administrador: ");
    scanf(" %[^\n]s", novoAdmin.senhaAdmin);

    printf("Digite o id do novo administrador:");
    scanf("%d", &novoAdmin.idAdmin);

    admin[tam++] = novoAdmin;

    printf("Novo administrador adicionado com sucesso.\n");

    int opcao, tamanho = 0, tentativas = 0, chances = 3;

    struct Produto produto[MAX_PRODUTOS];

    do {
        printf("        CONTROLE DE ACESSO E PRIVILÉGIO         \n");
        printf("  |      1 -  Administrador                     |\n");
        printf("  |      2 -  Usuário convencional              |\n");
        printf("  |      3 - Encerrar aplicação                 |\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                controleMenuAdmin(admin, usuario, produto, tentativas, chances, tam);
                break;
            case 2:
                controleMenuUsuario(produto, usuario, tamanho, tam);
                break;
            case 3:
                printf("Agradeço por sua interação comigo, até logo!\n");
                exit(1);
            default:
                printf("Opção inexistente, escolha 1, 2 ou 3.\n");
                break;
        }
    } while (opcao != 3);
    
    return 0;
}






