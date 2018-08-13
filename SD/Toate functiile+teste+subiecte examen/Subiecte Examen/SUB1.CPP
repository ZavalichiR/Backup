// Subiectul 1
#include <stdio.h>

struct lista {
  int data;
  lista *link;
};

void CitesteLista(lista *&cap)
{
  lista *p;
  int temp;
  printf("Introduceti elementele listei: ");
  do {
    scanf("%d", &temp);
    if(temp != 0)
      {
      p = new lista;
      p->data = temp;
      p->link = cap;
      cap = p;
      }
  } while(temp != 0);
}

void AfisLista(lista *cap)
{
  while(cap != NULL)
    {
    printf("%d ", cap->data);
    cap = cap->link;
    }
  printf("\n");
}

int CautaElement(lista *cap, int elem)
{
  while(cap != NULL)
    {
    if(cap->data == elem)
      return 1;
    cap = cap->link;
    }
  return 0;
}

void SortLista(lista *&cap)
{
  lista *p, *q, *sp, *sq;
  int k, x;
  if(cap != NULL)
    {
    k = 0;
    if(cap->link != NULL)
      do
	{
	p = cap;
	while(p->link != NULL)
	  {
	  q = cap;
	  sq = q;
	  sp = p;
	  p = p->link;
	  x = 0;
	  do
	    {
	    if(p->data < cap->data)
	      {
	      sp->link = p->link;
	      p->link = cap;
	      cap = p;
	      k = 1;
	      x = 1;
	      }
	    if(p->data < q->data && !x)
	      {
	      sp->link = p->link;
	      p->link = q;
	      sq->link = p;
	      p = sp;
	      k = 1;
	      x = 1;
	      }
	    sq = q;
	    q = q->link;
	    }
	  while(p != q && !x);
	  }
	}
	while(!k);
    }
}

main()
{
  lista *Lista;
  int elem;
  CitesteLista(Lista);
  printf("Am citit: ");
  AfisLista(Lista);
  printf("Valoarea cautata: ");
  scanf("%d", &elem);
  if(CautaElement(Lista, elem))
    printf("Valoarea %d este in lista!\n", elem);
  else
    printf("Valoarea %d nu este in lista!\n", elem);
  printf("Lista ordonata: ");
  SortLista(Lista);
  AfisLista(Lista);
}
