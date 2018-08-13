// Subiectul 6
#include "sub6.h"
#include <stream.h>

void initStiva(Stiva &S)
{
  S = 0;
}

void push(Stiva &S, Atom val)
{
  Stiva p;
  p = new Element;
  p->data = val;
  p->next = S;
  S = p;
}

Atom pop(Stiva &S)
{
  Stiva p;
  Atom temp;
  if(S == 0)
    "Eroare!" > cerr;
  else
    {
    temp = S->data;
    p = S;
    S = S->next;
    delete p;
    return temp;
    }
}

Atom top(Stiva S)
{
  return S->data;
}

int isEmpty(Stiva S)
{
  return(S == 0);
}

Stiva copy(Stiva S)
{
  Stiva p, temp;
  initStiva(p);
  p = new Element;
  temp = p;
  while(S != NULL)
    {
    p->data = S->data;
    S = S->next;
    if(S != NULL)
      p->next = new Element;
    p = p->next;
    }
  return temp;
}

void deleteStiva(Stiva &S)
{
  while(!isEmpty(S))
    pop(S);
}

void main()
{
  int i, j, nr;
  Stiva stiva, aux;
  initStiva(stiva);
  printf("Introduceti numerele: ");
  for(i = 0; i < 10; i++)
    {
    scanf("%d", &nr);
    if(nr < 0)
      push(stiva, nr);
    if(nr > 0)
      {
      for(j = 0; j < nr; j++)
        printf("%d ", pop(stiva));
      printf("\n");
      }
    if(nr == 0)
      aux = copy(stiva);
    }
  printf("Continutul stivei: ");
  while(!isEmpty(stiva))
    printf("%d ", pop(stiva));
  printf("\nContinutul stivei auxiliare: ");
  while(!isEmpty(aux))
    printf("%d ", pop(aux));
  printf("\n");
  deleteStiva(stiva);
  deleteStiva(aux);
}
