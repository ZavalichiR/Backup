#include"Header.h"
//void citireM(tip **a, int n)
//{
//	cout << "\nCitire matrice\n";
//	for (int i = 0; i < n; ++i){
//		for (int j = 0; j < n; ++j)
//		{
//			cout << "a[" << i << "][" << j << "]=";
//			cin >> a[i][j];
//		}
//	}
//}
//void afisareM(tip **a, int n)
//{
//	cout << "\nAfisare matrice\n";
//	for (int i = 0; i < n; ++i){
//		for (int j = 0; j < n; ++j)
//		{
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
////Algorit Clasic
//tip** inmultireM(tip **a, tip **b, int n)
//{
//	tip **r = new tip*[10];
//	for (int i = 0; i < n; ++i)
//		r[i] = new tip[n];
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			r[i][j] = 0;
//			for (int k = 0; k < n; ++k)
//			{
//				r[i][j] =r[i][j]+ a[i][k] * a[k][j];
//			}
//		}
//	}
//	return r;
//}
//

/*
* matrice.cpp
*
*  Created on: Apr 4, 2016
*      Author: cosmin
*/
#include <iostream>
#include <stdlib.h>
#include "Header.h"

using namespace std;

void citireM(int **a, int n)
{
	cout << "\nCitire matrice\n";
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
		{
			cout << "a[" << i << "][" << j << "]=";
			//cin >> a[i][j];
			a[i][j] = 1;
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
void generareMatrice(int **A, int n)
{
	for (int i = 0; i<n; ++i)
	{
		for (int j = 0; j<n; ++j)
		{
			A[i][j] = rand() % 10;
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
int** inmultireMatrice(int** A, int** B, int n)
{
	int **A11 = aloca2D(n/2), **A12 = aloca2D(n/2), **A21 = aloca2D(n/2), **A22 = aloca2D(n/2);
	int **B11 = aloca2D(n/2), **B12 = aloca2D(n/2), **B21 = aloca2D(n/2), **B22 = aloca2D(n/2);
	int **C11, **C12, **C21, **C22;
	int** C = aloca2D(n);

	if (n == 1)
	{
		C[0][0] = A[0][0] * B[0][0];
	}
	else
	{
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				A11[i][j] = A[i][j];
				A12[i][j] = A[i][j + n / 2];

				A21[i][j] = A[i + n / 2][j];
				A22[i][j] = A[i + n / 2][j + n / 2];

				B11[i][j] = B[i][j];
				B12[i][j] = B[i][j + n / 2];
				B21[i][j] = B[i + n / 2][j];
				B22[i][j] = B[i + n / 2][j + n / 2];
			}
		}
		C11 = adunareMatrice(inmultireMatrice(A11, B11, n / 2), inmultireMatrice(A12, B21, n / 2), n / 2);
		C12 = adunareMatrice(inmultireMatrice(A11, B12, n / 2), inmultireMatrice(A12, B22, n / 2), n / 2);
		C21 = adunareMatrice(inmultireMatrice(A21, B11, n / 2), inmultireMatrice(A22, B21, n / 2), n / 2);
		C22 = adunareMatrice(inmultireMatrice(A21, B12, n / 2), inmultireMatrice(A22, B22, n / 2), n / 2);

		C = concatenareMatrice(C11, C12, C21, C22, n);
	}

	return C;
}
