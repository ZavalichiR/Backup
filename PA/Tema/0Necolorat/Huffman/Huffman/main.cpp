#include "Header.h"


int main()
{

	char s[50];
	cout << "Introduceti sirul: ";
	cin.getline(s, 50);

	cout << "Sirul citit: "<< s << endl;

	int n = 0, j;
	Nod *v[27];
	Nod *p, *q;

	for (int i = 0; i < (int)strlen(s); i++)
	{
		for (j = 1; j <= n; j++)
		if (v[j]->data != s[i])
			continue;
		else
			break;

		if (j <= n)
			v[j]->frecventa++;
		else
		{
			n++;
			v[n] = new Nod;
			v[n]->data = s[i];
			v[n]->frecventa = 1;
			v[n]->drt = v[n]->stg = 0;
		}
	}
	j = n;
	heap_min(v, n);   // cream heap-ul cu nodurile create anterior

	while (j > 1)
	{
		p = remove(v, j);
		q = remove(v, j);
		Nod *w = new Nod;
		w->frecventa = p->frecventa + q->frecventa;     // procedura de interclasare optimala
		w->data = 'z' + 2;
		w->stg = p;
		w->drt = q;
		insert(v, j, w);
	}

	int V[27];
	cout << "\t\t\t\t    Codificare" << endl;
	cout << "\t\t----------------------------------------------------------";
	Huffman(v[1], V, 0);   // apelul functiei de codificare
	int iter = 0;
	cout << "\n\t\t----------------------------------------------------------" << endl;

	cout << endl;
	cout << "\nCodificare sir \" "<< s<< " \": ";
	afisare(s, v[1], iter, v[1]);

	cout << "\n\n\n\n";
	system("pause");
	return 0;
}



