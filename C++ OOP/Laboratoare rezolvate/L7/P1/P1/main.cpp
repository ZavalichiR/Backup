#include"Header.h"
int main()
{

	int m, n;
	system("cls");
	cout << "Numar linii: ";
	cin >> m;
	cout << "Numar coloane: ";
	cin >> n;
	Matrice a(m,n);
	cout << "Citire matrice a" << endl;
	a.citire();
	cout << "Matricea a ";
	a.afisare();

	Matrice b(m,n);
	cout << "Citire matrice a" << endl;
	b.citire();
	cout << "Matricea b ";
	b.afisare();

	Matrice d = a*b;
	cout << "Produs" << endl;
	d.afisare();

	Matrice e = a;
	cout << "Egalitate" << endl;
	e.afisare();

	Matrice f = a + b;
	cout << "Adunare" << endl;
	f.afisare();

	Matrice g = a - b;
	cout << "Scadere" << endl;
	g.afisare();

	cout << "compara" << endl;
	int i = b.operator==(a);
	cout <<"Rezultat:"<< i << endl;

	Matrice j=~a;
	cout << "a transpus" << endl;
	j.afisare();

	Matrice k=b;
 	int x = k[5];
	cout << "Elementul dat de <2>" << x << endl;

	Matrice l = a + 2;
	cout << "\na+2: " << endl;
	l.afisare();

	Matrice l2 = 2 + a;
	cout << "\n2+a: " << endl;
	l2.afisare();

	Matrice z=++a;
	cout << "++a" << endl;
	z.afisare();

	Matrice z2 = a++;
	cout << "a++" << endl;
	z2.afisare();



	system("pause");
	return 0;
}