/*
 * L1_A7.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "triunghi.h"
int main(void)
{
	unsigned int a, b, c;
	int valid;
	printf("Dati laturile triunghiului:\n"); //citim laturile
	printf("a=");
	scanf("%d", &a);
	printf("b=");
	scanf("%d", &b);
	printf("c=");
	scanf("%d", &c);
	valid=validare(a, b, c); //apelam functia validare si retinem rezultatul intr-o variabila
	if (valid==1) //daca laturile au fost validate, atunci trecem la discutia tipului de triunghi
	{
		if (a==b && b==c) //daca toate laturile sunt egale, atunci triunghiul este echilateral
		{
			printf("Triunghiul este echilateral.\n");
		}
		else if (a==b || b==c || a==c) //daca doua din ele (oricare 2) sunt egale, atunci triunghiul este isoscel
		//Am facut verificarea triunghiului isoscel dupa testul de triunghi echilateral, deoarece, altfel, un triunghi echilateral era vazut ca isoscel!
		//Testul a==b era adevarat, deci intra pe ramura "isoscel"
		{
			printf("Triunghiul este isoscel.\n");
		}
		else if (a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b) //folosim teorema lui Pitagora in toate 3 cazurile pentru a verifica daca triunghiul este dreptunghic
		{
			printf("Triunghiul este dreptunghic.\n");
		}
		else { //daca nu este niciun fel din cele de mai sus, atunci este oarecare (scalen)
			printf("Triunghiul este scalen.\n");
		}
	}
	else { //daca laturile triunghiului nu au trecut testul de validare, afisam eroare
		printf("%d, %d si %d nu pot reprezenta laturile unui triunghi.\n", a, b, c);
	}
	return 0;
}
