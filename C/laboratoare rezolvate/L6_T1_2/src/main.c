/*
 * main.c
 *
 *  Created on: Mar 27, 2015
 *      Author: student
 */
#include <stdio.h>
#include "header.h"
int main(void)
{
	WORD x; //il folosim pentru cerintele 1 si 3 (variabila de tip unsigned int, deci cu 4 octeti)
	S_WORD y; //il folosim pentru cerinta 2 (variabila de tip unsigned short int, deci cu 2 octeti)
	int v[32], n, op, rel;
	WORD biti;
	do { //afisam meniul pentru utilizator
		printf("Alegeti o optiune:\n1.VERIFICARE PUTERE A LUI 2\n2.INVERSARE OCTETI\n3.ASOCIERE VECTOR DE PARITATE\n");
		scanf("%d", &op); //citim optiunea dorita de utilizator
		if (op==1) //daca a introdus 1
		{
			printf("Introduceti numarul: ");
			scanf("%u", &x); //citim numarul pentru verificat
			if (putere(x)) //verificam daca acesta este sau nu putere a lui 2 (functia putere() creata returneaza 1 sau 0 in acest sens)
			{
				printf("%u este putere a lui 2.\n", x);
			}
			else {
				printf("%u nu este putere a lui 2.\n", x);
			}
		}
		else if (op==2) //daca a introdus 2
		{
			printf("Introduceti numarul: ");
			scanf("%hu", &y); //citim numarul intreg scurt fara semn de la tastatura
			afisareBinara(y); //il afisam in starea sa initiala, bit cu bit
			printf("\n");
			y=inversare(y); //inversam cei 2 octeti ai sai folosind functia inversare() creata, si depunem rezultatul in aceeasi variabila y
			printf("Numarul cu cei 2 octeti inversati: %hu\n", y);
			afisareBinara(y); //afisam numarul din nou, bit cu bit, de aceasta data cu octetii inversati
			printf("\n");
		}
		else if (op==3) //daca a introdus 3
		{
			printf("n=");
			scanf("%d", &n); //citim numarul de elemente din vector
			citireVector(v, n); //citim elementele vectorului v, de dimensiune n
			biti=asociere(v, n); //inseram sirul de biti corespunzator acestui vector in variabila "biti", apeland functia asociere() creata
			afisareBinara(biti); //afisam numarul astfel format, bit cu bit
			printf("\n");
		}
		else { //daca nu a introdus una din cele 3 optiuni disponibile
			printf("Introduceti o optiune valida!\n"); //afisam eroare
		}
		printf("Reluati programul? (DA=1, NU=0) ");
		scanf("%d", &rel); //cerem utilizatorului sa introduca in variabila "rel" optiunea de a relua sau nu programul
	} while (rel==1); //codul se executa in bucla atat timp cat utilizatorul a introdus 1 in variabila "rel"
	return 0;
}
