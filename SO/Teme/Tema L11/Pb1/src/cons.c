#include "../inc/mesaj.h"
#include "../inc/hdr.h"

int main(void)
{
	struct message msg;
	msg.mtype=tip; 
	int id_msgq_prod, id_msgq_cons; //id-urile cozilor de mesaje
	int i;

	if ((id_msgq_prod=msgget((key_t)PROD_KEY, 0))<0) //preluam coada de mesaje producator
	{
		err_sys("Eroare msgget");
	}
	if ((id_msgq_cons=msgget((key_t)CONS_KEY, 0))<0) //preluam coada de mesaje consumator
	{
		err_sys("Eroare msgget");
	}

	for (i=1; i<=capacitate; ++i)
	{
		sleep(random()%5);
		if (msgrcv(id_msgq_cons, &msg, capacitate, tip, 0)<0) 
		{
			err_sys("Eroare msgrcv");
		}
		printf("Consumatorul %d a consumat mesajul: %s\n", getpid(), msg.mtext);
		if (msgsnd(id_msgq_prod, &msg, 0, IPC_NOWAIT)<0) //trimitere mesaj de raspuns catre producator; IPC_NOWAIT = nu astepta in caz de eroare
		{
			err_sys("Eroare msgsnd");
		}
	}

	exit(1);
}
