// Subiectul 14
#include <stdio.h>
#include "arbore.h"

int test = 1;

void postordine(Nod *rad)
{
  if(rad != NULL)
    {
    postordine(rad->stg);
    postordine(rad->drt);
    printf("%c ", rad->data);
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

int isCautare(Nod *rad)
{
  if(rad != NULL)
    {
    isCautare(rad->stg);
    if(test)
      if(rad->stg != NULL && rad->drt != NULL)
	test = (rad->data > maxim(rad->stg) && rad->data < maxim(rad->drt));
      else
	if(rad->stg != NULL)
	  test = (rad->data < maxim(rad->stg));
	else
	  test = (rad->data > maxim(rad->drt));
    isCautare(rad->drt);
    }
  return test;
}

void main()
{
  Nod *rad;
  rad = creareArbore();
  printf("Arborele parcurs in postordine:\n");
  postordine(rad);
  printf("\nAdancimea: %d\n", adancime(rad));
  printf("Este arbore de cautare: ");
  if(isCautare(rad))
    printf("TRUE");
  else
    printf("FALSE");
  printf("\n");
}
