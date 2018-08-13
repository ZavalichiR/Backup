
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

using namespace std;

int main(void)
{
	int **A, **B, **C, n;
	bool ok;

	srand(time(0));

	do {
		cout << "Introduceti dimensiunea matricilor de generat:";
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
	generareMatrice(A, n);
	cout << "Matricea A generata:" << endl;
	afisareMatrice(A, n);

	B = aloca2D(n);
	generareMatrice(B, n);
	cout << endl << "Matricea B generata:" << endl;
	afisareMatrice(B, n);

	cout << endl << "Produsul matricelor A si B obtinut prin metoda lui Strassen:" << endl;
	C = strassen(A, B, n);
	afisareMatrice(C, n);

	dealoca2D(A, n);
	dealoca2D(B, n);
	dealoca2D(C, n);
	system("pause");
	return 0;
}
