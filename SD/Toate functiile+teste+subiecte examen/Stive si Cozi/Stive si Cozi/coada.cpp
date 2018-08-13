#include"coada.h"

//    Alocare Statica
void initt(coada1 &c)
{
	c.head = 0;
	c.tail = 0;
}
int nexPoz(int x)
{
	if (x < dim - 1)
		return x + 1;
	else
		return 0;
}
void put(coada1 &c, int val)
{
	//coada plina
	if (nexPoz(c.tail) == c.head)
	{
		cout << "\nCoada este plina\n";
		return;
	}
	else
	{
		c.vect[c.tail] = val;
		c.tail = nexPoz(c.tail);
	}
}
int get(coada1 &c)
{
	//coada goala
	if (c.head == c.tail){
		cout << "\nCoada este goala\n";
		return 0;
	}
	int aux = c.vect[c.head];
	c.head = nexPoz(c.head);
	return aux;
}
void front(coada1 &c)
{
	if (c.head == c.tail){
		cout << "\nCoada este goala\n";
		return;
	}
	else
		cout << c.vect[c.head] << endl;

}
void coada1Main()
{
	coada1 c;
	initt(c);
	cout << "\nElementul pe care il introduceti: ";
	int elm;
	cin >> elm;
	while (elm)
	{
		put(c, elm);
		cout << "\nElementul pe care il introduceti(!=0): ";
		cin >> elm;
	}

	cout << "\nFront: ";
	front(c);


	cout << "\nFaceti Get? (!=0  da) ";
	int elm2;
	cin >> elm2;
	while (elm2)
	{
		int val = get(c);
		if (val != 0)
			cout << val << endl;
		else
			cout << "\nCoada este goala\n";
		cout << "\nFaceti Get? (!=0  da) ";
		cin >> elm2;
	}

}

//    Alocare Dinamica

void inittC(coada2 *&c)
{
	c = new coada2;
	c->head = 0;
	c->tail = 0;
}
void putC(coada2 *&c, int val)
{
	element*p = new element;
	p->data = val;
	p->succ = 0;
	if (c->head == 0)
	{
		c->tail = p;
		c->head = p;
	}
	else
	{
		c->tail->succ = p;
		c->tail = p;
	}
}
int getC(coada2 *&c)
{
	if (c->head == 0)
	{
		cout << "\nCoada este goa\n";
		return 0;
	}
	else
	{
		int aux = c->head->data;
		element *p = c->head;
		c->head = c->head->succ;
		delete p;
		return aux;
	}
}
void frontC(coada2 *&c)
{
	if (c->head == 0)
	{
		cout << "\nCoada este goa\n";
		return;
	}
	else
		cout << c->head->data;
}
void coada2Main()
{
	coada2 *c;
	inittC(c);
	cout << "\nElementul pe care il introduceti: ";
	int elm;
	cin >> elm;
	while (elm)
	{
		putC(c, elm);
		cout << "\nElementul pe care il introduceti(!=0): ";
		cin >> elm;
	}

	cout << "\nFront: ";
	frontC(c);


	cout << "\nFaceti Get? (!=0  da) ";
	int elm2;
	cin >> elm2;
	while (elm2)
	{
		int val = getC(c);
		if (val != 0)
			cout << val << endl;
		else
			cout << "\nCoada este goala\n";
		cout << "\nFaceti Get? (!=0  da) ";
		cin >> elm2;
	}

}