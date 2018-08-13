#ifndef _PIXEL_H
#define _PIXEL_H
#include<iostream>
using namespace std;

struct pozitie{
	int x, y;
};
typedef pozitie Atom;

struct elm
{
	Atom data;
	elm *succ;
};
struct coada{
	elm *tail, *head;
};

void initC(coada *&C);
void put(coada *&C, Atom val);
Atom get(coada *&C);
void coloreaza(pozitie p);


#endif 