// Subiectul 3
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

void StergeElemDinLista(lista *&cap, int poz)
{
  int i = 0;
  lista *p, *temp;
  temp = cap;
  if(poz == 1) // se sterge primul element, adica din fata?
    {
    p = cap;
    cap = cap->link;
    delete p;
    return;
    }
  while(++i < poz - 1)
    temp = temp->link;
  p = temp->link;
  temp->link = p->link;
  delete p;
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
  printf("Introduceti pozitia elementului de sters: ");
  scanf("%d", &poz);
  printf("Lista actualizata: ");
  StergeElemDinLista(Lista, poz);
  AfisLista(Lista);
}
