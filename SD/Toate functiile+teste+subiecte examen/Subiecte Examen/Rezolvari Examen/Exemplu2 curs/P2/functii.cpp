#include"Header.h"
void inserare(Nod *&lista, int val)
{
		Nod *p = new Nod;
		p->data = val;
		p->succ = lista;
		lista = p;
		return;
}
void afisare(Nod *lista)
{
	if (lista)
	{
		afisare(lista->succ);
		cout << lista->data << " ";
	}
}
Nod *schimbareLegaturi(Nod *&lista)
{
	if (!lista)
	{
		cout << "Lista vida" << endl;
		return 0;
	}
	Nod *p = lista;
	Nod *q = p->succ;
	Nod *r = p->succ->succ;
	p->succ = 0;
	while (r->succ)
	{
		q->succ = p;
		p = q;
		q = r;
		r = r->succ;
	}
	q->succ = p;
	r->succ = q;
	return r;
}
int index = 1;
void sterge(Nod *&lista, int poz)//sterge dupa pozitie de la coada la cap
{
	if (lista)
	{
		sterge(lista->succ, poz);
		index += 1;
		if (index == poz + 1)
		{
			Nod*elm = lista;
			lista = lista->succ;
			delete elm;
			EXIT_SUCCESS;
		}


	}
}

//void sterge(Nod *&lista, int poz)
//{
//	int index = 1;
//	if (!lista)
//		return;
//	if (poz == index)
//	{
//		Nod *elm = lista;
//		lista = lista->succ;
//		delete elm;
//	}
//	else
//	{
//		Nod *p = lista;
//		while (p->succ && poz != index+1)
//		{
//			p = p->succ;
//			index++;
//		}
//			
//		if (p->succ && poz == index+1)
//		{
//			Nod *elm = p->succ;
//			p->succ= p->succ->succ;
//			delete elm;
//			return;
//		}
//	}
//
//	
//}

void ordonare(Nod *&lista)
{
	int ok = 1;
	while (ok)
	{
		ok = 0;
		Nod*p = lista;
		while (p->succ)
		{
			if (p->data > p->succ->data)
			{
				int aux = p->data;
				p->data = p->succ->data;
				p -> succ->data = aux;
				ok = 1;
			}
			p = p->succ;
				

		}
	}
}