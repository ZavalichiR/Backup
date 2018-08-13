#pragma once
#include<iostream>
using namespace std;
struct Nod
{
	int data;
	Nod *succ;
};
void inserare(Nod *&lista, int val);
void afisare(Nod *lista);
void afisarePermutari(Nod *lista); 
void stergere(Nod *&lista, int val);
void cautare(Nod *lista, int val);

Nod *unire(Nod *&lista1, Nod *&lista2);
void unire2(Nod *&lista1, Nod *&lista2);

void interclasare(Nod *&lista1, Nod *&lista2);
int count(Nod *lista);