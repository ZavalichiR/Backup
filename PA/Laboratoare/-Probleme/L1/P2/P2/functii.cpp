

#include"Header.h"
void creare(node *&head, int val)
{
	node *p = new node;
	p->data = val;
	p->suc = head;
	p->prec = 0;
	if (head)
		head->prec = p;
	head = p;
}
void afisare(node *head)
{
	if (head)
	{
		node *p = head;
		node *q = NULL;
		cout << "-----Afisare 1------" << endl;;
		while (p)
		{
			q = p;
			cout << p->data << " ";
			p = p->suc;
		}
		cout << "\n------Afisare 2-----" << endl;
		while (q)
		{
			cout << q->data << " ";
			q = q->prec;
		}
	}
}
void inserare(node *&head, int val, int poz)
{
	int index = 1;
	if (poz == index)
	{
		node *p = new node;
		p->data = val;
		p->suc = head;
		p->prec = 0;
		if (head)
			head->prec = p;
		head = p;
		return;
	}
	else{
		node *q = head;
		while (q)
		{
			if (poz == (index + 1))
			{
				node *elm = new node;
				elm->data = val;
				elm->suc = q->suc;
				elm->prec = q;
				if (q->suc)
				{
					q->suc->prec = elm;
				}
				q->suc = elm;

			}
			q = q->suc;
			index++;
		}
		if (index<poz)
			cout << "\nLista prea scurta" << endl;
	}
}

