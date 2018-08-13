#include"Header.h"
void creare(Coada &C)
{
	C.head = C.tail = 0;
}
int isEmpty(Coada &C)
{
	if (C.head == C.tail)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int nextPoz(int index)
{
	if (index < dim - 1)
	{
		return index + 1;
	}
	else
	{
		return 0;
	}
}
void put(Coada &C, Atom a)
{
	/*if (C.tail == dim)
	{
		cout << "Coada liniara plina" << endl;
		return;
	}
	C.vect[C.tail] = a;
	C.tail = C.tail+1;*/
	

	if (nextPoz(C.tail) != C.head)
	{
		C.vect[C.tail] = a;
		C.tail = nextPoz(C.tail);
	}
	

}

Atom get(Coada &C)
{
	Atom rezultat;
	if (C.tail == C.head)// si pentru  circuilara
	{
		cout << "GET ERROR-e goala" << endl;
	}
	rezultat = C.vect[C.head];

	C.head = (C.head + 1) % dim; //h=h+1 circularizat
	//C.tail = nextPos(C.tail)// pentru coada circulara
	return rezultat;
}

void afisareCoada(Coada &C)
{
	while (isEmpty(C) == 0)
	{
		cout << get(C) << " ";
	}
}

void TestCoadaCirculara()
{
	Coada c;
	creare(c);

	put(c, 1);
	put(c, 2);
	put(c, 3);
	put(c, 1);
	put(c, 2);
	put(c, 3);
	cout << get(c) << endl;
	afisareCoada(c);
}