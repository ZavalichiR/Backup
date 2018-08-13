

#include <iostream>
#include "header.h"

void creare(nod *&rad)
{
	rad = new nod;
	rad->frunza = true;
	rad->nr = 0;
}

int cautare(nod *&rad, int k,int pozitie)
{
	int i = 1;
	while (i <= rad->nr && k > rad->key[i - 1])
	{
		i++;
		//pozitie++;
	}
		
	if (i <= rad->nr && k == rad->key[i - 1])
		return pozitie;
	if (rad->frunza)
		return -1;
	else
		return cautare(rad->fii[i - 1], k,pozitie+1);
}

void sparge(nod *&u, int i, nod *&v)
{
	int aux = t, j;
	nod *w = new nod;//noul nod este o noua frunza
	w->frunza = v->frunza;//v->frunza este complet si tb sa avem aux-1 chei
	w->nr = aux - 1;
	//copiem partea dreapta a lui w in v
	for (j = 1; j<aux; j++)
		w->key[j - 1] = v->key[j + aux - 1];
	//copiem pointerii lui w daca nu este frunza
	if (!v->frunza)
	for (int j = 1; j <= aux; j++)
		w->fii[j - 1] = v->fii[j + aux - 1];
	v->nr = aux - 1;

	for (j = u->nr + 1; j >= i + 1; j--)
		u->fii[j] = u->fii[j - 1];

	u->fii[i] = w;

	for (j = u->nr; j >= i; j--)
		u->key[j] = u->key[j - 1];

	u->key[i - 1] = v->key[aux - 1];
	u->nr++;
}

void insereazaBArbore(nod *&rad, int k)
{
	nod *r = rad;
	if (r->nr == 2 * t - 1)
	{
		nod *s = new nod;
		rad = s;
		s->frunza = 0;
		s->nr = 0;
		s->fii[0] = r;
		sparge(s, 1, r);
		inserareNodIncomplet(s, k);
	}
	else
		inserareNodIncomplet(r, k);
}

void inserareNodIncomplet(nod *&v, int k)
{
	int i = v->nr;
	if (v->frunza) // shifteaza totul spre pointerul unde noua cheie k ar trb s fie
	{
		while (i >= 1 && k<v->key[i - 1])
		{
			v->key[i] = v->key[i - 1];
			i--;
		}
		//pune pe x in locul corect si ajunge la nr de chei
		v->key[i] = k;
		v->nr++;
	}
	else
	{
		//gaseste copiii unde noua cheie incepe
		while (i >= 1 && k<v->key[i - 1])
			i--;
		i++;
		if (v->fii[i - 1]->nr == 2 * t - 1) // nodul fiu este plin si spargem
		{
			sparge(v, i, v->fii[i - 1]);
			// v[fii-1],v[fii] devin noii fii
			//key[i-1] se schimba
			if (k>v->key[i - 1])
				i++;
		}//apeleaza recursiv ins nod incomplet
		inserareNodIncomplet(v->fii[i - 1], k);
	}
}

void afisare(nod *&rad, int nivel)
{
	if (rad)
	{
		int i;
		if (!rad->frunza)
			afisare(rad->fii[0], nivel + 1);
		for (i = 0; i<rad->nr; i++)
		{
			cout << "Nivel: " << nivel << "             Key: " << rad->key[i] << endl;
			
			if (!rad->frunza)
				afisare(rad->fii[i + 1], nivel + 1);
		}
	}
}

