#include<string.h>
#include<iostream>
#include "Fitness.h"
#include"MingeFitness.h"
#include "globale.h"
using namespace std;



MingeFitness::MingeFitness(Fitness *fit, double greutate) :Fitness(fit->getTip(),fit->getPret(), fit->getCod(), fit->getGarantie())
{
	this->greutate = greutate;
}

MingeFitness::~MingeFitness()
{
	greutate = 0;
}

double MingeFitness::getGreutate()
{
	return this->greutate;
}

void MingeFitness::afisare()
{
	cout << " Minge      ";
	cout<< "     ";
	std::cout.width(5);
	cout << this->greutate << "kg";
	cout << "          ";
	this->afisareFitness();
}

Fitness *citesteMinge(char *c)
{
	Fitness *fit;
	fit = citesteFitness(c); 
	float ok, g;
	do{
		cout << "Introduceti greutatea (int kg):";
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
	return new MingeFitness(fit, g); 
}