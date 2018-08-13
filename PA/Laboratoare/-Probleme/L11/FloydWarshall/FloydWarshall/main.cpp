#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include "Header.h"

using namespace std;

int **L, **P;

int main(void)
{

	int nrVarfuri, nrArce;
	cout << "\n Introduceti numarul de varfuri: ";
	cin >> nrVarfuri;
	cout << "\nIntroduceti numarul de arce: ";
	cin >> nrArce;

	L=aloca2D(nrVarfuri);
	P=aloca2D(nrVarfuri);

	int i, j;
	init_L(L);




	cout<<"Matricea L initiala:"<<endl;
	for (i=0; i<nrVarfuri; ++i)
	{
		for (j=0; j<nrVarfuri; ++j)
		{
			if (L[i][j] == plusInf)
			{
				cout << setw(5) << "-" << " ";
				continue;
			}
			cout<<setw(5)<<L[i][j]<<" ";
		}
		cout<<endl;
	}

	FloydWarshall(L, P, nrVarfuri);

	cout<<endl<<"Matricea L dupa algoritmul Floyd-Warshall:"<<endl;
	for (i=0; i<nrVarfuri; ++i)
	{
		for (j=0; j<nrVarfuri; ++j)
		{
			cout<<setw(5)<<L[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<endl<<"Matricea P a predecesorilor:"<<endl;
	for (i=0; i<nrVarfuri; ++i)
	{
		for (j=0; j<nrVarfuri; ++j)
		{
			cout<<setw(5)<<P[i][j]<<" ";
		}
		cout<<endl;
	}

	cout << endl << "Drumurile posibile sunt: " << endl;
	for (i = 0; i<nrVarfuri; ++i)
	{
		for (j = 0; j<nrVarfuri; ++j)
		{
			if (L[i][j] != plusInf && L[i][j] != 0) //daca exista drum
			{
				
				cout << "Cost= " << L[i][j]<<" " ;
				cout << "\t Drum: (" << i << " - " << j << ") : " << i << " ";
				afisareDrumuri(L, P, nrVarfuri, i, j);
				cout << endl;
				
			}
		}
	}

	dealoca2D(L, nrVarfuri);
	dealoca2D(P, nrVarfuri);
	system("pause");
//	f_in.close();
	return 0;
}
