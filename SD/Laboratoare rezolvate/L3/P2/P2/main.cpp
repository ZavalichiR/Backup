#include"Header.h"
#include<string>
int main(void)
{

	persoana data;
	Nod *cap = 0;
	int comanda;
	char pers[100];
	int n;

	do 
	{
	
		system("cls");

		cout << "1--> Introducere Agenda" << endl;
		cout << "2--> Introducere Agenda in ordine alfabetica" << endl;
		cout << "3--> Stergere persoana dupa nume" << endl;
		cout << "4--> Cautare nume dupa numar" << endl;
		cout << "5--> Afisare" << endl;
		cout << "0-->Iesire din prigram" << endl;

		cout << "Comanda: ";
		cin >> comanda;
		switch (comanda)
		{

		case 1:
		{
			cout << "Precizati numarul de persoane: ";
			cin >> n;
			while (n)
			{
				data.citireAgenda();
				inserare(cap, data);

				--n;
			}
			system("pause");
			break;
		}

		case 2:
		{
			cout << "Precizati numarul de persoane: ";
			cin >> n;
			while (n)
			{
				data.citireAgenda();
				insertOrder(cap, data);

				--n;
			}
			system("pause");
			break;
		}

		case 3:
		{
			cout << "Numele pe care vrei sa-l stergeti: ";
			
			cout << "Nume:";

			cin.ignore(100, '\n');
			cin.getline(pers, 100);

			stergere(cap, pers);
			system("pause");

			break;
		}

		case 4:
		{
			cout << "Introduceti numarul: ";
			int numar;
			cin >> numar;

			cautare(cap, numar);
			system("pause");
			break;
		}

		case 5:
		{
			cout << "   Agenda" << endl;
			afisare(cap);
			system("pause");
			break;
		}

		case 0:
		{
			Nod *q;
			while (cap)
			{
				q = cap;
				cap = cap->leg;
				delete q;
			}
			break;

		}

		default:
			cout << "Introduce in plm ce trebuie!!!!" << endl;
			system("pause");
			break;
		}

	} while (comanda);



	_getch();
	return 0;
}