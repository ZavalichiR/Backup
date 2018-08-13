
#include <iostream>
#include "header.h"

int main()
{
	nod *rad = 0;
	int n;
	creare(rad);
	
	cout << "Numarul de elemente: ";
	cin >> n;


	for (int i = 1; i <= n; ++i)
	{
		// int a = rand()%100;
		//insereazaBArbore(rad, a);
		insereazaBArbore(rad, i);
	}
		


	cout << "\n   ARBORE B   " << endl;
	afisare(rad, 1);

	int rel = 1;
	while (rel)
	{

		cout << "\nCautare numar: ";
		cin >> n;
		int poz = 1;
		int p;
		p = cautare(rad, n, poz);
		if (cautare(rad, n, poz) != -1)
			cout << "Numarul a fost gasit pe pozitie: " << p << endl;
		else
			cout << "Numarul nu a fost gasit." << endl;

		cout << "\nReluati cautarea? ";
		cout << "\n1-----DA ";
		cout << "\n0-----NU ";
		cin >> rel;
	}
	

	system("pause");

	return 0;
}

