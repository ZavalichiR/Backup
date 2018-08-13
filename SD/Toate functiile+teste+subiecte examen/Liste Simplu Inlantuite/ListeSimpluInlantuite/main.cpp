#include"Header.h"
int main()
{
	Nod *lista1 = nullptr;
	//Nod *lista2 = nullptr;
	//inserareaInFata(lista1);
	//inserareInSpate(lista1);

	//Inverseaza(lista1);

	/*cout << "\nCautare element in LISTA1\n ";
	Cauta(lista1);
	system("cls");*/

	/*cout << "\nStergere element in LISTA2\n";
	Sterge(lista2);
	system("cls");*/


	/*inserarePozitie(lista1, 99, 3);
	afisareCapCoada(lista1);*/

	//unireListe(lista1, lista2);

	/*Nod *l=interclasare(lista1, lista2);
	afisareCapCoada(l);*/

	/*interclasare2(lista1, lista2);
	afisareCapCoada(lista1);*/


	/*stergeElementePare(lista1);
	afisareCapCoada(lista1);*/

	//Nod *nou = mutaElementePare(lista1);
	//cout << "\nLista dupa stergere: ";
	//afisareCapCoada(lista1);
	//cout << "\nElemente pare: ";
	//afisareCapCoada(nou);

	Nod *lista = nullptr;
	cout << "Elm: ";
	int elm;
	cin >> elm;
	while (elm)
	{
		inserareCap(lista, elm);
		cout << "Elm: ";
		cin >> elm;
	}
	afisareCapCoada(lista);
	int ok = 1;
	palindrom(lista, lista, ok);
	if (ok == 1)
		cout << "Palindrom" << endl;
	Nod *l=insertEnd();
	afisareCapCoada(l);
	/*stergePozitie12(lista, 1);
	cout << endl;
	afisareCapCoada(lista);*/

	system("pause");
	return 0;
}