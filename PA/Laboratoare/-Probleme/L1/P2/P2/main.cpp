
#include"Header.h"
int main()
{
	node *nod = NULL;
	int e;
	cout << "Element: ";
	cin >> e;
	while (e)
	{
		creare(nod, e);
		cin >> e;
	}
	afisare(nod);
	cout << "Pozitia: ";
	int p;
	cin >> p;
	cout << "Valoare: ";
	cin >> e;
	while (p)
	{
		inserare(nod, e, p);
		afisare(nod);
		cout << "Pozitia: ";
		cin >> p;
		cout << "Valoare: ";
		cin >> e;
	}

	return 0;
}


