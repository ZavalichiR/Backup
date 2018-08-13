/*
 * main.c
 *
 *  Created on: Mar 20, 2015
 *      Author: student
 */
#include <stdio.h>
int main(void)
{
	char sir[32]; //declaram sirul de maxim 30 de caractere, efectiv (pentru ca ultimele 2 vor fi: '\n' (de la apasarea tastei ENTER) si '\0', care semnifica sfarsitul de sir)
	int rel;
	rel=1; //rel este variabila care retine daca utilizatorul doreste sau nu reluarea programului
	//porneste de la 1 pentru ca bucla repetitiva este de tip while(), iar conditia se testeaza anterior, asa incat trebuie sa intre in while() macar o data
	while (rel)
	{
		printf("Introduceti sirul de caractere (max. 30): ");
		fgets(sir, 31, stdin); //citim sirul de caractere de la tastatura (al doilea parametru este 31 = 32 - 1, pentru ca nu am luat in considerare caracterul '\0', care este pus automat de fgets() dupa ce citeste sirul de la tastatura
		//practic, de la tastatura citim efectiv maxim 31 de caractere (cu tot cu ENTER-ul pus la sfarsit, si acela este caracter efectiv)
		int a, e, i, o, u; //acestea reprezinta numarul de vocale de tipul respectiv
		a=e=i=o=u=0; //le initializam pe toate o data cu 0
		int k=0; //pornim de la pozitia 0 in sirul citit
		while (sir[k]!='\0') //parcurgem sirul cat timp nu am intalnit caracterul '\0' (sfarsit de sir de caractere)
		{
			switch (sir[k]) //folosim o instructiune switch, dupa caracterul curent, care ii testeaza valoarea si o compara cu vocalele cunoscute, care pot fi si litere mari si mici
			{
			//numarul de vocale respectiv se incrementeaza conform tipului de vocala intalnit
			case 'a': ++a;
			break;
			case 'e': ++e;
			break;
			case 'i': ++i;
			break;
			case 'o': ++o;
			break;
			case 'u': ++u;
			break;
			case 'A': ++a;
			break;
			case 'E': ++e;
			break;
			case 'I': ++i;
			break;
			case 'O': ++o;
			break;
			case 'U': ++u;
			break;
			}
			k++; //trecem la pozitia urmatoare in sirul citit (la caracterul urmator pentru a fi testat)
		}
		printf("Numarul de vocale:\na: %d\ne: %d\ni: %d\no: %d\nu: %d\n", a, e, i, o, u); //afisam rezultatele pe ecran
		printf("Reluati programul? (DA=1, NU=0) ");
		scanf("%d", &rel); //citim de la tastatura optiunea de a relua sau nu programul
		getchar(); //folosim functia getchar() dupa ce citim variabila rel, deoarece ENTER-ul tastat la aceasta citire ramane in buffer si impiedica functia fgets() sa citeasca sirul
		//functia fgets() citeste pana la '\n' sau EOF, deci, gasind in buffer \n, practic nu citeste nimic.
		//apeland getchar(), se "preia" acel '\n' in plus din buffer
	}
	return 0;
}
