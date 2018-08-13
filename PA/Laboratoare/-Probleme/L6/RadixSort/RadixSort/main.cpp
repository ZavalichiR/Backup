#include "Header.h"
#include<time.h>



int main(void)
{
	Nod *Lista = 0;

	int i=10000;
	int n;
	
	while (i)
	{
		i--;
		n = rand()%9999;
		InsereazaLista(Lista, n);
	}

	clock_t timp;
	timp = clock();

	radixSort(Lista, 5);

	timp = clock() - timp;
	cout << "Pentru 10.000 valori" << endl;
	printf("Pasi: %d    Timp: %f", timp, ((float)timp) / CLOCKS_PER_SEC);



	i = 20000;
	Nod *lista2 = 0;
	while (i)
	{
		i--;
		n = rand() % 19999;
		InsereazaLista(lista2, n);
	}

	clock_t timp2;
	timp2 = clock();

	radixSort(lista2, 5);

	timp2 = clock() - timp2;
	cout << "\n\n\nPentru 20.000 valori" << endl;
	printf("Pasi: %d    Timp: %f", timp2, ((float)timp2) / CLOCKS_PER_SEC);


	int ok;
	cout << " \n\nAfisati? " << endl;
	cout << "1-----DA" << endl;
	cin >> ok;
	if (ok == 1)
	{
		cout << "\nAfisare lista: ";
		afisareLista(Lista);
	}
	
	cout << endl;
	system("pause");
	return 0;
}