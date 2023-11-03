#include "sgc.h"

int main(void) {

    saudaUsuario();
    return 0;
}

void saudaUsuario() {
    
    printf("***********************************************\n");
    printf("Seja mais que bem-vindo(a) ao supermercado Sonata das Compras\n");
    mostraMenu();
}

void mostraMenu() {
    printf("        CONTROLE DE ACESSO E PRIVILÉGIO         \n");
    printf("  |      1 -  Administrador                     |\n");
    printf("  |      2 -  Usuário convencional              |\n");
    printf("  |      3 - Encerrar aplicação                 |\n");
    geraInteracao();
}

void geraInteracao() {
    
    int opcao, tamanho, tam, sairMenu = 0, tentativas = 0, chances = 3;

    struct Produto produto[MAX_PRODUTOS];
    struct Usuario *usuario = (struct Usuario *)malloc(sizeof(struct Usuario) * tam);
    strcpy(usuario[0].nomeUser, "Douglas");
    strcpy(usuario[0].senha, "1111");
    usuario[0].tipoUsuario = ADMINISTRADOR;

    do {
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                controleMenuAdmin(usuario, produto, tentativas, chances);
                break;
            case 2:
                controleMenuUsuario(produto, usuario, tamanho, &tam);
                break;
            case 3:
                printf("Agradeço por sua interação comigo, até logo!\n");
                exit(1);
            default:
                printf("Opção inexistente, só é possível optar por 1, 2 ou 3, caso seu cérebro de água-viva não consiga compreender.\n");
                break;
        }
        mostraMenu();
    } while (opcao != 3);
}

void controleMenuAdmin(struct Usuario *usuario, struct Produto *produto, int tentativas, int chances) {
    int tamanho = 0, tam = 0, possibilidades = 3;
    printf("                    LOGIN                   \n");

    char senha1[20];
    int acessou = 0;

    do {
        printf("Senha : ");
        scanf("%s", senha1);

        if (strcmp(senha1, usuario[0].senha) == 0) {
            acessou = 1;
            interageAdmin(produto, usuario, &tamanho, &tam);
        } 
        else {
            possibilidades--;
            tentativas++;
            printf("Senha inválida, ainda resta(m) mais %d chance(s).\n", possibilidades);
        }
    } while (tentativas < chances && !acessou);

    if (tentativas >= chances && !acessou) {
        printf("Tentativas de login fracassadas com sucesso, parabéns pela competência, até mais!\n");
        mostraMenu();
    }
}


void controleMenuUsuario(struct Produto *produto, struct Usuario *usuario, int tamanho, int *tam) {
    
    usuario = (struct Usuario *)malloc(sizeof(struct Usuario));

    int id, acessou = 0, tentativas = 0, possibilidades = 3, chances = 3, usuarioEncontrado = 0;
    char senha[20];
    
    if (*tam > 0){
        printf("Digite seu id :");
        scanf("%d", &id);
        
        for (int i = 0; i < *tam; i++){
            if (id == usuario[i].idUser){
                printf("Usuário encontrado com sucesso!\n");
                usuarioEncontrado = 1;
            
                do {
                    printf("Digite sua senha:");
                    scanf("%s", senha);
                
                    if (strcmp(senha, usuario[i].senha) == 0) {
                        acessou = 1;
                        interageUsuario(produto, usuario, &tamanho, tam);
                    }
                     else {
                        possibilidades--;
                        tentativas++;
                        printf("Senha inválida, ainda resta(m) mais %d chance(s).\n", possibilidades);
                    }
                } 
                while (tentativas < chances && !acessou);
                
                if (tentativas >= chances && !acessou) {
                    printf("Tentativas de login fracassadas com sucesso, parabéns pela competência, até mais!\n");
                    mostraMenu();
                }
            }
        }
        if (!usuarioEncontrado){
            printf("Usuário não encontrado.\n");
        }
        printf("\n");
    }
    else{
        printf("Não há mais ninguém aqui além do administrador máximo.\n");
    }
}
