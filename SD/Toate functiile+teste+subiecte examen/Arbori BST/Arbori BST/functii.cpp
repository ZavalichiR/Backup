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
			if (p->stg)
				put(C, p->stg);
			if (p->drt)
				put(C, p->drt);
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

bool isEchilibrat(Nod *rad)
{
	if (rad == 0)
		return 1;
	if (abs(adancime(rad->stg) - adancime(rad->drt)) <= 1)
		return 1;
	else
		return 0;
}
void afisareNodNivel(Nod *rad, int Nivel)
{
	if (rad)
	{
		if (Nivel==1)
			cout << rad->data << " ";
		afisareNodNivel(rad->stg,Nivel-1);
		afisareNodNivel(rad->drt,Nivel-1);
	}
}
int nrNoduriNivel(Nod *rad, int nivel)
{
	int n = 0;
	if (rad)
	{
		if (nivel == 1)
			n ++;
		else
		{
			n += nrNoduriNivel(rad->stg, nivel - 1);
			n += nrNoduriNivel(rad->drt, nivel - 1);
		}
	}
	return n;
}
/*Se citeste un numar pozitiv K. Sa se determine daca exista
un nod pentru care modulul diferentei dintre numarul de noduri
din subarborele sting si numarul de noduri din subarborele
drept este mai mare sau egal cu K.*/

int nrTotalNoduri(Nod *rad)
{
	int ns=1, nd=1;
	if (rad == 0)
		return 0;
	ns += nrTotalNoduri(rad->stg);
	nd += nrTotalNoduri(rad->drt);
	return ns + nd;
	//return nrFrunze(rad) + nrNoduri(rad);
}
void afisareNod(Nod *rad, int k)
{
	if (rad)
	{
		if (abs(nrTotalNoduri(rad->stg) - nrTotalNoduri(rad->drt)) >= k)
			cout << "\nNodul este: " << rad->data << endl;
		afisareNod(rad->stg,k);
		afisareNod(rad->drt, k);
	}
	

}

void reprezentareImplicita(Nod *rad)
{
		if (!rad)
			cout << " 0 ";
		if (rad)
		{
			cout << rad->data << " ";
			reprezentareImplicita(rad->stg);
			reprezentareImplicita(rad->drt);
		}
			
	
}