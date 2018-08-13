#include"Header.h"

int compare(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

void partitioneaza(int a[], int p, int q, int &k)
{

	int x = a[p];
	int i = p + 1;
	int j = q;
	while (i <= j)
	{
		if (a[i] <= x)
			i = i + 1;
		if (a[j] >= x)
			j = j - 1;
		if (i < j)
		{
			if ((a[i] > x) && (x > a[j]))
			{
				swap(a[i], a[j]);
				i = i + 1;
				j = j - 1;
			}
		}
			
		k = i - 1;
		a[p] = a[k];
		a[k] = x;
	}
	
}
void partitioneaza2(int a[], int p, int q, int &k)
{
	int x = a[p];
	int	i = p;
	int	j = q;
	while (i < j)
	{
		while (a[i] <= x && i <= q)
			i = i + 1;
		while (a[j] > x && j >= p)
			j = j - 1;
		if (i < j)
			swap(a[i], a[j]);
	}
	k = j;
	a[p] = a[k];
	a[k] = x;

}

void QuickSort1(int a[], int p, int	q)
{
	int k;
	if (p < q)
	{
		//partitioneaza(a, p, q, k);
		partitioneaza2(a, p, q, k);
		QuickSort1(a, p, k - 1);
		QuickSort1(a, k + 1, q);
	}
}

void QuickSort2(int a[], int  p, int q)
{
	int k;
	while (p < q)
	{
		//partitioneaza(a, p, q, k);
		partitioneaza2(a, p, q, k);
		if ((k - p) >(q - k))
		{
			QuickSort2(a, k + 1, q);
			q = k - 1;
		}
		else {
			QuickSort2(a, p, k - 1);
			p = k + 1;
		}
	}
}

