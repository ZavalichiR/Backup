#include"revista.h"

int tiraj(publicatie **tab)
{
	int t = 0;
	for (int i = 0; i < 6; i++)
	{

		revista *r = dynamic_cast<revista *>(tab[i]);
		if (r)
		{
			t += r->gett();

		}
		delete r;
	}
	return t;
}
void sort(publicatie**tab)
{
	int ok = 1;
	while (ok)
	{
		ok = 0;
		for (int i = 0; i < 5; i++)
		{
			if (tab[i]->getpag() > tab[i + 1]->getpag())
				swap(tab[i], tab[i + 1]);
		}
	}
}
int main()
{
	revista r("Time", 1234, "News", 1231);
	cout << r.operator+() << endl;
	publicatie** tab = new publicatie*[6];

	tab[0] = new publicatie("scoala", 112);
	tab[1] = new publicatie("facultate", 11213);
	tab[2] = new publicatie("medicina", 1121);
	tab[3] = new revista("accident", 23, "masina", 12345);
	tab[4] = new revista("Cancan", 23, "accident", 12345);
	tab[5] = new revista("Romania", 23, "presedinte", 12345);
	sort(tab);
	for (int i = 0; i < 6; i++)
	{
		tab[i]->afisare();
	}
	int t = tiraj(tab);
	cout << "tirajul total:" << t << endl;
	system("pause");
	return 0;

}