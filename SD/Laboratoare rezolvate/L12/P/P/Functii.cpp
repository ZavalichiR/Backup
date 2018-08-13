#include"Header.h"

void insert(int *&h, int val, int &n)
{
	h[n + 1] = val;
	n++;
	int fiu = val, tata = val / 2, aux;
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
void inordine(int *v, int i, int n)
{
	if (i <= n && (v[i] != '-'))
	{
		inordine(v, i * 2, n);
		cout << v[i];
		inordine(v, i * 2 + 1, n);
	}
}
void inordine0(int *v, int i, int n)
{
	if (i < n && (v[i] != '-'))
	{
		inordine0(v, 2 * i + 1, n);
		cout << v[i];
		inordine0(v, 2 * i + 2, n);
	}
}

void max_heap(int *a, int i, int n)
{
	int j, aux;
	aux = a[i];
	j = 2 * i;
	while (j <= n)
	{
		if (j<n && a[j + 1]>a[j])
			j = j + 1;
		if (aux>a[j])
			break;
		else
		if (aux <= a[j])
			a[j / 2] = a[j];
		j = 2 * j;
	}
	a[j / 2] = aux;
	return;
}
void build_maxheap(int *a, int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		max_heap(a, i, n);
	}
}
void heapsort(int* a, int n)
{
	int i, aux;
	for (i = n; i >= 2; i--)
	{
		aux = a[i];
		a[i] = a[1];
		a[1] = aux;
		max_heap(a, 1, i - 1);
	}
}