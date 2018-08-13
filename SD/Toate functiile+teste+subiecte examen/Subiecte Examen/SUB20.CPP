// Subiectul 20
#include <stdio.h>
#include <stdlib.h>

typedef int Atom;

struct Nod {
  Atom data;
  Nod *stg, *drt;
};

typedef Nod *pNod;

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

pNod maxim(pNod &rad)
{
  pNod temp;
  if(rad->drt == NULL)
    {
    temp = rad;
    rad = rad->stg;
    return temp;
    }
  return maxim(rad->drt);
}

int cauta(pNod rad, int n)
{
  int gasit = 0;
  if(rad == NULL)
    return 0;
  if(rad->data > n)
    gasit = cauta(rad->stg, n);
  else
    if(rad->data < n)
      gasit = cauta(rad->drt, n);
    else
      return 1;
  return gasit;
}

void stergeNod(pNod &rad)
{
  pNod temp;
  if(rad->stg == NULL)
    {
    temp = rad;
    rad = rad->drt;
    }
  else
    {
    temp = rad;
    rad = maxim(rad->stg);
    rad->stg = temp->stg;
    rad->drt = temp->drt;
    }
  delete temp;
}

int sterge(pNod rad, int n)
{
  int gasit = 0;
  if(rad == NULL)
    return 0;
  if(rad->data > n)
    gasit = cauta(rad->stg, n);
  else
    if(rad->data < n)
      gasit = cauta(rad->drt, n);
    else
      {
      stergeNod(rad);
      return 1;
      }
  return gasit;
}

void main()
{
  pNod rad;
  Atom i;
  printf("Intrare: ");
  rad = creareArbore();
  printf("Arborele in inordine: ");
  inordine(rad);
  printf("\nValoarea cautata: ");
  scanf("%d", &i);
  if(cauta(rad, i))
    printf("Se gaseste in arbore!\n");
  else
    printf("Nu se gaseste in arbore!\n");
  sterge(rad, maxim(rad)->data);
  printf("Am sters nodul cu valoarea cea mai mare.\n");
  printf("Arborele arata acum astfel: ");
  inordine(rad);
  printf("\n");
}
