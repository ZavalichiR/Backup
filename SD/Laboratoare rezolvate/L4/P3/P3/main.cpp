#include"Header.h"
int main(void)
{
int n,m;
Nod *head1 = 0;
Nod *head2 = 0;
//Nod *head3 = 0;
int element;
int i = 1;
cout << "Numarul de elemente pentru prima lista: ";
cin >> n;
while (n)
{

	cout << "Elementul " << i << " :";
	i++;
	cin >> element;
	creare(head1, element);
	n = n - 1;
}


cout << "Numarul de elemente pentru a doua lista: ";
cin >> m;
i = 1;
while (m)
{

	cout << "Elementul " << i << " :";
	i++;
	cin >> element;
	creare(head2, element);
	m = m - 1;
}

cout << "\nLista 1: ";
afisare(head1);
cout << endl;
cout << "\n Lista are: " << count(head1) << " Elemente" << endl;



cout << "\nLista 2: ";
afisare(head2);
cout << endl;
cout << "\n Lista are: " << count(head2) << " Elemente" << endl;

/*cout << "\nListele unite: ";
unire(head1, head2);
afisare(head1);
*/
intercalare(head1, head2);
cout << "\nListele intercalate: " << endl;
afisare(head1);
_getch();
	return 0;
}