#ifndef _COZI_H
#define _COZI_H

#include<iostream>
using namespace std;
typedef int Atom;
#define dim 20
struct Coada{
	int head, tail;
	Atom vect[dim];

};

void creare(Coada &C);
int isEmpty(Coada &C);
int nextPoz(int index);
void put(Coada &C, Atom a);
Atom get(Coada &C);
void afisareCoada(Coada &C);
void TestCoadaCirculara();



#endif