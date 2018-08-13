#include"Header.h"
void inserareFata(Nod *&head, int val)
{

	Nod *p = new Nod;
	p->data = val;
	p->succ = head;
	p->prev = 0;
	if (head != 0)
		head->prev = p;
	head = p;
}
void inserareCoada(Nod *&head, int val)
{
	Nod *p = new Nod;
	p->data = val;
	p->succ = 0;
	p->prev = 0;
	if (head == 0)
		head = p;
	else
	{
		Nod *q = head;
		while (q->succ)
			q = q->succ;
		q->succ = p;
		p->prev = q;
	}

}
void afisare(Nod *head)
{
	Nod *p = new Nod;
	p = head;
	Nod *q = new Nod;
	q = head;
	cout << "\nAfisare Cap-Coada" << endl;
	while (p)
	{
		cout << p->data << " ";
		q = p;
		p = p->succ;
	}
	cout << "\nAfisare Coada-Cap" << endl;
	while (q)
	{
		cout << q->data << " ";
		q = q->prev;
	}
}
void cautare(Nod *head, int val)
{
	Nod *p = new Nod;
	p = head;
	int i = 1;
	if (!p)
	{
		cout << "Lista vida" << endl;
		return;
	}

	while (p->succ && p->data != val)
	{
		p = p->succ;
		i++;
	}
	if (p->data==val)
	{
		cout << "Elementul: " << p->data << " a fost gasit pe pozitia: " << i << endl;
		return;
	}
	else
	{
		cout << "Elementul: " << val << " nu se afla in lista" << endl;
		return;
	}
}
void stergere(Nod *&head, int val)
{
	if (head == 0)
	{
		cout << "\ntoate elementele au fos sterse sau lista este goala-" << endl;
		return;
	}
	if (head->data == val)
	{
		Nod *p = head;
		/*if (head->succ != 0)
		{
			head->succ->prev = 0;
		}*/
		head = head->succ;
		head->prev = 0;
		delete p;
		return;
	}

	Nod *p = head;
	while (p && p->data != val)
	{
		p = p->succ;
	}

	if (p && p->data == val)
	{
		Nod *elm = p;
		p->prev->succ = p->succ;
		if (p->succ != 0)
			p->succ->prev = p->prev;
		delete elm;
	}
	else
		cout << "\n Elementul nu se afla in lista " << endl;

}
void inserarePozitie(Nod *&head, int val, int poz)
{
	int index = 1;
	if (head == 0)
	{
		cout << "\nLista este vida\n";
		return;
	}
	if (poz==index)
	{
		Nod *p = new Nod;
		p->data = val;
		p->succ = head;
		p->prev = 0;
		if (head!=0)
			head->prev = p;
		head = p;
		return;
	}
	Nod *p = head;
	while (p)
	{
		if (poz == (index + 1))
		{
			Nod *elm = new Nod;
			elm->data = val;
			elm->succ = p->succ;
			p->succ->prev = elm;
			p->succ = elm;
			elm->prev = p;	
			return;
		}
		p = p->succ;
		index++;
	}
	if (poz > index)
	{
		cout << "Lista este prea scurta" << endl;
		return;
	}
}
