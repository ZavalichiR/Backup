/*
 * pointeri.h
 *
 *  Created on: Jun 15, 2015
 *      Author: skynet
 */

#ifndef SRC_POINTERI_H_
#define SRC_POINTERI_H_

void* xmalloc(size_t nrOcteti);
int* citesteVector(int n);
void afiseazaVector(int *v, int n);
double **alocaMemorieMatrice(int n, int m);
void elibereazaMemorieMatrice(double **a, int n);
double** citesteMatrice(int n, int m);
void afiseazaMatrice(double **a, int n, int m);

#endif /* SRC_POINTERI_H_ */
