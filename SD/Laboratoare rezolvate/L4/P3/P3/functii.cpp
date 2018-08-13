#include"Header.h"

void creare(Nod *&lista, int val)
{
	int index = 1;
	if (lista == 0)
	{
		lista = new Nod;
		lista->data = val;
		lista->succ = lista;
	}
	
	else 
	{
		Nod *p = lista;
		while (p &&  index != 0)
		{

			p = p->succ;
			index--;
		}

	
			Nod *Elm = new Nod;
			Elm->data = val;
			Elm->succ = p->succ;
			p->succ = Elm;

	}

}

void afisare(Nod *lista)
{
	Nod *p = lista;
	if (p == 0)
	{
		return;
	}
	else
	{
		cout << p->data << " ";
		p = p->succ;
	}
	
	
	while (p!=lista) 
	{
		cout << p->data<<" ";
		p = p->succ;
	}
}

void unire(Nod *&lista1, Nod *&lista2)
{
	if (lista2==0)
	{
		return;
	}
	if (lista1 == 0)
	{
		lista1 = lista2;
		lista2 = nullptr;
		return;
	}
	Nod *p = lista1;
	while (p->succ != lista1)
	{
		p = p->succ;
	}
	p->succ = lista2;
	//p = p->succ;
	p = p->succ;
	while (p->succ != lista2)
	{
		p = p->succ;
	}
	p->succ = lista1;
	//p = p->succ;
	lista2 = nullptr;
}

int count(Nod *lista)
{
	int c=1;
	Nod *p = lista;
	while (p->succ != lista)
	{
		++c;
		p = p->succ;
	}
	return c;
}

void intercalare(Nod *&lista1, Nod *&lista2)
{
	int l1 = count(lista1);
	int l2 = count(lista2);
	
	
	Nod *p = lista1;
	Nod *q = lista2;

	if (l1 < l2)
	{
		p = lista1;
		q = lista2;
	}
	if (l2 > l1)
	{
		p = lista2;
		q = lista1;
	}

	Nod *p1 = p;
	Nod *q1 = q;
	Nod *p2 = p->succ;
	Nod *q2 = q->succ;
	int i = 0;

	do
	{
		p1->succ = q1;
		q1->succ = p2;
		
		p1 = p2;
		p2 = p2->succ;
		
		
		q1 = q2;
		q2 = q2->succ;

		cout << "!" << ++i << "!" << endl;

	} while (q1!=q);
	
	lista1 = p;
	lista2 = nullptr;
}

Nod *intrercalare2(Nod *lista1, Nod *lista2)
{
	Nod *lista3;
	Nod *cap3;
	Nod *cap1 = lista1;
	Nod *cap2 = lista2;
	if (lista1 == 0)
	{
		lista3 = lista2;
		return 0;
	}
	if (lista2 == 0)
	{
		lista3 = lista1;
		return 0;
	}

	lista3 = new Nod;
	cap3 = lista3;
	lista3->data = lista1->data;
	lista1 =  lista1->succ;
	lista3->succ = new Nod;
	lista3 = lista3->succ;
	lista3->data = lista2->data;
	lista2 = lista2->succ;
	while (lista1 != cap1 && lista2 != cap2)
	{
		lista3->succ = new Nod;
		lista3 = lista3->succ;
		lista3->data = lista1->data;
		lista1 = lista1->succ;

		lista3->succ = new Nod;
		lista3 = lista3->succ;
		lista3->data = lista2->data;
		lista2 = lista2->succ;
		
	}
	while (lista1 != cap1)
	{
		lista3->succ = new Nod;
		lista3 = lista3->succ;
		lista3->data = lista1->data;
		lista1 = lista1->succ;
	}

	while (lista2 != cap2)
	{
		lista3->succ = new Nod;
		lista3 = lista3->succ;
		lista3->data = lista2->data;
		lista2 = lista2->succ;
	}
	lista3->succ = cap3;
	return cap3;
}
