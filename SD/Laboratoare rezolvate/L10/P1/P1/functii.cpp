#include"Header.h"
Nod* MakeNod(int val)
{
	Nod *rad = new Nod;
		rad->data = val;
		rad->stg = 0;
		rad->drt = 0;
	return rad;
}
Nod *inserareBST(Nod*&rad, int val)
{
	if (rad==0)
		rad=MakeNod(val);
	else
	{
		if (val < rad->data)
			rad->stg= inserareBST(rad->stg, val);
		else
			if (val>rad->data)
				rad->drt= inserareBST(rad->drt, val);
			else
			cout << "Data " << val << " exista deja in arbore" << endl;
	}
	
	return rad;
}
void inordine(Nod *rad)
{
	if (rad)
	{
		inordine(rad->stg);
		cout << rad->data << endl;
		inordine(rad->drt);
	}
	
}
void indentat(Nod *rad,int level)
{
	for (int i = 0; i < level; ++i)
		cout << "\t";
	if (rad == 0)
	{
		cout << "_" << endl;
	}
	else
	{
		cout << rad->data << endl;
		indentat(rad->stg, level + 1);
		indentat(rad->drt, level + 1);
	}
}
int cautare(Nod *rad, int val)
{
	while (rad)
	{
		if (val < rad->data)
			rad =rad->stg;
		if (val>rad->data)
			rad = rad->drt;
		if (val == rad->data)
			return 1;
		
	}
	if (val != rad->data)
		return 0;
}
Nod* cautare2(Nod *r, int a)
{
	if (r == 0)
		return NULL;
	else
	if (a<r->data)
		return cautare2(r->stg, a);
	else
	if (a>r->data)
		return cautare2(r->drt, a);
	return r;
}
Nod* removeGreatest(Nod*& r)
{
	Nod* p;
	if (r->drt == 0)
	{
		p = r;
		r = r->stg;
		return p;
	}
	else
		return removeGreatest(r->drt);
}
void deleteRoot(Nod*& rad)
{
	Nod* p = rad;
	if (rad->stg == 0)
		rad = rad->drt;
	else
	if  (rad->drt == 0) rad = rad->stg;

	else
	{
		rad = removeGreatest(rad->stg);
		rad->stg = p->stg;
		rad->drt = p->drt;
	}
	delete p;
}
void sterge(Nod*& rad, int a)

{

	if (rad == NULL)
		cout << "Eroare: Valoarea " << a << " nu este in arbore!" << endl;
	else
	if (a<rad->data)
		sterge(rad->stg, a);
	else
	if (a>rad->data)
		sterge(rad->drt, a);
	else
		deleteRoot(rad);

}
Nod* cautare3(Nod *r, int a)
{
	Nod*rez = new Nod;
	
	while (r)
	{
		if (a < r->data)
			r = r->stg;
		else
			if (a>r->data)
				r = r->drt;
			else
			{
				rez = r;
				return rez;
			}
					
	}
	if (!r)
		return 0;
}
