#include<stdio.h>
#include<stdlib.h>

#define N 40

struct _linked{
    int dia;
    int mes;
    int ano;
    struct _linked *next;    
}; typedef struct _linked Linked;

struct _func{
    int id;
    char nome[N];
    double salario;
    struct _func *next;
}; typedef struct _func Func;




int main(){

    return 0;
}