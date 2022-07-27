#include <stdio.h>
#include <stdlib.h>

struct dllist{
  int data;
  struct dllist *prev, *next;
}; 
typedef struct dllist dlist;

// display the list in a forward manner
void printForw(dlist *p)
{
   dlist *plist;
   if (p==NULL)
   {
      printf("Empty List!\n");
      return;
   }
   for (plist=p;plist!=NULL;plist=plist->next)
      printf("Data: %d\n",plist->data);
}
// 
void printListR(dlist *p, int direction)
{
  if (p==NULL) return; // condição parada
  printf("Data: %d\n",p->data);
  if (direction==1)
      printListR(p->next,direction);
 else
      printListR(p->prev,direction);
}
// display the list in a backward manner
void printBack(dlist *p)
{
   dlist *plist;
   if (p==NULL)
   {
      printf("Empty List!\n");
      return;
   }
   for (plist=p;plist!=NULL;plist=plist->prev)
      printf("Data: %d\n",plist->data);
}
//
void clearList(dlist *dl)
{
	dlist *p=dl, *prev;
	while (p!=NULL)
	{
		prev=p;
		p=p->next;
		free(prev);
	}
}
// search for a key in the list
dlist *getAddressKey(int key, dlist *h)
{  
	dlist *dl=h;
	while (dl!=NULL && dl->data!=key)
	    dl=dl->next;
	if (dl==NULL)
	{
		printf("Key: %d not found!\n",key);
		return NULL;
	}
	return dl; // address of the key element
}
// to delete
void Test()
{
	dlist *dl,*head=NULL, *tail=NULL;
  printListR(head,1);
	printListR(tail,2);
	dl=(dlist *) malloc(sizeof(dlist));
	dl->data=10;
	dl->next=NULL;
	dl->prev=NULL;
	head=dl;
	tail=dl;
	dl=(dlist *) malloc(sizeof(dlist));
	dl->data=20;
	dl->prev=tail;
	dl->next=NULL;
	tail->next=dl;
	tail=dl;
	printListR(head,1);
	printListR(tail,2);
}
//
//****************
//**************** BEGIN: functions with double pointer (pointer to pointer)
//**************** 
void insertListEnd(int key, dlist **h, dlist **t)
{
	dlist *dl;
	dl=(dlist *)malloc(sizeof(dlist));
	dl->data=key;
	dl->next=NULL;
	dl->prev=NULL;
	if (*h==NULL) // list is empty
	{
		*h=dl;
		*t=dl;
		return;
	}
	(*t)->next=dl;
	dl->prev=*t;
	*t=dl;
}
// key -> new item    keybefore -> the new item must be inserted before this value
void insertListMiddle(int key, int keybefore, dlist **h, dlist **t)
{
	dlist *dl, *after;
	after=getAddressKey(keybefore,*h);
	if (after==NULL)
	   return;
	dl=(dlist *)malloc(sizeof(dlist));
	dl->data=key;
	dl->next=NULL;
	dl->prev=NULL;
	if (after==*h) // the new key will be the head
	{
		(*h)->prev=dl;
		dl->next=*h;
		*h=dl;
		return;
    }
    dl->prev=after->prev;
    dl->next=after;
    after->prev->next=dl;
    after->prev=dl;
}
//****************
//**************** BEGIN: functions with simple pointer
//**************** 
// Inserting withou double pointer (alert: gambiarra)
// We need to find the last element in the list to update tail
dlist *getLast(dlist *dl)
{
	dlist *p=dl;
	while (p->next!=NULL)
	   p=p->next;
	return p;
}
// we do not to pass tail as parameter
dlist *insertListEnd2(int key, dlist *h)
{
	dlist *dl, *t;
	dl=(dlist *)malloc(sizeof(dlist));
	dl->data=key;
	dl->next=NULL;
	dl->prev=NULL;
	if (h==NULL) // list is empty
	{
		h=dl;
		return h;
	}
	t=getLast(h); // but we have to find its address
	t->next=dl;
	dl->prev=t;
	return h;
}
//
// key -> new item    keybefore -> the new item must be inserted before this value
dlist *insertListMiddle2(int key, int keybefore, dlist *h)
{
	dlist *dl, *after;
	after=getAddressKey(keybefore,h);
	if (after==NULL)
	   return h;
	dl=(dlist *)malloc(sizeof(dlist));
	dl->data=key;
	dl->next=NULL;
	dl->prev=NULL;
	if (after==h) // the new key will be the head
	{
		h->prev=dl;
		dl->next=h;
		h=dl;
		return h;
    }
    dl->prev=after->prev;
    dl->next=after;
    after->prev->next=dl;
    after->prev=dl;
    return h;
}

//
int main()
{
	 //Test();
    dlist *head=NULL, *tail=NULL;
	// using double pointer (no gambiarra)
    //insertListEnd(10,&head,&tail);
    //insertListEnd(20,&head,&tail);
    //insertListEnd(30,&head,&tail);
    //insertListMiddle(15,20,&head,&tail);
    //insertListMiddle(5,10,&head,&tail);
    //insertListMiddle(25,30,&head,&tail);
    //insertListMiddle(100,50,&head,&tail);
    //printForw(head);
    //printf("-----------\n");
    //printBack(tail);
    //printf("-----------\n");
    //clearList(head);
    // using simple pointer (we need getLast function to find the last element)
    head=NULL;
    tail=NULL;
    head=insertListEnd2(10,head);
    tail=getLast(head);
    head=insertListEnd2(20,head);
    tail=getLast(head);
    head=insertListEnd2(30,head);
    tail=getLast(head);
    insertListMiddle2(15,20,head);
    tail=getLast(head);
    head=insertListMiddle2(5,10,head);
    tail=getLast(head);
    insertListMiddle2(25,30,head);
    tail=getLast(head);
    head=insertListMiddle2(100,50,head);
    tail=getLast(head);
    printListR(head,1);
    printf("-----------\n");
    printListR(tail,2);
    printf("-----------\n");
//
    return 0;	
}
 