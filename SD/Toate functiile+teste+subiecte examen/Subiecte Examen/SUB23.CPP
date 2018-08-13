// Subiectul 23
#include <stdio.h>
#include <stdlib.h>

struct Arbore {
  int vec[100];
  int n;
};

int max = 0, heap = 1;

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

void preordine(Arbore arb, int poz)
{
  if(poz <= arb.n)
    {
    printf("%d ", arb.vec[poz]);
    preordine(arb, 2 * poz);
    preordine(arb, 2 * poz + 1);
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

int isHeap(Arbore arb, int poz)
{
  if(poz < arb.n)
    {
    isHeap(arb, 2 * poz);
    if(heap)
      heap = (arb.vec[poz] > maxim(arb, 2 * poz) && arb.vec[poz] >
	maxim(arb, 2 * poz + 1));
    isHeap(arb, 2 * poz + 1);
    }
  return heap;
}

int extrage(Arbore &arb)
{
  int f, p, retur;
  if(arb.n != 0)
    {
    retur = arb.vec[1];
    arb.vec[1] = arb.vec[arb.n];
    arb.n--;
    p = 1;
    f = 2 * 1;
    while(f <= arb.n && (arb.vec[p] < arb.vec[f] || arb.vec[p] <
      arb.vec[f + 1]))
      {
      if(arb.vec[p] < arb.vec[f + 1])
	if(arb.vec[f] < arb.vec[f + 1])
	  f++;
      arb.vec[p] = arb.vec[f];
      arb.vec[f] = arb.vec[arb.n + 1];
      p = f;
      f = 2 * p;
      }
    }
  return retur;
}

void main()
{
  Arbore arb;
  printf("Intrare: ");
  arb = creareArbore();
  printf("Arborele in preordine: ");
  preordine(arb, 1);
  max = arb.vec[1];
  printf("\n");
  if(isHeap(arb, 1))
    printf("ESTE HEAP\n");
  else
    printf("NU ESTE HEAP\n");
  printf("Sirul ordonat: ");
  while(arb.n != 0)
    printf("%d ", extrage(arb));
  printf("\n");
}
