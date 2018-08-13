#include"Header.h"
int main()
{
	Nod *lista = nullptr;
	cout << "Elm: ";
	tip elm;
	cin >> elm;
	while (elm)
	{
		inserare(lista, elm);
		cout << "Elm: ";
		cin >> elm;
	}
	afisare(lista);
	cout << endl;
	ordonare(lista);
	afisare(lista);
	cout << endl;
	sterge(lista, 1);
	afisare(lista);
	cout << endl;
	Nod *lista2 = nullptr;
	/*lista2 = schimbareLegaturi(lista);
	afisare(lista2);*/
	system("pause");
	return 0;
}