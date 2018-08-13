#include"Header.h"
int main()
{
	Nod *lista = 0;
	int c1 = 0, c2 = 0;
	int elm=10000;
	while (elm)
	{
		inserarePopescu(lista, elm,c1);
		elm--;
	}

	//afisare(lista);

	Nod *lista2 = 0;
	int elm2=10000;
	while (elm2)
	{
		inserareIonescu(lista2, elm2,c2);
		elm2--;
	}

	//afisare(lista3);

	int c3 = 0;
	Nod *lista3=0;
	//cout << "\nIntroduceti pana ELM=0\n";
	int elm3=10000;
	/*cout << "\nELM: ";
	cin >> elm3;*/
	while (elm3)
	{
		inserare(lista3, elm3, c3);
		elm3--;
	}
	//afisare(lista2);

	cout << "\nOperatii POPESCU: " << c1 << endl;
	cout << "\nOperatii IONESCU: " << c2 << endl;
	cout << "\nOperatii POPESCU funcia 2: " << c3 <<" Se micsoreaza cu "<<c1-c3<<" iteratii"<< endl;

	system("pause");
	return 0;
}