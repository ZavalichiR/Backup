#include"Header.h"
int main()
{
	int n, M;
	int w[50], x[50];
	for (int i = 0; i < 50; ++i)
	{
		x[i] = 0;
	}
	cout << "Dimensiunea vectorului: ";
	cin >> n;

	cout << "Citire vector: \n";
	citire(w, n);

	cout << "Valoarea maxima M= ";
	cin >> M;

	
	int sum = suma(w, n);
	cout << "Suma elementelor vectorului: " << sum << endl;
	cout << "\nw=(";
	afisare(w, n);
	cout<< ")";
	submultimiOptim(0, 1, sum, w, x, M);

	cout << endl;
	system("pause");
	return 0;

}