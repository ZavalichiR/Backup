/*
 * L1_A5.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
int main(void)
{
	int h1, h2, m1, m2, s1, s2, h, m, s;
	/*
	 * h, m si s reprezinta numarul de ore, minute, respectiv secunde a duratei conexiunii
	 * h1, m1, s1 reprezinta momentul deconectarii
	 * h2, m2, s2 reprezinta momentul conectarii
	 */
	h=0; //initializam cu 0, pentru a avea de unde scade in caz de imprumut si pentru a nu obtine valori reziduale cand efectuam operatiile
	m=0;
	s=0;
	printf("Introduceti momentul conectarii, in format hh:mm:ss\n"); //citim cele 2 momente ale conexiunii Internet (in format hh:mm:ss)
	scanf("%2d:%2d:%2d", &h2, &m2, &s2);
	printf("Introduceti momentul deconectarii, in format hh:mm:ss\n");
	scanf("%2d:%2d:%2d", &h1, &m1, &s1);
	//pornim de la secunde, deoarece trebuie sa facem imprumut de la minute, daca s1<s2
	if (s1>=s2)
	{
		s=s1-s2;
	}
	else { //daca s1<s2, imprumutam 60 de secunde = 1 minut
		s=60+s1-s2;
		m--;
	}
	if (m1>=m2) //procedam la fel si cu minutele
	{
		m+=m1-m2;
	}
	else { //daca m1<m2 atunci imprumutam 60 de minute = 1 ora
		m+=60+m1-m2;
		h--;
	}
	if (h1>=h2) //la fel si cu orele
	{
		h+=h1-h2;
	}
	else { //daca h1<h2 imprumutam "o zi" = 24 de ore
		h+=24+h1-h2;
	}
	printf("Durata conexiunii a fost de %d ore, %d minute, %d secunde\n", h, m, s); //afisam durata conexiunii
	return 0;
}
