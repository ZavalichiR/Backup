#include"Header.h"
void eroare();
char readchar();
char citesteNume();
Nod* citesteArbore();
Nod* creareArbore();
char car;
void eroare()
{
	printf("Sirul de intrare este eronat!\n");
	printf("Apasati o tasta...");
	_getch();
	exit(1);
}
char readchar()
{
	char c;
	do c = getchar(); while (c == ' ');
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
	if (car == '-') {
		rad = 0;
		car = readchar();
	}
	else {
		rad = (Nod*)malloc(sizeof(Nod));
		rad->data = citesteNume();
		if (car != '(') {
			rad->stg = 0;
			rad->drt = 0;
		}
		else {
			car = readchar();
			rad->stg = citesteArbore();
			if (car != ',') rad->drt = 0;
			else {
				car = readchar();
				rad->drt = citesteArbore();
			}
			if (car != ')') eroare();
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
void inordine(Nod *p)
{
	if (p)
	{
		inordine(p->stg);
		cout << p->data << " ";
		inordine(p->drt);
	}
}
void preordine(Nod *p)
{
	if (p)
	{
		cout << p->data << " ";
		preordine(p->stg);
		preordine(p->drt);
	}
}
void postordine(Nod *p)
{
	if (p)
	{
		postordine(p->stg);
		postordine(p->drt);
		cout << p->data << " ";
	}
}
void afisareIntend(Nod *p,int nivel)
{
	int i;
	for (i = 0; i < nivel; ++i)
		cout << "\t";
	if (p == 0)
		cout << "_" << endl;
	else
	{
		cout << p->data << endl;
		afisareIntend(p->stg, nivel + 1);
		afisareIntend(p->drt,nivel + 1);
	}

}
int adancime(Nod *p)
{
	int a = 1, b = 1;
	if (p == 0)
		return 0;
	else
		a += adancime(p->stg);
	b += adancime(p->drt);
	if (a < b)
		return b;
	else
		return a;
}
int frunze(Nod *p)
{
	if (p==0)
		return 0;
	if ((p->stg == 0) && (p->drt == 0))
		return 1;
	return (frunze(p->stg) + frunze(p->drt));
}
void comuta(Nod *p)
{
	Nod *aux;
	if (p)
	{
		aux = p->stg;
		p->stg = p->drt;
		p->drt = aux;
		comuta(p->stg);
		comuta(p->drt);
	}
}
int nrnoduri(Nod *p)
{
	if (p == 0)
		return 0;
	if ((p->stg == 0) && (p->drt == 0))
		return 0;
	else
		return 1 + nrnoduri(p->stg) + nrnoduri(p->drt);
}
int elementeArbore(Nod *p)
{
	return nrnoduri(p) + frunze(p);
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
void dealocare(Nod *p)
{
	if (p)
	{
		dealocare(p->stg);
		dealocare(p->drt);
		delete p;
		p = 0;
	}
}
