#include"Header.h"
int main()
{
	//int n;
	coada *C;
	//int r;
	//cout << "\nNumarul de elemente: ";
	//cin >> n;
	initC(C);
	char sir[20];
	cout << "\nSirul de caractere: ";
	cin.getline(sir,19);

	if (palindrom(sir))
	{
		cout << "\nSirul este palindrom" << endl;
	}
	else
	{
		cout << "Sirul nu este palindrom" << endl;
	}
	/*
	while (n)
	{
		put(C, n);
		n--;
	}
	do{
		r = get(C, f);
		cout << r << endl;
	} while (f);
	*/

	return 0;
}