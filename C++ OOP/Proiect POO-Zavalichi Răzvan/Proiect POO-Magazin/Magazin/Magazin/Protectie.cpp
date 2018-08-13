#include<string.h>
#include<iostream>
#include<assert.h>
#include "Fitness.h"
#include"Protectie.h"
#include "globale.h"
using namespace std;


Protectie::Protectie(Fitness *fit,char *denumire,char *material) :Fitness(fit->getTip(),fit->getPret(), fit->getCod(), fit->getGarantie())
{
	this->material = new char[strlen(material) + 1]; 
	assert(this->material);
	strcpy(this->material, material);

	this->denumire = new char[strlen(denumire) + 1];
	assert(this->denumire);
	strcpy(this->denumire, denumire);
}

Protectie::~Protectie()
{
	if (material != NULL) delete[] material;
	if (denumire != NULL) delete[] denumire;
}

char *Protectie::getMaterial()
{
	return this->material;
}

char *Protectie::getDenumire()
{
	return this->denumire;
}

void Protectie::afisare()
{
	cout << " ";
	std::cout.width(11);
	cout << left << this->denumire;

	cout << "      ";
	std::cout.width(11);
	cout<<left << this->material << "     ";
	this->afisareFitness();
}

Fitness *citesteProtectie(char *c)
{
	Fitness *fit = new Fitness(); 
	char *d;
	cout << "Introduceti numele produsului:";
	d = citesteSir();
	char *m; 
	cout << "Introduceti tipul materialului:";
	m = citesteSir();
	fit = citesteFitness(c);
	return new Protectie(fit,d, m); 
}