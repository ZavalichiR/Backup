#include"Header.h"

void BbsortClasic(int a[], int n)
{
	int ok = 1;
	int i;
	int aux;
	while (ok)
	{
		ok = 0;
		for (i = 0; i < n - 1; ++i)
		{
			if (a[i]>a[i + 1])
			{
				aux = a[i];
				a[i] = a[i + 1];
				a[i + 1] = aux;
				ok = 1;
			}
			
		}
	}
}
void BbSort(int a[], int n)
{
		int n1;
		int ultim = n - 1;
		while (ultim > 0)
		{
			n1=ultim - 1;
			ultim = 0;
			for (int i=0;i<=n1;++i)
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
					ultim = i;
			}		
		}
}

void insSortClasic(int a[], int n)
{
	for (int i = 1; i < n - 1; ++i)
	{
		
		 int aux = a[i];
		 int j = i - 1;
		 while ((j >= 0) && (a[j]>aux))
		 {
			a[j + 1]  = a[j];
			j = j - 1;
		 }
		 a[j + 1]  = aux;

		 //-----Versiunea de mai jos este mai costisitoare-----///
		/*int j = i;
		while ((j >= 0) && (a[j - 1] > a[j]))
		{
			int aux = a[j];
			a[j] = a[j - 1];
			a[j - 1] = aux;
			j--;

		}*/
	}
}
void insertionSort(int a[], int n)
{
	int i;
	for (int k = 1; k <=n - 1; ++k)
	{
		i = k - 1;
		int temp = a[k];
		while ((i>=0) && (temp < a[i]))
		{
			a[i + 1] = a[i];
			i = i - 1;
		}
			
		if (i != k - 1)
			a[i + 1] = temp;
	}	
}

void naivSort(int a[], int n)
{
	for (int i=n-1;i>1;--i)
	{
		int locmax = 0;
		int	maxtemp = a[0];
		for (int j = 1; j<i; ++j)
		{
			if (a[j] > maxtemp)
			{
				locmax = j;
				maxtemp = a[j];
			}		
		}
			
		a[locmax] = a[i];
		a[i] = maxtemp;
	}	
}

