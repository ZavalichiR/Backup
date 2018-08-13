// Subiectul 12
#include <stdio.h>
#include "arbore.h"

int test = 1;

void inordine(Nod *rad)
{
  if(rad != NULL)
    {
    inordine(rad->stg);
    printf("%c ", rad->data);
    inordine(rad->drt);
    }
}

int adancime(Nod *t)
{
  int ads, add;
  if(t == 0)
    return 0;
  else
    {
    ads = adancime(t->stg);
    add = adancime(t->drt);
    return (ads > add) ? ads + 1 : add + 1;
    }
}

char max(char c1, char c2)
{
  if(c1 >= c2)
    return c1;
  return c2;
}

char maxim(Nod *rad)
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
  return(test);
}

void main()
{
  Nod *rad;
  printf("Introduceti arborele: ");
  rad = creareArbore();
  printf("Arborele parcurs in inordine:\n");
  inordine(rad);
  printf("Adancimea: %d\n", adancime(rad));
  printf("Litera cea mai mare: %c\n, maxim(rad));
  if(isHeap(rad))
    printf("Este arbore heap!\n");
  else
    printf("Nu este arbore heap!\n");
}
