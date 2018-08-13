#include"Header.h"

void inserarePopescu(Nod *&Head, int val,int &c)
{
	Nod *p = new Nod;
	p->data = val;
	c =c+ 2;
	if (Head == 0)
	{
		p->succ = p;
		c++;
		Head = p;
		c++;
	}
	else
	{

		p->succ = Head;
		Nod *q = Head;
		c = c + 2;
		while (q->succ != Head)
		{
			q = q->succ;
			c++;
		}
			
		q->succ = p;
		c++;
		//Head = p; // capul va fi ultimul
	}

}
Nod *returnLast(Nod *head)
{
	Nod *p = head;
	if (head)
	{
		while (p->succ != head)
			p = p->succ;
	}
	return p;
}
void inserareIonescu(Nod *&Head, int val,int &c)
{
	Nod *p = new Nod;
	p->data = val;
	Nod*last = returnLast(Head);
	c =c+ 3;
	if (Head == 0)
	{
		p->succ = p;
		c++;
		Head = p;
		c++;
	}
	else
	{
		last->succ = p;
		c++;
		p->succ = Head;
		c++;
		last = p;
		c++;
	}
}
void afisare(Nod *lista)
{
	if (lista == 0)
		cout << "\nLista este vida\n";
	else
	{
		Nod *p = lista;
		while (p->succ != lista)
		{
			cout << p->data << " ";
			p = p->succ;
		}
		cout << p->data << endl;
	}
}



void inserare(Nod *&lista, int val,int &c)
{
	Nod *p = new Nod;
	p->data = val;
	c = c+2;
	if (lista == 0)
		{
			p->succ = p;
			c++;
			lista = p;
			c++;
		}
	else
		{
		int aux = lista->data;
		c++;
		p->succ = lista->succ;
		c++;
		lista->succ = p;
		c++;
		lista = p;
		c++;
		p->data = val;
		c++;
		lista->succ->data = aux;
		c++;
		}
}