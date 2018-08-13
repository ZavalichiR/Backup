/*
 * data.h
 *
 *  Created on: May 7, 2015
 *      Author: skynet
 */

#ifndef L10_T1_2_SRC_DATA_H_
#define L10_T1_2_SRC_DATA_H_

struct _DATA {
	int zi, luna, an, ziAn;
};

typedef struct _DATA DATA;

void conversie1(DATA *d);
void conversie2(DATA *d);

#endif /* L10_T1_2_SRC_DATA_H_ */
