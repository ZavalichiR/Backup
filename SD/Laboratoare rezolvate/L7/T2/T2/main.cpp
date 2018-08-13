#include"Header.h"
#include<fstream>
#include<cstdlib>

int main()
{
	int o;
	int ok = 1;
	char *text = new char[100];
	cout << "Textul: ";
	cin >> text;
	cout << endl << text << endl;

	int f[128];
	calculareFrecventa(text, f);

	afisareFrecv(f);

	system("pause");
	/*
	char numefisier[20];
	ifstream fisier;
	cout << "Numele fisierului: ";
	cin.getline(numefisier, 20);
	fisier.open(numefisier);
	if (!fisier.is_open())
	{
		exit(EXIT_FAILURE);
	}

	char *key = new char[20];
	fisier >> key;
	inserare(key);
	while (fisier.good())
	{
		inserare(key);
		fisier >> key;
	}

	while (ok)
	{
		cout << "1-->Afisare" << endl;
		cout << "2-->Afisare alfabetica" << endl;
		cout << "3-->Frecventa de aparitie" << endl;
		cout << "<<<4>>> EXIT" << endl;
		do{
			cout << "\nRaspuns: ";
			cin >> o;
		} while (o<1 && o>3);

		switch (o)
		{
		case 1:
			afisare();
			system("pause");
			system("cls");
			break;
		case 2:
			sortare();
			afisare();
			system("pause");
			system("cls");
			break;
		case 3:
			break;
		case 4:
			ok = 0;
			break;

		}
		
	}
	*/
	system("cls");

	return 0;
}