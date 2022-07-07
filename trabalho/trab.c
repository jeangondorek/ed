#include <stdio.h>
#include <stdlib.h>

#define N 40
#define M 10

struct _data{
    int dia;
    int mes;
    int ano;
}; typedef struct _data Data;

struct _aluno{
    char matricula[M];
    char nome[N];
    struct Data;
    float media;
    struct _aluno *next;
}; typedef struct _aluno Aluno;

int emptyList(Aluno *first){
    if (first == NULL)
        return 1;
    return 0;
}

Aluno *addHead(Aluno *first, Aluno *new){
    if (emptyList(first)){
        return new;
    }

    new->next = first;
    first = new;

    return first;
}

Aluno *createAluno (char matricula[], char nome[], int dia, int mes, int ano ,float media){
    Aluno *new = malloc(sizeof(Aluno));
    Data *dat = malloc(sizeof(Data));
    snprintf(new->matricula, sizeof(new->matricula), "%s", matricula);
    snprintf(new->nome, sizeof(new->nome), "%s", nome);
    dat->dia = dia;
    dat->mes = mes;
    dat->ano = ano;
    new->media = media;
    new->next = NULL;
    return new;
}

Data *createData (int dia, int mes, int ano){
    Data *Data = malloc(sizeof(Data));
    Data->dia = dia;
    Data->mes = mes;
    Data->ano = ano;
    return Data;
}

void printList(Aluno *first){
    Aluno *aux;
    Data *dat;
    for (aux = first; aux != NULL; aux=aux->next){
        printf("%s\n%s\n%d/%d/%d\n%lf\n", aux->matricula, aux->nome, dat->dia, dat->mes,dat->ano, aux->media );
    }
    printf("\n");
}



int main(){

    Aluno *first = NULL;

    first = addHead(first, createAluno("asf1", "Teste", 5,10,1999 ,5648));
    first = addHead(first, createAluno("asf2", "Teste 2", 22,2,2011,23.4));
    first = addHead(first, createAluno("asf3", "Teste 3", 5,4,2021 ,23.4));
    first = addHead(first, createAluno("asf4"  ,"Maria", 5,5,1547 ,23.4));

    printList(first);

    return 0;
}