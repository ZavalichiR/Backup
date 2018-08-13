#include"sem.h"

int initsem(key_t semkey)
{
	int status,semid;
	semid=semget(semkey,1,SEMPERM|IPC_CREAT);
	status=semctl(semid,0,SETVAL,1);
	return semid;
}

void P(int semid)
{
	struct sembuf pbuf;
	pbuf.sem_num=0;
	pbuf.sem_op=-1;
	pbuf.sem_flg=SEM_UNDO;
	semop(semid,&pbuf,1);
}

void V(int semid)
{
	struct sembuf pbuf;
	pbuf.sem_num=0;
	pbuf.sem_op=1;
	pbuf.sem_flg=SEM_UNDO;
	semop(semid,&pbuf,1);
}
