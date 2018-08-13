#include"Header.h"
int main()
{
	Nod* arbore = new Nod;
	cout << "Creare arbore:" << endl;
	arbore = creareArbore();
	cout << "\nAfisare: ";
	afisare(arbore);
	cout << "\nAfisare1: ";
	afisare1(arbore);
	cout << "\nAfisare2 :";
	afisare2(arbore);
	cout << "\nOperanzi: ";
	afisareOperanzi(arbore);
	cout << "\nOperatori: ";
	afisareOperatori(arbore);
	cout << "\n Grad noduri: ";
	afisareGradNod(arbore);

	int g=0;
	determinareGrad(arbore,g);
	cout << "\n Grad: "<<g;
	int i;
	i = inaltime(arbore);
	cout << "\n Inaltime " << i;



	return 0;
}