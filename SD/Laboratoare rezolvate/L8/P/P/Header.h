#pragma once
#include<iostream>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
#define DIM_EXPR 100 
#define GRMAX 20 
#define Atom int 
struct Nod
{
	Atom data;
	int grad;
	Nod* vDesc[GRMAX];
};
Nod* creareArbore();

void afisare(Nod *arbore);
void afisare1(Nod *arbore);
void afisare2(Nod *arbore);
void afisareOperanzi(Nod *arbore);
void afisareOperatori(Nod *arbore);
void afisareGradNod(Nod *arbore);
void determinareGrad(Nod *arbore,int &grad);
int inaltime(Nod *arbore);
int evaluareExpresie(Nod *arbore);
int MAX(Nod *arbore);
void afisareNoduri(Nod *p);