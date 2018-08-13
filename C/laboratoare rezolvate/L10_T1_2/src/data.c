/*
 * data.c
 *
 *  Created on: May 7, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "data.h"

void conversie1(DATA *d)
{
	int nr_zile[]={31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	printf("Ziua din luna: ");
	scanf("%d", &(d->zi));
	printf("Luna: ");
	scanf("%d", &(d->luna));
	printf("Anul: ");
	scanf("%d", &(d->an));
	if (d->an%4==0)
	{
		nr_zile[1]=29;
	}
	else {
		nr_zile[1]=28;
	}
	d->ziAn=0;
	int i;
	for (i=0; i<d->luna-1; ++i)
	{
		d->ziAn+=*(nr_zile+i);
	}
	d->ziAn+=d->zi;
}
void conversie2(DATA *d)
{
	int nr_zile[]={31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	printf("Ziua din an: ");
	scanf("%d", &(d->ziAn));
	printf("Anul: ");
	scanf("%d", &(d->an));
	if (d->an%4==0)
	{
		nr_zile[1]=29;
	}
	else {
		nr_zile[1]=28;
	}
	int i, nrz;
	i=0;
	nrz=d->ziAn-nr_zile[i];
	while (nrz>=0)
	{
		nrz-=nr_zile[i];
		++i;
	}
	d->zi=nrz+nr_zile[i-1];
	d->luna=i+1;
}
