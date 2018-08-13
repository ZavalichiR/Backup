#pragma once
#include<iostream>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
using namespace std;
struct Nod{
	char data;
	Nod* stg, *drt;
};

Nod* creareArbore();
void eroare();
char readchar();
char citesteNume();
Nod* citesteArbore();
Nod* creareArbore();

void inordine(Nod *rad);
void preordine(Nod *rad);
void postordine(Nod *rad);
void afisareIntend(Nod *rad, int nivel);
void afisareLinie(Nod *rad);
Nod *creareArbore(char *expresie);
int adancime(Nod *rad);
int frunze(Nod *rad);
int nrnoduri(Nod *rad);
char Max(Nod *rad);
char Min(Nod *rad);
void comuta(Nod *rad);

void dealocare(Nod *rad);
int isHeap(Nod *rad);
void afisareHeap(Nod *rad);
void afisareFrunze(Nod *rad);

int isCautare(Nod *rad);
void afisareNoduri(Nod *rad);
void afisareNoduri2(Nod *rad);

