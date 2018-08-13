#pragma once

#include<Windows.h>
#include<iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
using namespace std;
struct Nod {
	char data;
	Nod *stg, *drt;
};
void eroare();
char readchar();
char citesteNume();
Nod* citesteArbore();
Nod* creareArbore();
void inordine(Nod *p);
void preordine(Nod *p);
void postordine(Nod *p);
void afisareIntend(Nod *p,int nivel);
int adancime(Nod *p);
int frunze(Nod *p);
int nrnoduri(Nod *p);
int elementeArbore(Nod *p);
char Max(Nod *p);
char Min(Nod *p);
void comuta(Nod *p);

void dealocare(Nod *p);

