// Subiectul 16
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

int max(int c1, int c2)
{
  if(c1 >= c2)
    return c1;
  return c2;
}

int depth(pNod rad)
{
  if(rad == NULL)
    return 0;
  return(1 + max(depth(rad->stg), depth(rad->drt)));
}

int cauta(pNod rad, Atom a)
{
  if(rad != NULL)
    if(rad->data == a || cauta(rad->stg, a) || cauta(rad->drt, a))
      return 1;
  return 0;
}

void main()
{
  pNod rad;
  Atom i;
  printf("Introduceti valorile: ");
  rad = creareArbore();
  printf("Arborele: ");
  inordine(rad);
  printf("\nValoarea cautata: ");
  scanf("%d", &i);
  if(cauta(rad, i))
    printf("ESTE\n");
  else
    printf("NU ESTE\n");
  if(abs(depth(rad->stg) - depth(rad->drt)) <= 1)
    printf("Este echilibrat!\n");
  else
    printf("Nu este echilibrat!\n");
}
