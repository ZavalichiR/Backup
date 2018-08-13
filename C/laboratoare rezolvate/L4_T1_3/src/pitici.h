/*
 * pitici.h
 *
 *  Created on: Apr 16, 2015
 *      Author: skynet
 */

#ifndef SRC_PITICI_H_
#define SRC_PITICI_H_

void citire(FILE *fisier, double x[][30], int d1, int d2);
void afisare(FILE *fisier, double x[][30], int d1, int d2);
void suma(double x[][30], double y[][30], double s[][30], int x1, int x2, int y1, int y2);
void produs(double x[][30], double y[][30], double p[][30], int x1, int x2, int y1, int y2);
void transpunere(double x[][30], double t[][30], int n, int m);
void zile_munca(FILE *fisier, double p[][30], int n, double G);

#endif /* SRC_PITICI_H_ */
