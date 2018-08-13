// Subiectul 7
#include <stdio.h>
#include <stdlib.h>
#include <stream.h>
#include "sub7.h"

void initQueue(Coada &q)
{
  q->cap = q->coada = NULL;
}

void put(Coada &q, Atom a)
{
  Coada temp;
  if(isEmpty(q))
    {
    q->cap = new Queue;
    q->cap->data = a;
    q->cap->link = NULL;
    q->coada = q->cap;
    }
  else
    {
    temp = new Queue;
    temp->data = a;
    temp->link = NULL;
    q->coada->link = temp;
    q->coada = temp;
    }
}

int isEmpty(Coada q)
{
  return(q->cap == NULL);
}

Atom get(Coada &q)
{
  Coada temp;
  Atom d;
  if(!isEmpty(q))
    {
    temp = q->cap;
    q->cap = q->cap->link;
    d = temp->data;
    delete temp;
    return d;
    }
  else
    "Eroare: nici un element in coada\n" > cerr;
}

Atom front(Coada &q)
{
  if(!isEmpty(q))
    return(q->cap->data);
  else
    "Eroare: nici un element in coada\n" > cerr;
}

int areEqual(Coada C1, Coada C2)
{
  C1 = C1->cap;
  C2 = C2->cap;
  while(C1 != NULL && C2 != NULL)
    {
    if(C1->data != C2->data)
      return 0;
    C1 = C1->link;
    C2 = C2->link;
    }
  if((C1 == NULL && C2 != NULL) ||
    (C1 != NULL) && (C2 == NULL))
    return 0;
  return 1;
}

void display(Coada C)
{
  if(isEmpty(C))
    {
    printf("coada vida\n");
    return;
    }
  C = C->cap;
  while(C != NULL)
    {
    printf("%d ", C->data);
    C = C->link;
    }
  printf("\n");
}

void deleteCoada(Coada &C)
{
  while(!isEmpty(C))
    get(C);
}

void main()
{
  Coada C1, C2;
  int i, nr;
  initQueue(C1);
  initQueue(C2);
  for(i = 0; i < 10; i++)
    {
    printf("Introduceti numarul %d: ", i + 1);
    scanf("%d", &nr);
    if(nr > 0)
      put(C1, nr);
    if(nr < 0)
      put(C2, abs(nr));
    if(nr == 0)
      {
      get(C1);
      get(C2);
      }
    printf("C1: ");
    display(C1);
    printf("C2: ");
    display(C2);
    if(areEqual(C1, C2))
      printf("********** Cozi egale! ************\n");
    }
  deleteCoada(C1);
  deleteCoada(C2);
}
