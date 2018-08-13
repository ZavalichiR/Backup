#pragma once
#include<iostream>
#include<conio.h>
using namespace std;
typedef int TD;

struct Nod
{
	Nod *leg;
	TD data;	
};
void inserare(Nod *&head, TD nou);
void afisare(Nod *lista);
void unireliste(Nod *&lista1, Nod *&lista2);
int count(Nod *lista);
void interclasare(Nod *&lista1, Nod*& lista2);
void afisareMijloc(Nod *lista);
void EstiWaiBucla(Nod *lista);
void FaBucla(Nod *lista);
