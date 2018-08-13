/*
 * L1_A3.c
 *
 *  Created on: Feb 25, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <math.h>
int main(void)
{
	double a, b, c, x1, x2, delta;
	printf("Rezolvarea ecuatiei ax^2+bx+c=0\n");
	printf("a="); //citim coeficientii
	scanf("%lf", &a);
	printf("b=");
	scanf("%lf", &b);
	printf("c=");
	scanf("%lf", &c);
	/*
	 * Luam in considerare fiecare caz, incepand cu valoarea lui a si continuand cu fiecare din ceilalti doi coeficienti, b si c
	 */
	if (a==0)
	{
		if (b==0)
		{
			if (c==0) //a=b=c=0 inseamna 0=0, deci x-ul poate fi oricat
			{
				printf("Ecuatia are o infinitate de solutii reale.\n");
			}
			else { //a=b=0 si c diferit de 0 inseamna 0=ceva diferit de 0, deci nicio solutie
				printf("Ecuatia nu are nicio solutie reala.\n");
			}
		}
		else { //a=0 si b diferit de 0 inseamna ca avem o ecuatie de gradul I, cu solutia x=-c/b (b diferit de 0!)
			x1=-c/b;
			printf("Ecuatia are o solutie reala x=%.2lf\n", x1);
		}
	}
	else { //daca a este diferit de 0, suntem in cazul general al unei ecuatii de gradul II
		delta=b*b-4*a*c; //calculam delta
		if (delta<0) //delta negativ = nicio solutie reala
		{
			printf("Ecuatia nu are nicio solutie reala.\n");
		}
		else if (delta==0) //delta=0 inseamna doua solutii identice
		{
			x1=-b/(2*a);
			printf("Ecuatia are doua solutii reale identice x1=x2=%.2lf\n", x1);
		}
		else if (delta>0) //delta>0 inseamna doua solutii distincte, calculate dupa formulele standard
		{
			x1=(-b+sqrt(delta))/(2*a);
			x2=(-b-sqrt(delta))/(2*a);
			printf("Ecuatia are doua solutii reale distincte x1=%.2lf si x2=%.2lf\n", x1, x2);
		}
	}
	return 0;
}
