#include"Header.h"

int main()
{
	Nod *radacina = NULL;
	
	int opt, ok = 1;
	while (ok)
	{
		system("color 0F");
		cout << "<1>--->Citire arbore " << endl;
		/*Frunzele arborelui sunt plasate crescãtor de la stânga spre dreapta*/
		cout << "<2>--->Afisare INORDINE " << endl;
		cout << "<3>--->Afisare POSTORDINE " << endl;
		cout << "<4>--->Afisare PREORDINE " << endl;
		cout << "<0>--->Iesire din program" << endl;
		do
		{
			cout << "Raspuns: ";
			cin >> opt;

		} while (opt<0 || opt>4 );
		switch (opt)
		{
		case 0:
			ok = 0;
			break;
		case 1:
			radacina=creare();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			cout << "Recursiv: ";
			inordineRecursiv(radacina);
			cout << endl;
			cout << "Iterativ: ";
			inordineIterativ(radacina);
			cout << endl;
			system("pause");
			system("cls");
			
			break;
		case 3:
			system("cls");
			cout << "Recursiv: ";
			postordineRecursiv(radacina);
			cout << endl;
			cout << "Iterativ: ";
			postordineIterativ(radacina);
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "Recursiv: ";
			preordineRecursiv(radacina);
			cout << endl;
			cout << "Iterativ: ";
			preordineIterativ(radacina);
			system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}