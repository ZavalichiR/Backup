#pragma once
#include<string.h>
#include<iostream>
using namespace std;
class masina
{
	char *marca;
	char *culoare;
	int pret;
	double viteza;
public:
	masina();
	masina(char * m, char *c, int p, double vi);
	void afisare();
	bool operator<(masina* m);

};