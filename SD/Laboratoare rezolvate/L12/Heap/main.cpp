#include"Header.h"
int main()
{
	int *v = new int[50];
	int val, n = 0;
	cout << "Introduceti valorile " << endl;;
	cout << "Valoare: ";
	cin >> val;
	while (val)
	{
		insert(v, val, n);
		cout << "Valoare: ";
		cin >> val;
	}
	cout << "Vectorul: ";
	for (int i = 1; i <= n; ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "Nod sters" << sterge(v, n) << endl;
	for (int i = 1; i <= n; ++i)
		cout << v[i] << " ";
	cout << endl;

	//Generare HEAP-metoda 1
	creareMaxHeap(v, n);
	sortareHeap(v, n);
	cout << "vectorul sortat crescator este : ";
	for (int i = 1; i <= n; i++)
		cout << v[i] << " ";


	system("pause");
	return 0;
}