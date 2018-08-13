#include"Header.h"
int main()
{

	int n, elm, i = 1;
	Nod *head = 0;
	cout << "\nPrecizati numarul de elemente: ";
	cin >> n;
	int m = n;
	while (n)
	{
		cout << "\nElementul " << i << " :";
		cin >> elm;
		inserareFata(head, elm);
		i = i + 1;
		n--;
	}
	while (m)
	{
		int elm;
		cout << "\nElm: ";
		cin >> elm;
		stergere(head, elm);
		afisare(head);
		//cautare(head, elm);
		m--;
	}

	/*int m2;
	cout << "\nPozitia: ";
	cin >> m2;
	while (m2)
	{
		inserarePozitie(head, 99,m2);
		afisare(head);
		cout << "\nPozitia: ";
		cin >> m2;
	}*/

	system("pause");
	return 0;
}