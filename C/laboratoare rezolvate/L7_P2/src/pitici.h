/*
 * pitici.h
 *
 *  Created on: Apr 3, 2015
 *      Author: student
 */
#ifndef PITICI_H_
#define PITICI_H_


struct _PUNCT
{
	double x; //abscisa
	double y; //ordonata
};

typedef struct _PUNCT PUNCT;

struct _PITICI
{
	unsigned int n;
	PUNCT *casute;
};

typedef struct _PITICI PITICI;

PITICI citire_pitici(FILE *f);
PUNCT citire_punct(FILE *f);
void afisare_pitici(PITICI p);
void procesare_poteci(FILE *f_in, FILE *f_out, PITICI vp1, PITICI vp2);

#endif /* PITICI_H_ */
