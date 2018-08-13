#include"Header.h"
int main()
{

	int operatie;
	PFnComparare functie;
	Catalog c1, c2, c3, c4;
	c2.citire();
	c2.afisare();
	do {
		do {
			cout << " Ce doriti sa efectuati?" << endl;
			cout << "0-->Iesire din program" << endl;
			cout << "1-->Sortare alfabetica a numelor" << endl;
			cout << "2-->Sortare descrescatoare dupa nota" << endl;
			cout << "3->>Sortare dupa lungimea numelui-crescator" << endl;
			cout << "RAspuns: " << endl;
			cin >> operatie;

		} while ((operatie < 0) || (operatie > 3));

		switch (operatie)
		{
		case 1:
			cout << "1-->Sortare alfabetica a numerelor" << endl;
			functie = comparNumeAlfabetic;
			c2.setComparator(functie);
			break;

		case 2:
			cout << "2 - sortare descrescatoare dupa nota;" << endl;
			functie = comparNoteDescrescator;
			c2.setComparator(functie);
			break;

		case 3:
			cout << "3 - sortare dupa lungimea numelui - crescator." << endl;
			functie = comparNumeDupaLungimeCrescator;
			c2.setComparator(functie);
			break;
		default:
			cout << "Sfarsitul executiei programului" << endl;
		}
		
	} while (operatie);
	
	c2.afisare();
	c2.elibMemorie2();
	

	

	_getch();
	return EXIT_FAILURE;
}