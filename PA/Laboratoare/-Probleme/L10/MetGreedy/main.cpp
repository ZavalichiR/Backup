#include"Header.h"

int main()
{
	vector<int> v;
	int i;
	int n;
	int sum;
	cout << "Dimensiune vector: " << endl << "n=";
	cin >> n;
	cout << endl;
	cout << "Citire vector: " << endl;;

	for (i = 0; i < n; i++)
	{
		int aux;
		cout << "v[" << i << "]=";
		cin >> aux;
		v.push_back(aux);
	}

	cout << "Afisare: ";
	afisare(v);
	sortHeap(v);
	cout << "Vectorul sortat: ";
	afisare(v);
	cout << endl << endl << endl;
	sum = greedy(v);
	cout << endl << "Suma=" << sum << endl;
	system("pause");
	return 0;
}