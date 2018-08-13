#include"Header.h"
int main()
{
	Nod *arbore = new Nod;
	cout << "Exemplu: A(B(D,E),C(F,G(-,H)))" << endl;
	arbore = creareArbore();
	/*if (isHeap(arbore))
	{
		cout << "Arbore heap";
		afisareHeap(arbore);
	}
	else
		cout << "Nu este heap";*/
	if (isCautare(arbore))
	{
		cout << "Arbore de Cautare";
	}
	else
		cout << "Nu este arbore de cautare" << endl;
	cout << "Noduri interne: " << nrnoduri(arbore) << " : ";
	afisareNoduri(arbore);
	cout << "\nFrunze: "; 
	afisareFrunze(arbore);

	cout << "\nLinie: ";
	afisareLinie(arbore);
	cout << "\nInordine: ";
	inordine(arbore);
	cout << "\nPostordine: ";
	postordine(arbore);
	cout << "\nPreordine: ";
	preordine(arbore);
	cout << "\nIntend: " << endl;
	afisareIntend(arbore,1);
	cout << "\nNumar frunze: " << frunze(arbore) << endl;
	cout << "\nNumar noduri: " << nrnoduri(arbore) << endl;
	cout << "\nAdancime: " << adancime(arbore) << endl;
	cout << "\nMaximul: " << Max(arbore) << endl;
	cout << "\nMinimul: " << Min(arbore) << endl;
	comuta(arbore);
	cout << "\nDupa comutare\n";
	afisareIntend(arbore, 1);


	Nod *arbore2 = new Nod;
	arbore2 = creareArbore("12*34+56+*+");//forma postfixata(poloneza)
	cout << "\nIntend: " << endl;
	afisareIntend(arbore2, 1);

	system("pause");
	return 0;
}