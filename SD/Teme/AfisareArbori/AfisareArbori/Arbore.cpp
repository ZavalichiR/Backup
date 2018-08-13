#include"Arbore.h"

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
		Nod *p = (Nod*) new char[sizeof(Nod)-(GRMAX - k + 1)*sizeof(Nod*)];
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
	exit(1);
}