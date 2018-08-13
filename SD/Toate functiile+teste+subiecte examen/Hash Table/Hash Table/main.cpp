#include"Header.h"
int main()
{
	Nod *HT[dim];
	init(HT);
	char *data = new char;
	cout << "\nData pe care o introduceti: ";
	cin.getline(data, 101);
	while (strlen(data))
	{
		inserare(HT,data);
		cout << "\nData pe care o introduceti: ";
		cin.getline(data, 101);
	}
	
	afisare(HT);
	sortare(HT);
	afisare(HT);

	//char *elm = new char;
	//cout << "\nDe sters: ";
	//cin.getline(elm, 100);
	//while (strlen(elm))
	//{
	//	stergere(HT, elm);
	//	afisare(HT);
	//	cout << "\nDe sters: ";
	//	cin.getline(elm, 100);
	//}
	//

	//char*text = new char;
	//int fr[128];
	//cout << "\nText: ";
	//cin.getline(text, 100);
	//cout << text << endl;
	//calculeazaFrecventa(text, fr);
	//afisareFrecv(fr);
	//cout << endl;
	system("pause");
	return 0;
}