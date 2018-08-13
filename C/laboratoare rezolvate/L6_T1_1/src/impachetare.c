/*
 * impachetare.c
 *
 *  Created on: Mar 27, 2015
 *      Author: student
 */
#include <stdio.h>
#include "impachetare.h"
void afisareBinara(WORD x) //afiseaza toti bitii unui numar intreg fara semn
{
	WORD nr=sizeof(WORD)<<3; //nr reprezinta numarul de biti al tipului respectiv de data; sizeof() returneaza numarul de bytes, deci trebuie inmultit cu 8 = 2^3 (shiftare la stanga cu 3 pozitii) pentru a afla numarul de biti
	//incepem sa construim masca pentru extragerea fiecarui bit (de la stanga, adica de la MSB, la dreapta, adica inspre LSB)
	WORD MASCA=(WORD)0; //MASCA->000...0 (conversie cast la WORD, pentru a nu considera constanta 0 ca si avand semn, pentru evitarea extensiei de semn
	MASCA=~MASCA; //MASCA->111...1
	MASCA=MASCA>>1; //MASCA->011...1
	MASCA=~MASCA; //MASCA->100...0

	// METODA 2: MASCA=1<<(nr-1);

	WORD c; //c reprezinta bitul extras curent
	while (nr) //cat timp mai exista biti de extras (numarul de biti ramasi este diferit de 0)
	{
		c=(x&MASCA)>>(nr-1); //facem operatia SI intre numar si MASCA, obtinand efectiv bit-ul de pe pozitia nr
		//acesta trebuie shiftat la dreapta cu nr pozitii pentru a-l aduce pe ultima pozitie; doar astfel, poate fi citit corect, ca si "cifra" (1 sau 0)
		/* exemplu, pentru primul bit, si x=1011001, => nr=7:
		 * x&MASCA -> 1011001 &
		 * 			  1000000
		 * 			 =1000000
		 * (x&MASCA)>>nr-1 -> 0000001 = 1 (in baza 10) => primul bit este 1
		 */
		putchar(c+'0'); //dupa ce am obtinut bit-ul, il afisam ca si caracter pe ecran, deci codul ASCII al lui '0', la care adunam bitul obtinut (1 sau 0)
		MASCA>>=1; //mutam masca cu o pozitie la dreapta, pentru a putea extrage urmatorul bit inspre dreapta din numarul x
		--nr; //decrementam numarul de biti (pozitia) ramasi de extras
	}
}
void impachetare(WORD z, WORD l, WORD a)
{
	WORD data=(WORD)0u; //cream un sir de biti de 0, care vor fi completati cu data calendaristica impachetata
	//conversie cast (WORD) la constanta 0u pentru a evita extensia de semn
	a-=1900; //scadem 1900 din an, pentru ca se numara incepand cu 1900
	data|=a; //facem SAU intre sirul de biti din data (momentan doar cu zerouri) si an, astfel incat pe ultimele 7 pozitii obtinem anul calendaristic
	data<<=4; //shiftam la stanga cu 4 pozitii pentru a "face loc" pentru luna, care ocupa 4 pozitii
	data|=l; //facem SAU intre sirul de biti din data (care are acum pe ultimele 4 pozitii zerouri) si luna, astfel incat vom obtine pe ultimele 4 pozitii luna
	data<<=5; //shiftam la stanga cu 5 pozitii pentru a "face loc" pentru zi, care ocupa 5 pozitii
	data|=z; //facem SAU intre sirul de biti din data (care are acum pe ultimele 5 pozitii zerouri) si zi, astfel incat vom obtine pe ultimele 5 pozitii ziua
	//in total 7 + 4 + 5 = 16 biti = 2 octeti = WORD = unsigned int
	afisareBinara(data); //afisam sirul de biti obtinut pe ecran
}
