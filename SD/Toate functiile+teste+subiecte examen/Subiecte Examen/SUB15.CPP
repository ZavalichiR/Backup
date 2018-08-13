// Subiectul 15
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

int nrNod(Nod *rad)
{
  int nr = 0;
  if(rad != NULL)
    {
    nr+=nrNod(rad->stg);
    nr++;
    nr+=nrNod(rad->drt);
    }
  return nr;
}

char min(char c1, char c2)
{
  if(c1 <= c2)
    return c1;
  return c2;
}

char minim(Nod *rad)
{
  char vmin;
  if(rad == NULL)
    return 'Z';
  vmin = rad->data;
  if(rad->stg != NULL)
    vmin = min(vmin, minim(rad->stg));
  if(rad->drt != NULL)
    vmin = min(vmin, minim(rad->drt));
  return vmin;
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

void afisMin(Nod *rad)
{
  if(rad != NULL)
    {
    afisMin(rad->stg);
    if(maxim(rad->stg) < rad->data && maxim(rad->drt) < rad->data)
      printf("%c ", rad->data);
    afisMin(rad->drt);
    }
}

void main()
{
  Nod *rad;
  rad = creareArbore();
  printf("Arborele parcurs in inordine:\n");
  inordine(rad);
  printf("\nNr. de noduri: %d\n", nrNod(rad));
  printf("Nodurile care indeplinesc conditia (d): ");
  afisMin(rad);
  printf("\n");
}
