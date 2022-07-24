#include<stdio.h>
#include<stdlib.h>

#define N 40

//asfas
struct _func {
    int cod;
    char nome[N];
    double salario;
    struct _func *next;
};
typedef struct _func Funcionario;

int emptyList(Funcionario *first){
    if (first == NULL)
        return 1;
    return 0;
}

/*
    Adiciona um elemento antes do primeiro.
*/
Funcionario *addHead(Funcionario *first, Funcionario *new){
    if (emptyList(first)){
        return new;
    }

    new->next = first;
    first = new;

    return first;
}

Funcionario *createFunc (int cod, char nome[], double salario ){
    Funcionario *new = malloc(sizeof(Funcionario));
    new->cod = cod;
    snprintf(new->nome, sizeof(new->nome), "%s", nome);
    //strcpy(new->nome, nome);
    new->salario = salario;
    new->next = NULL;

    return new;
}

void printList(Funcionario *first){
    Funcionario *aux;

    for (aux = first; aux != NULL; aux=aux->next){
        printf("%d %s %lf\n", aux->cod, aux->nome, aux->salario);
    }
    printf("\n");
}


int main(){

    Funcionario *first = NULL;

    first = addHead(first, createFunc(1, "Teste", 23.4));
    first = addHead(first, createFunc(2, "Teste 2", 23.4));
    first = addHead(first, createFunc(3, "Teste 3", 23.4));
    first = addHead(first, createFunc(4  ,"Maria", 23.4));

    printList(first);
    
    return 0;
}