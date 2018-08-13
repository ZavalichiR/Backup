#include<string.h>
#include<iostream>
#include<assert.h>
#include "Fitness.h"
#include"Greutati.h"
#include "globale.h"
using namespace std;



Greutati::Greutati(Fitness *fit, double greutate) :Fitness(fit->getTip(),fit->getPret(), fit->getCod(), fit->getGarantie())
{
	this->greutate = greutate;
}
Greutati::~Greutati()
{
	greutate = 0;
}

double Greutati::getGreutate()
{
	return this->greutate;
}

void Greutati::afisareGreutati()
{
	cout << "     ";
	std::cout.width(5);
	cout<<left << this->greutate << "kg     ";
	this->afisareFitness();
}

void Greutati::afisare()
{
	this->afisareGreutati();
	cout << endl;
}

Fitness *citesteGreutati(char *c)
{
	Fitness *fit;
	fit = citesteFitness(c); 
	float g; 
	cout << "Introduceti greutatea (int kg):";
	float ok;
	do{
		cout << "Introduceti greutatea (in kg):";
		cin >> g;
		ok = g;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cin >> ok;
		}
		g = ok;
	} while (g<0);
	return new Greutati(fit, g); 
}