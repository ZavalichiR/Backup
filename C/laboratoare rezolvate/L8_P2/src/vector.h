/*
 * vector.h
 *
 *  Created on: Apr 10, 2015
 *      Author: student
 */

#ifndef VECTOR_H_
#define VECTOR_H_

typedef unsigned int UI;

UI *xmalloc(UI n);
UI *citireVector(UI n);
void afisareVector(UI *v, UI n);
UI sumaCifre(UI x);
UI maxim(UI *v, UI n);
UI *vectorSumaCifre(UI *v, UI n);


#endif /* VECTOR_H_ */
