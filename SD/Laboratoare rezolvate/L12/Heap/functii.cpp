#include"Header.h"

void insert(int *h, int val, int &n)
{
	h[n + 1] = val;
	n++;
	int fiu =n, tata = n / 2, aux;
	while (tata >= 1)
	{
		if (h[tata] < h[fiu])
		{
			aux = h[tata];
			h[tata] = h[fiu];
			h[fiu] = aux;
			fiu = tata;
			tata = tata / 2;
		}
		else
			tata = 0;

	}
}
//void inordine(int *v, int i, int n)
//{
//	if (i <= n && (v[i] != '-'))
//	{
//		inordine(v, i * 2, n);
//		cout << v[i];
//		inordine(v, i * 2 + 1, n);
//	}
//}
//void inordine0(int *v, int i, int n)
//{
//	if (i < n && (v[i] != '-'))
//	{
//		inordine0(v, 2 * i + 1, n);
//		cout << v[i];
//		inordine0(v, 2 * i + 2, n);
//	}
//}
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
		if (h[fiu] > h[tata])
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
void percolate(int *h, int i,int n)
{
	
	n = n - 1;
	int tata = i;
	int fiu = 2*i;
	while (fiu <= n)
	{
		if (fiu + 1 <= n && h[fiu + 1] > h[fiu])
			fiu = fiu + 1;
		if (h[fiu] > h[tata])
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
		insert(h, i - 1, h[i]);
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
 