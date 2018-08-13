#pragma once
#include<iostream>
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
void afisare2(Nod *arbore);
int evaluare(Nod *arbore);
void afisareOperatori(Nod *arbore);
void afisareOperanzi(Nod *arbore);
void afisareGrad(Nod *arbore);
void determinareGrad(Nod *arbore, int &grad);
int inaltime(Nod *arbore);
