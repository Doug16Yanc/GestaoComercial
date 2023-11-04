#include "sgc.h"

void interageAdmin(struct Produto *produto, struct Usuario *usuario, int *tamanho, int tam) {
    struct Administrador *admin;
    int opcao;

    printf("****************************************************************\n");
    printf("                PÁGINA DO ADMINISTRADOR                         \n");
    printf("Bem-vindo(a), caro(a) administrador(a)\n");

    do {
        printf("Selecione sua alternativa:\n");
        printf(" (1) Adicionar produto\n");
        printf(" (2) Listar produtos no estoque\n");
        printf(" (3) Adicionar administrador\n");
        printf(" (4) Excluir administrador\n");
        printf(" (5) Adicionar usuário\n");
        printf(" (6) Listar usuários  \n");
        printf(" (7) Excluir usuário\n");
        printf(" (8) Retornar ao início\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(produto, tamanho);
                break;
            case 2:
                listarProdutos(produto, *tamanho);
                break;
            case 3:
                adicionarAdministrador(admin, tam);
                break;
            case 4:
                excluirAdministrador(admin, tam);
                break;
            case 5:
                adicionarUsuario(usuario, &tam);
                break;
            case 6:
                listarUsuarios(usuario, tam);
                break;
            case 7:
                excluirUsuario(usuario, &tam);
                break;
            case 8:
                printf("Retornando...\n");
                return;
                break;
            default:
                printf("Alternativa impossível!\n");
                break;
        }
    } while (opcao != 8);
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

void adicionarAdministrador(struct Administrador *admin, int tam){
    
    struct Administrador novoAdmin;

    printf("Digite o nome do novo administrador: ");
    scanf(" %[^\n]s", novoAdmin.nomeAdmin);

    printf("Digite a senha do novo administrador: ");
    scanf(" %[^\n]s", novoAdmin.senhaAdmin);

    printf("Digite o id do novo administrador:");
    scanf("%d", &novoAdmin.idAdmin);

    admin[tam++] = novoAdmin;

    printf("Novo administrador adicionado com sucesso.\n");
}

void excluirAdministrador(struct Administrador *admin, int tam) {
    int id, adminEncontrado = 0;

    printf("Digite o identificador do administrador a ser excluído:\n");
    scanf("%d", &id);

    for (int i = 0; i < tam; i++) {
        if (id == admin[i].idAdmin) {
            printf("Administrador encontrado com os seguintes dados:\n");
            printf(" > Id do administrador : %d\n", admin[i].idAdmin);
            printf(" > Nome : %s\n", admin[i].nomeAdmin);
            printf(" > Senha : %s\n", admin[i].senhaAdmin);
            adminEncontrado = 1;

            free(admin[i].nomeAdmin);
            free(admin[i].senhaAdmin);

            for (int j = i; j < tam - 1; j++) {
                admin[j] = admin[j + 1];
            }
            printf("Exclusão de administrador realizada com sucesso.\n");
            (tam)--;
        }
    }

    if (!adminEncontrado) {
        printf("Administrador não encontrado.\n");
    }
}

void controleMenuAdmin(struct Administrador *admin, struct Usuario *usuario, struct Produto *produto, int tentativas, int chances, int tam) { 

    int tamanho = 0, possibilidades = 3;
    printf("                    LOGIN                   \n");

    char nomeAdmin[30];
    char senhaAdmin[20];
    int acessou = 0;

    do {
        printf("Nome de usuário: ");
        scanf(" %[^\n]s", nomeAdmin);
        printf("Senha: ");
        scanf(" %[^\n]s", senhaAdmin);

        int administradorEncontrado = 0;
        for (int i = 0; i < tam; i++) {
            if (strcmp(nomeAdmin, admin[i].nomeAdmin) == 0 && strcmp(senhaAdmin, admin[i].senhaAdmin) == 0) {
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


void adicionarUsuario(struct Usuario *usuario, int *tam) {
    struct Usuario usuarioAdic;
    usuarioAdic.nomeUser == (char *)malloc(MAX_NOME_USER * sizeof(char));

    if (usuarioAdic.nomeUser == NULL){
        printf("Erro na alocação de memória.\n");
    }

    printf("Solicitando operação para realizar cadastro de usuário.\n");
    
    getchar();
    
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
    printf("        > Tipo de usuário : CONVENCIONAL\n");
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
            printf("        > Tipo de usuário : CONVENCIONAL\n");
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
            printf("        > Tipo de usuário : CONVENCIONAL\n");
            printf("\n-----------------------------------------------\n");
        }
    }
    else{
        printf("Não há ninguém aqui além do administrador máximo.\n");
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
        fprintf(fp, "%d %s %d %.2f\n", produto[i].idProd, produto[i].nomeProd, produto[i].quantidade, produto[i].preco);
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
        fprintf(fp, "%d %s %s\n", usuario[i].idUser, usuario[i].nomeUser, usuario[i].senha);
    }
    
    fclose(fp);
}



