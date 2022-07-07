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

Funcionario *addTail(Funcionario *first, Funcionario *new){
    Funcionario *aux;
    if (emptyList(first)){
        return new;
    }
    for (aux= first; aux->next != NULL; aux = aux->next);
    aux->next = new;
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
    if (first ==NULL){
        return;
    }
    printList(first->next);
    printf("%d %s %lf\n", first->cod, first->nome, first->salario);
    
}

Funcionario *insAfter(Funcionario *first, Funcionario *f, int id){
    Funcionario *aux;
    if (first == NULL){
        first = f;
        return first;
    }
    for (aux=first;aux->next!=NULL;aux=aux->next){
        if (aux->cod==id) break;
    }
    f->next=aux->next;
    aux->next=f;
    return first;
}

Funcionario *insBefore(Funcionario *first, Funcionario *f, int id){
    Funcionario *aux;
    if (first == NULL){
        first = f;
        return first;
    }
    for (aux=first;aux->next!=NULL;aux=aux->next){
        if (aux->cod==(id+1)) break;
    }
    f->next=aux->next;
    aux->next=f;
    return first;
}

int main(){
    Funcionario *first = NULL;
    first = addHead(first, createFunc(1, "teste", 23.4));
    first = addHead(first, createFunc(2, "teste 2", 23.4));
    first = addHead(first, createFunc(3, "teste 3", 23.4));
    first = addHead(first, createFunc(4, "teste 4", 23.4));
    first = addTail(first, createFunc(0, "asga 0", 23.4));
    first = insAfter(first, createFunc(8, "asga 8", 255.4), 2);
    first = insBefore(first, createFunc(9, "asga 9", 2635.4), 0);
    printList(first);
    return 0;
}