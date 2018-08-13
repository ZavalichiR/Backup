#ifndef _lista_
#define _lista_
#include"Protectie.h"
#include"MingeFitness.h"
#include"Greutati.h"
#include"Gantere.h"
#include"Haltere.h"
#include "Fitness.h"
#include<iomanip>

class Element
{
private:
	Fitness *produs; 
	Element *urm; 
public:
	Element() {}
	Element(Fitness *produs, Element *urm);
	Fitness *getFitness();
	Element *getUrmator();
	~Element();
	friend class Lista;
};

class Lista
{
private:
	Element *el;
	int nrEl;
public:
	Lista();
	~Lista();
	Element *getElement();
	int getNrEl();
	void operator += (Fitness *&p);
	void sterge(); 
	void afisare(); 
	int afisare2(int nr); 
	void afisareF(); 
};

void scrieListe(Lista *lista1, Lista*lista2, Lista *lista3, Lista *lista4, Lista *lista5, Lista *lista6); 
void citireListe(Lista *lista1, Lista*lista2, Lista *lista3, Lista *lista4, Lista *lista5, Lista *lista6); 
#endif