#include<fstream>
using namespace std;
#include<assert.h>
#include<string.h>
#include "lista.h"
#pragma warning(disable : 4996)

fstream f("Magazin.txt");

char *citesteSirF() 
{
	char sir[50];
	char *s = 0;
	int a;
	f >> sir;
	a = strlen(sir) + 1;
	s = new char[a];
	assert(s);
	strcpy(s, sir);
	return s;
}

void Fitness::afisareFitnessF()
{
	f <<this->tip<<" "<<this->cod << " " <<  this->garantie->getAni() << " " << this->garantie->getLuni() << " " << this->pret;
	f << endl;
}

void Fitness::afisareF()
{
	this->afisareFitnessF();
	f << endl;//
}
Fitness *citesteFitnessF()
{
	unsigned int a, l;
	char *c, *tip;
	double p;
	tip = citesteSirF();
	c = citesteSirF();
	f >> a;
	f >> l;
	Garantie *g = new Garantie(a, l);
	f >> p;
	return new Fitness(tip,p,c,g); 
}

void Protectie::afisareF()
{
	f << " " << this->denumire<< " " << this->material<<" ";
	this->afisareFitnessF();
	
}

Fitness *citesteProtectieF()
{
	Fitness *fit = new Fitness(); 
	char *d;
	d = citesteSirF();
	char *m;
	m = citesteSirF();
	fit = citesteFitnessF();
	return new Protectie(fit,d, m);
	
}

void MingeFitness::afisareF()
{
	f << " " << this->greutate << " ";
	this->afisareFitnessF();
}

Fitness *citesteMingeFitnessF()
{
	Fitness *fit;
	float g; 
	f >> g;
	fit = citesteFitnessF();
	return new MingeFitness(fit, g);
}

void Greutati::afisareGreutatiF()
{
	f << " " << this->greutate << " ";
	this->afisareFitnessF();
}

void Greutati::afisareF()
{
	this->afisareGreutatiF();
	f << endl; //----
}

Fitness *citesteGreutatiF()
{
	Fitness *fit;
	float g;
	f >> g;
	fit = citesteFitnessF();
	return new Greutati(fit, g); 
}

void Gantere::afisareGantereF()
{
	f << " " << this->nrDiscuri << " ";
	this->afisareGreutatiF();
	
}

void Gantere::afisareF()
{
	this->afisareGantereF();
	//f << endl; //
}

Fitness *citesteGantereF()
{
	Fitness *fit;
	int nrd; 
	f >> nrd;
	float g;
	f >> g;
	fit = citesteFitnessF();
	return new Gantere(fit, g, nrd); 
}

void Haltere::afisareF()
{
	f << " " << this->dimensiune << " ";
	this->afisareGantereF();
}

Fitness *citesteHaltereF()
{
	Fitness *fit;
	
	double dim; 
	double g; 
	int nrd;
	f >> dim;
	f >> nrd;
	f >> g;
	fit = citesteFitnessF();
	return new Haltere(fit, g, nrd, dim); 
}

void deschideF()
{
	f.open("Magazin.txt", ios::out);
}

void inchideF()
{
	f.close();
}


void citireListe(Lista *lista1, Lista*lista2, Lista *lista3, Lista *lista4, Lista *lista5, Lista *lista6)
{
	int nr, i = 1; 
	f >> nr;
	f.get();
	Fitness *a = new Fitness(); 
	assert(a);
	while (i <= nr)
	{
		a = citesteProtectieF(); 
		(*lista1) += a; 
		i++;
		f.get();
	}
	i = 1;
	f >> nr;
	f.get();
	while (i <= nr)
	{
		a = citesteMingeFitnessF(); 
		(*lista2) += a; 
		f.get();
		i++;
	}
	i = 1;
	f >> nr;
	f.get();
	while (i <= nr)
	{
		a = citesteGreutatiF(); 
		(*lista3) += a; 
		i++;
		f.get();
	}
	i = 1;
	f >> nr;
	f.get();
	while (i <= nr)
	{
		a = citesteGantereF(); 
		(*lista4) += a; 
		i++;
		f.get();
	}
	i = 1;
	f >> nr;
	f.get();
	while (i <= nr)
	{
		a = citesteHaltereF();
		(*lista5) += a; 
		i++;
		f.get();
	}
	i = 1;
	f >> nr;
	f.get();
	while (i <= nr)
	{
		a = citesteFitnessF(); 
		(*lista6) += a; 
		i++;
		f.get();
	}
	inchideF();
}

void scrieListe(Lista *lista1, Lista*lista2, Lista *lista3, Lista *lista4, Lista *lista5, Lista *lista6)
{
	deschideF();
	f << endl;
	f << lista1->getNrEl() << endl; 
	lista1->afisareF();

	f << endl;
	f << lista2->getNrEl() << endl;
	lista2->afisareF();

	f << endl;
	f << lista3->getNrEl() << endl;
	lista3->afisareF();

	f << endl;
	f << lista4->getNrEl() << endl;
	lista4->afisareF();

	f << endl;
	f << lista5->getNrEl() << endl;
	lista5->afisareF();

	f << endl;
	f << lista6->getNrEl() << endl;
	lista6->afisareF();
	inchideF();
}