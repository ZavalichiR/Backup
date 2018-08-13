// Subiectul 19
#include <stdio.h>
#include <stdlib.h>

struct Nod {
  int data;
  Nod *stg, *drt;
};

typedef Nod *pNod;

struct Atom {
  pNod adr;
  int poz;
};

struct Queue {
  Atom data;
  Queue *link;
};
struct Coada {
  Queue *tail, *head;
};

int nivel = 1;
int implicit[200];

void init(Coada &coada)
{
  coada.tail = coada.head = NULL;
}

int isEmpty(Coada coada)
{
  return(coada.head == NULL);
}

void put(Coada &coada, Atom atom)
{
  Queue *p;
  p = new Queue;
  p->data = atom;
  p->link = NULL;
  if(coada.tail != NULL)
    coada.tail->link = p;
  else
    coada.head = p;
  coada.tail = p;
}

Atom get(Coada &coada)
{
  Atom retur;
  Queue *temp = NULL;
  if(!isEmpty(coada))
    {
    retur = coada.head->data;
    temp = coada.head;
    coada.head = coada.head->link;
    if(coada.head == NULL)
      coada.tail = NULL;
    delete temp;
    }
  return retur;
}

void insert(pNod &rad, int a)
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
  int i;
  do {
    scanf("%d", &i);
    if(i != 0)
      insert(rad, i);
    }
  while(i != 0);
  return rad;
}

void preordine(pNod rad)
{
  if(rad != NULL)
    {
    printf("%d ", rad->data);
    preordine(rad->stg);
    preordine(rad->drt);
    }
}

int nrNodPoz(pNod rad)
{
  int nr = 0;
  if(rad != NULL)
    {
    if(rad->data > 0)
      nr++;
    nr+=nrNodPoz(rad->stg);
    nr+=nrNodPoz(rad->drt);
    }
  return nr;
}

int adancime(pNod rad)
{
  int as, ad;
  if(rad == NULL)
    return 0;
  as = adancime(rad->stg);
  ad = adancime(rad->drt);
  if(as > ad)
    return(as + 1);
  else
    return(ad + 1);
}

int produs(int i)
{
  int x, m = 1;
  for(x = 1; x <= i; x++)
    m*=2;
  return m;
}

int calc_imp(pNod rad)
{
  Atom data, e;
  pNod temp;
  Coada c;
  if(rad != NULL)
    init(c);
    e.poz = 1;
    e.adr = rad;
    put(c, e);
    {
    while(!isEmpty(c))
      {
      data = get(c);
      temp = data.adr;
      implicit[data.poz] = temp->data;
      if(temp->stg != NULL)
	{
	e.adr = temp->stg;
	e.poz = 2 * data.poz;
	put(c, e);
	}
      if(temp->drt != NULL)
	{
	e.adr = temp->drt;
	e.poz = 2 * data.poz + 1;
	put(c, e);
	}
      }
    }
  return data.poz;
}

void main()
{
  pNod rad;
  int i;
  printf("Intrare: ");
  rad = creareArbore();
  printf("Arborele in preordine: ");
  preordine(rad);
  printf("\nNumarul de noduri cu valori pozitive: %d\n", nrNodPoz(rad));
  printf("Reprezentare implicita: ");
  for(i = 1; i <= produs(adancime(rad)); i++)
    implicit[i] = 0;
  for(i = 1; i <= calc_imp(rad); i++)
    printf("%d ", implicit[i]);
  printf("\n");
}
