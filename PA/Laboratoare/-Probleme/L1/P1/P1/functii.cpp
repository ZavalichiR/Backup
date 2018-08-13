/*
* functii.cpp
*
*  Created on: Feb 17, 2017
*      Author: zava
*/
#include"header.h"
#include<stdlib.h>

void citire(int a[100][100], int n)
{
	cout << "Citire matrice: " << endl;
	for (int i = 0; i<n; ++i)
	{
		for (int j = 0; j<n; ++j)
		{
			//cout<<"a["<<i<<"]["<<j<<"]= ";
			a[i][j] = (int)rand() % 100;
			//cin>>a[i][j];
		}
	}
}
void afisare(int a[100][100], int n)
{
	cout << "Afisare matrice: " << endl;
	for (int i = 0; i<n; ++i)
	{
		for (int j = 0; j<n; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void rotire(int a[100][100], int n)
{
	/*int b[100][100];
	for (int i=0;i<n;++i)
	for(int j=0;j<n;++j)
	{
	b[i][j]=a[j][n-i-1];
	}
	afisare(b,3);
	*/
	for (int i = 0; i<n; ++i)
	{
		for (int j = i; j<n; ++j)
		{
			int aux = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = aux;

		}
	}
	for (int i = 0; i<n / 2; ++i)
	{
		for (int j = 0; j<n; ++j)
		{
			int aux = a[i][j];
			a[i][j] = a[n - 1 - i][j];
			a[n - 1 - i][j] = aux;
		}
	}
	cout << "Dupa rotire: " << endl;
	afisare(a, n);

}
