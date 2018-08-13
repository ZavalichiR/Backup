#include"Header.h"
int main()
{
	int elm;
	Nod *arbore = new Nod;
	arbore = nullptr;
	cout << "Element: ";
	cin >> elm;
	while (elm)
	{
		inserare(arbore, elm);
		cout << "Element: ";
		cin >> elm;
	}
	inordine(arbore);
	cout << endl;
	afisare(arbore);
	cout << endl;
	cout << "Adancime: " << adancime(arbore) << endl;
	cout << "Nr Noduri: " << nrNoduri(arbore) << endl;
	system("pause");
	return 0;
}