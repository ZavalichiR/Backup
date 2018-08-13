/*
 * multimi.h
 *
 *  Created on: Apr 10, 2015
 *      Author: student
 */

#ifndef MULTIMI_H_
#define MULTIMI_H_

typedef unsigned int UI;

struct _MULTIME {
	char nume;
	UI n;
	double *elemente;
};

typedef struct _MULTIME MULTIME;

void* xmalloc(size_t nrOcteti);
MULTIME citireMultime(char nume);
void afisareMultime(MULTIME m);
UI alegeMeniu();
UI apartineMultime(double val, MULTIME m);
MULTIME intersectie(MULTIME m1, MULTIME m2);
MULTIME diferentaSimetrica(MULTIME m1, MULTIME m2);
MULTIME reuniune(MULTIME m1, MULTIME m2);

#endif /* MULTIMI_H_ */
