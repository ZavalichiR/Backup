/*
 * trioda.h
 *
 *  Created on: Apr 14, 2015
 *      Author: skynet
 */

#ifndef SRC_TRIODA_H_
#define SRC_TRIODA_H_

void citireVector_intregi(FILE *in, int a[], unsigned int n);
void citireVector_reali(FILE *in, double a[], unsigned int n);
void afisareVector_intregi(int a[], unsigned int n);
void afisareVector_reali(double a[], unsigned int n);
void sumaVectori(int v1[], int v2[], int suma[], unsigned int n);
void sumaVectori_reali(double v1[], double v2[], double suma[], unsigned int n);
void inmultireVectori(int v1[], double v2[], double inmultire[], unsigned int n);
void vectorScalar(double a[], double v_scalar[], unsigned int n, double scalar);
double suma2Vectori(double v1[], double v2[], unsigned int n);

#endif /* SRC_TRIODA_H_ */
