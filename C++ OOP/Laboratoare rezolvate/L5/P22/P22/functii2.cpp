#include"Header2.h"
MultimePersoana::MultimePersoana()
{
	n = 0;
	dim = 20;
	p = new Persoana[dim];
}
MultimePersoana::MultimePersoana(int d)
{
	n = 0;
	dim = d;
	p = new Persoana[dim];
}
MultimePersoana::~MultimePersoana()
{
	n = -1;
	dim = -1;
	if (p)
	{
		delete[] p;
		p = nullptr;
	}
}
void MultimePersoana::introduce(Persoana P)
{
	int i;
	int ok = 1;
	if (n < dim-1)
	{
		for (i = 0; i < n; i++)
		{
			if (p[i].compara(P))
			{
				i = n;
				ok = 0;

			}
		}
		if (ok==1)
		{
			p[i] = P;
			n++;
		}
	}
	else
	{
		cout << endl << "Multimea este plina" << endl;
	}
}
void MultimePersoana::extrage(Persoana P)
{
	int i;
	int poz = -1;
	if (n)
	{
		for (i = 0; i < n; ++i)
		{
			if (p[i].compara(P))
			{
				poz = i;
				i = n;
			}
		}

		if (poz != -1)
		{
			n--;
			for (i = poz; i < n; ++i)
			{
				p[i] = p[i + 1];
			}
		}
		else
		{
			cout << "\n Persoana nu exista" << endl;
		}
	}
	else
	{
		cout << "\n Multimea este goala." << endl;
	}
}
void MultimePersoana::afiseaza()
{
	if (n)
	{
		int i;
		cout << "\n<<<<<<<<<<Multimea>>>>>>>>>" << endl;
		for (i = 0; i < n; ++i)
		{
			cout << "\n------Persoana nr. " << i + 1 << "-----";
			p[i].afisare();
		}
	}
	else
	{
		cout << "\nMultimea este goala" << endl;
	}
}