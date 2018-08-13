#include "../inc/pv.h"
int main(void)

{
	// Cheile pentru semafoare
	key_t client_key=0x200; //"numar de clienti in asteptare"
	key_t barber_key=0x300; //barbier
	key_t mutex_key=0x400; //excludere mutuala
	key_t shmkey=0x500; //zona de memorie partajata

	int shmid, semid;
	if ((shmid=shmget(shmkey, 0, 0))<0) //preluare ID
	{
		err_sys("Eroare - nu exista zona de memorie partajata");
	}
	if (shmctl(shmid, IPC_RMID, 0)<0) //sterge zona de memorie
	{
		err_sys("Eroare shmctl");
	}

	//stergem semafoarele
	if ((semid=semget(client_key, 0, 0))<0) //preluam id-ul setului de semafoare
	{
		err_sys("Eroare - nu exista setul de semafoare");
	}
	if (semctl(semid, 0, IPC_RMID, 0)<0) //stergem setul de semafoare
	{
		err_sys("Eroare semctl");
	}
	if ((semid=semget(barber_key, 0, 0))<0) //preluam id-ul setului de semafoare
	{
		err_sys("Eroare - nu exista setul de semafoare");
	}
	if (semctl(semid, 0, IPC_RMID, 0)<0) //stergem setul de semafoare
	{
		err_sys("Eroare semctl");
	}
	if ((semid=semget(mutex_key, 0, 0))<0) //preluam id-ul setului de semafoare
	{
		err_sys("Eroare - nu exista setul de semafoare");
	}
	if (semctl(semid, 0, IPC_RMID, 0)<0) //stergem setul de semafoare
	{
		err_sys("Eroare semctl");
	}
}
