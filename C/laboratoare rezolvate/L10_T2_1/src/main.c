/*
 * main.c
 *
 *  Created on: May 9, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
int main(void)
{
	MATRICE mat;
	char *nume=0;
	mat=incarcareInformatii(nume);
	afisareMatrice(&mat);
	free(mat.nume);
	dealoca2d(mat.a, mat.n);
	return 0;
}
