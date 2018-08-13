// Subiectul 10
#include <stdio.h>
#include "glista.h"

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

int adincimeGLista(GLista lista)
{
  int nr = 1;
  while(lista != NULL)
    {
    if(lista->tag == LISTA)
      nr+=adincimeGLista(lista->data.L);
    lista = lista->link;
    }
  return nr;
}

void main()
{
  GLista lista;
  printf("Introduceti lista: ");
  lista = creareGLista();
  printf("Nr. de atomi: %d\n", nrAtomi(lista));
  printf("Lista citita: ");
  afisGLista(lista);
  printf("\nAdincimea: %d\n", adincimeGLista(lista));
}
