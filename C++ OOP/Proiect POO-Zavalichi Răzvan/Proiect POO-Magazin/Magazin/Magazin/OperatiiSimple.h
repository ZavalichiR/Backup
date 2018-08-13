#include "meniu.h"
#include "lista.h"

#ifndef _operatiiSimple_
#define _operatiiSimple_

class ElementDespre :public Operatie
{
public:
	ElementDespre(char *nume);
	void execOperatie();
};

class OpAdaugareInLista :public Operatie 
{
protected:
	Lista *lista;
	Fitness *fit; 
public:
	OpAdaugareInLista(char *nume, Lista *&lista);
	virtual void execOperatie() = 0;
};

class OpAdaugareProdusNou :public OpAdaugareInLista 
{
public:
	OpAdaugareProdusNou(char *nume, Lista *&lista);
	void execOperatie();
};

class OpAdaugareProtectie :public OpAdaugareInLista  
{
public:
	OpAdaugareProtectie(char *nume, Lista *&lista);
	void execOperatie();
};

class OpAdaugareMingeFitness :public OpAdaugareInLista  
{
public:
	OpAdaugareMingeFitness(char *nume, Lista *&lista);
	void execOperatie();
};

//class OpAdaugareGreutati :public OpAdaugareInLista 
//{
//public:
//	OpAdaugareGreutati(char *nume, Lista *&lista);
//	void execOperatie();
//};

class OpAdaugareGantere : public OpAdaugareInLista 
{
public:
	OpAdaugareGantere(char *nume, Lista *&lista);
	void execOperatie();
};

class OpAdaugareHaltere : public OpAdaugareInLista 
{
public:
	OpAdaugareHaltere(char *nume, Lista *&lista);
	void execOperatie();
};


class OpAfisareLista :public Operatie
{
private:
	Lista *lista;
public:
	OpAfisareLista(char *nume, Lista *lista);
	void execOperatie();
};

class OpAfisareLista1 :public Operatie
{
private:
	Lista *lista;
public:
	OpAfisareLista1(char *nume, Lista *lista);
	void execOperatie();
};

class OpAfisareLista2 :public Operatie
{
private:
	Lista *lista;
public:
	OpAfisareLista2(char *nume, Lista *lista);
	void execOperatie();
};

class OpAfisareLista3 :public Operatie
{
private:
	Lista *lista;
public:
	OpAfisareLista3(char *nume, Lista *lista);
	void execOperatie();
};

class OpAfisareLista4 :public Operatie
{
private:
	Lista *lista;
public:
	OpAfisareLista4(char *nume, Lista *lista);
	void execOperatie();
};

class OpAfisareListeProduse :public Operatie 
{
private:
	Lista *lista1, *lista2, *lista3, *lista4, *lista5, *lista6;
public:
	OpAfisareListeProduse(char *nume, Lista *lista1, Lista *lista2, Lista *lista3, Lista *lista4, Lista *lista5, Lista *lista6);
	void execOperatie();
};

class OpAfisareListeForta :public Operatie 
{
private:
	Lista *lista1, *lista2, *lista3, *lista4;
public:
	OpAfisareListeForta(char *nume, Lista *lista1, Lista *lista2, Lista *lista3, Lista *lista4);
	void execOperatie();
};

class OpAfisareListeGreutati :public Operatie 
{
private:
	Lista *lista1, *lista2;
public:
	OpAfisareListeGreutati(char *nume, Lista *lista1, Lista *lista2);
	void execOperatie();
};

class OpCautareDupaCod :public Operatie 
{
private:
	Lista *lista;
public:
	OpCautareDupaCod(char *nume, Lista *lista);
	void execOperatie();
};

class OpStergereInLista :public Operatie
{
private:
	Lista *lista;
public:
	OpStergereInLista(char *nume, Lista *&lista);
	void execOperatie();
};

int verificareCod(char *c, char *ch, Lista *lista);

#endif