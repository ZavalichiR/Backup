#include "../inc/mesaj.h"
#include "../inc/hdr.h"

int main(void)
{
	struct message msg;
	msg.mtype=tip;
	char c='a'; 
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
		if (msgrcv(id_msgq_prod, &msg, capacitate, tip, 0)<0) //primire mesaj din coada;
		{
			err_sys("Eroare msgrcv");
		}
		strcpy(msg.mtext, &c);
		msg.mtext[1]='\0';
		c+=1;
		printf("Producatorul %d a produs mesajul: %s\n", getpid(), msg.mtext);
		if (msgsnd(id_msgq_cons, &msg, capacitate, IPC_NOWAIT)<0) //trimitere mesaj in coada, spre a fi consumat; IPC_NOWAIT = nu astepta in caz de eroare
		{
			err_sys("Eroare msgsnd");
		}
		sleep(random()%5);
	}

	exit(1);
}
