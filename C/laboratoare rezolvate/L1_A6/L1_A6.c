/*
 * L1_A6.c
 *
 *  Created on: Mar 3, 2015
 *      Author: skynet
 */
#include <stdio.h>
int main(void)
{
	int h1, m1, s1, dh, dm, ds, h, m, s;
	/*
	 * h1, m1, s1 reprezinta momentul conectarii, in ore, minute, respectiv secunde
	 * dh, dm, ds reprezinta durata in ore, minute, secunde a conexiunii
	 * h, m, s reprezinta momentul deconectarii, in ore, minute, respectiv secunde
	 */
	printf("Introduceti momentul conectarii (hh:mm:ss): "); //citim momentul conectarii
	scanf("%d:%d:%d", &h1, &m1, &s1);
	printf("Introduceti durata conexiunii (hh:mm:ss): "); //citim durata
	scanf("%d:%d:%d", &dh, &dm, &ds);
	h=0; //initializam cu 0 pentru a nu obtine valori reziduale cand efectuam operatiile
	m=0;
	s=0;
	if (s1+ds>=60) //pornim de la secunde, si adaugam un minut in plus daca suma depaseste 60
	{
		m++;
		s+=s1+ds-60;
	}
	else {
		s+=s1+ds;
	}
	if (m+m1+dm>=60) //la fel si cu minutele, dar tinem cont ca e posibil sa fi adaugat un minut in plus la verificarea secundelor (de aceea se adauga +m la verificare)
	{
		h++;
		m+=m1+dm-60;
	}
	else {
		m+=m1+dm;
	}
	if (h+h1+dh>=24) //asemanator cu numarul de ore, tot cu +h la verificare, pentru ca e posibil sa fi adaugat o ora in plus de la sumarea minutelor
	{
		h+=h1+dh-24;
	}
	else {
		h+=h1+dh;
	}
	printf("Conexiunea s-a incheiat la ora %.2d:%.2d:%.2d.\n", h, m, s); //afisam momentul deconectarii
	return 0;
}
