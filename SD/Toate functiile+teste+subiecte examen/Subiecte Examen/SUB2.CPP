// Subiectul 2
#include <stdio.h>

struct lista {
  int data;
  lista *link;
};

void CitesteLista(lista *&cap)
{
  lista *p;
  int temp;
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

void InsertElemInLista(lista *&cap, int elem, int poz)
{
  int i = 0;
  lista *p, *temp;
  temp = cap;
  p = new lista;
  p->data = elem;
  if(poz == 1) // se insereaza in pozitia 1, adica in fata?
    {
    p->link = cap;
    cap = p;
    return;
    }
  while(++i < poz - 1)
    temp = temp->link;
  p->link = temp->link;
  temp->link = p;
}

main()
{
  lista *Lista;
  int elem, poz;
  printf("Introduceti elementele listei: ");
  CitesteLista(Lista);
  printf("Am citit: ");
  AfisLista(Lista);
  printf("Valoarea cautata: ");
  scanf("%d", &elem);
  if(CautaElement(Lista, elem))
    printf("Valoarea %d este in lista!\n", elem);
  else
    printf("Valoarea %d nu este in lista!\n", elem);
  printf("Introduceti valoarea de inserat: ");
  scanf("%d", &elem);
  printf("Introduceti pozitia elementului de sters: ");
  scanf("%d", &poz);
  printf("Lista completata: ");
  InsertElemInLista(Lista, elem, poz);
  AfisLista(Lista);
}
