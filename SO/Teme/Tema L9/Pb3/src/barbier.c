#include <stdio.h>
#include <signal.h>
#include "../inc/pv.h"
// Cheile pentru semafoare
key_t client_key=0x200; 
key_t barbier_key=0x300; 
key_t mutex_key=0x400; 
key_t shmkey=0x500; 

int s_client, s_barbier, mutex; //cele 3 semafoare

struct databuf {
	int nrScaune, nrClienti;
	int in_asteptare; //numarul de clienti in asteptare 
};

int initsem(key_t semkey, int nr_sem, int val_sem)
{
	int semid;
	if ((semid=semget(semkey, nr_sem, SEMPERM | IPC_CREAT))==-1)
		{
		err_sys("Eroare semget");
	}
	
	int i;
	for (i=0; i<nr_sem; ++i)
	{
		if (semctl(semid, i, SETVAL, val_sem)<0)
		{
			err_sys("Eroare semctl");
		}
	}
	
	return semid;
}

void barbier()
{
	//preluam memoria partajata
	int shmid;
	shmid=shmget(shmkey, 0, SEMPERM);
	struct databuf* b_buf;
	b_buf=(struct databuf*) shmat(shmid, 0, 0);

	//preluam semafoarele
	int s_client, s_barbier, mutex;
	if ((s_client=semget(client_key, 0, 0))<0)
	{
		err_sys("Eroare semget");
	}
	if ((s_barbier=semget(barbier_key, 0, 0))<0)
	{
		err_sys("Eroare semget");
	}
	if ((mutex=semget(mutex_key, 0, 0))<0)
	{
		err_sys("Eroare semget");
	}
	printf("Numar de clienti: %d\n", b_buf->nrClienti);

	while (1)
	{
		printf("Barbierul asteapta clienti.\n");
		P(s_client); 
		printf("Barbierul are un client.\n");
		P(mutex); 
		b_buf->in_asteptare--;
		V(mutex);
		//barbiereste
		printf("Barbierul lucreaza.\n");
		sleep(random()%10);
		V(s_barbier); //barbierul a terminat de lucrat,
		printf("Barbierul a terminat de lucrat si asteapta un nou client.\n");
	}
}

void client()
{
	int pid=getpid();

	//preluam memoria partajata
	int shmid;
	shmid=shmget(shmkey, 0, SEMPERM);
	struct databuf* cl_buf;
	cl_buf=(struct databuf*) shmat(shmid, 0, 0);

	//preluam semafoarele
	int s_client, s_barber, mutex;
	if ((s_client=semget(client_key, 0, 0))<0)
	{
		err_sys("Eroare semget");
	}
	if ((s_barbier=semget(barbier_key, 0, 0))<0)
	{
		err_sys("Eroare semget");
	}
	if ((mutex=semget(mutex_key, 0, 0))<0)
	{
		err_sys("Eroare semget");
	}
	P(mutex); 
	printf("A sosit clientul %d in sala de asteptare.\n", pid);
	if (cl_buf->in_asteptare<cl_buf->nrScaune) //daca exista scaune libere
	{
		cl_buf->in_asteptare++; //a mai intrat un client si s-a asezat pe un scaun in sala de asteptare
		V(s_client); //deblocare
		printf("Barbierul se trezeste.\n");
		V(mutex); 
		P(s_barbier); //asteapta ca barbierul sa termine lucrul
		printf("Clientul %d este barbierit...\n", getpid());
		sleep(random()%10);
	}
	else //daca nu sunt scaune libere clientul pleaca
	{
		V(mutex); //clientul pleaca si elibereaza locul ocupat
	}
	exit(0);
}

int main(int argc, char *argv[])
{
	if (argc!=3) 	{
		fprintf(stderr, "Eroare! Nu au fost trimise ca argumente numarul de scaune si numarul de clienti.\n");
		exit(EXIT_FAILURE);
	}

	int s_client, s_barbier, mutex; 

	//initializarea semafoarelor
	s_client=initsem(client_key, 1, 0); 
	s_barbier=initsem(barbier_key, 1, 1); 
	mutex=initsem(mutex_key, 1, 1); 
	//initializarea memoriei partajate
	int shmid; //id-ul
	if ((shmid=shmget(shmkey, sizeof(struct databuf), IPC_CREAT | IPC_EXCL | 0666))<0) //alocam memoria partajata
	{
		err_sys("Eroare shmget");
	}
	struct databuf* barb_buf; //structura de date partajata de procesele create
	barb_buf=(struct databuf*) shmat(shmid, 0, 0);

	barb_buf->nrScaune=atoi(argv[1]); //numarul de scaune
	barb_buf->nrClienti=atoi(argv[2]); //numarul de clienti
	barb_buf->in_asteptare=0; //numarul de clienti aflati in sala de asteptare

	int pid_barbier; //PID-ul barbierului
	int* pids_clienti; //PID-urile clientilor
	int i;
	pids_clienti=(int*)malloc(barb_buf->nrClienti*sizeof(int));

	//cream procesul fiu pentru barbier
	if ((pid_barbier=fork())==0)
	{
		barbier();
	}

	printf("Numar de clienti: %d\n", barb_buf->nrClienti);
	//cream procesele fiu pentru clienti
	for (i=0; i<barb_buf->nrClienti; ++i)
	{
		if ((pids_clienti[i]=fork())==0)
		{
			client();
		}
	}

	for (i=0; i<barb_buf->nrClienti; ++i) //asteptam sa isi incheie executia clientii
	{
		waitpid(pids_clienti[i], NULL, 0);
	}
	
	kill(pid_barbier, SIGTERM);

	if (pids_clienti)
	{
		free(pids_clienti);
		pids_clienti=NULL;
	}

	//stergem semafoarele
	if (semctl(s_client, 0, IPC_RMID, 0)<0)
	{
		err_sys("Eroare semctl");
	}
	if (semctl(s_barbier, 0, IPC_RMID, 0)<0)
	{
		err_sys("Eroare semctl");
	}
	if (semctl(mutex, 0, IPC_RMID, 0)<0)
	{
		err_sys("Eroare semctl");
	}

	//eliberam zona de memorie partajata
	if (shmctl(shmid, IPC_RMID, 0)<0)
	{
		err_sys("Eroare shmctl");
	}

	return 0;
}
