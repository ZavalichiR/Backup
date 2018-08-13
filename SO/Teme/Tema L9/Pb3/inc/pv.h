#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include "hdr.h"
#define SEMPERM 0600 //permisiunile ce vor fi setate asupra semaforului creat

void P(int semid) //blocheaza resursa = intra in regiunea critica
{
	struct sembuf pbuf; //pbuf = structura de tip sembuf folosita de semop(), care defineste optiunile operatiei efectuate
	pbuf.sem_num=0; //numarul semaforului (indicele) asupra caruia se opereaza
	pbuf.sem_op=-1; //decrementeaza semaforul cu 1
	pbuf.sem_flg=SEM_UNDO; //SEM_UNDO pozitionat, atunci |sem_op| este adunat la semadj corespondent semaforului in tabela asociata in proces pentru setul de semafoare
	if (semop(semid, &pbuf, 1)) //operam asupra setului de semafoare cu id-ul "semid", folosind structura de optiuni "pbuf", facand "1" operatii asupra setului de semafoare
	{
		err_sys("Eroare semop");
	}
}
void V(int semid) //deblocheaza resursa = iesi din regiunea critica
{
	struct sembuf vbuf; //vbuf = structura de tip sembuf folosita de semop(), care defineste optiunile operatiei efectuate
	vbuf.sem_num=0; //numarul semaforului (indicele) asupra caruia se opereaza
	vbuf.sem_op=1; //incrementeaza semaforul cu 1
	vbuf.sem_flg=SEM_UNDO; //SEM_UNDO pozitionat, atunci |sem_op| este adunat la semadj corespondent semaforului in tabela asociata in proces pentru setul de semafoare
	if (semop(semid, &vbuf, 1)) //operam asupra setului de semafoare cu id-ul "semid", folosind structura de optiuni "pbuf", facand "1" operatii asupra setului de semafoare
	{
		err_sys("Eroare semop");
	}
}