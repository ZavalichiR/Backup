#include"Header.h"

void RSS(AVL *&rad)
{
	AVL *a = rad->drt;
	rad->bf = 0;
	a->bf = 0;
	rad->drt = a->stg;
	a->stg = rad;
	rad= a;
}
void RSD(AVL *&rad)
{
	AVL *a=rad->stg;
	rad->bf = 0;
	a->bf = 0;
	rad->stg = a->drt;
	a->drt = rad;
	rad = a;
	
}
void RDS(AVL *&rad)
{
	AVL *b, *a;
	b = rad->drt;
	a = b->stg;
	switch (a->bf)
	{
	case 0:
		rad->bf = b->bf = 0;
		break;
	case -1:
		rad->bf = 0;
		b->bf = 1;
		break;
	case 1:
		rad->bf = -1;
		b->bf = 0;
	}
	rad->drt = a->stg;
	b->stg = a->drt;
	a->stg = rad;
	a->drt = b;
	rad = a;
}
void RDD(AVL *&rad)
{
	AVL *b, *a;
	b = rad->stg;
	a = b->drt;
	switch (a->bf)
	{
	case 0:
		rad->bf = b->bf = 0;
		break;
	case -1:
		rad->bf = 0;
		b->bf = 1;
		break;
	case 1:
		rad->bf = -1;
		b->bf = 0;
	}
	rad->stg = a->drt;
	b->drt = a->stg;
	a->bf = 0;
	a->drt = rad;
	a->stg = b;
	rad = a;
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

int Eq_Required;
int nr;
void InsAVL(AVL *&a, int x)
{
	
	if (a == 0) 
	{
		a = new AVL;
		a->data = x; a->stg = a->drt = 0; a->bf = 0;
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
					a->bf= 0; // inserarea produce echilibru
					Eq_Required = 0;
			}

		}
		else Eq_Required = 0;
	}
}
AVL *echilibrare(AVL *rad)
{
	AVL *w;
	calculBf(rad);
	if (rad->bf == -2)
	{
		w = rad->stg;
		if (w->bf == 1)
			RDD(rad);
		else
			RSD(rad);
	}
	else
	if (rad->bf == 2)
	{
		w = rad->drt;
		if (w->bf == -1)
			RDS(rad);  
		else
			RSS(rad);
	}
	return rad;
}
AVL* insereaza(AVL *rad, int val)
{
	if (rad == NULL)
	{
		rad = new AVL;
		rad->data = val;
		rad->bf = 0;

		rad->drt = NULL;
		rad->stg = NULL;
		return rad;
	}
	else {
		if (val<rad->data)
			rad->stg = insereaza(rad->stg, val);
		else
		if (val>rad->data)
			rad->drt = insereaza(rad->drt, val);
		else
			cout << "Nodul exista deja" << endl;
	}
	rad = echilibrare(rad);//echilibreaza daca este necesar
	return rad;
}
AVL *arboreCurs()
{
	AVL *rad = 0;
	rad = insereaza(rad, 25);
	rad = insereaza(rad, 15);
	rad = insereaza(rad, 35);
	rad = insereaza(rad, 10);
	rad = insereaza(rad, 20);
	rad = insereaza(rad, 30);
	rad = insereaza(rad, 45);
	rad = insereaza(rad, 40);
	rad = insereaza(rad, 50);
	return rad;
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

AVL* stergere(AVL *rad, int val){
	AVL *q, *r, *w;
	if (rad != NULL)
	if (val<rad->data)
		rad->stg = stergere(rad->stg, val); 
	else
	if (val>rad->data)
		rad->drt = stergere(rad->drt,val);//cautare in subarborele drept
	else{
		
			q = rad;
		if (q->drt == NULL) 
			rad = q->stg;
		else
		if (q->stg == NULL) 
			rad = q->drt;
		else{
			w = q->stg;
			r = q;
			if (w->drt != NULL)
			{
				while (w->drt != NULL){
					r = w;
					w = w->drt;
				}
				rad->data = w->data;
				q = w;
				r->drt = w->stg;
				r = rad->stg;
				w = w->stg;
				if (r != NULL)
				while ((r != w) && (r != NULL)){
					r = echilibrare(r);
					r = r->drt;
				}
			}
			else{
				rad->data = w->data;
				rad->stg= w->stg;
				q = w;
			}
		}
		delete(q);// se sterge q
	}
	if (rad != NULL)
		rad = echilibrare(rad);// se echilibreaza p daca nu este NULL
	return rad;
}