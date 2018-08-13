#include"Header.h"

int main(void)
{

	/*
	int tab[10];
	int *p = &tab[10];
	tab[2] = 3;
	p[2] = 4;
	
	cout << p<<endl;
	cout << tab<<endl;
	*/
	Student s1,s2;
	int n;
	int v[10];
	

	int x1, x2;
	int x3, x4;

	/*cout << "\nCel mai mare divizor comun dintre P si Q" << endl;
	cout << "p= ";
	cin >> x1;
	cout << "q= ";
	cin >> x2;
	cout << "Cmmdc= " << cmmdc(x1, x2);
	*/

	cout << "Putere lui x" << endl;
	cout << "X=";
	cin >> x3;
	cout << "puterea: ";
	cin >> x4;
	cout << "" << x3 << " la puterea " << x4<<" :" << putere(x3, x4) << endl;




	s1.nota = 10;
	s1.nume = "Radu";

	cout << s1.nume << " -- " << s1.nota << endl;
	cout << "\nCitire structura" << endl;
	s2.citire();
	cout << "Afisare structura" << endl;
	s2.afisare();

	
	cout << "\n(Citire Vector) Numarul de element: ";
	cin >> n;
	CitireVect(v, n);
	
	cout << "Afisare vector" << endl;
	AfisareVect(v, n);
	cout << "Sortare vector" << endl;
	BSort(v, n);
	AfisareVect(v, n);

	cout << "Factorialul pentru numarul: ";
	cin >> n;
	cout << "(1)este: " << factorial(n) << endl;
		
	cout << "(2)este: " << factorial2(n) << endl;
	
	/*cout << "\nCel mai mare divizor comun dintre P si Q" << endl;
	cout << "p= ";
	cin >> x1;
	cout << "q= ";
	cin >> x2;
	cout << "Cmmdc= " << cmmdc(x1, x2);
	*/
	
	
	_getch();
	return 0;
}