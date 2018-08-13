#include"Header.h"
int main(void)
{

	int n1, n2;
	Nod *lista1 = 0, *lista2 = 0;
	cout << "Numarul de elemente pentru prima lista: ";
	cin >> n1;

	cout << "Prima lista: " << endl;
	while (n1)
	{
		inserare(lista1, n1);
		n1--;
	}

	cout << "Numarul de elemente pentru a doua lista: ";
	cin >> n2;
	cout << "A doua lista" << endl;
	while (n2)
	{
		inserare(lista2, n2);
		n2--;
	}

	cout << "Lista 1: ";
	afisare(lista1);
	cout << "Lista 2: ";
	afisare(lista2);

	//unireliste(lista1, lista2);
	//cout << "\nListele unite:";
	//afisare(lista1);

	interclasare(lista1, lista2);
	cout << "\nListele interclasate:";
	afisare(lista1);

	afisareMijloc(lista1);

	FaBucla(lista1);



	EstiWaiBucla(lista1);

	_getch();


	return 0;
}