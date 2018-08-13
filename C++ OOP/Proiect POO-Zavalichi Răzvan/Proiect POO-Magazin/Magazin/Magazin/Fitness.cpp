#include<string.h>
#include<iostream>
#include<assert.h>
#include "lista.h"
#include "globale.h"
using namespace std;



Garantie::Garantie(int ani, int luni)
{
	this->ani = ani;
	this->luni = luni;
}

Garantie::~Garantie()
{
	ani = 0;
	luni = 0;
}

int Garantie::getAni()
{
	return this->ani;
}

int Garantie::getLuni()
{
	return this->luni;
}

Fitness::Fitness(char *tip,double pret,char *cod, Garantie *garantie)
{
	this->cod = new char[strlen(cod) + 1];
	assert(this->cod);
	strcpy(this->cod, cod);

	this->pret = pret;

	this->tip = new char[strlen(tip) + 1];
	assert(this->tip);
	strcpy(this->tip, tip);

	this->garantie = new Garantie(*garantie);
	assert(this->garantie);
}

Fitness::~Fitness()
{
	garantie = 0;
	if (cod != NULL) delete[] cod;
	if (tip != NULL) delete[] tip;
	pret = 0;
}

char *Fitness::getCod()
{
	return this->cod;
}

double Fitness::getPret()
{
	return this->pret;
}

char *Fitness::getTip()
{
	return this->tip;
}

Garantie *Fitness::getGarantie()
{
	return this->garantie;
}

void Fitness::afisareFitness()
{	
	int ok1 = 0, ok2 = 0;
	cout << " ";
	std::cout.width(10);
	cout<<left << this->tip;

	cout<< "      "; 
	std::cout.width(5); 
	cout<<left << this->pret << "lei ";

	cout << "      " << this->cod;

    cout<<"        ";
	if (this->garantie->getAni() > 0)
	{
		ok1 = 1;
		if (this->garantie->getAni() == 1)
			cout << this->garantie->getAni() << " an";
		else
			cout << this->garantie->getAni() << " ani";
	}
	if (this->garantie->getLuni()>0)
	{
		ok2 = 1;
		if (ok1==1)
			cout << " si ";
		cout << this->garantie->getLuni() << " luni";
	}
	if (ok1 == 0 && ok2 == 0)
		cout << "-";
	cout << endl;
	

}

void Fitness::afisare()
{
	this->afisareFitness();
}

Fitness *citesteFitness(char *cod)
{
	int a, l, ok;
	char *tip;
	cout << "Introduceti tipul produsului: ";
	tip = citesteSir();
	float p;
	cout << "Introduceti pretul(in lei):";
	cin >> p;

	cout << "Introduceti garantia:" << endl;
	do{
		cout << "ani(>0):";
		cin >> a;
		ok = a;
		while (cin.fail())   //verifica daca a citit un int
		{
			cin.clear();
			cin.ignore();
			cin >> ok;
		}
		a = ok;
	} while (a<0);
	do{
		cout << "luni(0-11):";
		cin >> l;
		ok = l;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cin >> ok;
		}
		l = ok;
	} while (l<0 || l>11);
	Garantie *ga = new Garantie(a, l);
	return new Fitness(tip,p,cod, ga);
}