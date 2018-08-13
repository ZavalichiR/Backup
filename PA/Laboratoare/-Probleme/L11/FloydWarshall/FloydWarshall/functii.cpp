#include"Header.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

void FloydWarshall(int **L, int **P, int n)
{
	int i, j, k, temp;
	for (i = 0; i<n; ++i)
	{
		for (j = 0; j<n; ++j)
		{
			if (i != j && L[i][j] != plusInf)
			{
				P[i][j] = i;
			}
			else
			{
				P[i][j] = -1;
			}
		}
	}
	for (k = 0; k<n; ++k)
	{
		for (i = 0; i<n; ++i)
		{
			for (j = 0; j<n; ++j)
			{
				if (L[i][k] == plusInf || L[k][j] == plusInf)
				{
					temp = plusInf;
				}
				else
				{
					temp = L[i][k] + L[k][j];
				}
				if (temp<L[i][j])
				{
					L[i][j] = temp;
					P[i][j] = P[k][j];
				}
				if (i == j && L[i][j]<0)
				{
					cout << endl << "(Di)graful are circuite negative!";
					exit(EXIT_FAILURE);
				}
			}
		}
	}
}
int** aloca2D(int n)
{
	int** A = new int*[n];
	if (!A)
	{
		cerr << "Eroare la alocarea dinamica a memoriei!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i<n; ++i)
	{
		A[i] = new int[n];
		if (!A[i])
		{
			cerr << "Eroare la alocarea dinamica a memoriei!" << endl;
			exit(EXIT_FAILURE);
		}
	}
	return A;
}
void dealoca2D(int **&A, int n)
{
	for (int i = 0; i<n; ++i)
	{
		if (A[i])
		{
			delete[] A[i];
			A[i] = NULL;
		}
	}
	if (A)
	{
		delete[] A;
		A = NULL;
	}
}

void afisareDrumuri(int** L, int** P, int n, int i, int j)
{
	
	if (P[i][j] != -1)
	{
		if (i != j)
		{			
			afisareDrumuri(L, P, n, i, P[i][j]);
		}
		cout << j << " ";
	}
}
void init_L(int **L) {
	for (int i = 0; i < 7; ++i) {
		L[i][i] = 0;
	}
	L[0][1] = L[0][2] = L[0][3] = L[0][6] = plusInf;
	L[0][4] = 15;
	L[0][5] = 3;
	L[1][0] = L[1][2] = L[1][4] = L[1][5] = L[1][6] = plusInf;
	L[1][3] = 1;
	L[2][0] = L[2][1] = L[2][4] = L[2][5] = L[2][6] = plusInf;
	L[2][3] = 2;
	L[3][0] = L[3][2] = L[3][5] = L[3][6] = plusInf;
	L[3][1] = 2;
	L[3][4] = 5;
	L[4][1] = L[4][3] = L[4][5] = L[4][6] = plusInf;
	L[4][0] = 7;
	L[4][2] = 2;
	L[5][0] = L[5][2] = plusInf;
	L[5][1] = 20;
	L[5][3] = 10;
	L[5][4] = 8;
	L[5][6] = 2;
	L[6][0] = L[6][2] = L[6][3] = L[6][4] = plusInf;
	L[6][1] = 5;
	L[6][5] = 7;
}
