/*
 * main.c
 *
 *  Created on: Apr 3, 2015
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include "pitici.h"

int main(void)
{
	FILE *pitici_in, *pitici_out;
	pitici_in=fopen("PITICI.IN", "r");
	if (pitici_in==0)
	{
		fprintf(stderr, "Eroare la deschiderea fisierului \"PITICI.IN\"!\n");
		exit(EXIT_FAILURE);
	}
	pitici_out=fopen("PITICI.OUT", "w");
	if (pitici_out==0)
	{
		fprintf(stderr, "Eroare la deschiderea fisierului \"PITICI.OUT\"!\n");
		exit(EXIT_FAILURE);
	}
	PITICI r, a;
	r=citire_pitici(pitici_in);
	printf("Casutele piticilor cu scufii rosii se gasesc la urmatoarele coordonate:\n");
	afisare_pitici(r);
	a=citire_pitici(pitici_in);
	printf("\nCasutele piticilor cu scufii albastre se gasesc la urmatoarele coordonate:\n");
	afisare_pitici(a);
	printf("\n");
	procesare_poteci(pitici_in, pitici_out, r, a);
	fclose(pitici_in);
	fclose(pitici_out);
	return 0;
}
