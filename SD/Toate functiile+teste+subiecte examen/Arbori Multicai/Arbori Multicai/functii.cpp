#include"Header.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
Nod* parse(char buffer[], int start, int end);
Nod* creareArbore()
{
	char buffer[DIM_EXPR];
	cin >> buffer;
	int length = strlen(buffer);
	Nod* n = parse(buffer, 0, length - 1);
	return n;
}
Nod* parse(char buffer[], int start, int end)
{
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
			if (openP > 0)
				continue;
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
			if (openP > 0)
				continue;
			indici[k++] = i;
		}
	}
	if (k > 0)
	{
		Nod *p = (Nod*) new char[sizeof(Nod)-(GRMAX - k + 1)*sizeof(Nod*)];
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
	system("pause");
	exit(1);
}

void afisare(Nod *arbore)
{
	if (arbore->grad == 0)
		cout << (char)arbore->data << "-";
	else
	{
		cout << (char)arbore->data;
		for (int i = 0; i < arbore->grad; ++i)
			afisare(arbore->vDesc[i]);
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
int evaluare(Nod *arbore)
{
	int i, rez;
	if (arbore->grad == 0)
		rez = arbore->data - '0';
	else
	{
		if (arbore->data == '*')
		{
			rez = 1;
			for (i = 0; i < arbore->grad; ++i)
				rez *= evaluare(arbore->vDesc[i]);
		}
		if (arbore->data == '+')
		{
			rez = 0;
			for (i = 0; i < arbore->grad; ++i)
				rez += evaluare(arbore->vDesc[i]);
		}
	}
	return rez;
}
void afisareOperatori(Nod *arbore)//+ *
{
	if (arbore->grad != 0)
		cout << (char)arbore->data << " ";
	for (int i = 0; i < arbore->grad; ++i)
	{
		if (arbore == 0)
			return;
		afisareOperatori(arbore->vDesc[i]);
	}
}
void afisareOperanzi(Nod *arbore)
{
	if (arbore->grad == 0)
		cout << (char)arbore->data << " ";
	for (int i = 0; i < arbore->grad; ++i)
	{
		if (arbore == 0)
			return;
		afisareOperanzi(arbore->vDesc[i]);
	}
}
void afisareGrad(Nod *arbore)
{
	cout << (char)arbore->data << ": " << arbore->grad << endl;
	for (int i = 0; i < arbore->grad; ++i)
	{
		if (arbore== 0)
			return;
		afisareGrad(arbore->vDesc[i]);
	}

}
void determinareGrad(Nod *arbore, int &grad)
{
	if (grad < arbore->grad)
		grad = arbore->grad;
	for (int i = 0; i < arbore->grad; ++i)
	{
		if (arbore == 0)
			return;
		determinareGrad(arbore->vDesc[i], grad);
	}
}
int inaltime(Nod *arbore)
{
	int h, hmax = 1;
	if (arbore == 0)
		return 0;
	for (int i = 0; i < arbore->grad; ++i)
	{
		h = inaltime(arbore->vDesc[i]) + 1;
		if (h > hmax)
			hmax = h;
	}
	return hmax;

}

