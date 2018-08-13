#include"Header.h"



int main(void)
{
	cout << "-----Problema exemplu------\n"<<endl;

	Patrat p;
	p.SetLatura(10);
	cout << "Aria patratului: " << p.Aria() << endl;
	cout << "Perimetrul patratului: " << p.Perimetru() << endl;

	Dreptunghi d; //se apeleaza destructorul: lungime=0,latime=0
	Dreptunghi d1; // la fel
	Dreptunghi d2(8, 3); // se apeleaza destructorul lungime=lung, latime=lat
	Dreptunghi d4 = d; // se apeleaza destructorul copiator

	d.SetLungime(4);
	d.SetLatime(2);
	cout << d.Aria();
	cout << d.Perimetru();

	cout << "\n\n-----Problema 1-----\n\n" << endl;
	
	Multime m;
	int n;
	cout << "N= ";
	cin >> n;
	while (n)
	{
		m.Adauga(n);
		n--;
	}
	m.Afisare();
	m.Extrage(3);


	cout << "\n\n-----Problema 2-----\n\n" << endl;

	Stiva s;
	s.push(4);
	s.push(3);
	cout <<"Varful stivei:"<< s.top() << endl;
	s.push(9);
	cout << "Varful stivei:"<< s.pop() << endl;
	s.push(2);
	s.print();


	return 0;
}