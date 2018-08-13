/*
 * hexazecimal.c
 *
 *  Created on: Apr 18, 2015
 *      Author: skynet
 */
#include <string.h>
#include "hexazecimal.h"
void conversie(unsigned long x, char s[]) //converteste numarul natural x in hexazecimal, si depune rezultatul in sirul de caractere s
{
	int rest, i, aux, l;
	/*
	 * rest=restul impartirii lui x la 16
	 * i=pozitia curenta in sirul care se va forma
	 * aux=auxiliara cu care vom inversa caracterele din conversie
	 * l=variabila care va retine lungimea sirului hexa format
	 */
	s[0]='0'; //primele 2 caractere ale numarului in hexa trebuie sa fie "0x"
	s[1]='x';
	i=2; //pornim cu pozitia de la 2, pentru ca primele 2 sunt deja ocupate cu caracterele "0x" inainte de conversie pentru ca se incrementeaza inainte de a atribui prima valoare
	while (x) //repetam conversia cat timp impartirea intreaga a numarului, respectiv a noului "deimpartit" da un cat nenul
	{
		rest=x%16; //calculam restul impartirii la 16 a deimpartitului
		x/=16; //impartim intreg catul curent la 16
		if (rest<=9) //daca obtinem un rest mai mic sau egal cu 9
		{
			s[i]='0'+rest; //inseamna ca cifra hexa coincide cu cifra din baza 10, deci introducem codul ASCII al cifrei 0, la care adaugam valoarea cifrei obtinute, pentru a obtine caracterul in sir
		}
		else //daca restul obtinut este intre 10 si 15, atunci este cifra hexa, intre A si F
		{
			s[i]='A'+rest-10; //introducem in sir caracterul ASCII al cifrei hexa A, la care adaugam valoarea restului, dar trebuie sa scadem 10 din rezultat
		}
		++i; //trecem la urmatoarea pozitie in sirul de conversie hexa
	}
	s[i]='\0'; //sirul este construit manual, deci trebuie adaugat caracterul '\0' la final, pentru a marca "sfarsitul de sir"
	l=strlen(s); //calculam lungimea sirului s obtinut
	//conversia hexa se obtine in ordine inversa, deoarece algoritmul cu impartiri repetate, care preia resturile impartirilor la 16 obtine cifrele hexa in ordine inversata
	for (i=2; i<=(l+1)/2; ++i) //inversam cifrele hexa obtinute, egal departate de "jumatate", pornind de la pozitia 2, pana la acea "jumatate"
	{
		aux=s[i];
		s[i]=s[l-i+1];
		s[l-i+1]=aux;
	}
}
