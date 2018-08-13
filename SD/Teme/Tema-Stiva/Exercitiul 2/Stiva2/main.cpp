#include"Header.h"

int main()
{
	int vect[20];
	int nr;
	cout << "\nPrecizati numarul de elemente: ";
	cin >> nr;
	citireV(vect, nr);
	cout << "\nVectorul citit este: ";
	afisareV(vect, nr);
	inversare(vect, nr);
	cout << "\nVectorul inversat este: ";
	afisareV(vect, nr);

	return 0;
}