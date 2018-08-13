#include"Header.h"
int main()
{
	int *arbore = new int[50];
	int val2, i = 0;
	cout << "Introduceti valorile " << endl;;
	cout << "Valoare: ";
	cin >> val2;
	while (val2)
	{
		arbore[++i] = val2;
		cin >> val2;
	}
	for (int j = 1; j <= i; ++j)
	cout << arbore[j] << " ";

	cout << "\npostordine:";
	postordine(arbore,3, i);
	cout << "\nInordine: ";
	inordine(arbore, 1, i);
	if (isCauare(arbore, 1, i))
		cout << "Este BST" << endl;
	else
		cout << "nu este BST" << endl;



	int *v = new int[50];
	int val, n = 0;
	cout << "Introduceti valorile " << endl;;
	cout << "Valoare: ";
	cin >> val;
	while (val)
	{
		insert(v, val, n);
		//cout << "Valoare: ";
		cin >> val;
	}
	cout<<"Vectorul: ";
	for (int i = 1; i <= n; ++i)
		cout << v[i] << " ";
	if (isHeap(v, 1, n))
		cout << "Este Heap" << endl;
	cout << endl;
	creareMaxHeap2(v, n);

	//cout << "\npostordine:";
	//postordine(v, 1, n);
	//cout << "\nPreordine: ";
	//inordine(v, 1, n);
	//cout << "Vector:";
	//for (int i = 1; i <= n; ++i)
	//	cout << v[i] << " ";
	//cout << endl;

	//cout << "\nNod sters" << sterge(v, n) << endl;
	//for (int i = 1; i <= n; ++i)
	//	cout << v[i] << " ";
	//cout << endl;

	////Generare HEAP-metoda 1
	//creareMaxHeap(v, n);
	//inordine(v, 1, n);
	sortareHeap(v, n);
	/*cout << "vectorul sortat crescator este : ";
	for (int i = 1; i <= n; i++)
		cout << v[i] << " ";*/
	cout << "\nvectorul sortat descrescator este : ";
	while (n)
	{
		cout << v[n] << " ";
		n--;
	}



	system("pause");
	return 0;
}


