// Subiectul 4
#include <stdio.h>
#include <string.h>

struct abonat {
  char *nume;
  char *tel;
  };

struct lista {
  char *nume;
  char *tel;
  lista *next;
  };

typedef lista *plista;

void insert(plista &cap, abonat abon)
{
  plista q, q1, p;
  p = new lista;
  p->nume = abon.nume;
  p->tel = abon.tel;
  if(cap == NULL || strcmp(p->nume, cap->nume) < 0)
    {
    p->next = cap;
    cap = p;
    }
  else
    {
    q1 = cap;
    q = cap->next;
    while(q != NULL && strcmp(p->nume, q->nume) > 0)
      {
      q1 = q;
      q = q->next;
      }
    p->next = q1->next;
    q1->next = p;
    }
}

int caut(plista cap, abonat &abon)
/*
  Coduri de retur:

  -1 = agenda este goala
   0 = abonat negasit
   1 = agenda gasit
*/
{
  plista q, q1;
  if(cap == NULL)
    return -1;
  q = cap;
  q1 = cap->next;
  while(q != NULL && strcmp(abon.nume, q->nume))
    {
    q1 = q;
    q = q->next;
    }
  if(q == NULL)
    return 0;
  else
    {
    abon.tel = q->tel;
    return 1;
    }
}

char *getlinie(int lim)
{
  char *s = new char[lim];
  int i = 0;
  char c;
  fflush(stdin);
  while(--lim > 0 && (c = getchar()) != '\n' && c != EOF)
    s[i++] = c;
  s[i] = '\0';
  return s;
}

abonat intro_articol()
{
  abonat abon;
  abon.nume = getlinie(25);
  if(abon.nume[0] == '.')
    return abon;
  abon.tel = getlinie(8);
  return abon;
}

void CitireAgenda(plista &Lista)
{
  abonat abon;
  printf("Introduceti agenda:\n");
  for(;;)
    {
    abon = intro_articol();
    if(abon.nume[0] == '.')
      break;
    insert(Lista, abon);
    }
}

void AfisareAgenda(plista Lista)
{
  if(Lista == NULL)
    {
    printf("Agenda goala.\n");
    return;
    }
  printf("Continutul agendei:\n");
  while(Lista != NULL)
    {
    printf("%25s  %8s\n", Lista->nume, Lista->tel);
    Lista = Lista->next;
    }
}

main()
{
  plista agenda;
  abonat abon;
  CitireAgenda(agenda);
  AfisareAgenda(agenda);
  printf("Numele cautat: ");
  abon.nume = getlinie(25);
  if(caut(agenda, abon) == 1)
    printf("Numarul de telefon: %s\n", abon.tel);
  else
    printf("Abonat negasit.\n");
  return 0;
}
