#include"Header.h"
int main()
{
	complex c1(2, 3);
	complex c2(4, 5);
	complex c3 = c2;
	cout << "C3=C2" << endl;
	c3.afisare();
	complex c4 = c2 + c1, c5 = c2 - c1;
	cout << "C2+C1" << endl;
	c4.afisare();
	cout << "C2-C1" << endl;
	c5.afisare();
	complex c6 = c1*c2;
	cout << "C1*C2" << endl;
	c6.afisare();
	
	complex a;
	cin >> a;
	cout << a;
	a++;
	cout <<"a++: "<< a;
	++a;
	cout <<"++a: "<< a;
	a--;
	cout <<"a--: "<< a;
	--a;
	cout <<"--a: "<< a;


	
	return 0;
}