
#include"Header.h"
using namespace std;

int main()
{
	/*
	int operatie;
	PFnComparare unPointerLaOFunctieDeComparare;
	Catalog catalogulAnului1, catalogulAnului2, catalogulAnului3, catalogulAnului4;
	catalogulAnului2.citire();
	catalogulAnului2.afisare();
	do {
		do {
			cout<<" Ce doriti sa efectuati?" << endl;
			cout << "0-->Iesire din program" << endl;
			cout << "1-->Sortare alfabetica a numelor" << endl;
			cout << "2-->Sortare descrescatoare dupa nota" << endl;
			cout << "3->>Sortare dupa lungimea numelui-crescator" << endl;
			cin >> operatie;
			
		} while ((operatie < 0) || (operatie > 3));

		switch (operatie)
		{
		case 1:
			cout << "1-->Sortare alfabetica a numerelor" << endl;
			unPointerLaOFunctieDeComparare = comparNumeAlfabetic;
			catalogulAnului2.setComparator(unPointerLaOFunctieDeComparare);
			break;

		case 2:
			cout << "2 - sortare descrescatoare dupa nota;" << endl;
			unPointerLaOFunctieDeComparare = comparNoteDescrescator;
			catalogulAnului2.setComparator(unPointerLaOFunctieDeComparare);
			break;

		case 3:
			cout << "3 - sortare dupa lungimea numelui - crescator." << endl;
			unPointerLaOFunctieDeComparare = comparNumeDupaLungimeCrescator;
			catalogulAnului2.setComparator(unPointerLaOFunctieDeComparare);
			break;
		default: 
			cout << "Sfarsitul executiei programului" << endl;
		}

	}while(operatie);

	catalogulAnului2.elibMemorie();
	*/

	Student s;
	Grupa g;
	Catalog c;
	/*cout << "Structura Student" << endl;
	s.citire();
	s.afisare();
	s.elibMem();
	*/
	/*cout << "Grupa" << endl;
	g.citire();
	g.afisare();
	g.bSort();
	*/
	//cout << "Dupa sortare" << endl;
	//g.afisare();
	//g.elibMem();

	c.citire();


	
	


	_getch();
	return EXIT_SUCCESS;
}