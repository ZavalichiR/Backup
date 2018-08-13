#include"Header.h"

void inserare(Nod *&head, TD nou)
{
	Nod *q,*p = new Nod;
	p->data = nou;
	p->leg = 0;

	if (head == 0)
	{
		head = p;
	}
	else
	{
		q = head;
		while (q->leg)
		{
			q = q->leg;
		}
		q->leg = p;
	}
	
}

void afisare(Nod *lista)
{

	while (lista)
	{
		cout << lista->data <<" ";
		lista = lista->leg;
	}

}

void unireliste(Nod *&lista1, Nod *&lista2)
{
	Nod *p = lista1;

	while (p->leg)
	{
		p = p->leg;
	}
	p->leg = lista2;
	lista2 = 0;

}

int count(Nod *lista)
{
	int index=0;
	while (lista)
	{
		lista = lista->leg;
		index++;
	}

	return index;
}

void interclasare(Nod *&lista1, Nod *&lista2)
{
	Nod *p1;
	Nod *p2;

	if (count(lista1) > count(lista2))
	{
		p1 = lista1;
		p2 = lista2;

	}
	else
	{
		p1 = lista2;
		p2 = lista1;
	}

	Nod *newhead = p1;
	Nod *q=newhead;

	p1 = p1->leg;
	while (p2)
	{
		q->leg = p2;

		p2 = p2->leg;
		q = q->leg;

		q->leg = p1;
		p1 = p1->leg;
		q = q->leg;
	}

	lista1 = newhead;
	lista2 = 0;
}

void afisareMijloc(Nod *lista)
{
	Nod *p = lista, *q = lista->leg ;
	while (q)
	{
		p = p->leg;
		q = q->leg;
		if (q)
		{
			q = q->leg;
		}
	}
	cout << "Gasit: " << p->data << endl;

}
void EstiWaiBucla(Nod *lista)
{

	if (lista == 0 || lista->leg == 0)
	{

		cout << "Nu" << endl;
		return;
	}
	Nod *p = lista;
	Nod *q = lista->leg;


	while (q->leg)
	{
		p = p->leg;
		q = q->leg->leg;
		if (p == q)
		{
			cout << "Da" << endl;
			return;
		}
	}
	cout << "Nu" << endl;
	return;
}

void FaBucla(Nod *lista)
{
	Nod *p = lista;
	while (p->leg)
	{
		p = p->leg;
	}

	p->leg = lista;
}
