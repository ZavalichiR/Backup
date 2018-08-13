#pragma once
#include"Header.h"
struct elm{
	Nod *data;
	elm *succ;
};
struct coada{
	elm *tail, *head;
};
void initC(coada *&C);
Nod *get(coada *&C);
void put(coada *&C, Nod *val);