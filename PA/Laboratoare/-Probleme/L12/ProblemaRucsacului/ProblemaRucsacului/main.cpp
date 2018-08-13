#include <iostream>
#include "Header.h"

using namespace std;

int *p, *w, *x;

int main(void)
{
	int n, M;
	cout << "Introduceti numarul de obiecte n:\n n=  ";
	cin >> n;

	w = new int[n]; //vectorul de greutati
	p = new int[n]; //vectorul de profituri
	x = new int[n]; //vectorul solutie

	cout << "Introduceti greutatea si profitul fiecarui obiect:\n";
	/*for (int i = 0; i<n; ++i)
	{
		cout << "Obiectul " << (i + 1) << ":\n";
		cout << "greutate: ";
		cin >> w[i];
		cout << "profit: ";
		cin >> p[i];
		cout << endl;
	}*/
	cout << "Introduceti capacitatea rucsacului M:\n M= ";
	cin >> M;

	w[0] = 3; w[1] = 5; w[2] = 6;
	p[0] = 10; p[1] = 30; p[2] = 20;

	rucsac(M, n, w, p, x);

	cout << endl << "Solutia optima este: ";
	for (int i = 0; i<n - 1; ++i)
	{
		cout << x[i] << ", ";
	}
	cout << x[n - 1] << "\n";

	if (p)
	{
		delete[] p;
	}
	if (w)
	{
		delete[] w;
	}
	if (x)
	{
		delete[] x;
	}

	system("pause");
	return 0;
}
