// Subiectul 9
#include <stdio.h>
#include "glista.h"

GLista p = NULL, cap = NULL;

int nrAtomi(GLista lista)
{
  int nr = 0;
  while(lista != NULL)
    {
    if(lista->tag == ATOM)
      nr++;
    else
      nr+=nrAtomi(lista->data.L);
    lista = lista->link;
    }
  return nr;
}

void afisGLista(GLista lista)
{
  printf("(");
  if(lista->data.L == NULL)
    printf(")");
  while(lista != NULL)
    {
    if(lista->tag == ATOM)
      printf("%c", lista->data.A);
    else
      afisGLista(lista->data.L);
    lista = lista->link;
    if(lista == NULL)
      printf(")");
    else
      printf(",");
    }
}

GLista prelucrareGLista(GLista lista)
{
  GLista q;
  while(lista != NULL)
    {
    if(lista->tag == ATOM)
      {
      q = new GElement;
      q->tag = ATOM;
      q->data.A = lista->data.A;
      q->link = p;
      p = q;
      }
    if(lista->tag == LISTA)
      if(lista->data.L != NULL)
	{
	q = new GElement;
	q->tag = LISTA;
	prelucrareGLista(lista->data.L);
	q->data.L = p;
	q->link = NULL;
	p = q;
	}
    lista = lista->link;
    }
  return p;
}

void main()
{
  GLista lista, prel;
  printf("Introduceti lista: ");
  lista = creareGLista();
  printf("Nr. de atomi: %d\n", nrAtomi(lista));
  printf("Lista citita: ");
  afisGLista(lista);
  prel = prelucrareGLista(lista);
  printf("\nLista prelucrata: ");
  afisGLista(cap);
  printf("\n");
}
