#include"functii.h"

//-----ALGORITM-----
/*
-------Algoritm-------
1.Se va folosi o Stiva de OPERATORI( +,-,*,/,(,) )
	si un sir de caractere: char post[100];

2.Se parcurge sirul SIR (forma infixata data de la tastatura)
	de la stanga la dreapta pana intalneste '\0'-se termina

3.La intalnirea unui operand( 0 to 9) acesta este pus in sirul POST

3.La intalnirea parantezei deschise '(' aceasta este pusa in stiva

4.La intalnirea parantezei inchise ')' se extrage tot ce se afla in 
	stiva( si este pus in sirul POST) pana la intalnirea parantezei
	deschise ')', ')' se extrage dar nu se pune in sirul POST

5.La intalnirea unui operator +,-,* sau /
	se extrag din stiva toti operatorii de prioritate mai mare sau
	egala si se transfera in sirul POST, pana se ajunge la '('
	Operatorul curent se plaseaza in stiva

6.La finalul sirului SIR se goleste stiva si se transfera in sirul 
	POST

7.Se pune '\0' in POST, post[k]='\0'
*/
void poloneza(char *sir)//poloneza <=> forma postfixata
{
	int i = 0, k = 0;
	char *post=new char[100];
	stiva2 *S;
	initS(S);
	while (sir[i] != '\0')
	{
		if (sir[i] >= '0' && sir[i] <= '9')//(sir[i] >= 'a' && sir[i] <= 'z')
		{
			post[k] = sir[i];
			k++;
		}
		if (sir[i] == '(')
			pushS(S, sir[i]);
		if (sir[i] == ')')
		{
			while (topS(S) != '(')
			{
				post[k] = popS(S);
				k++;
			}
			popS(S);
		}
		if (sir[i] == '+' || sir[i] == '-')
		{
			while (S && topS(S) != '(' && sir[i] != 0)
			{
				post[k] = popS(S);
				k++;
			}
			pushS(S, sir[i]);
		}
		if (sir[i] == '*' || sir[i] == '/')
		{
			while (S && topS(S) != '+' && topS(S) != '-' && topS(S) != '(' && sir[i] != 0)
			{
				post[k] = popS(S);
				k++;
			}
			pushS(S, sir[i]);
		}
		i++;
	}
	while (S)
	{
		post[k] = popS(S);
		k++;
	}
	post[k] = '\0';
	cout << "\nForma postfixata este: " << post << endl;
	evaluarePoloneza(post);
}

//----ALGORITM----
/*
1.Se va folosi o stiva de OPERANZI(0 to 9)

2.Se parcurge sirul (forma poloneza/forma postfixata) de la stanga
	la dreapta

3.La intalnirea unui operand, acesta va fi pus in stiva

4.La intalnirea unui operator, se vor extrage din stiva 2 operanzi
	si li se atribuie operatorul

5.Rezultatul obtinut se va pune in stiva

6.LA finalul sirului rezultatul final va fi pus in stiva

7.Se extrage din stiva rezultatul final si se afiseaza
*/
void evaluarePoloneza(char *sir)
{
	int i = 0;
	int a, b;
	stiva2 *S;
	initS(S);
	while (sir[i] != '\0')
	{
		if (sir[i] >= '0' && sir[i] <= '9')
			pushS(S, sir[i]-'0');
		if (sir[i] == '+')
		{
			 a = popS(S);
			 b = popS(S);
			pushS(S, a + b);
		}
		if (sir[i] == '-')
		{
			a = popS(S);
			b = popS(S);
			pushS(S, b-a);
		}
		if (sir[i] == '*')
		{
			a = popS(S);
			b = popS(S);
			pushS(S, a * b);
		}
		if (sir[i] == '/')
		{
			a = popS(S);
			b = popS(S);
			pushS(S, b/a);
		}
		i++;
	}
	cout << "\nRezultat: " << popS(S) << endl;

}

void palindrom(char *sir)
{
	stiva2 *S;
	initS(S);
	coada2 *C;
	inittC(C);
	int ok = 1;
	for (int i = 0; i < (int)strlen(sir); ++i)
		pushS(S, sir[i]);
	for (int i = 0; i < (int)strlen(sir); ++i)
		putC(C, sir[i]);
	for (int i = 0; i < (int)strlen(sir); ++i)
	{
		if (popS(S) != getC(C))
			ok = 0;
	}
	if (ok == 0)
		cout << "\nSirul nu este palindrom\n";
	else
		cout << "\nSirul este palindrom\n";
}