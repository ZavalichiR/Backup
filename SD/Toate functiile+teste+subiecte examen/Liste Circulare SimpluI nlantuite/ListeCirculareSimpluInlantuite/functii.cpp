#include"Header.h"
//-----Ambele functii pentru inserare sunt corecte-------
void inserare(Nod *&lista, int val)
{
	Nod *p = new Nod;
	p->data = val;
	if (lista == 0)
	{
		p->succ = p;
		lista = p;
		return;
	}
	else
	{
		p->succ = lista;
		Nod *q = lista;
		while (q->succ!=lista)
			q = q->succ;
		q->succ = p;
		lista = p;
	}
		
}
//void inserare(Nod *&lista, int val)
//{
//	Nod *p = new Nod;
//	p->data = val;
//	if (lista == 0)
//	{
//		p->succ = p;
//		lista = p;
//	}
//	else
//	{
//		p->succ = lista->succ; /insereaza elemntul in dreapta capului
//		lista->succ = p;
//		lista = p;
//	}
//}

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
void afisarePermutari(Nod *lista)
{
	if (lista == 0)
	{
		cout << "\nLista vida\n";
		return;
	}
	else
	{
		cout << "\nPermutarile: \n";
		Nod *p = new Nod;
		p = lista;
		while (p->succ != lista)
		{
			afisare(p);
			p = p->succ;
		}
		afisare(p);
	}
}
void stergere(Nod *&lista, int val)
{
	if (lista == nullptr)
	{
		cout << "\nLista vida\n";
		return;
	}
	// verifica daca lista mai are doar un element
	if (lista->succ == lista)
	{
		cout << "\nSe sterge singurul element din lista\n";
		delete lista;
		lista = nullptr;
		return;
	}
	Nod *p = lista;
	while (p->succ != lista && p->succ->data != val)
		p = p->succ;
	if (p->succ->data == val)
	{
		Nod *elm = p->succ;
		// verifica daca lista mai are doar un element
		//if (p == p->succ)  
		//{
		//	delete p;
		//	lista = nullptr;
		//	return;
		//}
		p->succ = p->succ->succ;
		lista = p;
		delete elm;
	}
	
	// PS: Ambele functii de stergere a singurului element din lista
	//   functioneaza perfect	
}
void cautare(Nod *lista, int val)
{
	if (lista == 0)
	{
		cout << "\nLista vida\n";
		return;
	}
	Nod *p = lista;
	while (p->succ != lista && p->succ->data != val)
		p = p->succ;
	if (p->succ->data == val)
	{
		cout << "\nElementul " << p->succ->data << " a fost gasit\n";
		return;
	}
	else
	{
		cout << "\nElementul " << val << " nu a fost gasit\n";
		return;
	}
		
		
}
//-----Ambele functii pentru unire sunt corecte-----
Nod *unire(Nod *&lista1, Nod *&lista2)
{
	Nod *lista = new Nod;
	if (lista2 == nullptr)
		return lista = lista1;
	if (lista1 == nullptr)
		return lista = lista2;

	lista = lista1;
	Nod *p = lista1;
	while (p->succ != lista1)
		p = p->succ;
	p->succ = lista2;
	Nod *q = lista2;
	while (q->succ != lista2)
		q = q->succ;
	q->succ = lista1;
	return lista;
}
void unire2(Nod *&lista1, Nod *&lista2)
{
	if (lista1 == 0)
	{
		lista1 = lista2;
		lista2 = nullptr;
		return;
	}
	if (lista2 == 0)
		return;

	Nod *p = lista1;
	while (p->succ != lista1)
		p = p->succ;
	p->succ = lista2;
	p = p->succ;
	while (p->succ != lista2)
		p = p->succ;
	p->succ = lista1;
	lista2 = nullptr;
}

int count(Nod *lista)
{
	int i = 1;
	Nod *p = lista;
	if (p == 0)
		return 0;
	while (p->succ != lista)
	{
		p=p->succ;
		i++;
	}
	return i;
}
void interclasare(Nod *&lista1, Nod*&lista2)
{
	int l1 = count(lista1);
	int l2 = count(lista2);
	Nod *p, *q;
	if (l2 == 0)
		return;
	if (l1 == 0)
	{
		lista1 = lista2;
		return;
	}
	if (l1 <= l2)
	{
		p = lista1;
		q = lista2;
	}
		
	else
	{
		p = lista2;
		q = lista1;
	}
	Nod *p1 = p, 
		*p2 = p->succ;
	Nod *q1 = q, 
		*q2 = q->succ;

	while (p2 != p)
	{
		p1->succ = q1;
		q1->succ = p2;

		p1= p2;
		p2 = p2->succ;

		q1 = q2;
		q2 = q2->succ;
	}
	p1->succ = q1;
	q1->succ = q2;
	//q2 = q2->succ; //merge si cu
	while (q2->succ != q)
		q2 = q2->succ;
	q2->succ = p;
	

	lista1 = p;
	lista2 = nullptr;

}