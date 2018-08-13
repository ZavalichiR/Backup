// Subiectul 22
#include <stdio.h>
#include <stdlib.h>

struct Arbore {
  int vec[100];
  int n;
};

int max = 0, cautare = 1;

void insert(Arbore &arb, int a)
{
  int parent, current;
  arb.n++;
  arb.vec[arb.n] = a;
  current = arb.n;
  parent = current / 2;
  while(parent != 0 && a > arb.vec[parent])
    {
    arb.vec[current] = arb.vec[parent];
    arb.vec[parent] = a;
    current = parent;
    parent = current / 2;
    }
}

Arbore creareArbore()
{
  Arbore arb;
  int i;
  arb.n = 0;
  do {
    scanf("%d", &i);
    if(i != 0)
      {
      arb.n++;
      arb.vec[arb.n] = i;
      }
    }
  while(i != 0);
  return arb;
}

void inordine(Arbore arb, int poz)
{
  if(poz <= arb.n)
    {
    inordine(arb, 2 * poz);
    printf("%d ", arb.vec[poz]);
    inordine(arb, 2 * poz + 1);
    }
}

void postordine(Arbore arb, int poz)
{
  if(poz <= arb.n)
    {
    postordine(arb, 2 * poz);
    postordine(arb, 2 * poz + 1);
    printf("%d ", arb.vec[poz]);
    }
}

int maxim(Arbore arb, int poz)
{
  if(poz <= arb.n)
    {
    maxim(arb, 2 * poz);
    if(max < arb.vec[poz])
      max = arb.vec[poz];
    maxim(arb, 2 * poz + 1);
    }
  return max;
}

int isCautare(Arbore arb, int poz)
{
  if(poz < arb.n)
    {
    isCautare(arb, 2 * poz);
    if(cautare)
      if(2 * poz < arb.n && 2 * poz + 1 <= arb.n)
	cautare = (arb.vec[poz] > maxim(arb, 2 * poz) && arb.vec[poz] <
	  maxim(arb, 2 * poz + 1));
      else
	if(2 * poz <= arb.n)
	  cautare = (arb.vec[poz] > maxim(arb, 2 * poz));
	else
	  cautare = (arb.vec[poz] > maxim(arb, 2 * poz + 1));
    isCautare(arb, 2 * poz + 1);
    }
  return cautare;
}

void main()
{
  Arbore arb;
  int i;
  printf("Intrare: ");
  arb = creareArbore();
  printf("Arborele in inordine: ");
  inordine(arb, 1);
  printf("\nSubarborele stang al radacinii in postordine: ");
  postordine(arb, 2 * 1);
  max = arb.vec[1];
  printf("\n");
  if(isCautare(arb, 1))
    printf("ESTE ARBORE BINAR DE CAUTARE\n");
  else
    printf("NU ESTE ARBORE BINAR DE CAUTARE\n");
}
