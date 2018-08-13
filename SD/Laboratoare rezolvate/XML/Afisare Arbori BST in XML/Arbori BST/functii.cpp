#include"coada.h"
#include"stiva.h"
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
		if (val>rad->data)
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
void intend(Nod *rad, int nivel)
{
	for (int i = 0; i < nivel; ++i)
		cout << "\t";
	if (rad == 0)
		cout << "_" << endl;
	else
	{
		cout << rad->data << endl;
		intend(rad->stg, nivel + 1);
		intend(rad->drt, nivel + 1);
	}
}
void peLinie(Nod *rad)
{
	coada *C;
	initC(C);
	Nod *p = new Nod;
	p = rad;
	if (p)
	{
		put(C, p);
		while (C->head)
		{
			p = get(C);
			cout << p->data << " ";
			if (rad->stg)
				put(C, rad->stg);
			if (rad->drt)
				put(C, rad->drt);
		}
	}
}
int min(Nod *rad)
{
	if (rad)
	{
		int m = rad->data;
		while (rad->stg)
		{
			rad = rad->stg;
			m = rad->data;
		}
		return m;
	}
	else
		return 0;
}
int max(Nod *rad)
{
	if (rad)
	{
		int m = rad->data;
		while (rad->drt)
		{
			rad = rad->drt;
			m = rad->data;
		}

		return m;
	}
	else
		return 0;
	
}
int adancime(Nod *rad)
{
	int h1=1, h2 = 1;
	if (rad == 0)
		return 0;
	else
	{
		h1 =h1+ adancime(rad->stg);
		h2 =h2+ adancime(rad->drt);
	}
	if (h1 > h2)
		return h1;
	else
		return h2;
}
int nrFrunze(Nod *rad)
{
	if (rad == 0)
		return 0;
	if (rad->stg == 0 && rad->drt == 0)
		return 1;
	return nrFrunze(rad->stg) + nrFrunze(rad->drt);
}
int nrNoduri(Nod *rad)
{
	if (rad == 0)
		return 0;
	if (rad->stg == 0 && rad->drt == 0)
		return 0;
	return 1 + nrNoduri(rad->stg) + nrNoduri(rad->drt);
}
Nod *cauta(Nod *rad, int val)
{
	if (rad == 0 )
		return nullptr;
	else
		if (val < rad->data)
			return cauta(rad->stg, val);
	else
		if (val>rad->data)
			return cauta(rad->drt, val);
	return rad;
}
void comuta(Nod *&rad)
{
	Nod *aux = new Nod;
	if (rad)
	{
		aux = rad->stg;
		rad->stg = rad->drt;
		rad->drt = aux;
		comuta(rad->stg);
		comuta(rad->stg);
	}
}
void sterge(Nod *rad, int val)
{
	if (rad == 0)
	{
		cout << "\nValoarea: " << val << " nu se afla in arbore" << endl;
		return;
	}
	else
	{
		if (rad->data == val)
			stergeRadacina(rad);
		if (val < rad->data)
			sterge(rad->stg, val);
		if (val>rad->data)
			sterge(rad->drt, val);
	}
	
}
void stergeRadacina(Nod *rad)
{
	Nod *p = rad;
	if (rad->drt == 0)
		rad = rad->stg;
	if (rad->stg == 0)
		rad = rad->drt;
	else
	{
		rad = stergeMaxim(rad->stg);
		rad->stg = p->stg;
		rad->drt = p->drt;
	}
	delete p;
}
Nod *stergeMaxim(Nod *rad)
{
	Nod *p;
	if (rad->drt == 0)
	{
		p = rad;
		rad = rad->stg;
		return p;
	}
	else
		return stergeMaxim(rad->drt);
}
Nod *tata(Nod *rad, Nod *n)
{
	Nod *p = rad;
	Nod *q = rad;

		if (cauta(rad, n->data) == 0)
		{
			cout << "\n Nodul nu se afla in arbore\n";
			return nullptr;
		}
		if (rad == n)
			return 0;
		while (p->data != n->data)
		{
			q = p;
			if (n->data < p->data)
				p = p->stg;
			else
				p = p->drt;
		}
		return q;

}
Nod *min2(Nod *rad)
{
	Nod *p = rad;
	while (p->stg)
		p = p->stg;
	return p;
}
Nod *max2(Nod *rad)
{
	Nod *p = rad;
	while (p->drt)
		p = p->drt;
	return p;
}
Nod *succesor(Nod *rad, Nod *n)
{
	Nod *r = cauta(rad, n->data);
	if (r == 0)
		return 0;
	if (r->drt != 0)
		return min2(r->drt);
	Nod *p;
	p = tata(rad, n);
	while (p!=0 &&r==p->drt)//cat timp exista parinte si r este fiu drept
	{
		r = p;//urc in arbore pana cand r va fi intr-un
	     		//subarbore stang al unui nod
		p = tata(rad, p);
	}
	return p;

}
Nod *predecesor(Nod *rad, Nod *n)
{
	Nod *r = cauta(rad, n->data);
	if (r == 0)
		return 0;
	if (r->stg != 0)
		return max2(r->stg);
	Nod *p = tata(rad,n);
	while (p != 0 && r == p->stg)
	{
		r = p;
		p = tata(rad, p);
	}
	return p;
}
Nod2 *creareArbore(char *expresie)
{
	char ch;
	Nod2 *p = 0;
	stiva *S;
	initS(S);
	while (ch = *expresie++)
	{
		p = new Nod2;
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
void afisareIntend(Nod2 *rad, int nivel)
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

//--Salvare Fisier---/
 ofstream f("fisier.xml");
 int t = 0;
void tab(int nr)
{
	for (int i = 1; i <= nr; i++)
		f << "\t";
}

void salveazaFisier2(Nod *r)
{
	t++;
	f << "\n";
	tab(t); 
	f << "<NOD>\n";
	tab(t + 1);
	f << "<DATA>" << r->data << "</DATA> \n";
	if (r->stg || r->drt)
	{
		tab(t + 1);
		f << "<FII> \n";
		if (r->stg) salveazaFisier2(r->stg);
		if (r->drt) salveazaFisier2(r->drt);
		f << "\n";
		tab(t + 1);
		f << "</FII> \n";
	}
	tab(t);
	f << "</NOD>";
	t--;

}

void salveazaFisier(Nod *r)
{
	f << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
	f << "<Arbore>\n";
	salveazaFisier2(r);
	f << "\n</Arbore>\n";
}