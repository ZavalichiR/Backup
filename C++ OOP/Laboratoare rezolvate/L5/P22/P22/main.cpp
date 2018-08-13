#include"Header1.h"
#include"Header2.h"
int main()
{
	system("color 48");
	MultimePersoana M;
	Persoana P;
	int opt;
	int ok = 1;
	
	while (ok)
	{
		cout << "[1]--> Inserare" << endl;
		cout << "[2]--> Extragere" << endl;
		cout << "[3]--> Afisare" << endl;
		cout << "[0]--> Iesire" << endl;

		do
		{
			cout << "\nRaspuns: ";
			cin >> opt;

		} while (opt<0 || opt>3);
		switch (opt)
		{
		case 0:
			ok = 0;
			break;
		case 1:
			P.citire();
			M.introduce(P);
			system("pause");
			system("cls");
			break;
		case 2:
			P.citire2();
			M.extrage(P);
			system("pause");
			system("cls");
			break;
		case 3:
			M.afiseaza();
			system("pause");
			system("cls");
			break;
		}
	}
	system("color 10");
	return 0;
}