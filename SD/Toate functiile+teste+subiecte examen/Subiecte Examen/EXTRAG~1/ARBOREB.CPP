#include <alloc.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "arboreb.h"

void eroare();
char readchar();
char citesteNume();
Nod* citesteArbore();
Nod* creareArbore();

char car;

void eroare()
{
     printf("Sirul de intrare este eronat!\n");
     printf("Apasati tasta o tasta...");
     getch();
     exit(1);
}

char readchar()
{
     char c;
     do  c=getchar();  while(c==' ');
     return c;
}

char citesteNume()
{
     char c;
     if(!isalpha(car)) eroare();
     c = car;
     car = readchar();
     return c;
}

Nod* citesteArbore()
{
     Nod* rad;
     if( car=='-' )  {
		     rad=0;
		     car = readchar();
		     }
     else {
	  rad = (Nod*) malloc(sizeof(Nod));
	  rad->data = citesteNume();
	  if( car!='(' )  {
			 rad->stg = 0;
			 rad->drt = 0;
			 }
	  else {
	       car = readchar();
	       rad->stg = citesteArbore();
	       if( car!=',' )    rad->drt = 0;
	       else {
		    car = readchar();
		    rad->drt = citesteArbore();
		    }
	       if( car!=')' )  eroare();
	       car = readchar();
	       }
	  }
     return rad;
}

Nod* creareArbore()
{
     printf("\nIntroduceti arborele:");
     car = readchar();
     return citesteArbore();
}



