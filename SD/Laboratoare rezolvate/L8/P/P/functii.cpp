#include"Header.h"

Nod* parse(char buffer[], int start, int end);
Nod* parse2(char buffer[], int st, int dr);


Nod* creareArbore() {
	char buffer[DIM_EXPR];

	cin >> buffer;
	int length = strlen(buffer);

	Nod* n = parse(buffer, 0, length - 1);  return n;
}

Nod* parse(char buffer[], int start, int end) {
	int openP = 0;
	int indici[GRMAX];
	int k = 0;

	openP = 0;
	for (int i = start; i <= end; i++)
	{
		if (buffer[i] == '(')
			openP++;
		if (buffer[i] == ')')
			openP--;
		if (buffer[i] == '+')
		{
			if (openP > 0)  continue;
			indici[k++] = i;
		}
	}
	if (k > 0)
	{
		Nod *p = (Nod*) new char[sizeof(Nod)-(GRMAX - k - 1)*sizeof(Nod*)];
		p->grad = k + 1;
		p->data = '+';
		p->vDesc[0] = parse(buffer, start, indici[0] - 1);
		for (int j = 1; j < p->grad - 1; j++)
		{
			p->vDesc[j] = parse(buffer, indici[j - 1] + 1, indici[j] - 1);
		}
		p->vDesc[p->grad - 1] = parse(buffer, indici[p->grad - 2] + 1, end);
		return p;
	}

	openP = 0;
	for (int i = start; i <= end; i++)
	{
		if (buffer[i] == '(')
			openP++;
		if (buffer[i] == ')')
			openP--;
		if (buffer[i] == '*')
		{
			if (openP > 0)  continue;
			indici[k++] = i;
		}
	}
	if (k > 0)
	{
		Nod *p = (Nod*) new char[sizeof(Nod)-(GRMAX - k -  1)*sizeof(Nod*)];
		p->grad = k + 1;
		p->data = '*';
		p->vDesc[0] = parse(buffer, start, indici[0] - 1);
		for (int j = 1; j < p->grad - 1; j++)
		{
			p->vDesc[j] = parse(buffer, indici[j - 1] + 1, indici[j] - 1);
		}
		p->vDesc[p->grad - 1] = parse(buffer, indici[p->grad - 2] + 1, end);
		return p;
	}

	if (buffer[start] == '(' && buffer[end] == ')')
		return parse(buffer, start + 1, end - 1);

	if (start == end)
	if (isdigit(buffer[start]))
	{
		Nod* p = (Nod*) new char[sizeof(Nod)-(GRMAX)*sizeof(Nod*)];
		p->data = buffer[start];
		p->grad = 0;
		return p;
	}

	printf("\nExpresia de intrare este eronata. Apasati o tasta");
	_getch();
	exit(1);
}

void afisare(Nod *p)
{
	if (!p)
	{
		return;
	}
	if (!isdigit(p->data))
	{
		cout << (char)p->data << "(";
	}
	else
	{
		cout << (char)p->data;
		if (!p->grad)
		{
			return;
		}
	}
	for (int i = 0; i < p->grad; i++)
	{
		afisare(p->vDesc[i]);
		cout << ",";
	}
	afisare(p->vDesc[p->grad - 1]);
	cout << ")";
}
void afisare1(Nod *arbore)
{
	if (arbore->grad == 0)
	{
		cout << arbore->data - '0' << " ";
	}
	else
	{
		for (int i = 0; i < arbore->grad; ++i)
		{
			if (i == 0)
				cout << "(";
			afisare1(arbore->vDesc[i]);
			if (i < arbore->grad - 1)
				cout << (char)arbore->data << " ";
			if (i == arbore->grad - 1)
				cout << ")";
		}
	}
}
void afisare2(Nod *arbore)
{
	cout << (char)arbore->data << " ";
	for (int i = 0; i < arbore->grad; ++i)
	{
		if (arbore == 0)
			return;
		afisare2(arbore->vDesc[i]);
	}
}

void afisareOperanzi(Nod *p)
{
	if (p->grad == 0)
		cout << (char)p->data << " ";
	for (int i = 0; i < p->grad; i++)
	{
		if (p == 0)
			return;
		afisareOperanzi(p->vDesc[i]);
	}
}
void afisareOperatori(Nod *p)
{
	if (p->grad)
		cout << (char)p->data << " ";
	for (int i = 0; i < p->grad; i++)
	{
		if (p == 0)
			return;
		afisareOperatori(p->vDesc[i]);
	}
}
int grad = 0;

void afisareGradNod(Nod *p)
{
	cout << (char)p->data << " :" << p->grad << endl;;
	for (int i = 0; i < p->grad; i++)
	{
		if (p == 0)
			return;
		afisareGradNod(p->vDesc[i]);
	}
}
void determinareGrad(Nod *p,int &grad)
{
	if (grad < p->grad)
		grad = p->grad;
	for (int i = 0; i < p->grad; i++)
	{
		if (p == 0)
			return;
		determinareGrad(p->vDesc[i],grad);
	}
}

int inaltime(Nod *p)
{
	int h, hmax = 1;

	if (p == 0)
	{
		return 0;
	}

	for (int i = 0; i < p->grad; i++)
	{
		h = inaltime(p->vDesc[i]) + 1;
		if (h>hmax)
		{
			hmax = h;
		}
	}
	return hmax;
}
int evaluareExpresie(Nod *p)
{
	int rezultat, i;
	if (p)
	{
		if (p->grad == 0)
			rezultat = p->grad - '0';
		else
		{
			if (p->data == '+')
			{
				rezultat = 0;
				for (i = 0; i < p->grad; i++)
					rezultat += evaluareExpresie(p->vDesc[i]);
			}

			if (p->data == '*')

			{
				rezultat = 1;
				for (i = 0; i < p->grad; i++)
					rezultat = rezultat*evaluareExpresie(p->vDesc[i]);
			}
		}
	}
	else
	{
		return 0;
	}
	return rezultat;
}
int MAX(Nod *p)
{
	int h, max = 1;

	if (p == 0)
	{
		return 0;
	}

	for (int i = 0; i < p->grad; i++)
	{
		h = inaltime(p->vDesc[i]) + 1;
		if (h>max)
		{
			max = h;
		}
	}
	return max;
}
void afisareNoduri(Nod *p)
{
	cout << (char)p->data << " ";
	for (int i = 0; i < p->grad; i++)
	{
		if (p == 0)
			return;
		afisareNoduri(p->vDesc[i]);
	}
}