/****************************************************************
                      Fisierul GLISTA.CPP
*****************************************************************/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

#include "GLISTA.H"

char crtChar;

void eroare()
{
     printf("Sirul de intrare este eronat!\n"
             "Apasati o tasta ...");
     getch();
     exit(1);
}

void readchar()
{
     do crtChar=getchar();
     while(crtChar==' ');
}

char citesteAtom()
{
     char c;
     if(!isalpha(crtChar)) eroare();
     c = crtChar;
     readchar();
     return c;
}

GLista citesteGLista();

GElement* citesteGElement()
{
     GElement* p = new GElement;
     if(crtChar=='(') {
		      p->data.L = citesteGLista();
		      p->tag = LISTA;
		      }
     else {
	  p->data.A = citesteAtom();
	  p->tag = ATOM;
	  }
    p->link = NULL;
    return p;
}

GLista citesteGLista()
{
     GElement* cap, *coada, *p;
     if( crtChar!='(' ) eroare();
     readchar();
     if( crtChar==')' )  cap = NULL;
     else {
	  cap = citesteGElement();
	  coada = cap;
	  while( crtChar==',' ) {
		readchar();
                p = citesteGElement();
                coada->link = p;
                coada = p;
                }
          if( crtChar!=')' ) eroare();
          }
     readchar();
     return cap;
}

GLista creareGLista()
{
     do readchar(); 
     while (crtChar=='\n');
     return (citesteGLista());
}

