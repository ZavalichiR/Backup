#pragma once
#include"Header.h"
struct stiva
{
	Nod *data;
	stiva *leg;
};
void initS(stiva *&S);
void push(stiva *&S, Nod *val);
Nod* pop(stiva *&S);