#include"stiva.h"
//     Alocare Statica

void init(stiva1 &s)
{
	s.sp = -1;
}
void push(stiva1 &s, int val)
{
	if (s.sp < dim - 1)
		s.vect[++s.sp] = val;
	else
	{
		cout << "\nStiva este plina\n";
	}

}
int pop(stiva1 &s)
{
	if (s.sp != -1)
		return s.vect[s.sp--];
	else
		return 0;
}
int top(stiva1 s)
{
	if (s.sp != -1)
		return s.vect[s.sp];
	else

		return 0;
}
void stiva1Main()
{
	stiva1 s;
	init(s);
	cout << "\nElementul pe care il introduceti: ";
	int elm;
	cin >> elm;
	while (elm)
	{
		push(s, elm);
		cout << "\nElementul pe care il introduceti(!=0): ";
		cin >> elm;
	}

	cout << "\ntop: ";
	if (top(s)!=0)
		cout<<top(s) << endl;
	else
		cout << "\nStiva este goala\n";


	cout << "\nFaceti Pop? (!=0  da) ";
	int elm2;
	cin >> elm2;
	while (elm2)
	{
		int val = pop(s);
		if (val!= 0)
			cout << val << endl;
		else
			cout << "\nStiva este goala\n";
		cout << "\nFaceti Pop? (!=0  da) ";
		cin >> elm2;
	}

}

//     Alocare Dinamica

void initS(stiva2 *&S)
{
	S = nullptr;
}
void pushS(stiva2 *&S, int val)
{
	stiva2 *p = new stiva2;
	p->data = val;
	p->leg = S;
	S = p;
}
int popS(stiva2 *&S)
{
	if (S == 0)
	{
		//cout << "\nstiva este goala\n";
		return 0;
	}
	else
	{
		int aux = S->data;
		stiva2 *elm = S;
		S = S->leg;
		delete elm;
		return aux;
	}
}
int topS(stiva2 *S)
{
	if (S == 0)
	{
		cout << "\nStiva este goala\n";
		return 0;
	}
	else
		return S->data;
}
bool isEmpty(stiva2 *S)
{
	if (S == 0)
		return 1;
	else
		return 0;
}
stiva2 *copy(stiva2 *S)
{
	cout << isEmpty(S);
	if (S==0)
	{
		cout << "Stiva vida" << endl;
		return 0;
	}
	stiva2 *S2 = new stiva2;
	initS(S2);
	stiva2 *aux = new stiva2;
	initS(aux);
	while (S)
		pushS(aux, popS(S));
	while (aux)
		pushS(S2, popS(aux));
	return S2;
}
void sterge(stiva2 *&S)
{
	if (S)
	{
		cout << popS(S) << " ";
		sterge(S);
	}
}
void stiva2Main()
{
	stiva2 *s;
	initS(s);
	cout << "\nElementul pe care il introduceti: ";
	int elm;
	cin >> elm;
	while (elm)
	{
		pushS(s, elm);
		cout << "\nElementul pe care il introduceti(!=0): ";
		cin >> elm;
	}
	stiva2 *s2;
	s2 = copy(s);
	sterge(s2);

	//cout << "\ntop: ";
	//topS(s);


	//cout << "\nFaceti Pop? (!=0  da) ";
	//int elm2;
	//cin >> elm2;
	//while (elm2)
	//{
	//	int val = popS(s);// daca stiva este goala valoarea returnata este 0;
	//	if (val != 0)
	//		cout << val << endl;
	//	else
	//		cout << "\nStiva este goala\n";
	//	cout << "\nFaceti Pop? (!=0  da) ";
	//	cin >> elm2;
	system("pause");
	}