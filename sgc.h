
#ifndef SGC_H
#define SGC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME_PROD 900
#define MAX_NOME_USER 900
#define MAX_TAM_SENHA 900
#define MAX_PRODUTOS 100

enum TipoUsuario {
    ADMINISTRADOR, CONVENCIONAL
};

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
    enum TipoUsuario tipoUsuario;
};

/*Funções para o escopo principal*/

void saudaUsuario();
void mostraMenu();
void geraInteracao();
void controleMenuAdmin(struct Usuario *usuario, struct Produto *produto, int tentativas, int chances);
void controleMenuUsuario(struct Produto *produto, struct Usuario *usuario, int tamanho, int *tam);

/*Funções para o escopo dos usuários do tipo administrador*/

void interageAdmin(struct Produto *produto, struct Usuario *usuario, int *tamanho, int *tam);
void adicionarProduto(struct Produto *produto, int *tamanho);
void listarProdutos(struct Produto *produto, int tamanho);
void adicionarUsuario(struct Usuario *usuario, int *tam);
void excluirUsuario(struct Usuario *usuario, int *tam);
void carregarDados(struct Produto *produto, int *tamanho, struct Usuario *usuario, int *tam);

/*Funções para o escopo dos usuários do tipo convencional*/

void interageUsuario(struct Produto *produto, struct Usuario *usuario, int *tamanho, int *tam);
void fazerPedidos(struct Produto *produto, int *tamanho);
void listaPedidos();

#endif