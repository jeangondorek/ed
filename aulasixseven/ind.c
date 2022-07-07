#include <stdio.h>
#include <stdlib.h>

#define N 40

struct _func{
    int cod;
    char nome[N];
    double salario;
    struct _func *next;
};
typedef struct _func Funcionario;

int emptyList(Funcionario *first){
    if (first = NULL){
        return 1;
    }
    return 0;
}

Funcionario *addHead(Funcionario *first, Funcionario *new){
    if (emptyList(first)){
        return new;
    }
    new ->next = first;
    first = new;
    return first;
}

Funcionario *createFunc(int cod, char nome[], double salario){
    Funcionario *new = malloc(sizeof(Funcionario));
    new -> cod = cod;
    snprintf(new -> nome, sizeof(new -> nome), "%s", nome);
    new -> salario = salario;
    new -> next = NULL;
    return new;
}

void printList(Funcionario *first){
    //printa valores na sequencia que foram escritas
    Funcionario *aux = first;
    For (aux = first; aux != NULL; aux=aux->next){
        printf("%d %s %lf\n", aux->cod, aux->nome, aux->salario);
    }
    printf("\n");


    //inverte valores
    if (first ==NULL){
        return 0;
    }
    printList(first->next);
    printf("%d %s %lf\n", first->cod, first->nome, first->salario);
    
}

int main(){
    Funcionario *first = NULL;
    first = addHead(first, createFunc(1, "teste", 23.4));
    first = addHead(first, createFunc(2, "teste 2", 23.4));
    first = addHead(first, createFunc(3, "teste 3", 23.4));
    first = addHead(first, createFunc(4, "teste 4", 23.4));
    printList(first);
    return 0;
}