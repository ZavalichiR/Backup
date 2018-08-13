// Subiectul 8
#include <stdio.h>
#include "glista.h"

void afisGLista(GLista lista)
{
  while(lista != NULL)
    {
    if(lista->tag == ATOM)
      printf("%c ", lista->data.A);
    else
      afisGLista(lista->data.L);
    lista = lista->link;
    }
}

Atom minim(GLista lista)
{
  char min, temp;
  if(lista == NULL)
    return 'Z';
  if(lista->tag == ATOM)
    min = lista->data.A;
  else
    min = minim(lista->data.L);
  lista = lista->link;
  while(lista != NULL)
    {
    if(lista->tag == ATOM)
      {
      if(lista->data.A < min)
        min = lista->data.A;
      }
    else
      {
      temp = minim(lista->data.L);
      if(temp < min)
        min = temp;
      }
    lista = lista->link;
    }
  return min;
}

int areEqual(GLista l1, GLista l2)
{
  if((l1 == NULL && l2 != NULL) || (l1 != NULL && l2 == NULL))
    return 0;
  if(l1 == NULL && l2 == NULL)
    return 1;
  while(l1 != NULL && l2 != NULL)
    {
    if(l1->tag == ATOM)
      {
      if(l2->tag != ATOM)
        return 0;
      if(l1->data.A != l2->data.A)
        return 0;
      }
    else
      if(!areEqual(l1->data.L, l2->data.L))
        return 0;
    if(l2->tag == ATOM)
      {
      if(l1->tag != ATOM)
        return 0;
      if(l1->data.A != l2->data.A)
        return 0;
      }
    else
      if(!areEqual(l1->data.L, l2->data.L))
        return 0;
    l1 = l1->link;
    l2 = l2->link;
    }
  return 1;
}

void main()
{
  GLista lista1, lista2;
  printf("Introduceti lista: ");
  lista1 = creareGLista();
  printf("Atomii: ");
  afisGLista(lista1);
  printf("\nCel mai mic: %c\n", minim(lista1));
  printf("Introduceti a doua lista: ");
  lista2 = creareGLista();
  if(areEqual(lista1, lista2))
    printf("Sunt egale!\n");
  else
    printf("Nu sunt egale!\n");
}
