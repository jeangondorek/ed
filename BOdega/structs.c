#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//empresa
typedef struct Empresa{
    char nome[40];
    int cnpj;
}empresa;

//bebidas
typedef struct Bebida{
    int codigo;
    int quantidadeEstoque;
    char nome[40];
    float conteudoMl;
    float valor;
    float teorAlcoolico;
    struct bebida *anterior, *proximo;
}bebida;

typedef struct SentinelaBebida{
    bebida *primeiro, *ultimo;
}sentinelaBebida;

//clientes
typedef struct Cliente{
    int codigo, cpf, idade, inadimplente;
    char nome[40];
    struct Cliente *anterior, *proximo;
}cliente;

typedef struct SentinelaCliente{
    cliente *primeiro, *ultimo;
}sentinelaCliente;

//função de inicialização de structs
void iniciarSentinelas(sentinelaBebida *sBebida, sentinelaCliente *sCliente){
    sBebida->primeiro = NULL;
    
    sBebida->ultimo = NULL;

    sCliente->primeiro = NULL;
    sCliente->ultimo = NULL;
}