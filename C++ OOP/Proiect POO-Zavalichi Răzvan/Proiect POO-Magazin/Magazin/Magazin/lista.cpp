#include<iostream>
#include<assert.h>
#include"lista.h"
#include"globale.h"
using namespace std;



Element::Element(Fitness *produs, Element *urm)
{
	this->produs=produs;
	this->urm=urm;
}

Element::~Element() 
{
	delete produs;
	produs = 0;
	urm = 0;
}

Fitness *Element::getFitness()
{
	return this->produs;
}

Element *Element::getUrmator() 
{
	return urm;
}



Lista::Lista() 
{
	this->el=0;
	this->nrEl=0;
}

Lista::~Lista() 
{
	Element *aux;
	while (el!=NULL) 
	{			 	
		aux=el; 
		el=el->urm; 
		delete aux; 
	}
	el=0;
}

Element *Lista::getElement() 
{
	return this->el;
}

int Lista::getNrEl() 
{
	return this->nrEl;
}

void Lista::operator+=(Fitness *&produs) 
{
	el=new Element(produs,el); 
	assert(el);
	nrEl++; 
}

void Lista::afisare()
{
	int i=0;
	Element *cap=el; 
	if (cap == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 28);
		cout << "Nu exista niciun produs!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	}
		
	else
	{
		while(cap!=NULL)
		{
			i++; 
			cout<<"   ";
			cap->produs->afisare(); 
			cap=cap->urm; 
		}
	}
}

int Lista::afisare2(int nr)
{
	int i=nr; 
	Element *cap=el; 
	if(cap!=0)
	{
		while(cap!=NULL)
		{
			i++; 
			cout<<"   "; 
			cap->produs->afisare(); 
			cap=cap->urm; 
		}
	}
	return i; 
}

void Lista::afisareF()
{
	Element *cap=el; 
		while(cap!=NULL)
		{

			cap->produs->afisareF(); 
			cap=cap->urm; 
		}
}

void Lista::sterge()
{
	Element *aux, *cap=el; 
	char *cod=new char;
	if (el == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 28);
		cout << "Lista este vida!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	}
	else
	{
		do
		{
			cout<<"Dati codul produsului pe care doriti sa il stergeti: ";
			cin >> cod;
		} while (cod == nullptr);
		if (strcmp(el->getFitness()->getCod(), cod)==0)
		{
			aux = el;
			el = el->urm;
			cap = el;
			delete aux;
			nrEl--;
		}
		else 
		{
			while (el->urm != 0 && strcmp(el->urm->getFitness()->getCod(), cod))
				el=el->urm; 
			if (el->urm == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 28);
				cout << "Produsul cu codul "<<cod<<" nu se afla in magazin." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
			}
			else
			{
				aux=el->urm; 
				el->urm=aux->urm; 
				delete aux; 
				nrEl--;
			}
		}
		el=cap; 
	}
}

		
