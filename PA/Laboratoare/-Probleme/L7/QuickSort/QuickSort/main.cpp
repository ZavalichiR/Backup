#include"Header.h"
#include<time.h>

int main()
{
	int rel=1;
	while (rel)
	{
		int n;
		int v1[80000];
		int v2[80000];
		int v3[80000];
		int temp;
		cout << " Numarul de elemente: ";
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			temp = rand()%1000;
			v1[i] = temp;
			v2[i] = temp;
			v3[i] = temp;
		}

		clock_t q1;
		q1 = clock();

		QuickSort1(v1, 0, n - 1);

		q1 = clock() - q1;
		printf("\nPentru QuickSort1:  Pasi: %d    Timp: %f", q1, ((float)q1) / CLOCKS_PER_SEC);


		clock_t q2;
		q2 = clock();

		QuickSort2(v2, 0, n - 1);

		q2 = clock() - q2;
		printf("\nPentru QuickSort1:  Pasi: %d    Timp: %f", q2, ((float)q2) / CLOCKS_PER_SEC);

		clock_t q3;
		q3 = clock();

		qsort(v3, n, sizeof(int), compare);

		q3 = clock() - q3;
		printf("\nPentru QuickSort STL:  Pasi: %d    Timp: %f\n", q3, ((float)q3) / CLOCKS_PER_SEC);


		/*cout << "\n\nVectorul:" << endl;
		for (int j = 0; j < n; j++)
		{
		cout << v1[j] << " ";
		}
		cout << "\n\nVectorul:" << endl;
		for (int j = 0; j < n; j++)
		{
		cout << v2[j] << " ";
		}

		cout << "\n\nVectorul:" << endl;
		for (int j = 0; j < n; j++)
		{
		cout << v3[j] << " ";
		}*/
		
		cout << "Press 0 for close: ";
		cin >> rel;
		
	}
	system("pause");
	return 0;
}