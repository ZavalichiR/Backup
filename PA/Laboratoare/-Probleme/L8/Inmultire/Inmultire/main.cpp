
#include <iostream>
#include <stdlib.h>
#include "Header.h"

	using namespace std;

	int main(void)
	{
		int **A, **B, **C, n;
		bool ok;

		do {
			cout << "Dimensiunea matricei (putere a lui 2): ";
			cin >> n;

			ok = true;
			int aux = n;
			int rest;
			while (aux != 1)
			{
				rest = aux % 2;
				if (rest)
				{
					cout << endl << "Dimensiunea introdusa nu este putere a lui 2!" << endl << endl;
					ok = false;
					break;
				}
				aux = aux / 2;
			}
		} while (!ok);

		A = aloca2D(n);
		//generareMatrice(A, n);

		cout << " Citire Matrice: " << endl;
		citireM(A, n);
		cout << "Matricea A :" << endl;
		afisareMatrice(A, n);

		cout << " Citire Matrice: " << endl;
		B = aloca2D(n);
		//generareMatrice(B, n);
		citireM(B, n);
		cout << endl << "Matricea B:" << endl;
		afisareMatrice(B, n);

		cout << endl << "Produsul:" << endl;
		C = inmultireMatrice(A, B, n);
		afisareMatrice(C, n);

		dealoca2D(A, n);
		dealoca2D(B, n);
		dealoca2D(C, n);

		system("pause");
		return 0;
		
	}

	/*int n = 2;
	tip **a = new tip*[10];
	for (int i = 0; i < n; ++i)
		a[i] = new tip[n];
	tip **r;
	citireM(a, n);
	afisareM(a, n);
	r = inmultireM(a, a, n);
	afisareM(r, n);

	system("pause");*/
