#include"Header.h"

void main()
{
	int n = 10;
	MyVector<int> vectorI(n); //un vector de numere intregi 
	MyVector<float> vectorF(n); //un vector de numere reale 
	for (int i = 0; i < n; i++)
	{
		/* accesam elementele din membrul privat elem
		prin intermediul operatorului [] supraincarcat in clasa */
		vectorI[i] = i + 1;
		vectorF[i] = 1.5 * i;
	}
	vectorI.afisare();
	cout << endl;
	vectorF.afisare();
	int m;
	cout << "\nPrecizati numarul de elemete: ";
	cin >> m;
	MyVector<int> vector(m);
	vector.citire();
	vector.afisare();
	cout << "\nVectorul sortat: ";
	vector.sortare();
	vector.afisare();

}