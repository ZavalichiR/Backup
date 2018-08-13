#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "sem.h"

int main(void)
{
	int descriptor, i;
	char buf[16];
	int j;
	if ((descriptor=open("f.txt", O_CREAT | O_TRUNC | O_WRONLY, 0666))<0) //cream fisierul pentru scriere
	{
		err_sys("Eroare open");
	}
	
	if (fork()==0) //cream primul fiu
	{
		//cod executat in procesul fiu
		int pid=getpid();
		sprintf(buf, "%d", pid);
		strcat(buf, "\n");
		for (i=0; i<3; ++i)//pentru a afisa de 3 ori in fisier
		{
			P("sem.txt"); //blocam fisierul pentru scriere folosind fisierul semafor "sem.txt"
			if (write(descriptor, buf, sizeof(char)*strlen(buf))<0) //scriem in fisier
			{
				err_sys("Eroare write");
			}
			V("sem.txt"); //deblocam fisierul pentru scriere folosind fisierul semafor "sem.txt"
		}
		exit(1);
	}


	if (fork()==0) //cream al doilea fiu
	{
		//cod executat in procesul fiu
		int pid=getpid();
		sprintf(buf, "%d", pid);
		strcat(buf, "\n");
		for (i=0; i<3; ++i) // pentru a afisa de 3 ori in fisier
		{
			P("sem.txt"); //blocam fisierul pentru scriere folosind fisierul semafor "sem.txt"
			if (write(descriptor, buf, sizeof(char)*strlen(buf))<0)
			{
				err_sys("Eroare write");
			}
			V("sem.txt"); //deblocam fisierul pentru scriere folosind fisierul semafor "sem.txt"
		}
		exit(1);
	}

//Procesul TATA (diferenta consta in faptul ca nu avem fork() )
		int pid=getpid();
		sprintf(buf, "%d", pid);
		strcat(buf, "\n");
		for (i=0; i<=2; ++i)
		{
			P("sem.txt"); //blocam fisierul pentru scriere folosind fisierul semafor "sem.txt"
			if (write(descriptor, buf, sizeof(char)*strlen(buf))<0) //scriem in fisier
			{
				err_sys("Eroare write");
			}
			V("sem.txt"); //deblocam fisierul pentru scriere folosind fisierul semafor "sem.txt"
		}

return 0;
}
