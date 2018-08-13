#include"Header.h"

int a = 999;
int Min(Nod *rad)
{
		if (rad)
		{
			if (rad->data < a)
				a = rad->data;
			Min(rad->stg);
			Min(rad->drt);
		}
	return a;
}
int b = 0;
int Max(Nod *rad)
{
	if (rad)
	{
		if (rad->data > b)
			b = rad->data;
		Max(rad->stg);
		Max(rad->drt);
	}
	return b;
}
void InitS(Stiva *&S)
{
	S = nullptr;
}
void CreareS(Stiva *&S)
{
	S = 0;
}
void Push(Stiva *&S, Nod *val)
{
	Stiva *p = new Stiva;
	if (p==0)
	{
		return;
	}
	p->data = val;
	p->leg = S;
	S = p;
}
Nod *Top(Stiva *&S)
{
	if (S == 0)
	{
		cout << "Stiva este goala" << endl;
		exit(EXIT_FAILURE);
	}
	Nod *r = S->data;
	return r;

}
Nod* MakeNod(int val)
{
	Nod *p;
	p = new Nod;
	p->data = val;
	p->stg = 0;
	p->drt = 0;
	return p;
}

Nod* insert(Nod *&r, int val)
{
	if (r == 0)
		return MakeNod(val);
	else
	if (val<r->data)
		r->stg = insert(r->stg, val);
	else
	if (val>r->data)
		r->drt = insert(r->drt, val);
	return r;
}

Nod *Father(Nod *rad, Nod* r)
{

	//Stiva *S;
	//InitS(S);
	Nod *val=new Nod;
	if (rad == 0)
		return NULL;

	while (rad && rad->data != r->data)
	{
		if (r->data < rad->data)
		{
			//Push(S, rad);
			val = rad;
			rad = rad->stg;
		}
		else
		if (r->data>rad->data)
		{
			//Push(S, rad);
			val = rad;
			rad = rad->drt;
		}
	}
	//Nod *rez = Top(S);
	//return rez;
	return val;
	
}
Nod *pred(Nod *rad,int cheie)
{	
	
	Nod *p = rad;
	Nod *min = new Nod;
	min->data = Min(rad);
	while (p)
	{
		if (p->data > min->data && p->data<cheie)
		{
			min = p;
			p = p->drt;
		}
				
		else
		{
			p = p->stg;
		}
	}
	return min;
} 
Nod *succ(Nod *rad, int cheie)
{

	Nod *p = rad;
	Nod *max = new Nod;
	max->data = Max(rad);
	while (p)
	{
		if (p->data <max->data && p->data>cheie)
		{
			max = p;
			p = p->stg;
		}

		else
		{
				p = p->drt;		
		}
	}
	return max;
}
int maxim(Nod *rad)
{
	int a = 0, b;
	if (rad)
	{
		if (rad->data > a)
			a = rad->data;
		b = maxim(rad->stg);
		if (b > a)
			a = b;
		b = maxim(rad->drt);
		if (b > a)
			a = b;
	}
	return a;
}
int minim(Nod *rad)
{
	
	if (rad)
	{
		int a = rad->data, b;
		if (a > rad->data)
			a = rad->data;
		b = minim(rad->stg);
		if (a > b)
			a = b;
		b = minim(rad->drt);
		if (a > b)
			a = b;
	}
	return a;
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