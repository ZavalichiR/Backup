#include"Header.h"

Nod *HT[M];

void init()
{
	for (int i = 0; i < M; ++i)
	{
		HT[i] = 0;
	}
}

int f(char *key)
{
	int i;
	int sum = 0;
	for (i = 0; i < (int)strlen(key); ++i)

	{
		sum = sum + *(key + i);
	}
	return sum%M;
}

void inserare(char *key)
{
	int h = f(key);
	Nod *p=new Nod;
	p->key = new char[20];
	strcpy_s(p->key, 20, key);
	p->leg = HT[h];
	HT[h] = p;
}

void afisare()
{
	for (int i = 0; i < M; ++i)
		{
			if (HT[i])
			{
				cout << "\nDispersie: " << i << ": ";
				Nod* p = HT[i];
				while (p)
				{
					cout << p->key<<" ";
					p = p->leg;
				}
			}
		}
	cout << endl << endl;
}

void sortare()
{
	int ok;
	for (int i = 0; i < M; ++i)
	{
		ok = 0;
		while (ok==0)
		{
			ok = 1;
			Nod *p = HT[i];
			Nod *q;
			char *aux;
			if (p)
			{
				while (p->leg)
				{
					q = p->leg;
					if (strcmp(p->key, q->key) > 0)
					{
						aux = p->key;
						p->key = q->key;
						q->key = aux;
						ok = 0;
					}
					p = p->leg;
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

void calculareFrecventa(char *text, int fr[128])
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