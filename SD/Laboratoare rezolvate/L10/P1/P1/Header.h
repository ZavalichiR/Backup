#pragma once
#include<iostream>
using namespace std;

struct Nod{
	int data;
	Nod *stg, *drt;
};

Nod* MakeNod(Nod *rad, int val);
Nod *inserareBST(Nod *&rad, int val);
void inordine(Nod *rad);
void indentat(Nod *rad,int level);
int cautare(Nod *rad, int val);
Nod *cautare2(Nod *rad, int val);
Nod *removeGreatest(Nod *&r);
void deleteRoot(Nod *&rad);
void sterge(Nod *&rad, int a);
Nod *maxim(Nod *rad);
Nod* cautare3(Nod *r, int a);