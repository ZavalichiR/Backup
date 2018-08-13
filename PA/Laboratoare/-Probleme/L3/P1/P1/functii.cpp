#include"Header.h"
int cautareBinara(int a[5000], int n, int val,double &c)
{
	c++;
	int istg = 0;
	c++;
	int idrt = n - 1;
	c++;
	int imed;
	c++;
	while (istg <= idrt)
	{
		imed = (istg + idrt) / 2;
		c++;
		if (a[imed] == val)
		{
			return imed;
			c++;
		}
		else if (a[imed] > val)
		{
			idrt = imed - 1;
			c++;
		}
		else
		{
			istg = imed + 1;
			c++;
		}
	}
	return -1;
}

Nod *makeNod(int val)
{
	Nod *elm = new Nod;
	elm->data = val;
	elm->stg = 0;
	elm->drt = 0;
	return elm;
}
void inserare(Nod *&rad, int val)
{
	if (rad == 0)
		rad = makeNod(val);
	else
	{
		if (val < rad->data)
			inserare(rad->stg, val);
		else
		if (val>=rad->data)
			inserare(rad->drt, val);
		else
			cout << "Data: " << val << " exista deja in arbore" << endl;
	}

}
void inordine(Nod *rad)
{
	if (rad)
	{
		inordine(rad->stg);
		cout << rad->data << " ";
		inordine(rad->drt);
	}
}

Nod *cautArboreBinar(Nod *rad, int val,double &c)
{
	Nod *p = rad;
	c++;
	while (p && p->data != val)
	{
		if (val < p->data)
		{
			p = p->stg;
			c++;
		}
		else
		{
			p = p->drt;
			c++;
		}

	}
		c++;
	return p;
}