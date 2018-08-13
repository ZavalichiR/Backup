// Subiectul 17
#include <stdio.h>
#include <stdlib.h>

typedef int Atom;

struct Nod {
  Atom data;
  Nod *stg, *drt;
};

typedef Nod *pNod;

int nivel = 1;

void insert(pNod &rad, Atom a)
{
  if(rad == NULL)
    {    // make_nod(a) din curs
    rad = new Nod;
    rad->data = a;
    rad->stg = NULL;
    rad->drt = NULL;
    }
  else
    {
    if(a < rad->data)
      insert(rad->stg, a);
    else
      insert(rad->drt, a);
    }
}

pNod creareArbore()
{
  pNod rad = NULL;
  Atom i;
  do {
    scanf("%d", &i);
    if(i != 0)
      insert(rad, i);
    }
  while(i != 0);
  return rad;
}

void inordine(pNod rad)
{
  if(rad != NULL)
    {
    inordine(rad->stg);
    printf("%d ", rad->data);
    inordine(rad->drt);
    }
}

int nrFrunze(pNod rad)
{
  int nr = 0;
  if(rad != NULL)
    {
    if(rad->stg == NULL && rad->drt == NULL)
      nr++;
    nr+=nrFrunze(rad->stg);
    nr+=nrFrunze(rad->drt);
    }
  return nr;
}

nrVarfuriN(pNod rad, int n)
{
  int nr = 0;
  if(rad != NULL)
    {
    if(nivel == n)
      nr++;
    else
      {
      nivel++;
      nr+=nrVarfuriN(rad->stg, n);
      nivel++;
      nr+=nrVarfuriN(rad->drt, n);
      }
    }
  nivel--;
  return nr;
}

void main()
{
  pNod rad;
  Atom i;
  int level;
  printf("Intrare: ");
  rad = creareArbore();
  printf("Nivelul: ");
  scanf("%d", &level);
  printf("Arborele: ");
  inordine(rad);
  printf("\nNumarul de frunze: %d\n", nrFrunze(rad));
  printf("Numarul de noduri pe nivelul %d: %d\n", level,
    nrVarfuriN(rad, level));
}
