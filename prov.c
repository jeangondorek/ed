#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tpoint
{
    int x,y;
    struct tpoint *next, *prev;
};

struct tsent
{
    struct tpoint *first;
    struct tpoint *last;    
};

typedef struct tpoint point;
typedef struct tsent sentinela;

//usando itens elencados na prova

// #1
sentinela *intersec(S *s1, S *s2){
    sentinela *s3 = malloc(sizeof(S));
    s3-> last = NULL;
    s3-> first = NULL;
    point *aux1, *aux2, *new;
    for (aux1 = s1->first; aux1!=NULL; aux1 = aux1->next)
    {
        for (aux2 = s2 -> first; aux2!=NULL; aux2=aux2->next)
        {
            if (aux1->x == aux2->x && aux1->y == aux2->y)
            {
                new = malloc(sizeof(point));
                new->next = NULL;
                new->prev = NULL;
                new->x=aux1->x;
                new->y=aux1->y;
                if (s3->first == NULL)
                {
                    s3->first = new;
                    s3->last = new;
                }
                else{
                    s3->last->next = new;
                    mew->prev = s3->last;
                    s3->last=new;
                }
                
            }
        }
    }
    return s3;
}

// #2
void *deletePoint(sentinela *s, int x, int y){
    point *aux, *previous;
    aux = s->first;
    while (aux!=NULL)
    {
        previous = aux->prev;
        if (aux-> == x && aux->y ==y)
        {
            if (s->first == aux)
            {
                s->first = s->first->next;
                if (s->first !=NULL)
                {
                    s->first->prev = NULL;
                }
                else{
                    s->last = NULL;
                    free(aux);
                    break;
                }
            }
            else if (s->last == aux)
            {
                s->last = s->last->prev;
                s->last-> next= NULL;
                free(aux);
                break;
            }
            else
            {
                previous->next = aux->next;
                aux->next->prev = previous;
            }
            free(aux);
            if (previous == NULL)
            {
                aux = s->fist;
                continue;
            }
            else
            {
                aux = previous;
            }
        }
        aux = aux->next;
    }
}