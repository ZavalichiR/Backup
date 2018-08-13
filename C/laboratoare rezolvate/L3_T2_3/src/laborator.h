/*
 * laborator.h
 *
 *  Created on: Apr 15, 2015
 *      Author: skynet
 */

#ifndef SRC_LABORATOR_H_
#define SRC_LABORATOR_H_

int citesteVector(FILE *in, double a[]);
void scrieVector(FILE *out, double a[], int n);
int rezolvare_sistem(double a[6], double s[2]);
double produs_scalar(double v1[], double v2[], int n);

#endif /* SRC_LABORATOR_H_ */
