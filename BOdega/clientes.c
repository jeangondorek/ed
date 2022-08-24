#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.c"

int retornaIdadeCliente(sentinelaCliente *sCliente, int cpf){
    cliente *aux;
    for(aux = sCliente->primeiro; aux != NULL; aux = aux->proximo){
        if (aux->cpf == cpf){
            return aux->idade;
        }
    }
}

int verificaExisteCliente(sentinelaCliente *sCliente, int cpf){
    cliente *aux;
    if (sCliente->primeiro == NULL){
        return 0;
    }
    for(aux = sCliente->primeiro; aux != NULL; aux = aux->proximo){
        if (aux->cpf == cpf){
            return 1;
        }
    }
    return 0;
}

void cadastrarCliente(sentinelaCliente *sCliente){
    cliente *custumer, *aux;
    custumer = (cliente *)malloc(sizeof(cliente));

    printf("----Cadastro de Clientes----\n");
    printf("Código: ");
    scanf("%d", &custumer->codigo);
    printf("Nome cliente: ");
    scanf("%s", custumer->nome);
    printf("CPF: (Apenas números)");
    scanf("%d", &custumer->cpf);
    
    if (verificaExisteCliente(sCliente, custumer->cpf) == 1){
        printf("Cliente Já Cadastrado!\n");
        return "";
    }
    printf("Idade: ");
    scanf("%d", &custumer->idade);
    custumer->inadimplente = 0;
    custumer->anterior = NULL;
    custumer->proximo = NULL;
    if (sCliente->primeiro == NULL || sCliente->ultimo == NULL){
        sCliente->primeiro = custumer;
        sCliente->ultimo = custumer;
    } else {
        for (aux = sCliente->primeiro; aux != NULL; aux = aux->proximo){
            if (aux->idade >= custumer->idade){
                if (aux == sCliente->primeiro){
                    sCliente->primeiro->anterior = custumer;
                    custumer->proximo = sCliente->primeiro;
                    sCliente->primeiro = custumer;
                    break;
                } else {
                    custumer->anterior = aux->anterior;
                    aux->anterior->proximo = custumer;
                    custumer->proximo = aux;
                    aux->anterior = custumer;
                    break;
                } 
            }
        }
        if (aux == NULL){
            custumer->anterior = sCliente->ultimo;            
            sCliente->ultimo->proximo = custumer;
            sCliente->ultimo = custumer;
        }
    }
}

void listarClientes(sentinelaCliente *sCliente){
    cliente *aux;
    printf("----Lista de clientes----\n");
    if (sCliente->primeiro == NULL || sCliente->ultimo == NULL){
        printf("Lista vazia!\n");
        return "";
    }
    for(aux = sCliente->primeiro; aux != NULL; aux = aux->proximo){
        printf("Código: %d\n", aux->codigo);
        printf("Nome: %s\n", aux->nome);
        printf("CPF: %d\n", aux->cpf);
        printf("Idade: %d\n", aux->idade);
        printf("Inadimplente: %d\n", aux->inadimplente);
        printf("-----------------------------------------------\n");
    }
}

void limparClientes(cliente *primeiro){
    if (primeiro == NULL){
        free(primeiro);  
    }else{
        limparClientes(primeiro->proximo);
        free(primeiro);
    }
}

void quitarDebitos(sentinelaCliente *sCliente){
    cliente *aux;
    int cpf;

    printf("Digite o CPF do devedor: ");
    scanf("%d", &cpf);

    if (verificaExisteCliente(sCliente, cpf) == 0){
        printf("CPF não cadastrado!\n");
        return "";
    }
    
    for(aux = sCliente->primeiro; aux != NULL; aux = aux->proximo){
        if (aux->cpf == cpf){
            if (aux->inadimplente == 0){
                printf("Cliente não possui pendências.\n");
            }
            
            aux->inadimplente = 0;

            printf("Débido quitado.\n");
        }
    }
}

void atualizaInadimplencia(sentinelaCliente *sCliente, int cpf){
    cliente *aux;

    for(aux = sCliente->primeiro; aux != NULL; aux = aux->proximo){
        if (aux->cpf == cpf){
            aux->inadimplente = 1;
        } 
    }
}

int retornaInadimplencia(sentinelaCliente *sCliente, int cpf){
    cliente *aux;

    for(aux = sCliente->primeiro; aux != NULL; aux = aux->proximo){
        if (aux->cpf == cpf){
            return aux->inadimplente;
        }
    }
}