#include"Header.h"
int suma(int w[], int n)
{
	int s = 0;
	for (int i = 1; i <= n; ++i)
	{
		s = s + w[i];
	}
	return s;
}
void citire(int x[], int k)
{
	for (int i = 1; i <= k; ++i)
	{
		printf("x[%d]= ",i) ;
		cin >> x[i];
	}
}

void afisare(int x[], int k)
{
	for (int i = 1; i <= k; ++i)
	{
		cout << x[i] << " ";
	}
}

void submultimiOptim(int s, int k, int r, int w[],int x[],int M)
{
	x[k] = 1;
	int j = 1;
	if (s + w[k] == M)
	{
		cout << "\nVarianta " << j << ": ";
		afisare(x,k);
		j++;
	}
	else
	{
		if (s + w[k] + w[k + 1] <= M)
		{
			submultimiOptim(s + w[k], k + 1, r - w[k], w, x, M);
		}
		if (((s + r - w[k]) >= M) && (s + w[k + 1] <= M))
		{
			x[k] = 0;
			submultimiOptim(s, k + 1, r - w[k], w, x, M);
		}
	}
		
}