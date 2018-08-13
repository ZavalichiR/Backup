#include"coada.h"
void initC(coada *&C)
{
	C = new coada;
	C->tail = 0;
	C->head = 0;
}
Nod *get(coada *&C)
{
	if (C->head == 0)
	{
		cout << "\nCoada este goala\n";
		return 0;
	}
	Nod *aux = C->head->data;
	elm *p = C->head;
	C->head = C->head->succ;
	delete p;
	p = nullptr;
	return aux;
}
void put(coada *&C, Nod *val)
{
	elm *p = new elm;
	p->data = val;
	p->succ = 0;
	if (C->head == 0)
	{
		C->tail = p;
		C->head = p;
	}
	else{
		C->tail->succ = p;
		C->tail = p;
	}
	
}