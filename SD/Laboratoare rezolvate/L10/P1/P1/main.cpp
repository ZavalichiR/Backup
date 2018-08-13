#include"Header.h"
int main()
{
	int ok = 1, raspuns;
	Nod *Arbore = 0;
	while (ok)
	{
		cout << "<1>   Inserare" << endl;
		cout << "<2>   Afisare inline" << endl;
		cout << "<3>   Afisare indentata" << endl;
		cout << "<4>   Cautare NOD" << endl;
		cout << "<5>   Sterge NOD" << endl;
		cout << "<0>   EXIT" << endl;
		do
		{
			cout << "Raspuns: ";
			cin >> raspuns;
		} while (raspuns<0 || raspuns>5);

		switch(raspuns)
		{
			case 0:
			{
					  system("cls");
					  ok = 0;
					  system("pause");
					  system("cls");
					  break;
			}
			case 1:
			{
					  system("cls");
					  int data;
					  cout << "Data: ";
					  cin >> data;
					  do
					  {
						  Arbore = inserareBST(Arbore, data);
						  cout << "Data: ";
						  cin >> data;
					  } while (data != 0);
					  system("pause");
					  system("cls");
					  break;
			}
			case 2:
			{
					  system("cls");
					  cout << "          Afisare INORDINE" << endl;
					  inordine(Arbore);
					  system("pause");
					  system("cls");
					  break;
			}
			case 3:
			{
					  system("cls");
					  cout << "          Afisare INDENTATA" << endl;
					  indentat(Arbore,1);
					  system("pause");
					  system("cls");
					  break;
			}
			case 4:
			{
					  system("cls");
					  cout << "Nodul cautat: ";
					  int nod;
					  cin >> nod;
					  /*if (cautare(Arbore, nod) == 1)
					  {
						  cout << "Nodul a fost gasit" << endl;
					  }
					  else*/
						  //cout << "Nodul nu a fost gasit" << endl;
					  /*cout << "Nodul cautat este: " << cautare2(Arbore, nod)->data << endl;*/
					  if (cautare3(Arbore, nod))
						  cout << "NODUL CAUTAT ESTE:" << cautare3(Arbore, nod)->data << endl;
					  else
						  cout << "Nodul nu a fost gasit" << endl;
					  system("pause");
					  system("cls");
					  break;

			}
			case 5:
			{
					  system("cls");
					  int val;
					  cout << "Nodul pe care doriti sa-l stergeti: ";
					  cin >> val;
					  sterge(Arbore, val);
					  system("pause");
					  system("cls");

			}


		}


	}
	
	return 0;
}