#include"Header.h"

void initC(coada *&C)
{
	C = new coada;
	C->head = 0;
	C->tail = 0;
}
void put(coada *&C, Atom val)
{
	elm *p = new elm;
	p->data = val;
	p->succ = 0;

	if (C->head == 0)
	{
		C->tail = p;
		C->head = C->tail;

	}
	else
	{
		C->tail->succ = p;
		C->tail = p;
	}
}

Atom get(coada *&C)
{
	if (C->head == 0)
	{
		cout << "\nCoada este goala" << endl;
		EXIT_FAILURE;
	}
	Atom rezultat = C->head->data;
	elm *p = C->head;
	C->head = C->head->succ;
	delete p;
	return rezultat;

}

void coloreaza(pozitie p)
{
	coada *C;
	initC(C);
	put(C, p);
	while (C->head != 0)
	{
		Atom p = get(C);

	}
}