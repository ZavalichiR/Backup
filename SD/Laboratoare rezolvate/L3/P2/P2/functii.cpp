#include"Header.h"


void inserare(Nod *&cap, persoana val)
{
	Nod *element = new Nod;
	element->data = val;
	element->leg = cap;
	cap = element;

	}
void insertOrder(Nod *&lista, persoana val)
{
	if (lista == 0)
	{
		lista = new Nod;
		lista->data = val;
		lista->leg = 0;

		return;
	}

	if (strcmp(val.nume, lista->data.nume) < 0)
	{
		Nod *element = new Nod;
		element->data = val;
		element->leg = lista;
		lista = element;

		return;
	}

	Nod *p, *q;

	p = lista->leg;
	q = lista;

	while (p && strcmp(val.nume, p->data.nume)>0)
	{
		p = p->leg;
		q = q->leg;
	}

	Nod *element = new Nod;
	element->data = val;
	element->leg = p;
	q->leg = element;
}





void persoana::citireAgenda()
{

	cout << "Numar telefon :";
	cin >> nrt;
	cin.ignore(100, '\n');
	cout << "Nume: ";
	cin.getline(nume,100);

	


}

void afisareAgenda(persoana data)
{
	cout << "Nume: " << data.nume << endl;
	cout << "Numar telefon: " << data.nrt << endl;

}
void afisare(Nod *lista)
{
	while (lista!=NULL)
	{

		afisareAgenda(lista->data);
		lista = lista->leg;
	}
}

void stergere(Nod *&lista,char nume[100])
{
	if (lista == NULL)
	{
		return;
	}
	if (!strcmp(lista->data.nume,nume)) // sunt egale
	{
		cout << "Primul" << endl;
		Nod *p = lista;
		lista = lista->leg;
		delete p;
		return;
	}

	Nod *elm = lista;
	while (elm->leg != NULL && strcmp(elm->leg->data.nume,nume))
	{
		elm = elm->leg;
		
	}
	if (elm->leg != NULL && strcmp(elm->data.nume,nume))
	{
		Nod *desters = elm->leg;
		elm->leg = elm->leg->leg;
		delete desters;
	}
}

void cautare(Nod *&lista, int nrt)
{
	if (lista == 0)
	{
		cout << "Lista este goala" << endl;

		return;
	}
	Nod *p = lista;

	int index = 0;
	while (p && nrt!=p->data.nrt)
	{
		++index;
		p = p->leg;
	}

	if (p)
	{
		cout << "Index: " << index << endl;
		cout << "Numele este: " << p->data.nume << endl;
	}


}