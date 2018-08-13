/*
 * sir.c
 *
 *  Created on: Jun 2, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "sir.h"
void *xmalloc(size_t nrOcteti)
{
	void *p=0;
	p=malloc(nrOcteti);
	if (p==0)
	{
		fprintf(stderr, "Eroare la alocarea memoriei.\n");
		exit(EXIT_FAILURE);
	}
	return p;
}
