/*
 * nrcuvinte.c
 *
 *  Created on: Jun 3, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "nrcuvinte.h"
void eroare(char *numeP, char *par, char *er)
{
	fprintf(stderr, "%s: Eroare - \'%s\' %s\n", numeP, par, er);
	fprintf(stderr, "Utilizare corecta: %s [-l] [-w] [-c] < textfile\n", numeP);
	exit(EXIT_FAILURE);
}

