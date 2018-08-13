/*
 * matrice.h
 *
 *  Created on: Apr 15, 2015
 *      Author: skynet
 */

#ifndef SRC_MATRICE_H_
#define SRC_MATRICE_H_

void citire(FILE *fisier, double x[][20], int d1, int d2);
void afisare(double x[][20], int d1, int d2);
void suma(double x[][20], double y[][20], int x1, int x2, int y1, int y2);
void produs(double x[][20], double y[][20], int x1, int x2, int y1, int y2);

#endif /* SRC_MATRICE_H_ */
