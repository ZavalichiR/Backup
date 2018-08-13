/*
 * header.c
 *
 *  Created on: Mar 27, 2015
 *      Author: student
 */
#include <stdio.h>
#include "header.h"
int putere(WORD n) //verifica daca un numar intreg fara semn este sau nu putere a lui 2
{
	/*putem face acest lucru cu operatorul SI intre numarul si valoarea sa -1
	 *numarul este putere a lui 2 daca are un singur bit de 1, deci este de forma 0001000=2^3=8
	 *																		  8-1=0000111
	 *																	  8&(8-1)=0000000=0, deci 8 este putere a lui 2
	 */
	if (n&(n-1)) //daca operatia logica SI intre numarul n si (n-1) returneaza ceva diferit de 0, adica adevarat
	{
		return 0; //numarul nu este putere a lui 2
	}
	else { //altfel, daca SI logic intre n si (n-1) returneaza 0 (ca in exemplul de mai sus)
		return 1; //atunci numarul este putere a lui 2
	}
}
int inversare(S_WORD n) //inverseaza cei 2 octeti ai unui numar intreg scurt fara semn
{
	S_WORD n1, n2;
	/*n1 reprezinta primul octet al numarului (cei 8 biti din stanga)
	 *n2 este al doilea octet al numarului (restul de 8 biti din dreapta)
	 */
	n1=n<<((sizeof(n)<<3)/2);
	/*shiftam numarul n cu 8 pozitii la stanga
	 * sizeof(n)<<3 va returna 16 biti = 2 octeti * 8
	 * (sizeof(n)<<3)/2 = 8 pozitii de shiftat
	 * n = b15 b14 b13 b12 b11 b10 b9 b8 b7 b6 b5 b4 b3 b2 b1 b0
	 * dupa aceasta operatie, numarul n1 va arata astfel:
	 * b7 b6 b5 b4 b3 b2 b1 b0 0 0 0 0 0 0 0 0
	 * ^					^
	 * |					|
	 * 	   AL DOILEA OCTET (mutat practic in locul primului octet)
	 */
	n2=n>>((sizeof(n)<<3)/2);
	/*shiftam numarul n cu 8 pozitii la dreapta
	 * sizeof(n)<<3 va returna 16 biti = 2 octeti * 8
	 * (sizeof(n)<<3)/2 = 8 pozitii de shiftat
	 * n = b15 b14 b13 b12 b11 b10 b9 b8 b7 b6 b5 b4 b3 b2 b1 b0
	 * dupa aceasta operatie, numarul n1 va arata astfel:
	 * 0 0 0 0 0 0 0 0 b15 b14 b13 b12 b11 b10 b9 b8
	 * 					^						  ^
	 * 					|						  |
	 * 	   						PRIMUL OCTET (mutat practic in locul celui de al doilea)
	 */
	n=n1|n2;
	//facem operatia logica SAU intre cele 2 "parti" de octeti
	/*
	 * practic, operatia se desfasoara astfel:
	 * b7 b6 b5 b4 b3 b2 b1 b0 0   0   0   0   0   0   0  0  |
	 * 0  0  0  0  0  0  0  0  b15 b14 b13 b12 b11 b10 b9 b8
	 * -----------------------------------------------------
	 * b7 b6 b5 b4 b3 b2 b1 b0 b15 b14 b13 b12 b11 b10 b9 b8
	 * am obtinut astfel octetii inversati intre ei
	 */
	return n;
}
int asociere(int v[], int n) //asociaza elementelor vectorului v de dimensiune n, un sir de biti de paritate, conform paritatii fiecarui element
{
	WORD b=(WORD)0; //sirul de biti porneste de la 0
	int i; //i este indicele elementului curent din vectorul v
	for (i=0; i<n; ++i) //parcurgem elementele vectorului v
	{
		/*
		 * un numar este impar daca ultimul bit din reprezentarea sa binara este 1
		 * exemplu: 1001 = 9 este numar impar
		 * pentru a verifica, facem SI logic intre bitii numarului si un bit de 1
		 * 1001 &
		 * 0001
		 * ----
		 * 0001 = 1 , diferit de 0, deci numarul este impar
		 * numerele pare au OBLIGATORIU ultimul bit egal cu 0!
		 */
		if (v[i]&1) //daca elementul curent din vector este impar (adica operatia SI logic intre bitii numarului si 1 returneaza ceva diferit de 0)
		{
			//inseamna ca numarul este impar, si deci punem in sirul de biti format un bit de 0
			b|=0;
		}
		else { //daca elementul curent din vector este par (adica operatia SI logic intre bitii numarului si 1 returneaza 0)
			//inseamna ca numarul este par, si deci punem in sirul de biti format un bit de 1
			b|=1;
		}
		if (i!=n-1) //daca am ajuns la ultimul element si l-am procesat, NU trebuie sa mai shiftam sirul de biti cu o pozitie, pentru ca ar rezulta un bit de 0 in plus
		{
			b<<=1; //shiftam sirul de biti cu o pozitie la stanga pentru a "face loc" pentru bitul urmator, corespunzator urmatorului element din vector
		}
	}
	return b;
}
void afisareBinara(WORD x) //afiseaza toti bitii unui numar intreg fara semn
{
	WORD nr=sizeof(WORD)<<3; //nr reprezinta numarul de biti al tipului respectiv de data; sizeof() returneaza numarul de bytes, deci trebuie inmultit cu 8 = 2^3 (shiftare la stanga cu 3 pozitii) pentru a afla numarul de biti
	//incepem sa construim masca pentru extragerea fiecarui bit (de la stanga, adica de la MSB, la dreapta, adica inspre LSB)
	WORD MASCA=(WORD)0; //MASCA->000...0 (conversie cast la WORD, pentru a nu considera constanta 0 ca si avand semn, pentru evitarea extensiei de semn
	MASCA=~MASCA; //MASCA->111...1
	MASCA=MASCA>>1; //MASCA->011...1
	MASCA=~MASCA; //MASCA->100...0

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
void citireVector(int v[], int n) //citeste un vector de intregi v de la tastatura, de dimensiune n
{
	int i;
	for (i=0; i<n; ++i)
	{
		printf("v[%d]=", i);
		scanf("%d", &v[i]);
	}
}
