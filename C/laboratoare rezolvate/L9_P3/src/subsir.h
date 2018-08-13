/*
 * subsir.h
 *
 *  Created on: Jun 2, 2015
 *      Author: skynet
 */

#ifndef SRC_SUBSIR_H_
#define SRC_SUBSIR_H_

#define L 50

void *xmalloc(size_t nrOcteti);
char *substr(char *sir, int start, int stop);
char *str(char *sir, int start, int nr_car);
int citireText(char *text[], int lmax);
void afisareText(char *text[], int nl);
void eliberareMemorie(char *text[], int nl);

#endif /* SRC_SUBSIR_H_ */
