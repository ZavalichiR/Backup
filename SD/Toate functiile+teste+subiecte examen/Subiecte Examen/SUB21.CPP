// Subiectul 21
#include <stdio.h>
#include <stdlib.h>

struct Arbore {
  int vec[100];
  int n;
};

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

void main()
{
  Arbore arb, heap;
  int i;
  printf("Intrare: ");
  arb = creareArbore();
  printf("Arborele in postordine: ");
  postordine(arb, 1);
  printf("\nSubarborele drept al radacinii in inordine: ");
  inordine(arb, 2 * 1 + 1);
  heap.n = 0;
  for(i = 1; i <= arb.n; i++)
    insert(heap, arb.vec[i]);
  printf("\nHeap-ul de sus in jos: ");
  for(i = 1; i <= heap.n; i++)
    printf("%d ", heap.vec[i]);
  heap.n = 0;
  for(i = arb.n; i >= 1; i--)
    insert(heap, arb.vec[i]);
  printf("\nHeap-ul de jos in sus: ");
  for(i = heap.n; i >= 1; i--)
    printf("%d ", heap.vec[i]);
  printf("\n");
}
