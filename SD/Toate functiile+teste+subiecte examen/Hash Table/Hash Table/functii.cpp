#include"Header.h"
//Nod *HT[dim];
void init(Nod *HT[])
{
	for (int i = 0; i < dim; ++i)
		HT[i] = 0;
}
int functie(char *cheie)
{
	int sum = 0;
	for (int i = 0; i < (int)strlen(cheie); ++i)
		sum = sum + *(cheie + i);
	return sum % dim;
}
void afisare(Nod *HT[])
{
	for (int i = 0; i < dim; ++i)
	{
		if (HT[i])
		{
			cout << "\nInregistrari avand codul de dispersie: " << i << " : ";
			Nod *p = HT[i];
			while (p)
			{
				cout << p->data << " ";
				p = p->succ;
			}
		}
	}
	cout << endl;
}
Nod *cautare(Nod *HT[],char *cheie)
{
	int f = functie(cheie);
	Nod *p = HT[f];
	while (p)
	{
		if (strcmp(p->data, cheie) == 0)
			return p;
		p = p->succ;
	}
	return 0;
}
void inserare(Nod *HT[],char *cheie)
{
	int f = functie(cheie);
	Nod *p = new Nod;
	p->data = new char[strlen(cheie) + 1];
	strcpy_s(p->data, strlen(cheie) + 1, cheie);
	if (HT[f] == 0)
	{
		HT[f] = p;
		p->succ = 0;	
	}
	else
	{
		Nod *q = cautare(HT,cheie);
		if (q == 0)
		{
			p->succ = HT[f];
			HT[f] = p;
		}
		else
		{

			cout << "\nValoare dubla\n";

		}

	}

}
void sortare(Nod *HT[])
{
	//for (int i = 0; i < dim; ++i)
	//{

		int ok;
		for (int i = 0; i < dim; ++i)
		{
			ok = 0;
			while (ok == 0)
			{
				ok = 1;
				Nod *p = HT[i];
				Nod *q;
				char *aux;
				if (p)
				{
					while (p->succ)
					{
						q = p->succ;
						if (strcmp(p->data, q->data) > 0)
						{
							aux = p->data;
							p->data = q->data;
							q->data = aux;
							ok = 0;
						}
						p = p->succ;
					}
				}
			}
		
	}
}
void afisareFrecv(int fr[128])
{
	char diff = 'a' - 'A';

	for (char c = 'A'; c <= 'Z'; ++c)
	{
		if (fr[(int)c] + fr[(int)(c + diff)])
		{
			cout << c << (char)(c + diff) << " " << fr[(int)c] + fr[(int)(c + diff)] << endl;
		}
	}
}
void calculeazaFrecventa(char *text, int fr[128])
{
	for (int i = 0; i < 128; ++i)
	{
		fr[i] = 0;
	}
	for (char *c = text; *c; ++c) //*c dereferentiaza  *c echiv *c!='\0'
	{
		++fr[(int)(*c)];   //Spre ex codul aSCII pt (int)'A'=65 . fr[65]++;
	}
}
void stergere(Nod *HT[], char *cheie)
{
	int f = functie(cheie);
	Nod *p=HT[f];
	if (p)//verifica daca exista ceva pe pozitia f
		// poate fi alta valoare dar care are aceeasi cheie
		//ex functie("a")=functie("zav");
	{
		if (strcmp(p->data, cheie) == 0)
		{
			Nod *elm = p;
			HT[f] = p->succ;
			delete elm;
			return;
		}

		while (p->succ && strcmp(p->succ->data, cheie) != 0)
			p = p->succ;
		if (p->succ && (p->succ->data, cheie) == 0)
		{
			Nod *elm = p->succ;
			p->succ = p->succ->succ;
			delete elm;
		}
		else
			cout << "Elementul " << cheie << " nu se afla in tabela" << endl;
	}
	else
		cout << "Elementul " << cheie << " nu se afla in tabela" << endl;

}
