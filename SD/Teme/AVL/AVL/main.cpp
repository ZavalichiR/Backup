#include"Header.h"
#include<Windows.h>

int main()
{
	AVL *a = 0;
	int ok=1, raspuns,nod,element=1;
	while (ok)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "<1>    Inserare arbore AVL" << endl;
		cout << "<2>    Inserare arbore AVL(CURS)" << endl;
		cout << "<3>    Afisare Inordine" << endl;
		cout << "<4>    Afisare indentata" << endl;
		cout << "<5>    Sterge nod" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "<0>    EXIT" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		do{
			cout << "\n\t\t\tRaspuns: ";
			cin >> raspuns;
		} while (ok<0 || ok>5);
		switch (raspuns)
		{
		case 0:
		{
				  system("cls");
				  ok = 0;
				  system("cls");
				  break;
		}
		case 1:
		{
				  system("cls");
				  cout << "Inserati (0 indica finalul inserarii): " << endl;
				  cout << "Element: ";
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				  cin >> element;
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				  while (element)
				  {
					  a = insereaza(a, element);
					  afisareIndent(a, 1);
					  system("pause");
					  system("cls");
					  cout << "Element: ";
					  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					  cin >> element;
					  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					  
				};
				  system("pause");
				  system("cls");
				  break;
		}
		case 2:
		{
				  system("cls");
				  a = arboreCurs();
				  system("cls");
				  break;
		}
		case 3:
		{
				  system("cls");
				  cout << "\t\t\t\tInordine   " << endl;
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				  inordine(a);
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				  
				  cout << endl;
				  system("pause");
				  system("cls");
				  break;
		}
		case 4:
		{
				  system("cls");
				  cout << "\t\t\t\tAfisare Indentata" << endl;
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				  afisareIndent(a, 1);
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				  cout << endl;
				  system("pause");
				  system("cls");
				  break;
		}
		case 5:
		{
				  system("cls");
				  cout << "Nodul pe care doriti sa-l stergeti: ";
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				  cin >> nod;
				  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				  a = stergere(a, nod);
				  system("pause");
				  system("cls");
				  break;
		}
		}
	}
	return 0;
}