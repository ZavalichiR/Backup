#include"Header.h"

void init(Coada *&C)
{
	C = new Coada;
	C->head = 0;
	C->tail = 0;
}
void put(Coada *&C, Nod *val)
{
	Elm *p = new Elm;
	p->data = val;
	p->succ = 0;
	if (C->head == 0)
	{
		C->tail = p;
		C->head = p;
	}
	else
	{
		C->tail->succ = p;
		C->tail = p;
	}
}

Nod *get(Coada *&C)
{
	if (C->head == 0)
	{
		cout << "\nCoada este goala\n" << endl;
		return 0;
	}
	Nod *aux = C->head->data;
	Elm *p = C->head;
	C->head = C->head->succ;
	delete p;
	p = nullptr;
	return aux;

}
Nod *makeNod(tip val)
{
	Nod *p = new Nod;
	p->data = val;
	p->drt = 0;
	p->stg = 0;
	return p;
}
void inserare(Nod *&arbore, tip val)
{
	if (arbore == 0)
		arbore = makeNod(val);
	else
	{
		if (val < arbore->data)
			inserare(arbore->stg, val);
		else
			if (val>arbore->data)
				inserare(arbore->drt, val);
		else
			cout << "Valoarea: " << val << " exista deja in arbore" << endl;
	}
	
}
void afisare(Nod *arbore)
{
	Coada *C;
	init(C);
	Nod *p = new Nod;
	if (arbore)
	{
		put(C, arbore);
		while (C->head)
		{
			p = get(C);
			cout << p->data << " ";
			if (p->stg)
				put(C, p->stg);
			if (p->drt)
				put(C , p->drt);
		}

	}
}
void inordine(Nod *arbore)
{
	if (arbore)
	{
		inordine(arbore->stg);
		cout << arbore->data << " ";
		inordine(arbore->drt);
	}
}
int adancime(Nod *arbore)
{
	int h1=1, h2 = 1;
	if (arbore == 0)
		return 0;
	if (arbore->stg)
		h1 += adancime(arbore->drt);
	if (arbore->drt)
		h2 += adancime(arbore->stg);
	return h1 > h2 ? h1 : h2;
}
int nrNoduri(Nod *arbore)
{
	if (arbore == 0)
		return 0;
	if (arbore->stg == 0 && arbore->drt == 0)
		return 0;
	return 1 + nrNoduri(arbore->stg) + nrNoduri(arbore->drt);
}