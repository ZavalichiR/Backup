#include"Header.h"


void creare(Nod *&lista, int val,int index)
{
	if (lista == 0)
	{
		lista = new Nod;
		lista->data = val;
		lista->succ = lista;

	}
	
	else
	{
		Nod *p = lista;
		while (index)
		{
			p = p->succ;
			index--;
		}
		Nod *q = new Nod;
		q->data = val;
		q->succ = p->succ;
		p->succ = q;

	}
}


void afisare(Nod *lista)
{
	cout << lista->data<<" ";
	Nod *p = lista->succ;
	while (p!=lista)
	{
		cout << p->data<<" ";
		p=p->succ;
	}
	cout << endl;
}


void inversare_legaturi(Nod *&lista)
{
	if (lista==0)
	{
		return;
	}
	if (lista == lista->succ->succ)
	{
		return;
	}
	Nod *p = lista;
	Nod *q = p->succ;
	Nod *r = q->succ;
	do
	{
		q->succ = p;
		p = q;
		q = r;
		r = r->succ;
	} while (p != lista);
	lista = lista->succ;
}