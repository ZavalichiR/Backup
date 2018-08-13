#include"Header.h"
int main()
{
	Nod *lista = 0;
	cout << "\nIntroduceti pana ELM=0\n";
	int elm;
	cout << "\nELM: ";
	cin >> elm;
	while (elm)
	{
		inserare(lista, elm);
	cout << "\nELM: ";
	cin >> elm;
	}
	Nod *lista2 = 0;
	cout << "\nIntroduceti pana ELM=0\n";
	int elm2;
	cout << "\nELM: ";
	cin >> elm2;
	while (elm2)
	{
		inserare(lista2, elm2);
		cout << "\nELM: ";
		cin >> elm2;
	}

	afisare(lista);
	afisare(lista2);
	//afisarePermutari(lista);
	/*int elm2;
	cout << "\nELM: ";
	cin >> elm2;
	while (elm2)
	{
		cautare(lista, elm2);
		stergere(lista, elm2);
		afisare(lista);
		cout << "\nELM: ";
		cin >> elm2;
	}*/

	//Nod *l3 = new Nod;
	//l3 = unire(lista, lista2);

	/*cout << "\nDupa unire\n";
	unire2(lista, lista2);
	afisare(lista);*/
	
	interclasare(lista, lista2);
	cout << "\nDxupa interclasare\n";
	afisare(lista);
	system("pause");
	return 0;
}