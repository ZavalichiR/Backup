#include"Header.h"
void main()
{
	
	int n;
	cout << "numarul de elemente: ";
	cin >> n;
	Multime <int>m(n);
	m.citire();
	m.afisare();
	Multime <int>m2(m);
	m.sortare();
	cout << "\nvectorul sortat: ";
	m.afisare();
	cout << "\ndupa copiere:";
	m2.afisare();
	cout << "\nelementul maxim: " << m2.operator!() << endl;
	Multime <int>rez(m + m2);//rez=m+m2
	cout << "\nsuma: ";
	rez.afisare();
	cout << "\nadunare: ";
	int r = Aduna(2, 3);
	cout << r;
	Multime<int> *p = 0;
	p = new Multime<int>(m);
	cout << "\nElementul: ";
	cout<<p->operator[](2);//sau cout<<(*p)[2];
	system("pause");
}