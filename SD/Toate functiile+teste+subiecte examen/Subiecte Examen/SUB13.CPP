// Subiectul 13
#include <stdio.h>
#include "arbore.h"

int test = 1;

void preordine(Nod *rad)
{
  if(rad != NULL)
    {
    printf("%c ", rad->data);
    preordine(rad->stg);
    preordine(rad->drt);
    }
}

void afisFrunze(Nod *rad)
{
  if(rad != NULL)
    {
    if(rad->stg == NULL && rad->drt == NULL)
      printf("%c ", rad->data);
    afisFrunze(rad->stg);
    afisFrunze(rad->drt);
    }
}

char max(char c1, char c2)
{
  if(c1 >= c2)
    return c1;
  return c2;
}

char maxim(Nod *rad)
// gaseste nodul pentru care valoarea din radacina este mai mare decit
// toate valorile din subarborii descendenti
{
  char vmax;
  if(rad == NULL)
    return 0;
  vmax = rad->data;
  if(rad->stg != NULL)
    vmax = max(vmax, maxim(rad->stg));
  if(rad->drt != NULL)
    vmax = max(vmax, maxim(rad->drt));
  return vmax;
}

int isHeap(Nod *rad)
{
  if(rad != NULL)
    {
    isHeap(rad->stg);
    if(test)
      test = (rad->data > maxim(rad->stg) && rad->data > maxim(rad->drt));
    isHeap(rad->drt);
    }
  return test;
}

void afisHeap(Nod *rad)
// se parcurge astfel: rad SAD SAS
{
  if(rad != NULL)
    {
    printf("%c ", rad->data);
    afisHeap(rad->drt);
    afisHeap(rad->stg);
    }
}

void main()
{
  Nod *rad;
  rad = creareArbore();
  printf("Arborele parcurs in preordine:\n");
  preordine(rad);
  printf("\nEste heap: ");
  if(isHeap(rad))
    {
    printf("TRUE\n");
    printf("Literele ordonate (extrase din heap): ");
    afisHeap(rad);
    printf("\n");
    }
  else
    printf("FALSE\n");
}
