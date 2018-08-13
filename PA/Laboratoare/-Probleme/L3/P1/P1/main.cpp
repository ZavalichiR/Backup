#include"Header.h"
int main()
{

	int a[5000];
	int b[5000];
	for (int i = 0; i < 5000; ++i)
	{
		a[i] = rand();
		b[i] = a[i];

	}
	
	int ok = 1;
	while (ok)
	{
		ok = 0;
		for (int i = 0; i < 5000-1; ++i)
		{
			if (a[i]>a[i + 1])
			{
				swap(a[i], a[i + 1]);
				ok = 1;
			}		
		}
	}
	//cout << "\n\n\n" << endl;
	//for (int i = 0; i < 5000; ++i)
	//{
	//cout << a[i] << " ";
	//}
	///**/
	cout << "\n\n\n" << endl;
	Nod *arbore = nullptr;
	for (int i = 0; i < 5000; ++i)
		inserare(arbore, b[i]);
	

	int rel = 1;
	double contor1= 0;
	double contor2 = 0;
	while (rel)
	{
		int nr;
		cout << "\n\nNumarul cautat: ";
		cin >> nr;
		int r = cautareBinara(a, 5000, nr, contor1);
		Nod *r2 = cautArboreBinar(arbore, nr, contor2);

		cout << "\n--------------------Pentru vetor--------------------\n";
		if (r == -1)
			cout << "Elementul nu a fost gasit---------S-au efectuat " << contor1 << " operatii" << endl;
		else
			cout << "Elementul a fost gasit ---------S-au efectuat " << contor1 << " operatii" << endl;
		
		system("pause");


		cout << "\n--------------------Pentru arbore--------------------\n";
		if (!r2)
			cout << "Elementul nu a fost gasit---------S-au efectuat " << contor2 << " operatii" << endl;
		else
			cout << "Elementul a fost gasit ---------S-au efectuat " << contor2 << " operatii" << endl;
		
		cout << "\n\nReluati programul? \n1-----DA \n0-----NU\n";
		cin >> rel;
		
		
	}
	system("pause");
	
	return 0;

}