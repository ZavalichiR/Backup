#include "Header.h"


void setColor(int i)
{

	/*for (int j = 0; j < 256; j++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
		cout << " Culoarea: " << k << endl;
	}*/

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
void insert(Nod *v[27], int &n, Nod *val)
{
	int fiu, parinte;
	Nod *aux;
	n++;
	v[n] = val;
	fiu = n;
	parinte = n / 2;
	while (parinte>0)
	if (v[fiu]->frecventa < v[parinte]->frecventa) //daca nr de fii aparuti e mai mic decat cel al parintilor
	{
		aux = v[fiu]; 
		v[fiu] = v[parinte];
		v[parinte] = aux;
		fiu = parinte;
		parinte /= 2; 
	}
	else
		break;
}

Nod *remove(Nod *v[27], int &n) //stergere nod
{
	int parinte, fiu;
	Nod *p, *aux;
	p = v[1];
	n--;
	v[1] = v[n + 1];
	parinte = 1;
	fiu = 2;
	while (fiu <= n)
	{
		if (fiu + 1 <= n && v[fiu]->frecventa > v[fiu + 1]->frecventa)
			fiu++;
		if (v[parinte]->frecventa > v[fiu]->frecventa)
		{
			aux = v[fiu];
			v[fiu] = v[parinte];
			v[parinte] = aux;
			parinte = fiu;
			fiu *= 2;
		}
		else
			fiu = n + 1;
	}
	return p;
}

void percolate(Nod *v[27], int n, int i)
{
	int parinte, fiu;
	Nod *aux;
	parinte = i;
	fiu = 2 * i;
	while (fiu <= n)
	{
		if (fiu + 1 <= n && v[fiu]->frecventa > v[fiu + 1]->frecventa)
			fiu++;
		if (v[fiu]->frecventa < v[parinte]->frecventa)
		{
			aux = v[parinte];
			v[parinte] = v[fiu];
			v[fiu] = aux;
			parinte = fiu;
			fiu *= 2;
		}
		else
			fiu = n + 1;
	}
}

void heap_min(Nod *v[27], int n)
{
	setColor(9);
	cout << "\n\t\t\t      Frecventele caracterelor   " << endl;

	setColor(14);
	cout << "\t\t\t   ------------------------------" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "\t\t\t   |\t       ";
		setColor(10);
		cout << v[i]->data;
		setColor(14);
		cout<< ": " << v[i]->frecventa << "\t\t|" << endl;
	}
	cout << "\t\t\t   ------------------------------" << endl;
	
	setColor(7);
	for (int i = n / 2; i >= 1; i--)
		percolate(v, n, i);

	setColor(9);
	cout << "\n\t\t\t      Reprezentarea implicita " << endl;
	
	setColor(14);
	cout << "    ------------------------------------------------------------------------------" << endl;


	cout << "          Index: ";
	for (int i = 1; i <= n; i++)
		cout << i << ' ';
	cout << endl;


	cout << "      Caractere: ";
	setColor(10);
	for (int i = 1; i <= n; i++)
	{
		if (i >= 10)
			cout << " ";
		cout << v[i]->data << " ";
	}
	cout << endl;

	setColor(14);
	cout << "      Frecventa: ";
	for (int i = 1; i <= n; i++)
	{
		if (i >= 10)
			cout << " ";
		cout << v[i]->frecventa << " ";
	}



	cout << "\n    ------------------------------------------------------------------------------" << endl;
	setColor(7);
	cout << endl << endl;
}


void inord(Nod *v) 
{
	if (v != 0)
	{
		cout << v->data << " - " << v->frecventa << endl;
		inord(v->stg);
		inord(v->drt);
	}
}

void Huffman(Nod *varf, int V[27], int n)
{
	if (varf->stg == 0 && varf->drt == 0)   // in caz ca sirul de codificat este format dintr-un singur caracter
	{

		cout << endl << "\t\t   Caracter \" ";
		setColor(10);
		cout << varf->data;
		setColor(14);
		cout<< " \": ";   // codul sau va fi 0
		for (int i = 0; i < n; i++)
		{
			cout << V[i] << ' ';
			varf->codificare = varf->codificare + to_string(V[i]);
		}
	}
	else     // altfel
	{
		if (varf->stg)   // daca exista noduri in stanga
		{
			V[n] = 0;		// retinem val. 0
			Huffman(varf->stg, V, n + 1);    // parcurgem spre stanga pana la frunze
		}
		if (varf->drt)   // daca exista noduri in dreapta
		{
			V[n] = 1;     // retinem val. 0
			Huffman(varf->drt, V, n + 1);    // parcurgem spre dreapta pana la frunze
		}
	}
}
void afisare(char* s, Nod* varf, int &i, Nod *rad)
{
	int n = strlen(s);
	if (i > n)
		return;
	if (varf->data == s[i])
	{
		cout << varf->codificare <<" ";
		i++;
		afisare(s, rad, i, rad);

	}
	else
	{
		if (varf->stg)
		{
			afisare(s, varf->stg, i, rad);
		}
		if (varf->drt)  
		{
			afisare(s, varf->drt, i, rad);
		}
	}
}
