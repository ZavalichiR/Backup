#include"Header.h"
int main()
{
	// ARbore: A(B(D,E),C(F,G(-,H)))
	/*for (int i = 0; i < 256; ++i)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		cout << i <<"--TEXT"<< endl;
	}*/
	int ok = 1, rasp;
	Nod* arbore = new Nod;
	while (ok)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "<1>----> Creare arbore" << endl;
		cout << "<2>----> Afisare Inordine" << endl;
		cout << "<3>----> Afisare Preordine" << endl;
		cout << "<4>----> Afisare Postordine" << endl;
		cout << "<5>----> Adancime" << endl;
		cout << "<6>----> Numarul de frunze" << endl;
		cout << "<7>----> Numarul de noduri" << endl;
		cout << "<8>----> Nodul Maxim" << endl;
		cout << "<9>----> Nodul Minim" << endl;
		cout << "<10>---> Numarul de elemente arbore" << endl;
		cout << "<11>---> Comutare" << endl;
		cout << "<12>---> Afisare 2" << endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "\n<0>----> >>>Exit<<<" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		


		do{
			cout << "     Raspuns: ";
			cin >> rasp;
		} while (rasp<0 || rasp>12);
		switch (rasp)
		{
		case 0:
		{
				  ok = 0;
				  system("cls");
				  break;
		}
		case 1:
		{
				  system("cls");
				  cout << "Exemplu: A(B(D,E),C(F,G(-,H)))" << endl;
				  cin.ignore(100, '\n');
				  arbore = creareArbore();
				  system("pause");
				  system("cls");
				  break;
		}
		case 2:
		{
				  system("cls");
				  cout << "Inordine: ";
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				  inordine(arbore);
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				  
				  cout << endl;
				  system("pause");
				  system("cls");
				  break;
		}
		case 3:
		{
				  system("cls");
				  cout << "Preordine: ";
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				  preordine(arbore);
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				  
				  cout << endl;
				  system("pause");
				  break;
		}
		case 4:
		{
				  system("cls");
				  cout << "Postordine: ";
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				  postordine(arbore);
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				  
				  cout << endl;
				  system("pause");
				  system("cls");
				  break;
		}
		case 5:
		{
				  system("cls");
				  cout << "Adancime: ";
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				  cout << adancime(arbore) << endl;
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				  
				  cout << endl;
				  system("pause");
				  system("cls");
				  break;
		}
		case 6:
		{
				  system("cls");
				  cout << "Numarul de frunze: ";
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				  cout << frunze(arbore) << endl;
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				  
				  cout << endl;
				  system("pause");
				  system("cls");
				  break;
		}
		case 7:
		{
				  system("cls");
				  cout << "Numarul de noduri: ";
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				  cout << nrnoduri(arbore) << endl;
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				  
				  cout << endl;
				  system("pause");
				  system("cls");
				  break;
		}
		case 8:
		{
				  system("cls");
				  cout << "Nodul maxim: ";
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				  cout << Max(arbore) << endl;
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				  
				  cout << endl;
				  system("pause");
				  system("cls");
				  break;
		}
		case 9:
		{
				  system("cls");
				  cout << "Nodul minim ";
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				  cout << Min(arbore) << endl;
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				  
				  cout << endl;
				  system("pause");
				  system("cls");
				  break;
		}
		case 10:
		{
				  system("cls");
				  cout << "Numar elemente arbore: ";
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				  cout << elementeArbore(arbore) << endl;
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

				  cout << endl;
				  system("pause");
				  system("cls");
				  break;
		}
		case 11:
		{
				   system("cls");
				   comuta(arbore);
				   cout << endl;
				   system("pause");
				   system("cls");
				   break;
		}
		case 12:
		{
				   system("cls");
				   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				   afisareIntend(arbore,1);
				   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				   cout << endl;
				   system("pause");
				   system("cls");
				   break;
		}

		}
	}
	return 0;
}