#include "Header.h"
#include <queue>

void setColor(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void initDigraf(Digraf &D, int n)
{
	D.a = new int[n + 1];
	D.l = new Elem*[n + 1];
	for (int i = 1; i <= n; ++i) {
		D.a[i] = 0;// predecesori
		D.l[i] = nullptr; // element
	}
}

void insert(Elem *&cap, int val)
{
	Elem* p = new Elem;
	p->data = val;
	p->succ = cap;
	cap = p;
}

void citireDigraf(Digraf &D, int nr)
{
	int nrM;
	int i, val;
	for (i = 1; i <= nr; i++)
	{
		setColor(7);
		cout << "\n\tNumarul de muchii ale varfului";
		setColor(9);
		cout << "("<<i<<")";
		setColor(7);
		cout<<": ";
		cin >> nrM;
		// veriricare daca nmR este valid
		while (nrM > (nr - 1))
		{
			cout << "\tTrebuie indeplinita conditia:";
			setColor(12); 
			cout<<"(nrM < " << nr - 1<<")" << endl;
			setColor(7);
			cout << "\tNrm: ";
			cin >> nrM;
		}
		if (nrM)
			cout << "\t\tMuchiile: \n";
		for (int j = 1; j <= nrM; ++j)
		{
			cout << "\t\t\t Muchia ";
			setColor(10); 
			cout<< i << "-";
			cin >> val;
			setColor(7);
			// Verificare daca varful este valid
			if (val >= nr + 1)
			{
				setColor(12);
				cout << "\t\t\t !!!! Nu exista varful: " << val<<"!!!!\n";
				setColor(7);
				j--; //o ia de la capat
				continue;
			}
			insert(D.l[i], val);
			D.a[val]++;
		}
	}
}

int* sortareTopologicaBFS(Digraf D, int nrNoduri)
{
	queue<int> c; 
	int u, v;
	Elem *p;
	int *L = new int[nrNoduri];
	for (u = 1; u <= nrNoduri; u++) {
		if (D.a[u] == 0) {
			c.push(u);
		}
	}
	for (int k = 1; k <= nrNoduri; ++k) {
		if (c.empty()) {
			setColor(12);
			cout << "\nExista arce incidente spre interior!!" << endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
		u = c.front();
		c.pop();
		L[k] = u;
		p = D.l[u];
		while (p) {
			v = p->data;
			D.a[v]--;
			if (D.a[v] == 0) {
				c.push(v);
			}
			p = p->succ;
		}
	}
	return L;
}