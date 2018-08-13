/*
 * multimi.c
 *
 *  Created on: Apr 10, 2015
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include "multimi.h"
void* xmalloc(size_t nrOcteti)
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
MULTIME citireMultime(char nume)
{
	MULTIME multime;
	printf("card(%c)=", nume);
	scanf("%u", &multime.n);
	multime.nume=nume;
	printf("Dati elementele multimii %c:\n", nume);
	multime.elemente=(double *)xmalloc(sizeof(double)*multime.n);
	if (multime.elemente==0)
	{
		fprintf(stderr, "Eroare la alocarea memoriei!\n");
		exit(EXIT_FAILURE);
	}
	UI i;
	for (i=0; i<multime.n; ++i)
	{
		printf("Elementul %u: ", i+1);
		scanf("%lf", multime.elemente+i);
	}
	return multime;
}
void afisareMultime(MULTIME m)
{
	int i;
	printf("%c={", m.nume);
	for (i=0; i<m.n; ++i)
	{
		printf("%.2lf%c%c", *(m.elemente+i), (i==m.n-1)?'}':',', (i==m.n-1)?'\n':' ');
	}
}
UI alegeMeniu()
{
	UI alegere;
	printf("\nAlegeti o optiune:\n1.INTERSECTIE\n2.DIFERENTA SIMETRICA\n3.REUNIUNEA\n");
	scanf("%u", &alegere);
	return alegere;
}
UI apartineMultime(double val, MULTIME m)
{
	UI ok;
	UI i;
	ok=0;
	for (i=0; i<m.n; ++i)
	{
		if (*(m.elemente+i)==val)
		{
			ok=1;
			break;
		}
	}
	return ok;
}
MULTIME intersectie(MULTIME m1, MULTIME m2)
{
	MULTIME m_int;
	UI min;
	if (m1.n<=m2.n)
	{
		min=m1.n;
	}
	else {
		min=m2.n;
	}
	double *aux=0;
	aux=(double*)xmalloc(sizeof(double)*min);
	if (aux==0)
	{
		fprintf(stderr, "Eroare la alocarea memoriei!\n");
		exit(EXIT_FAILURE);
	}
	UI i, k;
	k=0;
	if (min==m1.n)
	{
		for (i=0; i<min; ++i)
		{
			if (apartineMultime(*(m1.elemente+i), m2))
			{
				*(aux+k)=*(m1.elemente+i);
				++k;
			}
		}
	}
	else {
		for (i=0; i<min; ++i)
		{
			if (apartineMultime(*(m2.elemente+i), m1))
			{
				*(aux+k)=*(m2.elemente+i);
				++k;
			}
		}
	}
	m_int.n=k;
	m_int.elemente=(double*)xmalloc(sizeof(double)*k);
	if (m_int.elemente==0)
	{
		fprintf(stderr, "Eroare la alocarea memoriei!\n");
		exit(EXIT_FAILURE);
	}
	for (i=0; i<k; ++i)
	{
		*(m_int.elemente+i)=*(aux+i);
	}
	m_int.nume='I';
	free(aux);
	aux=0;
	return m_int;
}
MULTIME diferentaSimetrica(MULTIME m1, MULTIME m2)
{
	MULTIME ds;
	MULTIME inters=intersectie(m1, m2);
	double *aux=0;
	aux=(double*)xmalloc((m1.n+m2.n)*sizeof(double));
	int i, k;
	k=0;
	for (i=0; i<m1.n; ++i)
	{
		if (!apartineMultime(*(m1.elemente+i), inters))
		{
			*(aux+k)=*(m1.elemente+i);
			++k;
		}
	}
	for (i=0; i<m2.n; ++i)
	{
		if (!apartineMultime(*(m2.elemente+i), inters))
		{
			*(aux+k)=*(m2.elemente+i);
			++k;
		}
	}
	ds.n=k;
	ds.nume='D';
	ds.elemente=(double*)xmalloc(k*sizeof(double));
	for (i=0; i<k; ++i)
	{
		*(ds.elemente+i)=*(aux+i);
	}
	free(aux);
	aux=0;
	return ds;
}
MULTIME reuniune(MULTIME m1, MULTIME m2)
{
	MULTIME r;
	double *aux=0;
	aux=(double*)xmalloc((m1.n+m2.n)*sizeof(double));
	int i, k;
	k=0;
	for (i=0; i<m1.n; ++i)
	{
		*(aux+k)=*(m1.elemente+i);
		++k;
	}
	for (i=0; i<m2.n; ++i)
	{
		if (!apartineMultime(*(m2.elemente+i), m1))
		{
			*(aux+k)=*(m2.elemente+i);
			++k;
		}
	}
	r.n=k;
	r.nume='R';
	r.elemente=(double*)xmalloc(k*sizeof(double));
	for (i=0; i<k; ++i)
	{
		*(r.elemente+i)=*(aux+i);
	}
	free(aux);
	aux=0;
	return r;
}
