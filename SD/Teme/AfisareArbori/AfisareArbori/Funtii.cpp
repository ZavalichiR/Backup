#include"Header.h"
void initS(Stiva *&S)
{
	S = nullptr;
}
void creareS(Stiva *&S)
{
	S = 0;
}
void push(Stiva *&S, Nod *val)
{
	Stiva *p = new Stiva;
	if (p == 0)
	{
		return;
	}
	p->data = val;
	p->leg = S;
	S = p;

}
Nod* pop(Stiva *&S)
{
	if (S == 0)
	{
		cout << "\nStiva este goala-POP" << endl;
		EXIT_FAILURE;
	}

	Nod *rezultat = S->data;
	Stiva *p = S;
	S = S->leg;
	delete p;

	return rezultat;
}

void adauga(Nod*&a,char valoare)
{
	if (a==NULL)
	{
		a = new Nod;
		a->data = valoare;
		a->stanga = 0;
		a->dreapta = 0;
		return;
	}

	if (valoare < a->data)
	{
		adauga(a->stanga,valoare);
		
	}
	else
	{
		adauga(a->dreapta,valoare);
	}
	
}
Nod* creare()
{
	system("cls");
	system("color 04");
	Nod *radacina = NULL;
	char text[100];
	char data;
	int i = 0;
	cout << "Sirul de caractere (Apasati tasta 0 pentru a indica finanul sirului): ";
	cin.ignore(100, '\n');
	cin.getline(text, 100);
	data = text[0];

	while (data != '0' && i<strlen(text))
	{
		i = i + 1;
		adauga(radacina, data);
		data = text[i];
	}
	return radacina;
}

void inordineRecursiv(Nod *a)
{
	if (a)
	{
		inordineRecursiv(a->stanga);
		cout << a->data << " ";
		inordineRecursiv(a->dreapta);
	}
}
void inordineIterativ(Nod*a)
{
	Stiva *S;
	initS(S);
	Nod *p = a;
	while (p || S != 0)
	{
		if (p == 0)
		{
			p = pop(S);
			cout << p->data << " ";
			p = p->dreapta;
		}
		else
		{
			push(S, p);
			p = p->stanga;
		}
	}

}

void postordineRecursiv(Nod *a)
{
	if (a)
	{
		postordineRecursiv(a->stanga);
		postordineRecursiv(a->dreapta);
		cout << a->data << " ";
	}
}
void postordineIterativ(Nod *a)
{
	Stiva *S;
	S = nullptr;
	Stiva *S2;
	S2 = nullptr;
	Nod *p = a;
	push(S, p);
	while (S!=0)
	{
		p = pop(S);
		push(S2, p);
		if (p->stanga)
			push(S, p->stanga);
		if (p->dreapta)
			push(S, p->dreapta);
	}
	while (S2!=0)
	{
		cout << pop(S2)->data << " ";
	}
	cout << endl;

}

void preordineRecursiv(Nod *a)
{
	if (a)
	{
		cout << a->data << " ";
		preordineRecursiv(a->stanga);
		preordineRecursiv(a->dreapta);
	}
}
void preordineIterativ(Nod *a)
{
	Stiva *S = new Stiva;
	S = nullptr;
	Nod*p = new Nod;
	if (!a)
		cout << "arbore vid" << endl;
	else
	{
		push(S, a);
		while (S!=0)
		{
			p = pop(S);
			cout << p->data << " ";
			if (p->dreapta)
				push(S, p->dreapta);
			if (p->stanga)
				push(S, p->stanga);
		}
	}
	cout << endl;
}

