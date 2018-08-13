#include"Header.h"
void RSS(AVL *&rad)//simpla
{
	AVL *a = rad->drt;
	a->bf = 0;
	rad->bf = 0;
	rad->drt = a->stg;
	a->stg = rad;
	rad = a;
}
void RSD(AVL *&rad)//simpla
{
	AVL *a = rad->stg;
	a->bf = 0;
	rad->bf = 0;
	rad->stg = a->drt;
	a->drt = rad;
	rad = a;
}
void RDS(AVL *&rad)//dubla
{
	AVL *a, *b;
	b = rad->drt;
	a = b->stg;
	switch (a->bf)
	{
	case 0:
	{
			  rad -> bf = 0;
			  b->bf = 0;
			  break;
	}
	case -1:
	{
			   rad->bf = 0;
			   b->bf = 1;
			   break;
	}
	case 1:
	{
			  rad->bf = -1;
			  b->bf = 0;
			  break;
	}
	}
	rad->drt = a->stg;
	b->stg = a->drt;
	a->stg = rad;
	a->drt = b;
	rad = a;
}
void RDD(AVL *&rad)//dubla
{
	AVL *b, *a;
	b = rad->stg;
	a = b->drt;
	switch (a->bf)
	{
	case 0:
	{
			  rad->bf = 0;
			  b->bf = 0;
			  break;
	}
	case 1:
	{
			  rad->bf = 0;
			  b->bf = 1;
			  break;
	}
	case -1:
	{
			   rad->bf = -1;
			   b->bf = 0;
			   break;
	}
	}
	rad->stg = a->drt;
	b->drt = a->stg;
	a->drt = rad;
	a->stg = b;
	rad = a;
}
int Eq_Required;
int nr;
void InsAVL(AVL *&a, int x)
{

	if (a == 0)
	{
		a = new AVL;
		a->data = x; 
		a->stg = a->drt = 0;
		a->bf = 0;
		Eq_Required = 1;
	}
	else
	{
		if (x < a->data)
		{ //inserez in stânga ca la BST
			nr++; //asta pentru numararea operatiilor
			InsAVL(a->stg, x);
			if (Eq_Required)
				switch (a->bf)
			{
				case 1: // adincimea pe subarb stang e mai mare
					Eq_Required = 0;
					//aleg tipul de rotație
					(x < a->stg->data) ? RSD(a) : RDD(a);
					break;
				case 0: //nu exista dezechilibru
					a->bf = 1; //dar se produce acum
					break;
				case -1: //adincimea pe subarb stang e mai mica
					a->bf = 0; // inserarea produce echilibru
					Eq_Required = 0;
			}
		}
		else
		if (x > a->data)
		{
			nr++;
			InsAVL(a->drt, x);
			if (Eq_Required)
				switch (a->bf)
			{
				case -1: // adincimea pe subarb drept e mai mare
					Eq_Required = 0;
					//aleg tipul de rotație
					(x > a->drt->data) ? RSS(a) : RDS(a);
					break;
				case 0: //nu exista dezechilibru
					a->bf = -1; //dar se produce acum
					break;
				case 1: //adincimea pe subarb stang e mai mica
					a->bf = 0; // inserarea produce echilibru
					Eq_Required = 0;
			}

		}
		else Eq_Required = 0;
	}
}
void afisareIndent(AVL *rad, int nivel)
{
	int i;
	for (i = 0; i < nivel; ++i)
		cout << "\t";
	if (rad == 0)
		cout << "_" << endl;
	else
	{
		cout << rad->data << endl;
		afisareIndent(rad->stg, nivel + 1);
		afisareIndent(rad->drt, nivel + 1);
	}

}
void inordine(AVL *rad)
{
	if (rad)
	{
		inordine(rad->stg);
		cout << rad->data << " ";
		inordine(rad->drt);
	}
}
int adancime(AVL *rad)
{
	int h1 = 1, h2 = 1;
	if (rad == 0)
		return 0;
	else
	{
		h1 += adancime(rad->stg);
		h2 += adancime(rad->drt);
	}
	return (h1 > h2) ? h1 : h2;
}
void adancime(AVL* rad, int &max, int lung)
{
	if (rad != NULL){
		adancime(rad->drt, max, lung + 1);
		if ((rad->stg == NULL) && (rad->drt == NULL) && (max < lung))
			max = lung;
		adancime(rad->stg, max, lung + 1);
	}
	else
		return;
}
void calculBf(AVL *rad)
{
	int hstg = 1, hdrt = 1;
	if (rad->stg != NULL)
		adancime(rad->stg, hstg, 1);
	else
		hstg = 0;
	if (rad->drt != NULL)
		adancime(rad->drt, hdrt, 1);
	else
		hdrt = 0;
	rad->bf = hdrt - hstg;
}
int max(AVL *rad)
{
	int a = 0, b;
	if (rad)
	{
		if (a < rad->data)
			a = rad->data;
		b = max(rad->stg);
		if (b>a)
			a = b;
		b = max(rad->drt);
		if (b > a)
			a = b;
	}
	return a;
}
int min(AVL *rad)
{
	int a=99, b;
	if (rad)
	{
		if (a > rad->data)
			a = rad->data;
		b = min(rad->stg);
		if (b<a)
			a = b;
		b = min(rad->drt);
		if (b < a)
			a = b;
	}
	return a;
}
AVL *arboreCurs()
{
	AVL *rad = 0;
	InsAVL(rad, 1);
	InsAVL(rad, 2);
	InsAVL(rad, 3);
	InsAVL(rad, 4);
	InsAVL(rad, 5);
	InsAVL(rad, 6);
	InsAVL(rad, 7);
	InsAVL(rad, 8);
	InsAVL(rad, 9);
	return rad;
}