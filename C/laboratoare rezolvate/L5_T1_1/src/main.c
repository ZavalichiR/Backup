/*
 * main.c
 *
 *  Created on: Mar 20, 2015
 *      Author: student
 */
#include <stdio.h>
#include "caracter.h"
int main(void)
{
	int c, n; //c=caracterul cautat, n=numarul sau de aparitii
	char sir[32]; //declaram sirul de maxim 30 de caractere, efectiv (pentru ca ultimele 2 vor fi: '\n' (de la apasarea tastei ENTER) si '\0', care semnifica sfarsitul de sir)
	printf("Introduceti sirul de caractere (max.30): ");
	fgets(sir, 31, stdin); //citim sirul de caractere de la tastatura (al doilea parametru este 31 = 32 - 1, pentru ca nu am luat in considerare caracterul '\0', care este pus automat de fgets() dupa ce citeste sirul de la tastatura
	//practic, de la tastatura citim efectiv maxim 31 de caractere (cu tot cu ENTER-ul pus la sfarsit, si acela este caracter efectiv)
	printf("Introduceti caracterul cautat: ");
	c=getchar(); //citim caracterul cautat cu ajutorul functiei getchar(), care citeste un caracter de la "stdin" = tastatura
	n=nr_aparitii(c, sir); //apelam functia nr_aparitii(), care ne va furniza numarul de aparitii ale caracterului c in sirul "sir"
	printf("Caracterul %c apare de %d ori.\n", c, n); //afisam rezultatul pe ecran
	return 0;
}
