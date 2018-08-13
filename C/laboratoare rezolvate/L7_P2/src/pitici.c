/*
 * pitici.c
 *
 *  Created on: Apr 3, 2015
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include "pitici.h"

PUNCT citire_punct(FILE *f)
{
	PUNCT x;
	fscanf(f, "%lf %lf", &x.x, &x.y);
	return x;
}
PITICI citire_pitici(FILE *f)
{
	PITICI p;
	fscanf(f, "%u", &p.n);
	p.casute=(PUNCT*)malloc(sizeof(PUNCT)*p.n);
	if (p.casute==0)
	{
		fprintf(stderr, "Eroare la alocarea memoriei pentru citirea casutelor piticilor!\n");
		exit(EXIT_FAILURE);
	}
	int i;
	for (i=0; i<p.n; ++i)
	{
		p.casute[i]=citire_punct(f);
	}
	return p;
}
void afisare_pitici(PITICI p)
{
	int i;
	printf("\t");
	for (i=0; i<p.n; ++i)
	{
		printf("(%.1lf, %.1lf)\t", p.casute[i].x, p.casute[i].y);
	}
}
void procesare_poteci(FILE *f_in, FILE *f_out, PITICI vp1, PITICI vp2)
{
	int k, i;
	double a, b, c;
	PUNCT p1, p2;
	fscanf(f_in, "%d", &k);
	for (i=1; i<=k; ++i)
	{
		fscanf(f_in, "%lf", &p1.x);
		fscanf(f_in, "%lf", &p1.y);
		fscanf(f_in, "%lf", &p2.x);
		fscanf(f_in, "%lf", &p2.y);
		a=p1.y-p2.y;
		b=p2.x-p1.x;
		c=p1.x*p2.y-p1.y*p2.x;
		int semn1, semn2, invalid=0;
		double fxy;
		fxy=a*vp1.casute[0].x+b*vp1.casute[0].y+c;
		if (fxy==0)
		{
			invalid=1;
			//continue;
		}
		else if (fxy<0)
		{
			semn1=-1;
		}
		else {
			semn1=1;
		}
		int j;
		for (j=1; j<vp1.n; ++j)
		{
			fxy=a*vp1.casute[j].x+b*vp1.casute[j].y+c;
			if (fxy==0 || fxy*semn1<0)
			{
				invalid=1;
				j=vp1.n;
			}
		}
		fxy=a*vp2.casute[0].x+b*vp2.casute[0].y+c;
		if (fxy==0)
		{
			invalid=1;
			//continue;
		}
		else if (fxy<0)
		{
			semn2=-1;
		}
		else {
			semn2=1;
		}
		for (j=1; j<vp2.n; ++j)
		{
			fxy=a*vp2.casute[j].x+b*vp2.casute[j].y+c;
			if (fxy==0 || fxy*semn2<0)
			{
				invalid=1;
				j=vp2.n;
			}
		}
		if (invalid)
		{
			fprintf(f_out, "NU - Sfetnicul %d a dat o solutie invalida\n", i);
		}
		else if (semn1*semn2<0)
		{
			fprintf(f_out, "DA - Sfetnicul %d a dat o solutie valida\n", i);
		}
	}
}
