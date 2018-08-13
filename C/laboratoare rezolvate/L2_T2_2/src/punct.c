/*
 * punct.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "punct.h"
void pozitie(double x, double y)
{
	if (x==0 && y==0) //daca ambele coordonate sunt 0, atunci punctul e in origine
	{
		printf("Punctul se afla in origine.\n");
	}
	else if (x==0) //daca x=0, atunci se afla pe axa Oy
	{
		if (y>0) //daca y>0, atunci punctul se afla in partea de sus fata de Ox, adica intre cadranele I si II
		{
			printf("Punctul se afla pe axa Oy, intre cadranele I-II.\n");
		}
		else { //daca y<0, atunci punctul se afla in partea de jos fata de Ox, adica intre cadranele III si IV
			printf("Punctul se afla pe axa Oy, intre cadranele III-IV.\n");
		}
	}
	else if (y==0) //daca y=0, atunci se afla pe axa Oy
	{
		if (x>0) //daca x>0, atunci punctul se afla in partea dreapta fata de Oy, adica intre cadranele I si IV
		{
			printf("Punctul se afla pe axa Ox, intre cadranele I-IV.\n");
		}
		else { //daca x<0, atunci punctul se afla in partea stanga fata de Oy, adica intre cadranele II si III
			printf("Punctul se afla pe axa Ox, intre cadranele II-III.\n");
		}
	}
	/*
	 * Urmeaza apoi discutia pe cadrane, in functie de semnul fiecarei coordonate, in acest caz nenula, deci punctul nu se mai poate afla pe una din axe
	 */
	else if (x>0 && y>0)
	{
		printf("Punctul se afla in cadranul I.\n");
	}
	else if (x<0 && y>0)
	{
		printf("Punctul se afla in cadranul II.\n");
	}
	else if (x<0 && y<0)
	{
		printf("Punctul se afla in cadranul III.\n");
	}
	else {
		printf("Punctul se afla in cadranul IV.\n");
	}
}
