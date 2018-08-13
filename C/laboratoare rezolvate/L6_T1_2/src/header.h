/*
 * header.h
 *
 *  Created on: Mar 27, 2015
 *      Author: student
 */

#ifndef HEADER_H_
#define HEADER_H_

typedef unsigned int WORD; //folosim WORD pentru un numar natural pe 4 octeti (cerintele 1 si 3)
typedef unsigned short int S_WORD; //folosim S_WORD pentru un numar natural pe 2 octeti (cerinta 2)

int putere(WORD n);
int inversare(S_WORD n);
int asociere(int v[], int n);
void afisareBinara(WORD x);
void citireVector(int v[], int n);

#endif /* HEADER_H_ */
