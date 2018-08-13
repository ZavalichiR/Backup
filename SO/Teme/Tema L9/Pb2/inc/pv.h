#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "hdr.h"
#define SEMPERM 0600 

void P(int semid, int sem_num)
{
	struct sembuf pbuf; 
	pbuf.sem_num=sem_num;
	pbuf.sem_op=-1; 
	pbuf.sem_flg=SEM_UNDO; 
	if (semop(semid, &pbuf, 1)) 
	{
		err_sys("Eroare semop");
	}
}
void V(int semid, int sem_num) 
{
	struct sembuf vbuf; 
	vbuf.sem_num=sem_num; 
	vbuf.sem_op=1; 
	vbuf.sem_flg=SEM_UNDO;
	if (semop(semid, &vbuf, 1)) 
	{
		err_sys("Eroare semop");
	}
}
