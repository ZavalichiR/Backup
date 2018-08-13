#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

//Liste alocate static

struct element {
	char *data;
	int succ, prev;
};

//element v[8] = { { "v[0]",1,7 },{ "v[1]",2,0 } ,{ "v[2]",4,1 } ,{ "v[3]",6,-1 } ,{ "v[4]",5,2 } ,{ "v[5]",-1,4 } ,{ "v[6]",7,3 },{ "v[7]",0,6 } };

//element v[8] = { { "v[0]",1,6 },{ "v[1]",2,0 } ,{ "v[2]",4,1 } ,{ "v[3]",6,-1 } ,{ "v[4]",5,2 } ,{ "v[5]",-1,4 } ,{ "v[6]",0,3 },{ "v[7]",0,6 } };
//element v[9] = { { "v[0]",1,7 },{ "v[1]",2,0 } ,{ "v[2]",4,1 } ,{ "v[3]",6,-1 } ,{ "v[4]",5,2 } ,{ "v[5]",8,4 } ,{ "v[6]",7,3 },{ "v[7]",0,6 },{"v[8]",-1,5 } }; -element in coada
element v[10] = { { "v[0]",1,7 },{ "v[1]",2,0 } ,{ "v[2]",4,1 } ,{ "v[3]",6,9 } ,{ "v[4]",5,2 } ,{ "v[5]",8,4 } ,{ "v[6]",7,3 },{ "v[7]",0,6 },{ "v[8]",-1,5 }, { "v[9]",3,-1 }};//- element in fata

void AfisareCapCoada()
{
	int cap1;
	cap1 = 9;
	int crt;
	crt = cap1;
	while (crt != -1)
	{
		cout << v[crt].data <<" ";
		crt = v[crt].succ;
	}
}

void AfisareCoadaCap()
{
	int cap2;
	cap2 = 8;
	int crt=cap2;
	while (crt != -1)
	{
		cout << v[crt].data << " ";
		crt = v[crt].prev;
	}
}

//Liste alocate Dinamic


struct Nod{
	int data;
	Nod* succ,*prec;
};

void InserareFata(Nod *&lista, int val)
{
	Nod *p;
	p = new Nod;
	p->data = val;
	p->prec = 0;
	p->succ = lista;

	if (lista)
	{
		lista->prec = p;
	}
	lista = p;
}

void InserareCoada(Nod*&lista, int val)
{
	Nod *p;
	p = new Nod;
	p->data = val;
	p->succ = NULL;
	p->prec = NULL;
	if (lista == NULL)
	{
		lista = p;
	}
	else
	{
		Nod *q;
		q = lista;
		while (q->succ != NULL)
		{
			q = q->succ;
		}
		q->succ = p;
		p->prec = q;

	}

}
void Afisare(Nod *lista)
{
	Nod *p = lista, *q = lista;

	cout << "\n----Afisare Cap-Coada----";
	while (p)
	{
		cout << p->data << " ";
		
		q = p;
		p = p->succ;
		
	}
	
	cout << "\n----Afisare Coada-Cap----";
	while (q)
	{
		cout << q->data<<" ";
		q = q->prec;
	}
}

void Sterge(Nod *&lista, int val)
{
	if (lista == NULL)
	{
		return;
	}

	if (lista->data == val)
	{
	
		Nod*p = lista;
		if (lista->succ != 0)
		{
			lista->succ->prec = NULL;
		}
		lista = lista->succ;
		delete p;
		return;
	}

	Nod *p = lista;
	while (p&&p->data!=val)
	{
		p = p->succ;
	}
	if (p == 0)
	{
		return;
	}
	p->prec->succ = p->succ;
	if(p->succ!=0)
	{
		p->succ->prec = p->prec;
	}
}


void stergeIndex(Nod *&lista, int index)
{
	if (lista == NULL)
	{
		cout << "\nLista este goala" << endl;
		return;
	}
	Nod *p = lista;
	int i = 0;
	if (index == 0)
	{
		if (p->succ != 0)
		{
			p->succ->prec = 0;
		}
		p = p->succ;
		lista = p;
		delete p;

	}
	while (p && index != i)
	{
		i++;
		p = p->succ;
	}

	if (p == 0)
	{
		cout << "\n Indexul este prea mare" << endl;
		return;
	}

	p->prec->succ = p->succ;
	if (p->succ != 0)
	{
		p->succ->prec = p->prec;
	}
}


int main(void)
{
	///--------------------
	cout << "-----Lista dublu inlantuita alocata static-----\n\n\n";
	cout << "Afisare Cap-Coada" << endl;
	AfisareCapCoada();

	cout << "\n\nAfisare Coada-Cap " << endl;
	AfisareCoadaCap();


	//--------------------
	cout << "\n\n\n-----Lista dublu inlantuita alocata dinamic-----\n";
	int n;
	Nod*head = 0;
	cout << "\nPrecizati numarul de elemente: ";

	cin >> n;
	while (n)
	{
		InserareCoada(head, n);
		n--;
	}


	Afisare(head);

	
	int s = 1;
	while (s == 1)
	{
		cout << "\nValoarea pe care doriti sa o stergeti: ";
		int r;
		cin >> r;
		stergeIndex(head, 2);
		Sterge(head, r);
		Afisare(head);
		cout << "\n1-->Sterge alt element\n0-->Iesire din program\n;";
		cout << "Raspuns: ";
		cin >> s;
	}

	
	
	_getch();
	return 0;
}