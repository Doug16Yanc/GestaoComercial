#include "sgc.h"

/*Há um superadministrador do sistema que é validado de forma pioneira e, então, ele faz a gestão de todo o
sistema e seus usuários.*/

int main(void) {
    struct Usuario usuario[MAX_USUARIOS];
    struct Produto produto[MAX_PRODUTOS];
    int tamanho = 0;
    struct SuperAdmin *admin = (struct SuperAdmin *)malloc(sizeof(struct SuperAdmin));
    strcpy(admin[0].nomeAdmin, "Dooglahss");        /*A pronúncia do meu nome em alemão, por favor, não ligue para isso*/
    strcpy(admin[0].senhaAdmin, "2222");
    struct Usuario usuarioAdic;
    int tam = 0;
    char nome[90];
    char senha[90];
    
    if (admin == NULL){
        printf("Não há memória disponível.\n");
        exit(1);
    }
    
    printf("*************************************************************\n");
    printf("Sistema de gestão comercial protegido por autenticação através de nome e senha do administrador máximo.\n");
    printf("Nome:: ");
    scanf(" %[^\n]s", nome);
    printf("Senha: ");
    scanf(" %[^\n]s", senha);
    
    if (strcmp(nome, admin[0].nomeAdmin) == 0 && strcmp(senha, admin[0].senhaAdmin) == 0) {
        interageAdmin(produto, usuario, &tamanho, &tam);  
        free(admin);
                                                                    /*Após autenticação correta, seguir para as
                                                                    devidas funções administrativas*/
    }
    else{
        printf("Administrador máximo não reconhecido. Encerrando...\n");
        exit(1);            /*Se errar nome ou senha, só havia uma chance, portanto, sistema encerra*/
    }
    /*O administrador ao adicionar um usuário do tipo ADMINISTRADOR e ao escolher a opção de ceder espaço
    ao outro administrador há solicitação de login e senha. Ao adicionar um usuário do tipo CONVENCIONAL,
    a página do USUÁRIO é exibida diretamente para o usuário que foi cadastrado em última instância após retorno
    à página do ADMINISTRADOR ou, no caso de nenhum usuário do tipo CONVENCIONAL ter sido cadastrado, o ADMINISTRADOR 
    em instância acessa essa página e há permissão já que houve login e senha anteriormente.*/
        
    return 0;
}

/*Nunca usei tanto ponteiro em toda minha vida*/
