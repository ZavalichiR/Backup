#include"Header.h"
nod *HT[M];
void initializare()
{
	for (int i = 0; i < M; ++i)
	{
		HT[i] = 0;
	}
}
int f(char *cheie)
{
	int sum = 0;
	for (unsigned int i = 0; i < strlen(cheie); ++i)
	{
		sum = sum + ((*(cheie + i))|i)*(i*(i + 1) + 1);
	}
	return sum%M;
}
void inserare(char *cheie)
{
	int h = f(cheie);
	nod *p = new nod;
	p->cheie = cheie;
	p->succ = HT[h];
	HT[h] = p;
}

void afisare()
{
	for (int i = 0; i < M; ++i)
	{
		if (HT[i])
		{
			cout << "\n Inregistrari avand costul de dispersie:" << i << ":";
			nod *p = HT[i];
			while (p)
			{
				cout << p->cheie << "  ";
				p = p->succ;
			}
		}

	}
}

nod *cautare(char *cheie)
{
	int h = f(cheie);
	nod *p = HT[h];
	nod *ret = NULL;
	if (p != NULL) {
		while (p)
		{
			if (strcmp(p->cheie, cheie) == 0)
			{
				ret = p;
				break;
			}
			p = p->succ;
		}
	}

	return ret;
}

void stergere(char *cheie)
{
	int h = f(cheie);
	nod *p = HT[h];

	if (strcmp(p->cheie, cheie) == 0)
	{
	nod *elm = p;
	HT[h] = p->succ;
	delete elm;
	return;
	}

	if (p != NULL) 
	{
			while (p->succ && strcmp(p->succ->cheie, cheie) != 0)
			{
				p = p->succ;
			}
			if (p->succ != 0)
			{
				nod *elm = p->succ;
				p->succ = p->succ->succ;
				delete elm;
			}
		else
		{
			exit(EXIT_FAILURE);
		}
	}
}