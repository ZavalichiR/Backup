
#include "Header.h"
#include"coada.h"
#include"stiva.h"

char car;
//-------------Anexa--------------
void eroare()
{
	printf("Sirul de intrare este eronat!\n");
	printf("Apasati tasta o tasta...");
	system("pause");
	exit(1);
}
char readchar()
{
	char c;
	do  c = getchar();  while (c == ' ');
	return c;
}
char citesteNume()
{
	char c;
	if (!isalpha(car)) eroare();
	c = car;
	car = readchar();
	return c;
}
Nod* citesteArbore()
{
	Nod* rad;
	if (car == '-')  {
		rad = 0;
		car = readchar();
	}
	else {
		rad = (Nod*)malloc(sizeof(Nod));
		rad->data = citesteNume();
		if (car != '(')  {
			rad->stg = 0;
			rad->drt = 0;
		}
		else {
			car = readchar();
			rad->stg = citesteArbore();
			if (car != ',')    rad->drt = 0;
			else {
				car = readchar();
				rad->drt = citesteArbore();
			}
			if (car != ')')  eroare();
			car = readchar();
		}
	}
	return rad;
}
Nod* creareArbore()
{
	printf("\nIntroduceti arborele:");
	car = readchar();
	return citesteArbore();
}
//--------------------------------
void inordine(Nod *rad)
{
	if (rad)
	{
		inordine(rad->stg);
		cout << rad->data << " ";
		inordine(rad->drt);
	}
}
void preordine(Nod *rad)
{
	if (rad)
	{
		cout << rad->data << " ";
		preordine(rad->stg);
		preordine(rad->drt);
	}
}
void postordine(Nod *rad)
{
	if (rad)
	{
		postordine(rad->stg);
		postordine(rad->drt);
		cout << rad->data << " ";
	}
}
void afisareIntend(Nod *rad, int nivel)
{
	for (int i = 0; i < nivel; ++i)
	{
		cout << "\t";
	}
	if (rad == 0)
		cout << "-" << endl;
	else
	{
		cout << rad->data << endl;
		afisareIntend(rad->stg, nivel + 1);
		afisareIntend(rad->drt, nivel + 1);
	}
}
int adancime(Nod *rad)
{
	int h1 = 1 , h2 = 1;
	if (rad == 0)
		return 0;
	else
	{
		h1 += adancime(rad->stg);
		h2 += adancime(rad->drt);
	}
	if (h1 > h2)
		return h1;
	else
	return h2;
}
int frunze(Nod *rad)
{
	if (rad == 0)
		return 0;
	if (rad->stg == 0 && rad->drt == 0)
		return 1;
	return frunze(rad->stg) + frunze(rad->drt);

}
int nrnoduri(Nod *rad)
{
	if (rad == 0)
		return 0;
	if (rad->stg == 0 && rad->drt == 0)
		return 0;
	return 1 + nrnoduri(rad->stg) + nrnoduri(rad->drt);
}
void comuta(Nod *rad)
{
	Nod *aux;
	if (rad)
	{
		aux = rad->stg;
		rad->stg = rad->drt;
		rad->drt = aux;
		comuta(rad->stg);
		comuta(rad->drt);
	}
}
char Max(Nod *p)
{
	char a = 0, b;
	if (p)
	{
		if (p->data>a)
			a = p->data;
		b = Max(p->stg);
		if (b>a)
			a = b;
		b = Max(p->drt);
		if (b>a)
			a = b;
	}
	return a;
}
char Min(Nod *p)
{
	char a = 'z' + 1, b;
	if (p)
	{
		if (p->data<a)
			a = p->data;
		b = Min(p->stg);
		if (b<a)
			a = b;
		b = Min(p->drt);
		if (b<a)
			a = b;
	}
	return a;
}
void afisareLinie(Nod *rad)
{
	Nod *p = new Nod;
	coada *C;
	initC(C);
	p = rad;
	if (p)
	{
		put(C, p);
		while (C->head)
		{
			p = get(C);
			cout << p->data << " ";
			if (p->stg)
				put(C, p->stg);
			if (p->drt)
				put(C, p->drt);
		}

	}

}
Nod *creareArbore(char *expresie)
{
	char ch;
	Nod *p = 0;
	stiva *S;
	initS(S);
	while (ch = *expresie++)
	{
		p = new Nod;
		p->data = ch;
		if (isdigit(ch))
		{
			p->stg = NULL;
			p->drt = NULL;
		}
		else
		{
			p->drt = pop(S);
			p->stg = pop(S);
		}
		push(S, p);
	}
	return p;
}
void dealocare(Nod *rad)
{
	if (rad)
	{
		dealocare(rad->stg);
		dealocare(rad->drt);
		delete rad;
		rad= 0;
	}
}
int test = 1;
int isHeap(Nod *rad)
	{
		if (rad != NULL)
		{
			isHeap(rad->stg);
			if (test)
				test = (rad->data > Max(rad->stg) && rad->data > Max(rad->drt));
			isHeap(rad->drt);
		}
		return test;
	}
void afisareHeap(Nod *rad)
{
	if (rad)
	{
		cout << rad->data<<" ";
		afisareHeap(rad->drt);
		afisareHeap(rad->stg);
	}
}
void afisareFrunze(Nod *rad)
{
	if (rad)
	{
		if (!rad->stg && !rad->drt)
			cout << rad->data << " ";
		afisareFrunze(rad->stg);
		afisareFrunze(rad->drt);
	}
}
void afisareNoduri(Nod *rad)
{
	if (rad)
	{
		if (rad->stg && rad->drt)
			cout << rad->data << " ";
		afisareNoduri(rad->stg);
		afisareNoduri(rad->drt);
	}
}
void afisareNoduri2(Nod *rad)
{
	if (rad)
	{
		if (rad->stg && rad->drt)
		if (rad->data > rad->stg->data && rad->data > rad->drt->data)
			cout << rad->data << " ";
		if (rad->stg && rad->data > rad->stg->data)
			cout << rad->data << " ";
		if (rad->drt && rad->data > rad->drt->data)
			cout << rad->data << " ";

		afisareNoduri2(rad->stg);
		afisareNoduri2(rad->drt);
	}
}//noduri mai mari ca nodurile subarborilor

int test2 = 1;
int isCautare(Nod *rad)
{
	if (rad != NULL)
	{
		isCautare(rad->stg);
		if (test2)
		if (rad->stg != NULL && rad->drt != NULL)
			test2 = (rad->data > Max(rad->stg) && rad->data < Max(rad->drt));
		else
		if (rad->stg != NULL)
			test2 = (rad->data > Max(rad->stg));
		else
		if (rad->drt != NULL)
			test2 = (rad->data < Max(rad->drt));
		isCautare(rad->drt);
	}
	return test2;
}
int isEchilibra(Nod *rad)
{
	if (abs(adancime(rad->stg) - adancime(rad->drt)) <= 1)
		return 1;
	else
		return 0;
}
