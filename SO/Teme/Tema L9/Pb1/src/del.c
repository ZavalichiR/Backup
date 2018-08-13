#include "../inc/pcsem.h"
int main(void)
{
	int shmid, semid;
	if ((shmid=shmget(shmkey, 0, 0))<0)
	{
		err_sys("Eroare - nu exista zona de memorie partajata");
	}
	if (shmctl(shmid, IPC_RMID, 0)<0)
	{
		err_sys("Eroare shmctl");
	}
	if ((semid=semget(semkey, 0, 0))<0) 
	{
		err_sys("Eroare - nu exista setul de semafoare");
	}
	if (semctl(semid, 0, IPC_RMID, 0)<0)
	{
		err_sys("Eroare semctl");
	}
	printf("OK.\n");
	exit(0);
}
