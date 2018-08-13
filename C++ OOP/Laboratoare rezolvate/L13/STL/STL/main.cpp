#include<iostream>
#include<vector>
#include<time.h>
#include<algorithm>
#include"Header.h"
using namespace std;
int main()
{
	masina **vMasina = new masina*[5];
	vMasina[0] = new masina("Acura", "Alb", 40000, 250);
	vMasina[1] = new masina("Audi", "Negru", 15000, 220);
	vMasina[2] = new masina("Ford", "Alb",9000, 200);
	vMasina[3] = new masina("volkswagen", "Albastru", 17000, 180);
	vMasina[4] = new masina("Logan", "Rosu",3000 , 120);
	

	vector<masina*> vector(vMasina, vMasina + 5);
	time_t begin = clock();
	std::make_heap(vector.begin(), vector.end());
	std::sort_heap(vector.begin(), vector.end());
	time_t end = clock();
	for (int i = 0; i < (int)vector.size(); i++)
	{
		vMasina[i]->afisare();
		cout << endl;
	}
	system("pause");

	return 0;
}