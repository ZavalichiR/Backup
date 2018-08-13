/*
 * norme.h
 *
 *  Created on: May 14, 2015
 *      Author: skynet
 */

#ifndef SRC_NORME_H_
#define SRC_NORME_H_

struct _NORME {
	char *nume;
	double (*f)(double *, int);
};

typedef struct _NORME NORME;

void *xmalloc(size_t nrOcteti);
double* citireVector(int n);
void afisareVector(double *v, int n);
void meniu(NORME tab[], int nf, char *msg);
double n1(double *v, int n);
double n2(double *v, int n);
double ninf(double *v, int n);

#endif /* SRC_NORME_H_ */
