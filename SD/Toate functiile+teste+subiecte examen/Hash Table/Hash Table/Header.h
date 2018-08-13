#pragma once
#include<iostream>
using namespace std;
#define dim 20
struct Nod{
	char *data;
	Nod *succ;

};
void init(Nod *HT[]);
int functie(char *cheie);
void afisare(Nod *HT[]);
void inserare(Nod *HT[],char *cheie);
void stergere(Nod *HT[],char *cheie);
Nod *cautare(Nod *HT[],char *cheie);
void sortare(Nod *HT[]);
void afisareFrecv(int fr[128]);
void calculeazaFrecventa(char *text, int fr[128]);

