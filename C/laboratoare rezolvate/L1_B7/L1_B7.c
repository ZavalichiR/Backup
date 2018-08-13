/*
 * L1_B7.c
 *
 *  Created on: Apr 14, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <math.h>
int main(void)
{
    int n, p, r;
    double x, rezultat;
    printf("x=");
    scanf("%lf", &x); //citim x
    printf("n=");
    scanf("%d", &n); //citim n
    printf("%lf^%d=", x, n); //afisam initial un mesaj de tipul x^n=
    p=1; //pornim cu puterea de la 1
    rezultat=1; //initializam rezultatul cu 1, deoarece vom face inmultiri folosindu-l
    while (n) //cat timp puterea n este diferita de 0
    {
        r=n%2; //restul impartirii puterii n la 2 reprezinta un bit de 1 sau un bit de 0, precum se imparte sau nu la 2
        n/=2; //impartim acea putere la 2
        if (r) //daca restul este 1 (adica ultimul bit al lui n este 1)
        {
        	rezultat*=pow(x,p); //inmultim rezultatul obtinut anterior cu puterea p a numarului x
        }
        p*=2; //crestem puterea p conform puterilor lui 2 din reprezentarea binara a lui n
    }
    printf("%lf\n", rezultat); //afisam rezultatul
    return 0;
}
