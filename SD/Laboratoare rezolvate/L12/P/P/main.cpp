
#include"Header.h"

int main()
{
	int *vv = new int[50];
	int nr,n=0;
	cout << "Valoare: ";
	cin >> nr;
	while (nr)
	{
		insert(vv,nr,n);
		cout << "Valoare: ";
		cin >> nr;
	}
	cout << "Vectorul Heap este:";
	for (int i = 1; i <= n; i++)
		cout << vv[i] << " ";
	cout << endl;

	build_maxheap(vv, n);
	heapsort(vv, n);
	cout << "Vectorul sortat crescator este : ";
	for (int i = 1; i <= n; i++)
		cout << vv[i] << " ";

	system("pause");
	return 0;
}

       