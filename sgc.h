#ifndef SGC_H
#define SGC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME_PROD 900
#define MAX_NOME_USER 900
#define MAX_TAM_SENHA 900
#define MAX_PRODUTOS 100
#define MAX_USUARIOS 100

struct Produto {
    char nomeProd[MAX_NOME_PROD];
    float preco;
    int quantidade;
    int idProd;
};

struct Usuario {
    int idUser;
    char nomeUser[MAX_NOME_USER];
    char senha[MAX_TAM_SENHA];
};

struct Administrador {
    int idAdmin;
    char nomeAdmin[MAX_NOME_USER];
    char senhaAdmin[MAX_TAM_SENHA];
};

struct Pedido{
    int idPedido;
    int quanti;
    float valorTotal;
};


/*Funções para o escopo dos usuários do tipo administrador*/

void interageAdmin(struct Produto *produto, struct Usuario *usuario, int *tamanho, int tam);
void adicionarProduto(struct Produto *produto, int *tamanho);
void listarProdutos(struct Produto *produto, int tamanho);
void adicionarAdministrador(struct Administrador *admin, int tam);
void excluirAdministrador(struct Administrador *admin, int tam);
void controleMenuAdmin(struct Administrador *admin, struct Usuario *usuario, struct Produto *produto, int tentativas, int chances, int tam);
void adicionarUsuario(struct Usuario *usuario, int *tam);
void excluirUsuario(struct Usuario *usuario, int *tam);
void listarUsuarios(struct Usuario *usuario, int tam);
void salvarUsuarios(struct Usuario *usuario, int *tam);
void salvarProdutos(struct Produto *produto, int *tamanho);

/*Funções para o escopo dos usuários do tipo convencional*/

void controleMenuUsuario(struct Produto *produto, struct Usuario *usuario, int tamanho, int tam);
void interageUsuario(struct Produto *produto, struct Usuario *usuario, int *tamanho, int tam);
void fazerPedidos(struct Produto *produto, struct Pedido *pedido, int *tamanho, int *tamPedido);
void listaPedidos(struct Pedido *pedido, int tamPedido);
void salvarPedidos(struct Pedido *pedido, int *tamPedido);

#endif