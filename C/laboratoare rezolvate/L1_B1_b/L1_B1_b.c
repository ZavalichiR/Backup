/*
 * L1_B1_b.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
int main(void)
{
	double c, f, pas;
	printf("Introduceti pasul: ");
	scanf("%lf", &pas); //citim pasul de la tastatura
	c=-160/9.; //corespunzator temperaturii 0 K, temperatura in grade Celsius este -160/9 C, conform formulei de la punctul a)
	while (c<=1340/9.) //de la aceasta temperatura initiala, adica -160/9 C, pana la temperatura corespunzatoare in grade C a 300 K, adica 1340/9 C
	{
		f=(160+9*c)/5; //l-am scos pe F din formula de la punctul a) si am obtinut transformarea inversa, din grade C in grade K
		printf("%6.2lf C | %6.2lf F \n", c, f); //afisam cate o linie a tabelului, cu cele 2 temperaturi separate de o bara verticala
		c+=pas; //incrementam numarul de grade Celsius cu pasul citit de la tastatura
	}
	return 0;
}
