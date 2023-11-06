#include "sgc.h"

void interageAdmin(struct Produto *produto, struct Usuario *usuario, int *tamanho, int *tam) {
    int opcao, chances = 3, tentativas = 0;
    struct Pedido *pedido;
    int *tamPedido = 0;

    printf("****************************************************************\n");
    printf("        Bem-vindo(a) ao supermercado Sonata das Compras         \n");
    printf("                PÁGINA DO ADMINISTRADOR                         \n");
    printf("Bem-vindo(a), caro(a) administrador(a)\n");

    do {
        printf("        CONTROLE DE ACESSO E PRIVILÉGIO         \n");
        printf(" (1) Adicionar produto\n");
        printf(" (2) Listar produtos no estoque\n");
        printf(" (3) Adicionar usuário\n");
        printf(" (4) Listar usuários  \n");
        printf(" (5) Excluir usuário\n");
        printf(" (6) Ceder espaço ao usuário:\n");
        printf(" (7) Ceder espaço ao outro administrador:\n");
        printf(" (8) Encerrar aplicação\n");

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
                listarUsuarios(usuario, *tam);
                break;
            case 5:
                excluirUsuario(usuario, tam);
                break;
            case 6:
                controleMenuUsuario(produto, usuario, *tamanho, *tam);
                break;
            case 7:
                controleMenuAdmin(usuario, produto, tentativas, chances, tam);
                break;
            case 8:
                printf("Foi um prazer sua interação comigo, até logo!\n");
                exit(1);
                break;
            default:
                printf("Alternativa impossível!\n");
                break;
        }
    } while (opcao != 6);
}

void adicionarProduto(struct Produto *produto, int *tamanho) {
    struct Produto produtoAdic;

    produtoAdic.nomeProd == (char *)malloc(MAX_NOME_PROD * sizeof(char));

    if (produtoAdic.nomeProd == NULL) {
        printf("Não há memória disponível.\n");
        exit(1);
    }

    printf("Solicitando operação para realizar adição de produto ao estoque.\n");

    printf("Digite o nome do produto:");
    scanf(" %[^\n]s", produtoAdic.nomeProd);

    printf("Digite a quantidade em estoque:");
    scanf("%d", &produtoAdic.quantidade);

    printf("Digite o preço unitário:");
    scanf("%f", &produtoAdic.preco);
    
    printf("Digite o id do produto:");
    scanf("%d", &produtoAdic.idProd);

    produto[(*tamanho)++] = produtoAdic;
    
    printf("Adição de produto realizada com sucesso.\n");
    
    salvarProdutos(produto, tamanho);
    
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

void adicionarUsuario( struct Usuario *usuario, int *tam) {
    struct Usuario usuarioAdic;

    usuarioAdic.nomeUser == (char *)malloc(MAX_NOME_USER * sizeof(char));

    int escolha;

    if (usuarioAdic.nomeUser == NULL){
        printf("Erro na alocação de memória.\n");
    }

    printf("Solicitando operação para realizar cadastro de usuário.\n");
    
    printf("Escolha o tipo de usuário:\n (1) ADMINISTRADOR\n (2) CONVENCIONAL\n");
    scanf("%d", &escolha);
    
    if (escolha == 1){
        usuarioAdic.tipo = 1;
    }
    else if (escolha == 2){
        usuarioAdic.tipo = 2;
    }
    else{
        printf("Escolha impossível.\n");
    }
    printf("Digite o nome do usuário:");
    scanf(" %[^\n]s", usuarioAdic.nomeUser);

    printf("Digite a senha de acesso desse usuário:");
    scanf(" %[^\n]s", usuarioAdic.senha);

    
    printf("Digite o id desse usuário:");
    scanf("%d", &usuarioAdic.idUser);
    
    usuario[(*tam)++] = usuarioAdic;
    
    printf("Processo de cadastro de usuário no sistema realizado com sucesso.\n");
    printf("\n");
    printf("*********************COMPROVANTE***********************\n");
    printf("        > Id do usuário : %d\n ", usuarioAdic.idUser);
    printf("       > Nome : %s\n", usuarioAdic.nomeUser);
    printf("        > Senha : %s \n", usuarioAdic.senha);
    if (usuarioAdic.tipo == 1){
        printf("       > ADMINISTRADOR\n");
    }
    else if (usuarioAdic.tipo == 2){
        printf("       > CONVENCIONAL\n");
    }
    printf("************************************************\n");
    
    salvarUsuarios(usuario, tam);
}

void excluirUsuario(struct Usuario *usuario, int *tam) {
    int id, usuarioEncontrado = 0;
    
    printf("Digite o identificador do usuário a ser excluído:\n");
    scanf("%d", &id);
    
    for (int i = 0; i < *tam; i++) {
        if (id == usuario[i].idUser) {
            printf("Usuário encontrado com os seguintes dados:\n");
            printf("        > Id do usuário : %d\n", usuario[i].idUser);
            printf("        > Nome : %s\n", usuario[i].nomeUser);
            printf("        > Senha : %s\n", usuario[i].senha);
            printf("        > Tipo: %s\n", usuario[i].tipo  ? "Administrador" : "Convencional");
            usuarioEncontrado = 1;
            
            for (int j = i; j < *tam - 1; j++) {
                usuario[j] = usuario[j + 1];
            }
            printf("Exclusão de usuário realizada com sucesso.\n");
            (*tam)--;
        }
    }
    
    if (!usuarioEncontrado) {
        printf("Usuário não encontrado.\n");
    }
}

void listarUsuarios(struct Usuario *usuario, int tam){
    if (tam > 0){
        printf("            LISTAGEM DE USUÁRIOS            \n");
        printf("-------------------------------------------------\n");
        for (int i = 0; i < tam; i++){
            printf("************************************************\n");
            printf("        > Id do usuário : %d\n", usuario[i].idUser);
            printf("        > Nome : %s\n", usuario[i].nomeUser);
            printf("        > Senha : %s\n", usuario[i].senha);
            printf("        >Tipo: %s\n", (usuario[i].tipo == 1) ? "Administrador" : "Convencional");
            printf("\n-----------------------------------------------\n");
        }
    }
    else{
        printf("Sem dados registrados.\n");
    }
}

void controleMenuAdmin(struct Usuario *usuario, struct Produto *produto, int tentativas, int chances, int *tam) { 

    int tamanho = 0, possibilidades = 3;
    printf("                    LOGIN                   \n");

    char nome[30];
    char senha[20];
    int acessou = 0;

    do {
        printf("Nome de usuário: ");
        scanf(" %[^\n]s", nome);
        printf("Senha: ");
        scanf(" %[^\n]s", senha);

        int administradorEncontrado = 0;
        for (int i = 0; i < *tam; i++) {
            if (strcmp(nome, usuario[i].nomeUser) == 0 && strcmp(senha, usuario[i].senha) == 0) {
                acessou = 1;
                administradorEncontrado = 1;
                interageAdmin(produto, usuario, &tamanho, tam);
                break;
            }
        }

        if (!administradorEncontrado) {
            possibilidades--;
            tentativas++;
            printf("Nome de usuário ou senha inválidos, ainda resta(m) mais %d chance(s).\n", possibilidades);
        }
    }
    while (tentativas < chances && !acessou);

    if (tentativas >= chances && !acessou) {
        printf("Tentativas de login fracassadas com sucesso, parabéns pela competência, até mais!\n");
        return;
    }
}
void salvarProdutos(struct Produto *produto, int *tamanho){
    FILE *fp;
    fp = fopen("estoque.txt", "w");
    
    if (fp == NULL) {
        printf("Erro na abertura do arquivo de usuários.\n");
        exit(1);
    }
    
    for (int i = 0; i < *tamanho; i++) {
        fprintf(fp, "Id : %d\n Descrição : %s\n Estoque: %d\n Preço unitário : %.2f\n", produto[i].idProd, produto[i].nomeProd, produto[i].quantidade, produto[i].preco);
    }
    
    fclose(fp);
}

void salvarUsuarios(struct Usuario *usuario, int *tam) {
    FILE *fp;
    fp = fopen("usuario.txt", "w");
    
    if (fp == NULL) {
        printf("Erro na abertura do arquivo de usuários.\n");
        exit(1);
    }
    
    for (int i = 0; i < *tam; i++) {
        fprintf(fp, "\nId : %d\n Nome : %s\n Senha : %s\n", usuario[i].idUser, usuario[i].nomeUser, usuario[i].senha);
    }
    
    fclose(fp);
}







