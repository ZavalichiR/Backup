/*
 * punct.h
 *
 *  Created on: Apr 3, 2015
 *      Author: student
 */

#ifndef PUNCT_H_
#define PUNCT_H_

struct _PUNCT //declaram o structura de tip "punct" care are in componenta 2 numere reale, reprezentand abscisa si ordonata unui punct din plan
{
	double x; //abscisa
	double y; //ordonata
};

typedef struct _PUNCT PUNCT; //cream un sinonim pentru structura _PUNCT, pentru a putea declara mai usor variabile
//dupa aceasta operatie, putem scrie "PUNCT a;", astfel incat aceasta instructiune se traduce: "struct _PUNCT a;"

/*
 * DUPA declararea unei variabile de tip PUNCT, in memoria RAM, aceasta se retine astfel:
 *
 *  _________________
 * |        |		 |
 * |  p1.x  |  p1.y  | --> memoria se "partitioneaza" in "blocuri" de atatea variabile cate exista in structura, care ocupa un anume spatiu, cat indica tipul acestora
 * |________|________|
 * 		 PUNCT p1; -> in acest caz, se aloca in memorie un bloc de 2 variabile reale "double", care sunt asociate unui bloc "mare", al variabilei "p1", care este de tip _PUNCT
 *
 */

/*
 * daca dorim sa declaram un VECTOR de structuri, putem face astfel:
 * PUNCT v[20];
 * semnificatia acestei instructiuni este asemanatoare cu crearea unui vector de tip intreg, real, etc.
 * se aloca, in memorie, spatiu pentru 20 de variabile de tip "PUNCT"
 * sa presupunem ca am declarat variabila v ca vector de structuri PUNCT, astfel:
 * PUNCT v[3];
 * in memoria RAM, s-a intamplat urmatorul "fenomen":
 *
 * 				  ordonata
 * 			    primului punct ... etc
 * 		  abscisa     |
 * 	   primului punct |
 *           |        |
 * 		 _________________  _________________  _________________
 * 	 -->|        |		  ||        |		 ||        |		|
 * 	v|  | v[0].x | v[0].y || v[1].x | v[1].y || v[2].x | v[2].y |
 * 	 -->|________|________||________|________||________|________|
 *
 * 	 	^-----------------^^-----------------^^-----------------^
 * 	 		    v[0]			  v[1]               v[2]
 * 	 			 ^				    ^				   ^
 * 	 			 |					|				   |
 * 	 			 |					|				   |
 * 	 		primul punct	 al doilea punct	 al treilea punct
 *
 * fiecare element al vectorului, v[i], este o structura de tip PUNCT, care are abscisa (v[i].x) si ordonata (v[i].y)
 */


void citire(int n, PUNCT v[], FILE *f);
void afisare(int n, PUNCT v[]);
double distanta(PUNCT a, PUNCT b);
double semiperimetru(PUNCT a, PUNCT b, PUNCT c);
double ariaTriunghi(PUNCT a, PUNCT b, PUNCT c);
double perimetru(int n, PUNCT v[]);
double ariaTotala(int n, PUNCT v[]);

#endif /* PUNCT_H_ */
