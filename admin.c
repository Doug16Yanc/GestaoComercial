#include "sgc.h"

void interageAdmin(struct Produto *produto, struct Usuario *usuario, int *tamanho, int *tam) {
    int opcao;

    printf("********************************\n");
    printf("Bem-vindo(a), %s, caro(a) administrador(a)\n", usuario[0].nomeUser);

    do {
        printf("Selecione sua alternativa:\n");
        printf(" (1) Adicionar produto\n");
        printf(" (2) Listar produtos no estoque\n");
        printf(" (3) Adicionar usuário\n");
        printf(" (4) Excluir usuário\n");
        printf(" (5) Retornar ao início\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(produto, tamanho);
                break;
            case 2:
                listarProdutos(produto, *tamanho);
                break;
            case 3:
                adicionarUsuario(usuario, tam);
                break;
            case 4:
                excluirUsuario(usuario, tam);
                break;
            case 5:
                printf("Retornando...\n");
                mostraMenu();
                break;
            default:
                printf("Alternativa impossível!\n");
                break;
        }
    } while (opcao != 5);
}

void adicionarProduto(struct Produto *produto, int *tamanho) {
    struct Produto produtoAdic;

    produtoAdic.nomeProd == (char *)malloc(MAX_NOME_PROD * sizeof(char));

    if (produtoAdic.nomeProd == NULL) {
        printf("Não há memória disponível.\n");
        exit(1);
    }

    printf("Solicitando operação para realizar adição de produto ao estoque.\n");

    FILE *fp;
    
    fp = fopen("estoque.txt", "w");
    
    if (fp == NULL){
        printf("Erro na abertura de arquivo.\n");
        exit(1);
    }
    printf("Digite o nome do produto:");
    scanf(" %[^\n]s", produtoAdic.nomeProd);

    printf("Digite a quantidade em estoque:");
    scanf("%d", &produtoAdic.quantidade);

    printf("Digite o preço unitário:");
    scanf("%f", &produtoAdic.preco);
    
    printf("Digite o id do produto:");
    scanf("%d", &produtoAdic.idProd);

    produto[(*tamanho)++] = produtoAdic;
    
    fprintf(fp, "%d %s %.2f %d\n", produtoAdic.idProd, produtoAdic.nomeProd, produtoAdic.preco, produtoAdic.quantidade);

    fclose(fp);

    printf("Adição de produto realizada com sucesso.\n");
}

void listarProdutos(struct Produto *produto, int tamanho) {
  
    if (tamanho > 0){    
        printf("Lista de produtos no estoque\n");
        for (int i = 0; i < tamanho; i++) {
            printf(" > Id : %d \n", produto[i].idProd);
            printf(" > Nome : %s \n", produto[i].nomeProd);
            printf(" > Quantidade em estoque : %d\n", produto[i].quantidade);
            printf(" > Preço unitário : R$ %.2f\n", produto[i].preco);
            printf("\n");
        }
    }
    else{
        printf("Não há produtos no estoque.\n");
    }
   
}

void adicionarUsuario(struct Usuario *usuario, int *tam) {
    struct Usuario usuarioAdic;
    int escolha;
    usuarioAdic.nomeUser == (char *)malloc(MAX_NOME_USER * sizeof(char));

    if (usuarioAdic.nomeUser == NULL){
        printf("Erro na alocação de memória.\n");
    }

    printf("Solicitando operação para realizar cadastro de usuário.\n");

    FILE *fp;
    fp = fopen("usuario.txt", "w");
    
    if (fp == NULL){
        printf("Erro na abertura de arquivo.\n");
        exit(1);
    }
    
    getchar();
    
    printf("Digite o nome do usuário:");
    scanf(" %[^\n]s", usuarioAdic.nomeUser);

    printf("Digite a senha de acesso desse usuário:");
    scanf(" %[^\n]s", usuarioAdic.senha);

    printf("Qual o tipo de usuário? \n (1) ADMINISTRADOR\n (2) CONVENCIONAL \n");
    scanf("%d", &escolha);

    if (escolha == 1) {
        usuarioAdic.tipoUsuario = ADMINISTRADOR;
    } else if (escolha == 2) {
        usuarioAdic.tipoUsuario = CONVENCIONAL;
    } else {
        printf("Escolha impossível.\n");
        return;
    }   
    
    printf("Digite o id desse usuário:");
    scanf("%d", &usuarioAdic.idUser);

    fprintf(fp, "%d %s %s %d\n", usuarioAdic.idUser, usuarioAdic.nomeUser, usuarioAdic.senha, usuarioAdic.tipoUsuario);

    fclose(fp);
    
    usuario[(*tam)++] = usuarioAdic;

    printf("Processo de cadastro de usuário no sistema realizado com sucesso.\n");
    
    printf("*********************COMPROVANTE***********************\n");
    printf("        > Id do usuário : %d\n ", usuarioAdic.idUser);
    printf("      > Nome : %s\n", usuarioAdic.nomeUser);
    printf("        > Senha : %s \n", usuarioAdic.senha);
    if (usuarioAdic.tipoUsuario == ADMINISTRADOR) {
        printf("     > Tipo de usuário: ADMINISTRADOR\n");
    } 
    else if (usuarioAdic.tipoUsuario == CONVENCIONAL) {
        printf("     > Tipo de usuário: CONVENCIONAL\n");
    } 
    else {
        printf("> Tipo de usuário: Desconhecido\n");
    }
}

void excluirUsuario(struct Usuario *usuario, int *tam) {
    
}