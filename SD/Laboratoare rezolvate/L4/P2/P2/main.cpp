#include"Header.h"
int main()
{
	int n, i;
	Nod *head = 0;
	cout << "Numarul de elemente: ";
	cin >> n;
	cout << "\nPozitia:";
	cin >> i;
	while (n)
	{
		creare(head, n, i);
		n--;
	}
	afisare(head);
	return 0;
}