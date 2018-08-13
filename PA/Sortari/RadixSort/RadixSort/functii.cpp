#include "Header.h"


void InsereazaLista(Nod *&Head, int element)
{
	Nod *p = new Nod;
	p->next = 0;
	p->data = element;
	if (!Head)
		Head = p;
	else
	{
		Nod *q = Head;
		while (q->next)
			q = q->next;
		q->next = p;
	}
	
	
}

void afisareLista(Nod *Head)
{
	if (Head)
	{
		while (Head)
		{
			cout << Head->data << " ";
			Head = Head->next;
		}
	}
}


void StergereNod(Nod *&Head)
{
	if (Head == NULL)
	{
		return;
	}
	else
	{
		Nod *p = new Nod;
		p = Head->next;
		delete Head;
		Head = p;
	}
}

void concatenare(Nod *&Head1, Nod *Head2)
{
	Nod *p = Head1;
	if (p)
	{
		while (p->next)
			{
				p = p->next;
			}
	    p->next = Head2;
	}
	else
	{
		if (Head2)
			Head1 = Head2;
	}
}


void radixSort(Nod *&Head, int m)
{
	Nod *pachet[k];
	int i;
	int j;
	int w;
	int x;
	int y;
	int indice;
	for (i = m - 1; i >= 0; --i)
	{
		for (j = 0; j <= k - 1; ++j)
		{
			pachet[j] = new Nod;
			pachet[j] = 0;
		}
		//Impachetare
		while (Head != NULL)  
		{
			w = Head->data;
			StergereNod(Head);
			x = w / pow(10, m-i);
			y = w / pow(10, (m-i) - 1);
			indice = y - 10 * x;
			InsereazaLista(pachet[indice], w);
		}
		//Despachetare
		for (j = 0; j <= k - 1; ++j)  
		{
			concatenare(Head, pachet[j]);
		}
	}
}