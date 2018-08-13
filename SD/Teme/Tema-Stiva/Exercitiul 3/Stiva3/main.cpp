#include"Header.h"
using namespace std;

int main()
{
	char *sir=0;
	Stiva S;
	cout << "Dati sirul de caractere: ";
	sir = new char[10];
	cin.getline(sir, 10);

	if (verificare(sir)==1)
		cout << "Sirul este palindrom\n";
	else
		cout << "Sirul nu este palindrom\n";


	return 0;
}