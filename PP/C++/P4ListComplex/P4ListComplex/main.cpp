#include"Header.h"
int main()
{
	complex<int> c1(1, 1);
	complex<int> c2(2, 2);
	complex<int> c3(3, 3);
	complex<int> c4(4, 4);
	complex<int> c5(5, 5);

	list<int> l;
	l.add(c1);
	l.add(c2);
	l.add(c3);
	l.add(c4);
	l.add(c5);
	l.afisare();
	system("pause");
	return 0;
}