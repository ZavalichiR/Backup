#ifndef _Header_
#define _Header_
#include<iostream>
using namespace std;
typedef int tip;
struct Nod{
	tip data;
	Nod *stg, *drt;
};
Nod *makeNod(tip val);
void inserare(Nod *&arbore, tip val);
void afisare(Nod *arbore);
void inordine(Nod *arbore);
int adancime(Nod *arbore);
int nrNoduri(Nod *arbore);

struct Elm{
	Nod *data;
	Elm *succ;
};
struct Coada{
	Elm *tail, *head;
};
void init(Coada *&C);
void put(Coada *&C, Nod *val);
Nod *get(Coada *&C);
#endif