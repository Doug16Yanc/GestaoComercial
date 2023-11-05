#include "sgc.h"

int main(void) {
    struct Usuario usuario[MAX_USUARIOS];
    struct Produto produto[MAX_PRODUTOS];
    int tamanho = 0;
    struct SuperAdmin *admin = (struct SuperAdmin *)malloc(sizeof(struct SuperAdmin));
    strcpy(admin[0].nomeAdmin, "Dooglahss");
    strcpy(admin[0].senhaAdmin, "2222");
    struct Usuario usuarioAdic;
    int tam = 0;
    char nome[90];
    char senha[90];

    printf("*************************************************************\n");
     printf("Nome:: ");
    scanf(" %[^\n]s", nome);
    printf("Senha: ");
    scanf(" %[^\n]s", senha);
    
    if (strcmp(nome, admin[0].nomeAdmin) == 0 && strcmp(senha, admin[0].senhaAdmin) == 0) {
        interageAdmin(produto, usuario, &tamanho, tam);
    }
    else{
        printf("Administrador máximo não reconhecido. Encerrando...\n");
        exit(1);
    }
        
    return 0;
}









