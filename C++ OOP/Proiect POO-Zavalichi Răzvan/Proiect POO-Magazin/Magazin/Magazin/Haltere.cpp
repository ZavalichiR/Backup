#include<string.h>
#include<iostream>
using namespace std;
#include<assert.h>
#include "Fitness.h"
#include"Haltere.h"
#include "globale.h"

Haltere::Haltere(Fitness *fit, double greutate, int nrDiscuri, double dimensiune) :Gantere(fit,greutate, nrDiscuri)
{
	this->dimensiune = dimensiune;
}

Haltere::~Haltere()
{
	//cout<<"\nDestructor Haltere\n"<<endl;
}

double Haltere::getDimensiune()
{
	return this->dimensiune;
}

void Haltere::afisare()
{
	cout << " Haltera      ";
	cout << this->dimensiune << "cm             ";
	std::cout << std::setw(2);
	cout << this->getNrDiscuri();
	cout << "  ";
	this->afisareGreutati();
}

Fitness *citesteHaltere(char *c)
{
	Fitness *fit;
	fit = citesteFitness(c); 
	double dim; 
	double g; 
	int nd; 
	cout << "Introduceti dimensiunea barei (in cm):";
	double ok;
	cin >> dim;
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

	int ok2;
	do{
		cout << "Introduceti numarul de discuri:";
		cin >> nd;
		ok2 = nd;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cin >> ok2;
		}
		nd = ok2;
	} while (nd<0);
	return new Haltere(fit,g,nd,dim); 
}