#ifndef _P2_
#define _P2_
#include<iostream>
#include<conio.h>
using namespace std;

struct Nod {
	int data;
	Nod *succ;
};

void creare(Nod *&lista, int val);
void afisare(Nod *lista);
void unire(Nod *&lista1, Nod *&lista2);
int count(Nod *lista);
void intercalare(Nod *&lista1, Nod *&lista2);
Nod *intrercalare2(Nod *lista1, Nod *lista2);
#endif
