//problema producator-consumator
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>
#include "hdr.h"

#define SEMPERM 0600 //permisiunile asupra semafoarelor
#define N 3 //numarul de semafoare
#define BUFFMAX 4 //dimensiunea buffer-ului

key_t semkey=0x700;
key_t shmkey=0x800;

struct databuf {
	int nr_prod; //nr de producatori
	int nextin; //urmatoarea pozitie de produs
	int nextout; //urmatoarea pozitie de consumat
	char d_buff[BUFFMAX]; //bufferul de date
};

typedef enum {
	spacesleft, itemsready, mutex //cele 3 semafoare
	//spatii libere ramase in buffer (indice 0)
	//spatii ocupate, gata de consumat din buffer (indice 1)
	//semaforul de excludere mutuala (indice 2)
} semaphore;

void P(int semid, int name) //blocheaza resursa = intra in regiunea critica
{
	struct sembuf pbuf; //pbuf = structura de tip sembuf folosita de semop(), care defineste optiunile operatiei efectuate
	pbuf.sem_num=name; //numarul semaforului (indicele) asupra caruia se opereaza
	pbuf.sem_op=-1; //decrementeaza semaforul cu 1
	pbuf.sem_flg=SEM_UNDO; //SEM_UNDO pozitionat, atunci |sem_op| este adunat la semadj corespondent semaforului in tabela asociata in proces pentru setul de semafoare
	if (semop(semid, &pbuf, 1)) //operam asupra setului de semafoare cu id-ul "semid", folosind structura de optiuni "pbuf", facand "1" operatii asupra setului de semafoare
	{
		err_sys("Eroare semop");
	}
}
void V(int semid, int name) //deblocheaza resursa = iesi din regiunea critica
{
	struct sembuf vbuf; //vbuf = structura de tip sembuf folosita de semop(), care defineste optiunile operatiei efectuate
	vbuf.sem_num=name; //numarul semaforului (indicele) asupra caruia se opereaza
	vbuf.sem_op=1; //incrementeaza semaforul cu 1
	vbuf.sem_flg=SEM_UNDO; //SEM_UNDO pozitionat, atunci |sem_op| este adunat la semadj corespondent semaforului in tabela asociata in proces pentru setul de semafoare
	if (semop(semid, &vbuf, 1)) //operam asupra setului de semafoare cu id-ul "semid", folosind structura de optiuni "pbuf", facand "1" operatii asupra setului de semafoare
	{
		err_sys("Eroare semop");
	}
}

void afis(char* p, int l1, int l2) //afiseaza caracterele din buffer intre limitele l1 si l2
{
	int i;
	for (i=l1; i<l2+1; (++i)%(BUFFMAX+1))
	{
		putchar(p[i]);
	}
	putchar('\n');
}