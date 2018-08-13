#include"Dreptunghi.h"
#include"Triunghi.h"
#include"Cerc.h"
#include"Patrat.h"
int main()
{
	cout << "\n\n---------Primul program-------------" << endl;
	Figura **fig = new Figura*[4];
	fig[0] = new Cerc();
	fig[1] = new Cerc(4, 5, 6, "verde","cerc2");
	fig[2] = new Patrat();
	fig[3] = new Patrat(3, 3, 6, "violet","patrat2");
	for (int i = 0; i < 4; ++i)
	{
		fig[i]->afisare();
	}
	double mx = 0;
	int index;
	for (int i = 0; i < 4; ++i)
	{
		if (mx < fig[i]->Arie())
		{
			mx = fig[i]->Arie(); 
			index = i;
		}
		
	}
	cout << endl;
	cout << "Aria maxima este: " << mx << endl;
	cout << "Figura: " << fig[index]->GetNume() << " are aria maxima de: " << mx << endl;
	system("pause");

	cout << "\n\n---------Primul program-------------" << endl;
	//Max semiperimetru
	//sortare Arie
	//dinamic cast pe semiperimetru


	Figura2 **tab = new Figura2*[4];
	tab[0] = new Dreptunghi(1, 2, 4, 5);
	tab[1] = new Dreptunghi(1, 2, 6, 8);
	tab[2] = new Triunghi(1, 1, 2, 2, 1, 3);
	tab[3] = new Triunghi(2, 2, 3, 3, 2, 8);
	for (int i = 0; i < 4; ++i)
	{
		tab[i]->afisare();
		cout << "Arie=" << tab[i]->Aria() << endl;
		cout << "Perimetru=" << tab[i]->Perimetru() << endl;
	}
	for (int i = 0; i < 3; ++i)
	for (int j = i; j < 4; ++j)
	if (tab[i]->Aria() > tab[j]->Aria())
		swap(tab[i], tab[j]);
	for (int i = 0; i < 4; ++i)
	{
		cout << endl;
		tab[i]->afisare();
	}
	for (int i = 0; i < 4; ++i)
	{
		Triunghi *p = dynamic_cast<Triunghi*>(tab[i]);
		if (p != 0)
		{
			cout << p->SemiPerimetru() << endl;
		}
	}
	system("pause");
	return 0;

}