/*
 * linii.h
 *
 *  Created on: Jun 3, 2015
 *      Author: skynet
 */

#ifndef SRC_LINII_H_
#define SRC_LINII_H_

#define L 50
#define YES 1
#define NO 0

void *xmalloc(size_t nrOcteti);
int citireText(FILE *in, char *text[], int lmax);
void afisareText(char *text[], int start, int stop);
void eliberareMemorie(char *text[], int nl);

#endif /* SRC_LINII_H_ */
