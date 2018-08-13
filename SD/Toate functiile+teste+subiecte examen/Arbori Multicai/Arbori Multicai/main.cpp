#include"Header.h"
int main()
{
	cout << "\nExemplu de arbore: 2+3+(2*4+3). (- / nu functioneaza\n";
	Nod*arbore = 0;
	arbore=creareArbore();
	afisare(arbore);
	cout << endl;
	afisare2(arbore);
	cout << "\nRezultat: " << evaluare(arbore) << endl;
	cout << "\nOperatori: ";
	afisareOperatori(arbore);
	cout << "\nOperanzi: ";
	afisareOperanzi(arbore);
	cout << "\nGradul\n";
	afisareGrad(arbore);

	int grad = 1;
	determinareGrad(arbore, grad);
	cout << "\nGradul arborelui: " << grad << endl;

	cout << "\nInaltime: " << inaltime(arbore) << endl;




	system("pause");
	return 0;
}