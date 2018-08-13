#include "../inc/pcsem.h"
void put(char ch)
{
	int shmid; 
	struct databuf* pbuf; 
	char* pd_buf; 
	shmid=shmget(shmkey, 0, SEMPERM);
	pbuf=(struct databuf*) shmat(shmid, 0, 0);
	pd_buf=pbuf->d_buff;
	pd_buf[pbuf->nextin]=ch;
	pbuf->nextin=(pbuf->nextin+1)%(BUFFMAX+1);
	afis(pd_buf, 0, 4);
}
void producer(void)
{
	char local;
	int semid, shmid; 
	struct databuf *pbuf;
	shmid=shmget(shmkey, 0, SEMPERM);
	pbuf=(struct databuf*) shmat(shmid, 0, 0);
	pbuf->nr_prod++; 
	semid=semget(semkey, 0, SEMPERM);
	for (local='a'; local<='z'; ++local)
	{
		P(semid, spacesleft); 
		P(semid, mutex);
		put(local); 
		V(semid, mutex);
		V(semid, itemsready);
	}
	pbuf->nr_prod--;
	exit(0);
}
int main(void)
{
	producer();
	return 0;
}
