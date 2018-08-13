// Subiectul 18
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

int adincime(pNod rad)
{
  int as, ad;
  if(rad == NULL)
    return 0;
  as = adincime(rad->stg);
  ad = adincime(rad->drt);
  if(as > ad)
    return(as + 1);
  else
    return(ad + 1);
}

int nrNoduri(pNod rad)
{
  int ns, nd;
  if(rad == NULL)
    return 0;
  ns = nrNoduri(rad->stg);
  nd = nrNoduri(rad->drt);
  return (ns + nd + 1);
}

void main()
{
  pNod rad;
  int k;
  printf("Introduceti arborele: ");
  rad = creareArbore();
  printf("Arborele: ");
  inordine(rad);
  printf("\nAdincimea: %d\n", adincime(rad));
  printf("Introduceti diferenta K: ");
  scanf("%d", &k);
  if(abs(nrNoduri(rad->stg) - nrNoduri(rad->drt)) >= k)
    printf("Exista nod cu proprietatea de la punctul (d)!\n",
}
