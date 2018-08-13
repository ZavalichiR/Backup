#include<string.h>
#include<iostream>
using namespace std;
#include "Fitness.h"
#include"Gantere.h"
#include "globale.h"


Gantere::Gantere(Fitness *fit, double greutate, int nrDiscuri) :Greutati(fit, greutate)
{
	this->nrDiscuri = nrDiscuri;
}

Gantere::~Gantere()
{
	nrDiscuri = 0;
}

int Gantere::getNrDiscuri()
{
	return this->nrDiscuri;
}

void Gantere::afisareGantere()
{
	cout << " Gantera ";
	cout<< "       ";
	/*cout << std::cout.width(2)*/
	std::cout << std::setw(2);
	cout << this->nrDiscuri;
	cout << "  ";
	this->afisareGreutati();
}

void Gantere::afisare()
{
	this->afisareGantere();
}

Fitness *citesteGantere(char *c)
{
	Fitness *fit;
	fit = citesteFitness(c);
	int nd, ok;
	float g, ok2;
	do{
		cout << "Introduceti greutate (in kg):";
		cin >> g;
		ok2 = g;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cin >> ok2;
		}
		g = ok2;
	} while (g < 0);
	do{
		cout << "Introduceti numarul de discuri:";
		cin >> nd;
		ok = nd;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cin >> ok;
		}
		nd = ok;
	} while (nd < 0);
	return new Gantere(fit, g, nd);
}