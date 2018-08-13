#include <stdio.h>
#include "../inc/pv.h"

key_t forks_key=0x200; 
key_t valet_key=0x400; 
int furculite; 
int valet; 

int initsem(key_t semkey, int nr_sem, int val_sem)
{
	int semid;
	if ((semid=semget(semkey, nr_sem, SEMPERM | IPC_CREAT))==-1) 
	{
		err_sys("Eroare semget");
	}
	
	int i;
	for (i=0; i<nr_sem; ++i) 	{
		if (semctl(semid, i, SETVAL, val_sem)<0) 
		{
			err_sys("Eroare semctl");
		}
	}
	
	return semid;
}

void philosopher(int i, int nr_iter)
{
	int pid=getpid();
	int j;
	for (j=0; j<nr_iter; ++j)
	{
		printf("\n                      ITERATIA %d\n",j+1);
		printf("\n-------------------------------------------------------\n");
		P(valet, 0); 
		printf("Filosoful %d intra in camera.\n", pid);
		P(furculite, i); 
		printf("Filosoful %d ridica furculita stanga.\n", pid);
		P(furculite, (i+1)%5); 
		printf("Filosoful %d ridica furculita dreapta.\n", pid);
		printf("Filosoful %d mananca.\n", pid);
		sleep(random()%5);
		V(furculite, i); 
		printf("Filosoful %d elibereaza furculita stanga.\n", pid);
		V(furculite, (i+1)%5); 
		printf("Filosoful %d elibereaza furculita dreapta.\n", pid);
		V(valet, 0); 
		printf("Filosoful %d iese din camera.\n", pid);
		printf("-------------------------------------------------------\n");
	}
}

void del(key_t semkey)
{
	int semid;
	if ((semid=semget(semkey, 0, 0))<0) 
	{
		err_sys("Eroare ­ nu exista setul de semafoare ");
	}
	if (semctl(semid, 0, IPC_RMID, 0)<0) 
	{
		err_sys("Eroare semctl");
	}
}

int main(int argc, char* argv[])
{
	furculite=initsem(forks_key, 5, 1); 
	valet=initsem(valet_key, 1, 4); 
	int pid_parinte=getpid();
	int pids[5]; 
	int i;
	int nr_iteratii=atoi(argv[1]);

	if ((pids[0]=fork())==0) 
	{
		philosopher(0, nr_iteratii);
		exit(0);
	}
	if ((pids[1]=fork())==0) 
	{
		philosopher(1, nr_iteratii);
		exit(0);
	}
	if ((pids[2]=fork())==0) 
	{
		philosopher(2, nr_iteratii);
		exit(0);
	}
	if ((pids[3]=fork())==0) 
	{
		philosopher(3, nr_iteratii);
		exit(0);
	}
	if ((pids[4]=fork())==0)
	{
		philosopher(4, nr_iteratii);
		exit(0);
	}

	for (i=0; i<5; ++i) 
	{
		waitpid(pids[i], NULL, 0);
	}

	del(forks_key);
	del(valet_key);
	
}
