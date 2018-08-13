#include"Header.h"
/*
void crearestiva(StivaOrdonata &S)
{
	S.sp = 0;
}

void push(StivaOrdonata &S, Atom val)
{
	if (S.sp == dim)
	{
		cout << "Stiva plina-Push " << endl;
		return;
	}

	S.vect[S.sp] = val;
	S.sp++;
}



Atom pop(StivaOrdonata &S)
{
	if (S.sp == 0)
	{
		cout << "\nStiva goala-POP" << endl;
		return 0;
	}
	S.sp--;
	return S.vect[S.sp];
}

int isEmpty(StivaOrdonata S)
{
	if (S.sp == 0)
	{
		cout << "\nStiva goala-POP" << endl;
		return 0;
	}
	else
		return 1;
}


Atom top(StivaOrdonata S)
{
	if (isEmpty(S)==1)
	{
		return S.vect[S.sp - 1];
	}
	else
	{
		cout << "\nStiva goala -POP" << endl;
	}
}
*/

//--------------------------------------------------///
void crearestiva(StivaOrdonata &S)
{
	S.sp = dim;
}

void push(StivaOrdonata &S, Atom val)
{
	if (S.sp == 0)
	{
		cout << "Stiva plina-Push " << endl;
		return;
	}

	S.sp--;
	S.vect[S.sp] = val;
	
}



Atom pop(StivaOrdonata &S)
{
	if (S.sp == dim)
	{
		cout << "\nStiva goala-POP" << endl;
		return 0;
	}
	
	return S.vect[S.sp];
	S.sp++;
}

int isEmpty(StivaOrdonata S)
{
	return(S.sp == dim );
}


Atom top(StivaOrdonata S)
{
	if (isEmpty(S))
	{
		return S.vect[S.sp + 1];
	}

	else
	{
		cout << "\nStiva goala -POP" << endl;
	}
}

void testStiva(StivaOrdonata &S)
{
	StivaOrdonata X;
	crearestiva(X);
	int n;
	int m;
	cout << "Numarul de elemente din stiva: ";
	cin >> n;
	m = n;


	while(n)
	{
		push(X, n);
		n--;
	}


	cout << "TOP: " << top(X) << endl;



	while (m)
	{
		cout << "POP: " << pop(X) << endl;
		m--;
	}
	
}

//............................................//
void Creare(StivaInalntuita *&S)
{
	S = nullptr;
}

void Initializare(StivaInalntuita *&S)
{
	S = 0;
}

void Push(StivaInalntuita *&S, Atom data)
{

	StivaInalntuita *p=new StivaInalntuita;
	if (p == nullptr)
	{
		return;
	}
	p->data = data;
	p->leg = S;
	S = p;
	
}

Atom Pop(StivaInalntuita *&S)
{
	if (S==nullptr)
	{
		cout << "\nStiva este goala-POP" << endl;
		return 0;
	}
	Atom rezultat = S->data;
	StivaInalntuita *p = S;
	S = S->leg;
	delete(p);
	return rezultat;
}

bool IsEmpty2(StivaInalntuita *S)
{
	return (S == 0); //bool-return 1;
}

Atom Top(StivaInalntuita *S)
{
	if (S == nullptr)
	{
		cout << "\nStiva este goala-POP" << endl;
		return 0;
	}

	return S->data;
}

void Testare()
{
	StivaInalntuita *S;
	Creare(S);
	Initializare(S);

	int n;
	int m;
	cout << "Numarul de elemente din stiva: ";
	cin >> n;
	m = n;


	while (n)
	{
		Push(S, n);
		n--;
	}


	cout << "TOP: " << Top(S) << endl;



	while (m)
	{
		cout << "POP: " << Pop(S) << endl;
		m--;
	}

}

void EvaluareFormaPostafixata(char s[])
{ 
	StivaInalntuita *St = 0;
	Atom a1, a2;
	int i = 0;
	Creare(St);
	Initializare(St);
	
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9') //operand
		{
			Push(St, s[i]-'0'); //daca gaseste operand il baga in stiva
		}
		else if (s[i] == '+')
		{
			a1 = Pop(St);
			a2 = Pop(St);
			Push(St, a1 + a2);
		}
		else if (s[i] == '-')
		{
			a1 = Pop(St);
			a2 = Pop(St);
			Push(St, a2 - a1);
		}
		else
		{
			cout << "Operatie"<<s[i] <<" neimplementata" << endl;
		}

		i++;
	}
	cout << Pop(St) << endl;
}