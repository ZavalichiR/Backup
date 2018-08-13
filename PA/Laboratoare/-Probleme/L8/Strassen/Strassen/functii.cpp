
#include <iostream>
#include <stdlib.h>
#include "Header.h"

using namespace std;

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
void generareMatrice(int **A, int n)
{
	for (int i = 0; i<n; ++i)
	{
		for (int j = 0; j<n; ++j)
		{
			//A[i][j] = rand() % 10;
			A[i][j] = 1;
		}
	}
}
void afisareMatrice(int **A, int n)
{
	for (int i = 0; i<n; ++i)
	{
		for (int j = 0; j<n; ++j)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}
int** adunareMatrice(int** A, int** B, int n)
{
	int** S = aloca2D(n);
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			S[i][j] = A[i][j] + B[i][j];
		}
	}
	return S;
}
int** scadereMatrice(int** A, int** B, int n)
{
	int** S = aloca2D(n);
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			S[i][j] = A[i][j] - B[i][j];
		}
	}
	return S;
}
int** sfert(int** A, int n, int nrSfert)
{
	int** sfert = aloca2D(n / 2);

	switch (nrSfert)
	{
	case 1:
		for (int i = 0; i<n / 2; i++)
		{
			for (int j = 0; j<n / 2; j++)
			{
				sfert[i][j] = A[i][j];
			}
		}
		break;

	case 2:
		for (int i = 0; i<n / 2; i++)
		{
			for (int j = 0; j<n / 2; j++)
			{
				sfert[i][j] = A[i][j + n / 2];
			}
		}
		break;

	case 3:
		for (int i = 0; i<n / 2; i++)
		{
			for (int j = 0; j<n / 2; j++)
			{
				sfert[i][j] = A[i + n / 2][j];
			}
		}
		break;

	case 4:
		for (int i = 0; i<n / 2; i++)
		{
			for (int j = 0; j<n / 2; j++)
			{
				sfert[i][j] = A[i + n / 2][j + n / 2];
			}
		}
	}

	return sfert;
}
int** concatenareMatrice(int** A, int** B, int** C, int** D, int dim)
{
	int** E = aloca2D(dim);

	for (int i = 0; i<dim / 2; i++)
	{
		for (int j = 0; j<dim / 2; j++)
		{
			E[i][j] = A[i][j];
			E[i][j + dim / 2] = B[i][j];
			E[i + dim / 2][j] = C[i][j];
			E[i + dim / 2][j + dim / 2] = D[i][j];
		}
	}

	return E;
}
int** strassen(int** A, int** B, int n)
{
	int **M1, **M2, **M3, **M4, **M5, **M6, **M7;
	int **A11, **A12, **A21, **A22;
	int **B11, **B12, **B21, **B22;
	int **C11, **C12, **C21, **C22;
	int **C = aloca2D(n);

	if (n == 1)
	{
		C[0][0] = A[0][0] * B[0][0];
	}
	else
	{
		A11 = sfert(A, n, 1);
		A12 = sfert(A, n, 2);
		A21 = sfert(A, n, 3);
		A22 = sfert(A, n, 4);

		B11 = sfert(B, n, 1);
		B12 = sfert(B, n, 2);
		B21 = sfert(B, n, 3);
		B22 = sfert(B, n, 4);

		M1 = strassen(adunareMatrice(A11, A22, n / 2), adunareMatrice(B11, B22, n / 2), n / 2);
		M2 = strassen(adunareMatrice(A21, A22, n / 2), B11, n / 2);
		M3 = strassen(A11, scadereMatrice(B12, B22, n / 2), n / 2);
		M4 = strassen(A22, scadereMatrice(B21, B11, n / 2), n / 2);
		M5 = strassen(adunareMatrice(A11, A12, n / 2), B22, n / 2);
		M6 = strassen(scadereMatrice(A21, A11, n / 2), adunareMatrice(B11, B12, n / 2), n / 2);
		M7 = strassen(scadereMatrice(A12, A22, n / 2), adunareMatrice(B21, B22, n / 2), n / 2);

		C11 = adunareMatrice(adunareMatrice(M1, M4, n / 2), scadereMatrice(M7, M5, n / 2), n / 2);
		C12 = adunareMatrice(M3, M5, n / 2);
		C21 = adunareMatrice(M2, M4, n / 2);
		C22 = adunareMatrice(scadereMatrice(M1, M2, n / 2), adunareMatrice(M3, M6, n / 2), n / 2);

		C = concatenareMatrice(C11, C12, C21, C22, n);
	}

	return C;
}
