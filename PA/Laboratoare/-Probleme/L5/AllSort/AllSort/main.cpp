#include"Header.h"
#include <time.h> 
int main()
{

	int a[50000];
	int b[50000];
	int c[50000];
	//int d[50000];
	
	int n;
	int rel = 1;
	while (rel)
	{
		cout << "\nNumarul de valori (n<=50 000): ";
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int temp = rand();
			a[i] = temp;
			b[i] = temp;
			c[i] = temp;
			//d[i] = temp;
		}


		cout << "\nPentru  " << n << " valori" << endl;;
		clock_t bbst;
		bbst = clock();
		BbSort(a, n);
		bbst = clock() - bbst;
		printf("BbSort:         %d pasi (%f secunde).\n", bbst, ((float)bbst) / CLOCKS_PER_SEC);
		/////////////////////////////////////////////////////////////////


		clock_t ist;
		ist = clock();
		insertionSort(b, n);
		ist = clock() - ist;
		printf("Insertion Sort:  %d pasi (%f secunde).\n", ist, ((float)ist) / CLOCKS_PER_SEC);
		/////////////////////////////////////////////////////////////////

		clock_t nst;
		nst = clock();
		naivSort(c, n);
		nst = clock() - nst;
		printf("Naiv Sort:       %d pasi (%f secunde).\n", nst, ((float)nst) / CLOCKS_PER_SEC);
		/////////////////////////////////////////////////////////////////

		cout << "Reluati pentru al numar de valori? ";
		cout << "\n1----Da";
		cout << "\n0----NU\n :r: ";
		cin >> rel;
	}
	
		

	/*cout << " Vectorul : \n" << endl;
	for (int i = 0; i < n; ++i)
		cout << a[i] << "  ";
	cout << endl;
	for (int i = 0; i < n; ++i)
		cout << b[i] << "  ";
	cout << endl;
	for (int i = 0; i < n; ++i)
		cout << c[i] << "  ";*/




	


	/*cout << "\n\n\n Vectorul sortat: \n" << endl;
	for (int i = 0; i < n; ++i)
		cout << a[i] << "  ";
	cout << endl;
	for (int i = 0; i < n; ++i)
		cout << b[i] << "  ";
	cout << endl;
	for (int i = 0; i < n; ++i)
		cout << c[i] << "  ";*/

	system("pause");
	return 0;
}