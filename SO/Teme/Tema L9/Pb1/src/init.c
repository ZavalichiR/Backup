#include <signal.h>
#include "../inc/pcsem.h"

int shmid; 
void initsem(int semid, int semnr, int val)
{
	semctl(semid, semnr, SETVAL, val); 
	printf("Initializarea este: semnr=%d, val=%d\n", semnr, val);
}
int main(void)
{
	int semid, i;
	struct databuf* pbuf; 
	if ((semid=semget(semkey, N, SEMPERM | IPC_CREAT))<0) 
	{
		err_sys("Eroare semget");
	}
	if ((shmid=shmget(shmkey, sizeof(struct databuf), IPC_CREAT | IPC_EXCL | 0666))<0)
	{
		err_sys("Eroare shmget");
	}
	initsem(semid, spacesleft, BUFFMAX+1);
	initsem(semid, itemsready, 0);
	initsem(semid, mutex, 1); 
	pbuf=(struct databuf*) shmat(shmid, 0, 0);
	pbuf->nextin=0; pbuf->nextout=0; pbuf->nr_prod=0;
}
