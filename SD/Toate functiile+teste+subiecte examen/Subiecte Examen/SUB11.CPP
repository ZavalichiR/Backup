// Subiectul 11
#include <stdio.h>
#include "arbore.h"

void inordine(Nod *t)
{
  if(t != 0)
    {
    inordine(t->stg);
    printf("%c ", t->data);
    inordine(t->drt);
    }
}

typedef Nod *Atom;

struct Queue {
  Atom data;
  Queue *link;
};
struct Coada {
  Queue *tail, *head;
};

void init(Coada &coada)
{
  coada.tail = coada.head = NULL;
}

int isEmpty(Coada coada)
{
  return(coada.head == NULL);
}

void put(Coada &coada, Atom atom)
{
  Queue *p;
  p = new Queue;
  p->data = atom;
  p->link = NULL;
  if(coada.tail != NULL)
    coada.tail->link = p;
  else
    coada.head = p;
  coada.tail = p;
}

Atom get(Coada &coada)
{
  Atom retur;
  Queue *temp = NULL;
  if(!isEmpty(coada))
    {
    retur = coada.head->data;
    temp = coada.head;
    coada.head = coada.head->link;
    if(coada.head == NULL)
      coada.tail = NULL;
    delete temp;
    }
  return retur;
}

void afisCoada(Coada &coada)
{
  Nod *temp;
  while(!isEmpty(coada))
    {
    temp = get(coada);
    printf("%c ", temp->data);
    if(temp->stg != NULL)
      put(coada, temp->stg);
    if(temp->drt != NULL)
      put(coada, temp->drt);
    }
}

void nivele(Nod *rad)
{
  Coada coada;
  init(coada);
  put(coada, rad);
  afisCoada(coada);
}

void main()
{
  Nod *rad;
  rad = creareArbore();
  printf("Arborele in inordine:\n");
  inordine(rad);
  printf("\nArborele parcurs pe nivele: ");
  nivele(rad);
  printf("\n");
}
