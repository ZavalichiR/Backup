#include"Header.h"
int main(void)
{
	Stiva S;
	char sir[dim];

	cout << "\nSirul de caractere: ";
	cin.getline(sir, dim);
	if (Verificare(sir) == 0)
		{
			cout << "\nInchiderea parantezelor nu este corecta" << endl;
		}
	else
		{
			cout << "\nInchiderea parantezelor este corecta" << endl;
		}

	 


	return 0;
}