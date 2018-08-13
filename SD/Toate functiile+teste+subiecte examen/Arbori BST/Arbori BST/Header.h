#pragma once
#include<iostream>
using namespace std;
struct Nod{
	int data;
	Nod *stg, *drt;
};

Nod *makeNod(int val);
void inserare(Nod *&rad,int val);
void inordine(Nod *rad);
void preordine(Nod *rad);
void postordine(Nod *rad);
void peLinie(Nod *rad);
void intend(Nod *rad,int nivel);
int max(Nod *rad);
int min(Nod *rad);
Nod *max2(Nod *rad);
Nod *min2(Nod *rad);
int adancime(Nod *rad);
int nrFrunze(Nod *rad);
int nrNoduri(Nod *rad);
Nod *cauta(Nod *rad, int val);
void comuta(Nod *&rad);
void sterge(Nod *rad, int val);
void stergeRadacina(Nod *rad);
Nod *stergeMaxim(Nod *rad);
Nod *predecesor(Nod *rad,Nod *n);//intoarce pointer la predecesorul nodului n
Nod *succesor(Nod *rad, Nod *n);//intoarce pointer la succesorul nodului n
Nod *tata(Nod *rad,Nod *n);//intoarce pointer la nodul tata a nodului n

struct Nod2{
	char data;
	Nod2 *stg, *drt;
};
void afisareIntend(Nod2 *rad, int nivel);
Nod2 *creareArbore(char *expresie);//Creare arbore binar cand se da forma postfixata/poloneze a unei expresii matematice

bool isEchilibrat(Nod *rad);
void afisareNodNivel(Nod *rad, int Nivel);//afisare noduri de pe un nivel dat
int nrNoduriNivel(Nod *rad, int nivel);
int nrTotalNoduri(Nod *rad);
void afisareNod(Nod *rad, int k);
void reprezentareImplicita(Nod *rad);