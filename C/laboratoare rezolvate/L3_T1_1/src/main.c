/*
 * main.c
 *
 *  Created on: Apr 14, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "meteo.h"
int main(void)
{
    FILE *out; //declaram un fisier de iesire, in variabila de tip pointer "out"
    out=fopen("raport.dat", "w"); //citim efectiv fisierul de pe disc, folosind functia fopen(); fisierul raport.dat va fi folosit pentru scriere, deci al doilea parametru va fi "w" ("write")
    if (out==0) //daca fopen returneaza 0, adica citirea fisierului de pe disc a esuat, afisam eroare
    {
        fprintf(stderr, "Eroare la deschiderea fisierului raport.dat!");
        exit(EXIT_FAILURE); //iesim din program, deoarece nu putem afisa niciun rezultat daca fisierul de iesire nu s-a putut deschide
    }
    char luna[15];
    int temp[30], nr_zile;
    int maxim, minim;
    double medie_a, medie_g;
    printf("Introduceti luna: ");
    fgets(luna, 14, stdin); //citim luna, sir de maxim 14 caractere (deci numele lunii + \n (ENTER) )
    luna[strlen(luna)-1]='\0'; //stergem ENTER-ul apasat, inlocuindu-l cu \0, pe penultima pozitie in sirul de caractere luna, deci sirul va arata asa: <nume_luna>\0\0
    //am sters \n-ul pentru a nu adauga acea linie noua la afisarea in fisier
    printf("Introduceti numarul de zile: ");
    scanf("%d", &nr_zile); //citim numarul de zile = numarul de temperaturi ce trebuie introduse
    printf("Introduceti temperaturile masurate:\n");
    citireVector(temp, nr_zile); //apelam functia citireVector(), care citeste temperaturile, in numar de nr_zile, si le depune in vectorul temp[]
    //incepem sa scriem raportul in fisierul raport.dat, linie cu linie
    fprintf(out, "Raport de temperatura pentru ultimele %d zile din luna %s.", nr_zile, luna);
    fprintf(out, "\nTemperaturile citite sunt: ");
    afisareVector(out, temp, nr_zile); //apelam functia afisareVector, care scrie in fisier, pe rand, temperaturile, pe o linie
    maxim=maxVector(temp, nr_zile); //calculam maximul temperaturilor citite
    fprintf(out, "\tValoarea maxima a temperaturii este: %d.", maxim);
    minim=minVector(temp, nr_zile); //calculam minimul temperaturilor citite
    fprintf(out, "\n\tValoarea minima a temperaturii este: %d.", minim);
    medie_a=medieAritmVector(temp, nr_zile); //calculam media temperaturilor citite
    fprintf(out, "\n\tValoarea medie a temperaturii este: %.3lf.", medie_a);
    medie_g=medieGeomVector(temp, nr_zile); //calculam media geometrica a temperaturilor citite
    fprintf(out, "\n\tMedia geometrica a temperaturilor este: %.4lf.\n\n\n", medie_g);
    fprintf(out, "Final raport.");
    fclose(out); //dupa ce terminam de lucrat cu fisierul, acesta trebuie obligatoriu inchis
    return 0;
}
