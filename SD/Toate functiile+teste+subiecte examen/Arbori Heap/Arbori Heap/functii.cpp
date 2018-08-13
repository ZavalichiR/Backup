#include"Header.h"

void insert(int *h, int val, int &n)
{
	h[n + 1] = val;
	n++;
	int fiu = n, tata = n / 2, aux;
	while (tata >= 1)
	{
		if (h[tata] < h[fiu])
		{
			aux = h[tata];
			h[tata] = h[fiu];
			h[fiu] = aux;
			fiu = tata;
			tata = fiu / 2;
		}
		else
			tata = 0;

	}
}

void inordine(int *v, int i, int n)
{
	if (i <= n && (v[i] != '-'))
	{
		inordine(v, i * 2, n);
		cout << v[i];
		inordine(v, i * 2 + 1, n);
	}
}
void postordine(int *v, int i, int n)
{
	if (i <= n)
	{
		postordine(v, 2 * i, n);
		postordine(v, 2 * i + 1, n);
		cout << v[i] << " ";
	}
}

int sterge(int *h, int &n)
{
	int rez = h[1];
	h[1] = h[n];
	n = n - 1;
	int tata = 1;
	int fiu = 2;
	while (fiu <= n)
	{
		if (fiu + 1 <= n && h[fiu + 1] > h[fiu])
			fiu = fiu + 1;
		if ( h[tata]<h[fiu])
		{
			int aux = h[tata];
			h[tata] = h[fiu];
			h[fiu] = aux;
			tata = fiu;
			fiu = 2 * tata;
		}
		else
			fiu = n + 1;
	}
	return rez;
}
//Metoda 2
void percolate(int *h, int i, int n)
{

	n = n - 1;
	int tata = i;
	int fiu = 2 * i;
	while (fiu <= n)
	{
		if (fiu + 1 <= n && h[fiu + 1] > h[fiu])
			fiu = fiu + 1;
		if (h[tata]<h[fiu])
		{
			int aux = h[tata];
			h[tata] = h[fiu];
			h[fiu] = aux;
			tata = fiu;
			fiu = 2 * tata;
		}
		else
			fiu = n + 1;
	}

}

void creareMaxHeap(int *h, int n)
{
	for (int i = n / 2; i >= 1; --i)
		percolate(h, i, n);
}
//Metoda 1
void creareMaxHeap2(int *h, int n)
{
	for (int i = 2; i <= n; ++i)
	{
		int aux = i - 1;
		insert(h, h[i], aux);
	}
}
//Sortarea
void sortareHeap(int *h, int n)
{
	int aux;
	for (int i = n; i >= 1; i--)
	{
		aux = sterge(h, n);
		h[n + 1] = aux;
	}
}

int m = 0;
int max(int *h, int i, int n)
{
	if (i <= n)
	{
		max(h, 2 * i, n);
		if (m < h[i])
			m = h[i];
		max(h, 2 * i + 1, n);
	}
	return m;
}
bool test = 1;
bool isCauare(int *h,int i, int n)
{
	if (i<n)
	{
		isCauare(h, 2 * i, n);
		if (test)
			if ((2 * i <= n) && (2 * i + 1 <= n))
				test = (h[i] > h[2*i]) && (h[i] < h[2*i+1]);
			else
			if (2 * i <= n)
				test = h[i] > h[2 * i];
			else
			if (2 * i + 1 <= n)
				test = h[i] < h[2 * i + 1];
			isCauare(h, 2 * i + 1, n);
		
	}
	return test;
}
bool t=1;

bool isHeap(int *h, int i, int n)
{
	for (i = 1; i <= n; ++i)
	{
		if (2*i < n)
		if (h[2 * i ] > h[i])
			return 0;
		if (2 * i + 1 < n)
		if (h[2 * i + 1] > h[i])
			return 0;
	}
}