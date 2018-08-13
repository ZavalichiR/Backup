#include"Header.h"
int main()
{
	Nod *arbore = nullptr;
	cout << "\nIntroduceti in arbore(val !=0)\n";
	int val;
	cout << "Valoare: ";
	cin >> val;
	while (val)
	{
		inserare(arbore, val);
		cout << "Valoare: ";
		cin >> val;
	}

	cout << "Reprezentare implicita: ";
	reprezentareImplicita(arbore);
	afisareNod(arbore, 3);
	if (isEchilibrat(arbore))
		cout << "\nEchilibrat" << endl;
	else
		cout << "Dezechilibra" << endl;
	cout << "Pe nivelul 4 sunt: " << nrNoduriNivel(arbore, 4) << " noduri: ";
	afisareNodNivel(arbore, 4);
	cout << "\nLinie: ";
	peLinie(arbore);
	cout << "\nInordine: ";
	inordine(arbore);
	cout << "\nPostordine: ";
	postordine(arbore);
	cout << "\nPreordine: ";
	preordine(arbore);
	cout << "\nIntend: " << endl;
	intend(arbore, 1);
	cout << "\nCauta elementul: ";
	int elm;
	cin >> elm;
	Nod *p = cauta(arbore, elm);
	if (p)
		cout << "Elementul cautat: " << p->data << endl;
	else
		cout << "Elementul nu a fost gasit" << endl;
	cout << "\nNumar frunze: " << nrFrunze(arbore) << endl;
	cout << "\nNumar noduri: " << nrNoduri(arbore) << endl;
	cout << "\nAdancime: " << adancime(arbore) << endl;
	cout << "\nMaximul: " << max(arbore) << endl;
	cout << "\nMinimul: " << min(arbore) << endl;
	cout << "\nPrecizati nodul: ";
	int n;
	cin >> n;
	Nod *q = new Nod;
	q->data = n;
	if (tata(arbore, q))
		cout << "Tatal nodului: " << q->data << " este: " << tata(arbore, q)->data << endl;
	comuta(arbore);
	cout << "\nDupa comutare\n";
	intend(arbore, 1);



	Nod2 *arbore2 = new Nod2;
	arbore2 = creareArbore("12*34+56+*+");//forma postfixata(poloneza)
	cout << "\nIntend: " << endl;
	afisareIntend(arbore2, 1);

	system("pause");
	return 0;

}