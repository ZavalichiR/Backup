#include"Header.h"

//-------Functii elementare
void inserareCap(Nod *&head, int val)
{
	Nod *p = new Nod;
	p->data = val;
	p->succ = head;
	head = p;
}
void inserareCoada(Nod *&head, int val)
{
	Nod *p = new Nod;
	p->data = val;
	p->succ = 0;
	if (head==0)
		head = p;
	else
	{
		Nod *q = new Nod;
		q = head;
		while (q->succ)
			q = q->succ;
		q->succ = p;
	}
}
void inserareOrdine(Nod *&head, int val)
{
	if (head==0)
	{
		Nod *p= new Nod;
		p->data = val;
		p->succ = head;
		head = p;
		head->succ = 0;
		return;
	}
	if (val <= head->data)
	{
		Nod *p = new Nod;
		p->data = val;
		p->succ = head;
		head = p;
		return;
	}
	else
	{
		Nod *p = head->succ;
		Nod *q = head;
		while (p && val > p->data)
		{
			p = p->succ;
			q = q->succ;

		}
		Nod *elm = new Nod;
		elm->data = val;
		elm->succ = p;
		q->succ = elm;
	}

}
void afisareCapCoada(Nod *head)
{
	Nod *p = head;
	if (p)
	{
		while (p)
		{
			cout << p->data << " ";
			p = p->succ;
		}
	}
	else
		cout << "Lista este vida";
	
}
void afisareCoadaCap(Nod *head)
{
	Nod *p = head;
	if (p)
	{
		afisareCoadaCap(p->succ);
		cout << p->data << " ";
	}
}
void cautare(Nod *head, int val)
{
	Nod *p = new Nod;
	p = head;
	int i = 1;
	if (!p)
	{
		cout << "Lista vida" << endl;
		return;
	}
	else
	{
		while (p && p->data != val)
		{
			p = p->succ;
			i++;
		}	
	}
	if (p->data == val)
	{
		cout << "Elementul " << p->data << " a fost gasit pe pozitia " << i << endl;
	}
	else
		cout << "Elemntul " << val << " nu a fost gasit" << endl;
}
void sterge(Nod *&head, int val)
{
	Nod *p = new Nod;
	p = head;
	if (head == 0)
	{
		cout << "Lista este vida" << endl;
		return;
	}
	if (head->data==val)
	{
		head = head->succ;
		delete p;
		return;
	}
	while (p->succ && p->succ->data != val)
		p = p->succ;
	if (p->succ)
	{
		Nod *e = p->succ;
		p->succ = p->succ->succ;
		delete e;
		return;
	}

}
int ind = 1;
void stergePozitie1(Nod *&lista, int poz)//sterge dupa pozitie de la coada la cap
{
	if (lista)
	{
		stergePozitie1(lista->succ, poz);
		ind += 1;
		if (ind == poz + 1)
		{
			Nod*elm = lista;
			lista = lista->succ;
			delete elm;
			EXIT_SUCCESS;
		}


	}
}
void stergePozitie12(Nod *&lista, int poz)
{
	if (!lista)
		return;
	Nod* p = lista;
	while (poz-- && p)
	{
		p = p->succ;
	}
	if (poz > 0)
	{
		return;
		cout << "Lista pre scurta" << endl;
	}

	if (p == 0)
	{
		Nod *elm = lista;
		lista = lista->succ;
		delete elm;

	}
	else{
		Nod *q = lista;
		while (p->succ)
		{
			p = p->succ;
			q = q->succ;
		}

		if (q->succ)
		{
			Nod *elm = q->succ;
			q->succ = q->succ->succ;
			delete elm;
		}
	}

}
void stergePozitie2(Nod *&lista, int poz)
{
	int ind2 = 1;
	if (!lista)
		return;
	if (poz == ind2)
	{
		Nod *elm = lista;
		lista = lista->succ;
		delete elm;
	}
	else
	{
		Nod *p = lista;
		while (p->succ && poz != ind2+1)
		{
			p = p->succ;
			ind2++;
		}
			
		if (p->succ && poz == ind2+1)
		{
			Nod *elm = p->succ;
			p->succ= p->succ->succ;
			delete elm;
			return;
		}
	}

	
}
void ordonare(Nod *&lista)
{
	int ok = 1;
	while (ok)
	{
		ok = 0;
		Nod*p = lista;
		while (p->succ)
		{
			if (p->data > p->succ->data)
			{
				int aux = p->data;
				p->data = p->succ->data;
				p->succ->data = aux;
				ok = 1;
			}
			p = p->succ;


		}
	}
}
Nod *inversareLegaturi(Nod *&head)
{
	Nod*p, *q, *r;
	p = head;
	q = p->succ;
	r = p->succ->succ;
	p->succ = 0;
	while (r->succ)
	{
		q->succ = p;
		p = q;
		q = r;
		r = r->succ;
	}
	q->succ = p;
	r->succ = q;
	return r;
}

//------Functii pentru main
void inserareaInFata(Nod *&head)
{
	int n, i = 1, element;
	cout << "\n---------Inserare IN FATA----------\n";
	cout << "Precizati numarul de elemente: ";
	cin >> n;
	while (n)
	{
		n--;
		cout << "Elementul " << i << ": ";
		cin >> element;
		i++;
		inserareCap(head, element);
	}
	cout << "Afisare Cap-Coada" << endl;
	afisareCapCoada(head);
	cout << "\nAfisare Coada-Cap" << endl;
	afisareCoadaCap(head);
	cout << endl;
}
void inserareInSpate(Nod *&head)
{
	int n, i = 1, element;
	cout << "\n---------Inserare IN COADA----------\n";
	cout << "Precizati numarul de elemente: ";
	cin >> n;
	while (n)
	{
		n--;
		cout << "Elementul " << i << ": ";
		cin >> element;
		i++;
		inserareCoada(head, element);
	}
	cout << "Afisare Cap-Coada" << endl;
	afisareCapCoada(head);
	cout << "\nAfisare Coada-Cap" << endl;
	afisareCoadaCap(head);
	cout << endl;
}
void Cauta(Nod *&head)
{
	int ok;
	int val;
	do{
		cout << "Elementul: ";
		cin >> val;
		cautare(head, val);
		system("pause");
		system("cls");
		afisareCapCoada(head);
		cout << "\n(1) Cauta un element\n(0) Nu cauta" << endl;
		cin >> ok;
	} while (ok);
}
void Sterge(Nod *&head)
{
	afisareCapCoada(head);
	int ok;
	int val;
	do{
		cout << "\nElementul: ";
		cin >> val;
		sterge(head, val);
		afisareCapCoada(head);
		cout << "\n(1) Sterge un element\n(0) Nu sterge" << endl;
		cin >> ok;
	} while (ok);
}
void Inverseaza(Nod *&head)
{
	Nod *p = inversareLegaturi(head);
	cout << "\nDupa inversarea legaturilor: " << endl;
	cout << "Afisare CAP-COADA\n";
	afisareCapCoada(p);
}
//---------------------------

//-------Functii Curs
void inserarePozitie(Nod *&head, int val, int pozitie)
{
	int index = 1;
	if (index == pozitie)
	{
		Nod *p = new Nod;
		p->data = val;
		p->succ = head;
		head = p;
		return;
	}
	
	Nod *p = head;
	Nod *elm = new Nod;
	elm->data = val;
	while (p)
	{
		if (pozitie == index + 1)
		{
			elm->succ = p->succ;
			p->succ = elm;
			return;
		}
		p = p->succ;
		index++;
	}

	if (pozitie > index)
	{
		cout << "Lista este prea scurta" << endl;
		return;
	}
	
}
void unireListe(Nod *&lista1, Nod *&lista2)
{
	//La capatul listei 1 se adauga lista 2
	Nod *p = lista1;
	while (p->succ)
		p = p->succ;
	p->succ = lista2;
}
int count(Nod *lista)
{
	if (lista == 0)
		return 0;
	int c = 1;
	Nod *p = lista;
	while (p->succ)
	{
		++c;
		p = p->succ;
	}
	return c;
}
Nod *interclasare(Nod *lista1, Nod *lista2)
{
	Nod *lista = new Nod;
	lista->succ = 0;
	Nod *p = lista1;
	Nod *q = lista2;
	while (p && q)
	{
		inserareCoada(lista, p->data);
		inserareCoada(lista, q->data);
		p = p->succ;
		q = q->succ;
	}
	//inserarea o sa plece de la al doilea element deoarece lista ia ca primul element o valoare random
	//						//stergem acea valoare random
	Nod *desters = lista;
	lista = lista->succ;
	delete desters;
	while (p)
	{
		inserareCoada(lista, p->data);
		p = p->succ;
	}
	while (q)
	{
		inserareCoada(lista, q->data);
		q = q->succ;
	}
	return lista;
}
void interclasare2(Nod *&lista1, Nod *&lista2)
{
	int l1 = count(lista1);
	int l2 = count(lista2);
	Nod *p=new Nod;
	Nod *q=new Nod;
	if (l1 == 0)
	{
		lista1 = lista2;
		return;
	}
	if (l2 == 0)
	{
		return;
	}
	if (l1 < l2)
	{
		p = lista1;
		q = lista2;
	}
	if (l2 < l1)
	{
		p = lista2;
		q = lista1;
	}
	if (l1 == l2)
	{
		p = lista1;
		q = lista2;
	}
	Nod *p1 = p;
	Nod *q1 = q;
	Nod *p2 = p->succ;
	Nod *q2 = q->succ;
	while (p2)
	{
		p1->succ = q1;
		q1->succ = p2;

		p1 = p2;
		p2 = p2->succ;

		q1 = q2;
		q2 = q2->succ;
	}
	p1->succ = q1;
	q1->succ = q2;

	lista1 = p;
	lista2 = nullptr;
}
void stergeElementePare(Nod *&lista)
{
	int ok = 1;
	{
		while (ok)
		{
			ok = 0;
			if (lista && (lista->data % 2) == 0)
			{
				ok = 1;
				Nod *p = lista;
				lista = lista->succ;
				delete p;
			}
		}
	}
	if (lista == 0)
	{
		cout << "\nLista este goala\n";
		return;
	}
	 ok = 1;
	{
		while (ok)
		{
			ok = 0;
			Nod *q = lista;
			while (q->succ && (q->succ->data % 2) != 0)
			{
				q = q->succ;
			}
					
			if (q->succ && (q->succ->data % 2) == 0)
			{
				Nod *elm = q->succ;
				q->succ = q->succ->succ;
				delete elm;
				ok = 1;
			}
			
		}
	}
}
Nod *mutaElementePare(Nod *&lista)
{
	int ok = 1;
	Nod *par = nullptr;
	while (ok)
	{
		ok = 0;
		if (lista && (lista->data) % 2 == 0)
		{
			Nod *elm = lista;
			inserareCoada(par, elm->data);
			lista = lista->succ;
			delete elm;
			ok = 1;
		}
	}
	if (lista == 0)
	{
		cout << "\nLista a fost golita\n";
		return par;
	}

	ok = 1;
	while (ok)
	{
		ok = 0;
		Nod *p = lista;
		while (p->succ && (p->succ->data % 2) != 0)
			p = p->succ;
		if (p->succ && (p->succ->data % 2) == 0)
		{
			Nod *elm = p->succ;
			inserareCoada(par, elm->data);
			p->succ = p->succ->succ;
			delete elm;
			ok = 1;
		}
	}
	return par;
}
void palindrom(Nod *p, Nod *&q, int &ok)
{
	if (p)
	{
		palindrom(p->succ, q, ok);
		if (p->data != q->data)
			ok = 0;
		q = q->succ;
	}
}
Nod *insertEnd()
{
	cout << "Elm: ";
	int elm;
	cin >> elm;
	if (elm)
	{
		Nod *p = new Nod;
		p->succ = insertEnd();
		p->data = elm;
		return p;
	}
	return 0;
}